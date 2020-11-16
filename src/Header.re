open Shortener;
open Webapi;

module Styles {
  open Css;

  let root = style([
    display(`flex),
    alignItems(`center),
    // justifyContent(`spaceBetween),

    width(`percent(100.0)),
    padding(px(SDefs.primaryPaddingPx * 2))
  ]);
};

module Logo {
  module Styles {
    open Css;

    let root = style([
      display(`flex),
      alignItems(`center),

      color(white)
    ]);

    let circle = style([
      display(`flex),
      alignItems(`center),
      justifyContent(`center),

      width(SDefs.nameSignSize),
      height(SDefs.nameSignSize),
      borderRadius(`percent(50.)),

      backgroundColor(SDefs.primaryColor),
      fontFamily(`custom(Fonts.jost)),
      fontWeight(`bold),
      fontSize(SDefs.nameSignFontSize),
    ]);
    
    let title = style([
      margin2(~h=SDefs.nameHMargin, ~v=`zero),
      fontSize(SDefs.nameFontSize),
    ]);

    let firstName = style([
      fontWeight(bold)
    ]);
  };

  [@react.component]
  let make = () => {
    let comp = Js.String.split(" ", Data.fullName);

    <div className=Styles.root>
      <div className=Styles.circle>
      {React.string(String.length(Data.fullName) > 0 ? String.make(1, String.get(Data.fullName, 0)) : "")}
      </div>
      <div className=Styles.title>
        <span className=Styles.firstName>{React.string(comp[0] ++ " ")}</span>
        {React.string(Array.length(comp) > 0 ? comp[Array.length(comp) - 1] : "")}
      </div>
    </div>
  }
};

module NavigationItem {
  module Styles {
    open Css;

    let root = style([
      padding(`zero),
      border(`zero, `none, `currentColor),
      background(`none),

      margin(SDefs.navItemMargin),
      
      fontSize(SDefs.navItemFontSize),
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
    open Css;
    
    let root = style([
      display(`none),
      margin4(~left=SDefs.navMarginLeft, ~top=SDefs.navMarginTop, ~right=SDefs.navMarginRight, ~bottom=SDefs.navMarginBottom),

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