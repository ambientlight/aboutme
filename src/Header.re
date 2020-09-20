open Css;

module Styles {
  let root = style([
    display(`flex),
    alignItems(`center),
    justifyContent(`spaceBetween),

    width(`percent(100.0)),
    padding(px(32))
  ]);
};

module Logo {
  module Styles {
    let root = style([
      display(`flex),
      alignItems(`center),

      color(white)
    ]);

    let circle = style([
      display(`flex),
      alignItems(`center),
      justifyContent(`center),

      width(px(50)),
      height(px(50)),
      borderRadius(`percent(50.)),

      backgroundColor(blue),
      fontFamily(`custom(Fonts.jost)),
      fontWeight(`bold),
      fontSize(`px(32)),
    ]);
    
    let title = style([
      margin2(~h=`px(12), ~v=`zero),
      fontSize(`px(18)),
    ]);

    let firstName = style([
      fontWeight(bold)
    ]);
  };

  [@react.component]
  let make = () => 
    <div className=Styles.root>
      <div className=Styles.circle>{ReasonReact.string("T")}</div>
      <div className=Styles.title>
        <span className=Styles.firstName>{ReasonReact.string("Taras ")}</span>
        {ReasonReact.string("Vozniuk")}
      </div>
    </div>
};

module NavigationItem {
  module Styles {
    let root = style([
      padding(`zero),
      border(`zero, `none, `currentColor),
      background(`none),

      fontSize(px(15)),
      fontFamily(`custom(Fonts.jost)),
      cursor(`pointer),
      color(white),

      selector("&:focus", [
        outline(`zero, `none, `currentColor)
      ]),

      selector("&:active", [
        color(darkgrey)
      ])
    ])
  };

  [@react.component]
  let make = (~children) => 
    <button className=Styles.root>
      children
    </button>
}

module Navigation {
  module Styles {

  };

  [@react.component]
  let make = () => 
    <div>
      <NavigationItem>{ReasonReact.string("About Me")}</NavigationItem>
    </div>
};

[@react.component]
let make = () => 
  <header className=Styles.root>
    <Logo/>
    <Navigation/>
  </header>