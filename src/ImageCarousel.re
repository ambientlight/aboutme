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

  let compactImage = style([
    width(`percent(48.))
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

    selector("&.white", [
      backgroundColor(white)
    ])
  ]);
}

let handleScroll = (event, indicatorCount, indicatorGroupRef: React.ref(Js.Nullable.t(Dom.element))) => {
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

[@react.component]
let make = (~urls: array(string), ~compact: bool=false) => {
  let indicatorGroupRef = React.useRef(Js.Nullable.null);
  let indicatorCount = compact ? Array.length(Utils.Array.pairwise(urls)) : Array.length(urls);
  
  <>
    <div className=Styles.root onScroll={event => handleScroll(event, indicatorCount, indicatorGroupRef)}>
      {
        compact
        ? Utils.Array.pairwise(urls) 
          |> Array.map(pair => 
            <div className=Styles.doubleImageGroup>
              <img className=Styles.compactImage src=pair[0]/>
              { Array.length(pair) > 1 ? <img className=Styles.compactImage src=pair[1]/> : <> </>}
            </div>
          )
          |> ReasonReact.array
        : urls
          |> Array.map(url => <img src=url/>)
          |> ReasonReact.array
      }
    </div>
    
    <div className=Styles.indicatorGroup ref={ReactDOM.Ref.domRef(indicatorGroupRef)}>
      {
        Belt.Array.range(0, indicatorCount - 1)
        |> Array.map(idx => <div className={Styles.indicator ++ (idx == 0 ? " white" : "")}></div>)
        |> ReasonReact.array
      }
    </div>
  </>;
}