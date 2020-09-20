open Css;

module Styles {
  let root = style([
    display(`flex),
    alignItems(`center),
    //justifyContent(`spaceAround),
    flexDirection(`column),

    //width(vw(100.0)),
    //height(vh(100.0)),
    overflowX(Css.Types.Overflow.hidden),
    overflowY(Css.Types.Overflow.scroll),

    backgroundColor(rgb(0,0,0)),

    fontFamily(`custom(Fonts.jost)),
    color(white)
  ])
};

[@react.component]
let make = () => 
  <div className=Styles.root>
    <Header/>
    <Intro/>
  </div>