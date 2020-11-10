module Styles {
  open Css;

  let root = style([
    display(`flex),
    overflowX(`auto),
    width(`percent(100.)),
    
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

    selector("& > img", [
      unsafe("scroll-snap-align", "start"),
      flexShrink(0.),
      width(`percent(100.)),
      marginRight(`percent(2.)),
      borderRadius(px(4)),
      
      display(`flex),
      justifyContent(`center),
      alignItems(`center),
      fontSize(px(100))
    ])
  ]);

  let compactImage = style([
    width(`percent(48.))
  ]);
}

[@react.component]
let make = (~urls: array(string), ~compact: bool=false) => {
  <div className=Styles.root>
    {
      urls
      |> Array.map(url => <img className={compact ? Styles.compactImage : ""} src=url/>)
      |> ReasonReact.array
    }
  </div>
}