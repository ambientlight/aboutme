open Css;
open Shortener;
open Webapi;

module Styles {
  let root = style([
    display(`flex),
    alignItems(`center),
    // justifyContent(`spaceBetween),

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
      <div className=Styles.circle>{React.string("T")}</div>
      <div className=Styles.title>
        <span className=Styles.firstName>{React.string("Taras ")}</span>
        {React.string("Vozniuk")}
      </div>
    </div>
};

module NavigationItem {
  module Styles {
    let root = style([
      padding(`zero),
      border(`zero, `none, `currentColor),
      background(`none),

      margin(px(12)),
      
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
  
  /***
   * similar to <a/> nav with scroll-behavior: smooth
   */
  let scrollIntoSeperatorView = navId => {
    let state = Dom.History.state(Dom.history);
    Dom.history
    |> Dom.History.pushState(state, navId, "#" ++ navId);

    Dom.document
    |> Dom.Document.getElementById(navId)
    |. optmap(elem => Dom.Element.scrollIntoViewWithOptions({"behavior": "smooth", "block": "start"}, elem))
    |> ignore;
  };

  [@react.component]
  let make = (~children, ~navId: string) => 
    <button className=Styles.root onClick={_event => scrollIntoSeperatorView(navId)}>
      children
    </button>
}

module Navigation {
  module Styles {
    let root = style([
      display(`none),
      margin4(~left=px(32), ~top=px(4), ~right=px(64), ~bottom=`zero),

      Media.atLeast(Media.Breakpoint.Tablet, [display(`initial)])
    ])
  };

  [@react.component]
  let make = () => 
    <div className=Styles.root>
      <NavigationItem navId="stacks">{React.string(Data.stacksTitle)}</NavigationItem>
      <NavigationItem navId="journey">{React.string(Data.journeyTitle)}</NavigationItem>
      <NavigationItem navId="proj">{React.string(Data.projectsTitle)}</NavigationItem>
      <NavigationItem navId="awards">{React.string(Data.awardsTitle)}</NavigationItem>
      <NavigationItem navId="contrib">{React.string(Data.contribsTitle)}</NavigationItem>
    </div>
};

[@react.component]
let make = () => 
  <header className=Styles.root>
    <Logo/>
    <Navigation/>
  </header>