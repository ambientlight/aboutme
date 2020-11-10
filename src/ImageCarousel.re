module Styles {
  open Css;

  let root = style([
    display(`flex),
    overflowX(`auto),
    width(`percent(100.)),
    paddingBottom(px(8)),

    unsafe("scroll-snap-type", "x mandatory"),
    unsafe("scroll-behavior", "smooth"),
    unsafe("-webkit-overflow-scrolling", "touch"),

    selector("&::-webkit-scrollbar", [
      width(px(5)),
      height(px(5))
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
}

[@react.component]
let make = (~urls: array(string), ~compact: bool=false) => {
  <div className=Styles.root>
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
}