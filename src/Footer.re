open Css;

module Styles {
  let root = style([
    marginTop(px(40)),

    height(`px(54)),
    width(`percent(100.0)),
    borderTop(px(1), `solid, rgb(50, 50, 50)),

    display(`flex),
    alignItems(center),
    justifyContent(`spaceBetween)
  ])

  let linksBlock = style([
  ]);

  let footerLink = style([
    color(grey),
    textDecoration(`none),
    padding(px(12)),

    selector("&:hover, &:visited, &:link, &:active", [
      textDecoration(`none)
    ]),

    selector("&:hover", [
      color(white)
    ])
  ]);

  let footerInfo = style([
    margin(px(12)),
    fontSize(px(15))
  ]);
};

[@react.component]
let make = () => 
  <div className=Styles.root>
    <div className=Styles.linksBlock>
      <a className=Styles.footerLink href="https://github.com/ambientlight">{ReasonReact.string("github")}</a>
      <a className=Styles.footerLink href="https://stackoverflow.com/users/2380455/ambientlight">{ReasonReact.string("stackoverflow")}</a>
      <a className=Styles.footerLink href="https://www.linkedin.com/in/tarasvozniuk/">{ReasonReact.string("linkedin")}</a>
    </div>

    <div className=Styles.footerInfo>
      {React.string("Taras Vozniuk, made with ")}
      <span style={ReactDOM.Style.make(~color="#e25555", ())}>{React.string({j|❤|j})}</span>
      {React.string(" in reasonml")}
    </div>
  </div>