open Css;

module Styles {
  let positionRow = style([
    display(`flex),
    flexDirection(`row),
    Media.atMost(Media.Breakpoint.Phone, [
      flexWrap(`wrap)
    ]),
    
    selector("& > *", [
      margin(SDefs.journeyItemMargin)
    ])
  ]);

  let entityImg = style([
    width(SDefs.journeyItemImgSize),
    height(SDefs.journeyItemImgSize),
    padding(SDefs.journeyItemPadding)
  ]);

  let entityImgBgCover = style([
    width(SDefs.journeyItemImgSize),
    height(SDefs.journeyItemImgSize),
    // borderRadius(SDefs.journeyItemImgBorderRadius),
    backgroundColor(white),
    padding(SDefs.journeyItemPadding)
  ]);

  let companyName = style([
    fontFamily(`custom(Fonts.montserrat)),
    margin(`zero),

    selector("& > a", [
      color(white),
      selector("&:visited, &:link, &:active", [
        textDecoration(`none)
      ]),
      selector("&:hover", [
        textDecoration(`underline)
      ])
    ])
  ]);

  let jobTitle = style([
    marginTop(`zero),
    color(grey),
    fontWeight(`normal),
  ]);

  let mainInfo = style([
    fontSize(SDefs.journeyItemContentFontSize)
  ]);

  let textBlock = style([
    Media.atMost(Media.Breakpoint.Phone, [
      width(`percent(100.)),
    ])
  ]);

  let positionImgAnchor = style([
    Media.atMost(Media.Breakpoint.Phone, [
      margin(`auto)
    ])
  ]);
};

type jobInfo = {
  companyName: string,
  jobTitle: string,
  duration: string,
  imgUrl: string,
  description: string,
  href: string,

  bgCover: bool
};

[@react.component]
let make = (~info: jobInfo) => 
  <div className=Styles.positionRow>
    <a className=Styles.positionImgAnchor href=info.href>
      <img className={info.bgCover ? Styles.entityImgBgCover : Styles.entityImg} src={info.imgUrl}/>
    </a>
    <div className=Styles.textBlock>
      <h3 className=Styles.companyName><a href=info.href>{React.string(info.companyName)}</a></h3>
      <h4 className=Styles.jobTitle>
        {React.string([info.jobTitle, info.duration] |> Utils.List.join(~seperator=": "))}
      </h4>
      <section className=Styles.mainInfo>
        {
          info.description 
          |> String.split_on_char('\n')
          |. Belt.List.mapWithIndex((idx, str) => <p key={string_of_int(idx)}>{React.string(str)}</p>)
          |> Array.of_list
          |> React.array
        }
      </section>
    </div>
  </div>