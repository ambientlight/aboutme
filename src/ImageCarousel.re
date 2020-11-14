open Webapi;
open Shortener;

module Styles {
  open Css;

  let root = style([
    display(`flex),
    overflowX(`auto),
    width(`percent(100.)),
    // paddingBottom(px(8)),

    unsafe("scroll-snap-type", "x mandatory"),
    unsafe("scroll-behavior", "smooth"),
    unsafe("-webkit-overflow-scrolling", "touch"),

    selector("&::-webkit-scrollbar", [
      width(px(5)),
      height(px(0))
    ]),

    selector("&::-webkit-scrollbar-thumb", [
      backgroundColor(white),
      borderRadius(px(5))
    ]),

    selector("&::-webkit-scrollbar-track", [
      backgroundColor(transparent)
    ]),

    selector("& > *", [
      unsafe("scroll-snap-align", "start"),
      flexShrink(0.),
      width(`percent(100.)),
      marginRight(`percent(2.)),
      borderRadius(px(4)),
      
      display(`flex),
      alignItems(`center)
    ])
  ]);

  let doubleImageGroup = style([
    display(`flex),
    justifyContent(`spaceBetween)
  ]);

  let image = style([
    cursor(pointer)
  ]);

  let compactImage = merge([
    image, 
    style([
      width(`percent(48.))
    ])
  ]);

  let indicatorGroup = style([
    display(`flex),
    width(`percent(100.)),
    justifyContent(`center)
  ]);

  let indicator = style([
    backgroundColor(grey),
    width(px(16)),
    height(px(16)),
    borderRadius(px(8)),
    margin2(~v=zero, ~h=px(4)),

    selector("&:hover", [
      cursor(pointer)
    ]),

    selector("&.white", [
      backgroundColor(white)
    ])
  ]);
}

let handleScroll = (event, indicatorCount, indicatorGroupRef: React.ref(Js.Nullable.t(Dom.Element.t))) => {
  let elem: Webapi.Dom.HtmlElement.t = event |> ReactEvent.UI.target |> Obj.magic;
  let perc = ((elem |> Webapi.Dom.HtmlElement.scrollLeft) /. float_of_int((elem |> Webapi.Dom.HtmlElement.scrollWidth)));
  let idx = int_of_float(floor(perc *. float_of_int(indicatorCount)));
  
  indicatorGroupRef.current
  |> Js.Nullable.toOption
  |. Belt.Option.map(indicatorGroup =>
    indicatorGroup 
    |> Webapi.Dom.Element.childNodes
    |> Webapi.Dom.NodeList.toArray
    |. Belt.Array.forEachWithIndex((indicatorIdx, indicator) => {
      let classList = indicator |> Obj.magic 
      |> Webapi.Dom.HtmlElement.classList;

      if(idx == indicatorIdx){
        classList |> Webapi.Dom.DomTokenList.add("white")
      } else {
        classList |> Webapi.Dom.DomTokenList.remove("white")
      }
    })
  )
  |> ignore
};

let scrollIntoPage = (id) => {
  Dom.document
  |> Dom.Document.getElementById(id)
  |. optmap(elem => Dom.Element.scrollIntoViewWithOptions({"behavior": "smooth", "block": "nearest"}, elem))
  |> ignore;
};

[@react.component]
let make = (~id: string, ~urls: array(string), ~compact: bool=false) => {
  let indicatorGroupRef = React.useRef(Js.Nullable.null);
  let indicatorCount = compact ? Array.length(Utils.Array.pairwise(urls)) : Array.length(urls);
  let (_, openImageDetail) = ImageDetail.Context.use();

  <>
    <div className=Styles.root onScroll={event => handleScroll(event, indicatorCount, indicatorGroupRef)}>
      {
        compact
        ? Utils.Array.pairwise(urls) 
          |> Array.mapi((idx, pair) => {
            let key = id ++ string_of_int(idx);
            <div key id=key className=Styles.doubleImageGroup>
              <img className=Styles.compactImage src=pair[0] onClick={_event => openImageDetail(ImageDetail.Shown(urls, idx * 2))}/>
              { Array.length(pair) > 1 
                ? <img className=Styles.compactImage src=pair[1] onClick={_event => openImageDetail(ImageDetail.Shown(urls, idx * 2 + 1))}/> 
                : <> </>}
            </div>
          })
          |> ReasonReact.array
        : urls
          |> Array.mapi((idx, url) => { 
            let key = id ++ string_of_int(idx);
            <img className=Styles.image key id=key src=url onClick={_event => openImageDetail(ImageDetail.Shown(urls, idx))}/>
          })
          |> ReasonReact.array
      }
    </div>
    
    <div className=Styles.indicatorGroup ref={ReactDOM.Ref.domRef(indicatorGroupRef)}>
      {
        Belt.Array.range(0, indicatorCount - 1)
        |> Array.map(idx => {
          let key = id ++ string_of_int(idx);
          <div key className={Styles.indicator ++ (idx == 0 ? " white" : "")} onClick={_event => scrollIntoPage(key)}></div>
        })
        |> ReasonReact.array
      }
    </div>
  </>;
}