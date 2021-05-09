open Css;

type info = {
  name: string,
  imgUrl: string,
  href: string
};

module Styles {
  let card = style([
    display(`flex),
    flexDirection(`column),
    alignItems(`center),

    width(SDefs.sCardWidth),
    margin(SDefs.sCardMargin),

    backgroundColor(SDefs.sCardBackgrounColor),
    border(SDefs.sCardBorderWidth, `solid, SDefs.sCardBorderColor),
    // borderRadius(SDefs.sCardBorderRadius),

    fontWeight(`normal),
    padding(SDefs.sCardPadding),

    color(white),

    selector("&:hover, &:visited, &:link, &:active", [
      textDecoration(`none)
    ]),

    selector("&:hover", [
      transform(SDefs.sCardHoverTransform)
    ])
  ]);

  let cardImg = style([
    width(SDefs.sCardImgSize),
    height(SDefs.sCardImgSize),
    borderRadius(SDefs.sCardImgBorderRadius),
    marginBottom(SDefs.sCardBottomMargin)
  ]);

  let cardCompact = merge([
    card,
    style([
      width(SDefs.sCompactCardWidth),
      margin(SDefs.sCompactCardMargin),
      padding(SDefs.sCompactCardPadding),
      fontSize(SDefs.sCompactCardFontSize)
    ])
  ])

  let cardImgCompact = merge([
    cardImg,
    style([
      width(SDefs.sCompactCardImgSize),
      height(SDefs.sCompactCardImgSize),
      borderRadius(SDefs.sCompactCardImgBorderRadius),
      marginBottom(SDefs.sCompactCardBottomMargin)
    ])
  ])
};

[@react.component]
let make = (~info: info, ~isCompact: bool=false) => 
  <a target="_blank" href=info.href className={isCompact ? Styles.cardCompact : Styles.card}>
    <img className={isCompact ? Styles.cardImgCompact : Styles.cardImg} src=info.imgUrl/>
    {React.string(info.name)}
  </a>;