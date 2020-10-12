open Css;

module Styles {
  let seperatorBlock = style([
    width(`percent(100.0)),
    paddingLeft(px(16)),

    marginTop(px(38)),
    marginBottom(px(38)),

    fontWeight(`medium),
    
    fontSize(px(30)),
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
};

[@react.component]
let make = (~title) =>
  <div className=Styles.seperatorBlock>
    {React.string(title)}
    <div className=Styles.seperator>
      <div className=Styles.sepBlue></div>
      <div className=Styles.sepGrey></div>
    </div>
  </div>;