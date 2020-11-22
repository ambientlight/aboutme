open Css;
open Shortener;
open Webapi;

type state = 
  | Hidden 
  | Shown(array(string), int);

type setState = state => unit;

module Context {
  let context: React.Context.t((state, setState)) = React.createContext((Hidden, _ => ()));
  let use = () => React.useContext(context);
  let make = React.Context.provider(context);

  [@bs.obj]
  external makeProps:(~value: 'props, ~children: React.element, unit) => {
    .
    "value": 'props,
    "children": React.element,
  };
};

module WithBackdrop {
  module Styles {
    let root = style([
      display(`flex),
      alignItems(`center),
      justifyContent(`center),

      position(`fixed),
      top(`zero),
      left(`zero),
      bottom(`zero),
      right(`zero),
      backgroundColor(SDefs.imageDetailBackdropBgColor),
      zIndex(1)
    ]);

    let bottomPanel = style([
      display(`flex),
      flexDirection(`rowReverse),

      position(`fixed),
      width(`percent(100.)),
      bottom(`zero)
    ]);

    let button = style([
      border(`zero, `none, `currentColor),
      background(`none),

      padding2(~h=SDefs.imageDetailButtonHPadding, ~v=SDefs.imageDetailButtonVPadding),
      
      cursor(`pointer),
      backgroundColor(SDefs.imageDetailButtonBgColor),
      
      selector("&:focus", [
        outline(`zero, `none, `currentColor)
      ]),

      selector("&:active", [
        opacity(0.5)
      ]),

      selector("& > img", [
        width(SDefs.imageDetailButtonIconSize),
        height(SDefs.imageDetailButtonIconSize)
      ])
    ]);

    let imageContext = style([
      selector("& > img", [
        width(`vw(100.)),
        height(`vh(100.)),
        objectFit(`contain)
      ])
    ]);
  }

  let body = () => 
    Dom.document 
    |> Dom.Document.asHtmlDocument
    |. optfmap(doc => doc |> Dom.HtmlDocument.body)
    |. optfmap(body => body |> Dom.Element.asHtmlElement);

  [@react.component]
  let make = (~url, ~didClose, ~onLeft, ~onRight, ~noLeftRight) => {
    React.useEffect0(() => {
      body() |. optmap(body => body
        |> Dom.HtmlElement.style 
        |> Dom.CssStyleDeclaration.setProperty("overflow", "hidden", ""))
      |> ignore;

      Some(() => {
        body() |. optmap(body => body 
          |> Dom.HtmlElement.style 
          |> Dom.CssStyleDeclaration.setProperty("overflow", "unset", ""))
        |> ignore;
      })
    });

    React.useEffect(() => {
      let onKeydown = (ev) => {
        let kev = Obj.magic(ev)
        switch(ReactEvent.Keyboard.key(kev)){
        | "ArrowLeft" => onLeft(kev)
        | "ArrowRight" => onRight(kev)
        | "Escape" => didClose(kev)
        | _ => ()
        }
      };

      Dom.EventTarget.addEventListener("keydown", onKeydown, Dom.Document.asEventTarget(Dom.document));
      Some(() => {
        Dom.EventTarget.removeEventListener("keydown", onKeydown,  Dom.Document.asEventTarget(Dom.document))
      })
    });

    <div className=Styles.root>
      <div className=Styles.imageContext onClick=didClose>
        <img src=url/>
      </div>

      <div className=Styles.bottomPanel>
        <button className=Styles.button onClick=didClose>
          <img src=Icons.close/>
        </button>
        <button hidden=noLeftRight className=Styles.button onClick=onRight>
          <img src=Icons.forward/>
        </button>
        <button hidden=noLeftRight className=Styles.button onClick=onLeft>
          <img src=Icons.back/>
        </button>
      </div>
      
    </div>
  }
}

let modalRoot = Dom.document |> Dom.Document.getElementById("modal");

[@react.component]
let make = () => {
  let (state, setState) = Context.use(); 
  switch(state, modalRoot){
  | (Shown(urls, idx), Some(modalRoot)) => 
    ReactDOM.createPortal(
      <WithBackdrop
        url={urls[idx]}
        noLeftRight={Array.length(urls) <= 1}
        onLeft=(_e => setState(Shown(urls, idx > 0 ? idx - 1 : Array.length(urls) - 1))) 
        onRight=(_e => setState(Shown(urls, idx < Array.length(urls) - 1 ? idx + 1 : 0))) 
        didClose=(_e => setState(Hidden))
      />, modalRoot)
  | _ => <> </>
  }
}