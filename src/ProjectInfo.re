
open Css;

let teamIcon = [%bs.raw "require('assets/svgs/people_alt-white.svg')"];
let linkIcon = [%bs.raw "require('assets/svgs/link-white.svg')"];
let todayIcon = [%bs.raw "require('assets/svgs/today-white.svg')"];

module Styles {
  let root = style([
    width(`percent(100.)),
    padding2(~h=px(16), ~v=zero)
  ]);

  let projectTitle = style([
    fontWeight(`medium),
    fontSize(px(26))
  ]);

  let iframeContainer = style([
    width(px(500)),
    height(px(350))
  ]);

  let flexRow = style([
    display(`flex),
    Media.atMost(Media.Breakpoint.Phone, [
      flexWrap(`wrap)
    ])
  ]);

  let detail = style([
    display(`flex),
    flexDirection(`column),
    
    selector("& > *", [
      width(`percent(100.)),
      marginBottom(px(16)),
    ]),

    Media.atLeast(Media.Breakpoint.Tablet, [
      maxWidth(`percent(66.6))
    ]),
  ]);

  let description = style([
    backgroundColor(hex("333")),
    border(px(2), `solid, hex("444")),
    borderRadius(px(10)),

    padding(px(24)),
    width(`percent(100.)),
    height(`percent(100.)),

    Media.atLeast(Media.Breakpoint.Tablet, [
      marginLeft(px(24)),
      minWidth(`percent(33.3))
    ])
  ]);

  let descriptionHeader = style([
    margin4(~bottom=px(16), ~top=zero, ~right=zero, ~left=zero)
  ]);

  let iconDetail = style([
    display(`flex),
    alignItems(`center),

    selector("& > img", [
      width(px(16)),
      height(px(16)),
      marginRight(px(12))
    ]),

    fontSize(px(15)),
    marginBottom(px(4))
  ]);

  let iconBlock = style([
    
  ]);

  let descriptionDetail = style([
    fontSize(px(14)),
    margin2(~v=px(16), ~h=zero)
  ]);

  let cardList = style([
    display(`flex),
    flexWrap(`wrap)
  ]);

  let stackCard = style([
    backgroundColor(hex("666")),
    borderRadius(px(4)),
    padding2(~v=px(4), ~h=px(8)),
    fontSize(px(14)),
    margin4(~left=zero, ~top=px(4), ~right=px(4), ~bottom=px(4)),
    color(hex("ddd"))
  ]);

  let textDetail = style([
    marginTop(px(18))
  ])
};

type media = 
  | Youtube(string)
  | Image(string)
  | Text(string)

type linkable = {
  title: string,
  href: option(string)
}

type projectInfo = {
  title: string,
  media: array(media),
  team: option(linkable),
  href: option(linkable),
  duration: string,
  stackDescription: string,
  stackComponents: array(string)
};

[@react.component]
let make = (~info: projectInfo) => 
  <div className=Styles.root>
    <h2 className=Styles.projectTitle>{React.string(info.title)}</h2>

    <div className=Styles.flexRow>
      <div className=Styles.detail>
        {
          info.media
          |> Array.map(media => 
            switch(media){
            | Youtube(url) => 
              <div dangerouslySetInnerHTML={ 
                "__html": "<iframe width=\"100%\" height=\"280px\" className=Styles.smt src=\"" ++ url ++ "\" frameborder=\"0\" allow=\"accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture\" allowfullscreen></iframe>" 
              }></div>
            | Image(url) => 
              <img src=url/>
            | Text(text) => 
              <div className=Styles.textDetail>
                {React.string(text)}
              </div>
            }
          )
          |> ReasonReact.array
        }
      </div>

      <div className=Styles.description>
        <h4 className=Styles.descriptionHeader>{React.string("Description")}</h4>

        <div className=Styles.iconBlock>
          <div className=Styles.iconDetail>{ 
            switch(info.team){
            | Some(team) => (<> <img src=teamIcon/>{React.string(team.title)}</>)
            | None => (<> </>)
            }
          } </div>
          <div className=Styles.iconDetail>{ 
            switch(info.href){
            | Some(href) => (<> <img src=linkIcon/>{React.string(href.title)}</>)
            | None => (<> </>)
            }
          } </div>
          <div className=Styles.iconDetail>
            <img src=todayIcon/>{React.string(info.duration)}
          </div>
        </div>

        <div className=Styles.descriptionDetail>{React.string(info.stackDescription)}</div>

        <h4 className=Styles.descriptionHeader>{React.string("Stack")}</h4>
        <div className=Styles.cardList>
          {
            info.stackComponents
            |> Array.map(comp => <div className=Styles.stackCard>{React.string(comp)}</div>)
            |> ReasonReact.array
          }
        </div>
      </div>

    </div>

  </div>;