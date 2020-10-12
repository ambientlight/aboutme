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

    backgroundColor(rgb(33,33,33)),

    fontFamily(`custom(Fonts.jost)),
    color(white)
  ]);
};

[@react.component]
let make = () => 
  <div className=Styles.root>
    <Header/>
    <Intro/>
    <Stacks/>
    <Journey/>
    <Projects/>
    <Footer/>
  </div>