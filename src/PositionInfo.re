open Css;

let geothingsLogo = [%bs.raw "require('assets/imgs/geothings_logo.png')"];

module Styles {
  let positionRow = style([
    display(`flex),
    flexDirection(`row),

    selector("& > *", [
      margin(px(16))
    ])
  ]);

  let entityImg = style([
    width(px(200)),
    height(px(200)),
    borderRadius(px(30)),
    backgroundColor(white),
    padding(px(20))
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
    fontSize(px(15))
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
    <div>
      <h3 className=Styles.companyName>{ReasonReact.string(info.companyName)}</h3>
      <h4 className=Styles.jobTitle>
        {ReasonReact.string([info.jobTitle, info.duration] |> Utils.List.join(~seperator=": "))}
      </h4>
      <section className=Styles.mainInfo>
        {
          info.description 
          |> String.split_on_char('\n')
          |. Belt.List.mapWithIndex((idx, str) => <p key={string_of_int(idx)}>{ReasonReact.string(str)}</p>)
          |> Array.of_list
          |> ReasonReact.array
        }
      </section>
    </div>
  </div>