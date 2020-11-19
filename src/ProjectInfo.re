
open Css;
open Operators;

module Styles {
  let root = style([
    width(`percent(100.)),
    padding2(~h=SDefs.primaryPadding, ~v=zero)
  ]);

  let projectTitle = style([
    fontWeight(`medium),
    fontSize(SDefs.projectTitleFontSize)
  ]);

  let iframeContainer = style([
    width(SDefs.iFrameContainerWidth),
    height(SDefs.iFrameContainerHeight)
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
      marginBottom(SDefs.projectDetailMarginBottom),
    ]),

    Media.atLeast(Media.Breakpoint.Tablet, [
      maxWidth(`percent(66.6))
    ]),
  ]);

  let description = style([
    backgroundColor(SDefs.projectDescriptionBackgrounColor),
    border(SDefs.projectDescriptionBorderWidth, `solid, SDefs.projectDescriptionBorderColor),
    borderRadius(SDefs.projectDescriptionBorderRadius),

    padding(SDefs.projectDescriptionPadding),
    width(`percent(100.)),
    height(`percent(100.)),

    Media.atLeast(Media.Breakpoint.Tablet, [
      marginLeft(SDefs.projectDescriptionMarginLeft),
      minWidth(`percent(33.3))
    ])
  ]);

  let descriptionHeader = style([
    margin4(~bottom=SDefs.projectDescriptionHeaderMarginBottom, ~top=zero, ~right=zero, ~left=zero)
  ]);

  let iconDetail = style([
    display(`flex),
    alignItems(`center),

    selector("& > a", [
      display(`flex),
      alignItems(`center),
      
      color(white),
      selector("&:visited, &:link, &:active", [
        textDecoration(`none)
      ]),
      selector("&:hover", [
        textDecoration(`underline)
      ])
    ]),

    selector("img", [
      width(SDefs.projectDescriptionIconSize),
      height(SDefs.projectDescriptionIconSize),
      marginRight(SDefs.projectDescriptionIconMarginRight)
    ]),

    fontSize(SDefs.projectDescriptionIconDetailFontSize),
    marginBottom(SDefs.projectDescriptionIconDetailMarginBottom)
  ]);

  let iconBlock = style([
    
  ]);

  let descriptionDetail = style([
    fontSize(SDefs.projectDescriptionDetailFontSize),
    margin2(~v=SDefs.projectDescriptionDetailVMargin, ~h=zero)
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
    marginTop(SDefs.projectTextDetailMarginTop)
  ]);

  let doubleImageGroup = style([
    display(`flex),
    justifyContent(`spaceBetween)
  ]);

  let image = style([
    cursor(pointer)
  ])

  let compactImage = merge([
    image,
    style([
      width(`percent(48.))
    ])
  ])
};

type media = 
  | Youtube(string)
  | Image(string)
  | DoubleImage(string, string)
  | Text(string)
  | Carousel(string, array(string), bool)

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
let make = (~info: projectInfo) => {
  let (_, openImageDetail) = ImageDetail.Context.use();

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
              <img className=Styles.image src=url onClick={_ => openImageDetail(Shown([|url|], 0))}/>
            | DoubleImage(url0, url1) =>
              <div className=Styles.doubleImageGroup>
                <img src=url0 className=Styles.compactImage onClick={_ => openImageDetail(Shown([|url0|], 0))}/>
                <img src=url1 className=Styles.compactImage onClick={_ => openImageDetail(Shown([|url1|], 1))}/>
              </div>
            | Text(text) => 
              <div className=Styles.textDetail>
                {React.string(text)}
              </div>
            | Carousel(id, imgs, compact) => 
              <ImageCarousel id urls=imgs compact/>
            }
          )
          |> React.array
        }
      </div>

      <div className=Styles.description>
        <h4 className=Styles.descriptionHeader>{React.string("Description")}</h4>

        <div className=Styles.iconBlock>
          <div className=Styles.iconDetail>{ 
            switch(info.team){
            | Some(team) => (<a href={team.href |? ""}><img src=Icons.team/>{React.string(team.title)}</a>)
            | None => (<> </>)
            }
          } </div>
          <div className=Styles.iconDetail>{ 
            switch(info.href){
            | Some(href) => (<a href={href.href |? ""}><img src=Icons.link/>{React.string(href.title)}</a>)
            | None => (<> </>)
            }
          } </div>
          <div className=Styles.iconDetail>
            <img src=Icons.today/>{React.string(info.duration)}
          </div>
        </div>

        <div className=Styles.descriptionDetail>{React.string(info.stackDescription)}</div>

        {
          (Array.length(info.stackComponents) > 0) 
          ? <h4 className=Styles.descriptionHeader>{React.string("Stack")}</h4>
          : (<> </>)
        }

        <div className=Styles.cardList>
          {
            info.stackComponents
            |> Array.map(comp => <div className=Styles.stackCard>{React.string(comp)}</div>)
            |> React.array
          }
        </div>
      </div>

    </div>
  </div>
}