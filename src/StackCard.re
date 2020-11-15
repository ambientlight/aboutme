open Css;

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

    backgroundColor(hex("333")),
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

  let cardCompact = merge([
    card,
    style([
      width(px(96)),
      margin(px(7)),
      padding(px(8)),
      fontSize(px(14))
    ])
  ])

  let cardImgCompact = merge([
    cardImg,
    style([
      width(px(32)),
      height(px(32)),
      borderRadius(px(8)),
      marginBottom(px(4))
    ])
  ])
};

[@react.component]
let make = (~info: info, ~isCompact: bool=false) => 
  <div className={isCompact ? Styles.cardCompact : Styles.card}>
    <img className={isCompact ? Styles.cardImgCompact : Styles.cardImg} src=info.imgUrl/>
    {React.string(info.name)}
  </div>;