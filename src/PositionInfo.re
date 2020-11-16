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
    borderRadius(SDefs.journeyItemImgBorderRadius),
    backgroundColor(white),
    padding(SDefs.journeyItemPadding)
  ]);

  let companyName = style([
    margin(`zero)
  ]);

  let jobTitle = style([
    marginTop(`zero),
    color(grey),
    fontWeight(`semiBold)
  ]);

  let mainInfo = style([
    fontSize(SDefs.journeyItemContentFontSize)
  ]);

  let textBlock = style([
    Media.atMost(Media.Breakpoint.Phone, [
      width(`percent(100.)),
    ])
  ]);
};

type jobInfo = {
  companyName: string,
  jobTitle: string,
  duration: string,
  imgUrl: string,
  description: string
};

[@react.component]
let make = (~info: jobInfo) => 
  <div className=Styles.positionRow>
    <img className=Styles.entityImg src={info.imgUrl}/>
    <div className=Styles.textBlock>
      <h3 className=Styles.companyName>{React.string(info.companyName)}</h3>
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