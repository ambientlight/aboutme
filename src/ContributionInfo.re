module Styles {
  open Css;

  let root = style([
    marginBottom(px(20))
  ]);


  let link = style([
    display(`flex),
    fontSize(px(18)),
    marginBottom(px(4)),
    
    color(white),

    selector("&:hover, &:visited, &:link, &:active", [
      textDecoration(`underline)
    ]),

    selector("img", [
      margin4(~left=`zero, ~top=px(4), ~right=px(4), ~bottom=px(4)),
      
      width(px(20)),
      height(px(20)),
    ])
  ]);
  
  let description = style([
    color(hex("888"))
  ]);
}

type t = {
  href: string,
  title: string,
  description: string
};

[@react.component]
let make = (~info: t) =>
  <div className=Styles.root>
    <a target="_blank" className=Styles.link href={info.href}>
      <img src=Icons.cGithub/>
      {React.string(info.title)}
    </a>
    <span className=Styles.description>{React.string(info.description)}</span>
  </div>