open Css;

module Styles {
  let root = style([
    display(`flex),
    flexWrap(`wrap),
    width(`percent(100.)),
    justifyContent(`center)
  ]);
};

module StackCard {
  type info = {
    name: string,
    imgUrl: string
  };

  module Styles {
    let card = style([
      display(`flex),
      flexDirection(`column),
      alignItems(`center),

      width(px(160)),
      margin(px(8)),

      backgroundColor(Css.Types.Color.hex("333")),
      border(px(2), `solid, hex("444")),
      borderRadius(px(10)),

      fontWeight(`medium),
      padding(px(16)),

      selector("&:hover", [
        transform(translateY(px(-4)))
      ])
    ]);

    let cardImg = style([
      width(px(64)),
      height(px(64)),
      borderRadius(px(8)),
      marginBottom(px(8))
    ]);
  };

  [@react.component]
  let make = (~info: info) => 
    <div className=Styles.card>
      <img className=Styles.cardImg src=info.imgUrl/>
      {React.string(info.name)}
    </div>;
};

let pythonLogo = [%bs.raw "require('assets/imgs/python_logo.png')"];

let languages: array(StackCard.info) = [|
  {
    name: "typescript",
    imgUrl: [%bs.raw "require('assets/imgs/typescript_logo.jpg')"]
  },
  {
    name: "javascript",
    imgUrl: [%bs.raw "require('assets/imgs/javascript_logo.jpg')"]
  },
  {
    name: "reasonml",
    imgUrl: [%bs.raw "require('assets/imgs/reasonml_logo.jpg')"]
  },
  {
    name: "python",
    imgUrl: [%bs.raw "require('assets/imgs/python_logo.png')"]
  },
  {
    name: "swift",
    imgUrl: [%bs.raw "require('assets/imgs/swift_logo.png')"]
  },
  {
    name: "java",
    imgUrl: [%bs.raw "require('assets/imgs/java_logo.png')"]
  },
  { 
    name: "kotlin",
    imgUrl: [%bs.raw "require('assets/imgs/kotlin_logo.png')"]
  },
  {
    name: "ocaml",
    imgUrl: [%bs.raw "require('assets/imgs/ocaml_logo.jpg')"]
  },
  {
    name: "objective-c",
    imgUrl: [%bs.raw "require('assets/imgs/objc_logo.png')"]
  },
  { 
    name: "c/c++",
    imgUrl: [%bs.raw "require('assets/imgs/cpp_logo.png')"]
  }
|]; 

[@react.component]
let make = () => 
  <>
    <Seperator title="Languages"/>
    <div className=Styles.root>
    {
      languages
      |> Array.map(lang => <StackCard info=lang/>)
      |> ReasonReact.array
    }
    </div>
  </>