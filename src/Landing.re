open Css;

module Styles {
  let root = style([
    display(`flex),
    alignItems(`center),
    flexDirection(`column),

    overflowX(Css.Types.Overflow.hidden),
    // overflowY(Css.Types.Overflow.scroll),

    backgroundColor(rgb(33,33,33)),

    fontFamily(`custom(Fonts.jost)),
    color(white),
  ]);

  let innerContent = style([
    display(`flex),
    alignItems(`center),
    flexDirection(`column),
    width(`percent(100.0)),

    Media.exactly(Media.Breakpoint.Tablet, [
      padding2(~v=`zero, ~h=px(16))
    ]),
    Media.atLeast(Media.Breakpoint.Laptop, [
      width(px(900))
    ])
  ])
};

[@react.component]
let make = () => 
  <div className=Styles.root>
    <Header/>
    <Intro/>
    
    <div className=Styles.innerContent>
      <Stacks/>
      <Journey/>
      <Projects/>
    </div>
    
    <Footer/>
  </div>