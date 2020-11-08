open Css;

module Styles {
  let root = style([
    width(`percent(100.0)),
    paddingLeft(px(16)),

    marginTop(px(38)),
    marginBottom(px(38)),

    fontWeight(`medium),
    
    fontSize(px(30))
  ]);

  let seperatorLink = style([
    color(white),
    selector("&:hover, &:visited, &:link, &:active", [
      textDecoration(`none)
    ]),

    selector("&:hover", [
      cursor(pointer),
      selector("& > img", [
        display(initial)
      ])
    ])
  ]);

  let seperator = style([
    display(`flex)    
  ]);

  let sepBlue = style([
    width(px(32)),
    height(px(4)),

    backgroundColor(blue)
  ]);

  let sepGrey = style([
    width(px(128)),
    height(px(4)),
    
    backgroundColor(rgb(50, 50, 50))
  ]);

  let link = style([
    display(none),
    paddingLeft(px(4)),
    verticalAlign(`middle)
  ]);
};

let link = [%bs.raw "require('assets/svgs/link-gray-24.svg')"];

[@react.component]
let make = (~title, ~navId) =>
  <div id=navId className=Styles.root>
    <a href={"#" ++ navId} className=Styles.seperatorLink>
      {React.string(title)}
      <img className=Styles.link src=link/>
    </a>

    <div className=Styles.seperator>
      <div className=Styles.sepBlue></div>
      <div className=Styles.sepGrey></div>
    </div>
  </div>;