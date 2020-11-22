open Css;

module Styles {
  let root = style([
    width(`percent(100.0)),
    paddingLeft(SDefs.primaryPadding),

    margin2(~h=zero, ~v=SDefs.seperatorVMargin),
    
    // fontWeight(`medium),
    fontFamily(`custom(Fonts.montserrat)),
    fontSize(SDefs.seperatorFontSize)
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
    width(SDefs.seperatorUndescorePrimaryWidth),
    height(SDefs.seperatorUndescorePrimaryHeight),

    backgroundColor(SDefs.primaryColor)
  ]);

  let sepGrey = style([
    width(SDefs.seperatorUndescoreGrayWidth),
    height(SDefs.seperatorUndescoreGrayHeight),
    
    backgroundColor(SDefs.seperatorUndescoreGrayColor)
  ]);

  let link = style([
    display(none),
    paddingLeft(SDefs.seperatorLinkPaddingLeft),
    verticalAlign(`middle)
  ]);
};

[@react.component]
let make = (~title, ~navId) =>
  <div id=navId className=Styles.root>
    <a href={j|#$navId|j} className=Styles.seperatorLink>
      {React.string(title)}
      <img className=Styles.link src=Icons.linkGray/>
    </a>

    <div className=Styles.seperator>
      <div className=Styles.sepBlue></div>
      <div className=Styles.sepGrey></div>
    </div>
  </div>;