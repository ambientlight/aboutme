open Css;

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

let geobingan0 = [%bs.raw "require('assets/screenshots/geobingan_0.png')"];
let geobingan1 = [%bs.raw "require('assets/screenshots/geobingan_1.png')"];

let teamIcon = [%bs.raw "require('assets/svgs/people_alt-white.svg')"];
let linkIcon = [%bs.raw "require('assets/svgs/link-white.svg')"];
let todayIcon = [%bs.raw "require('assets/svgs/today-white.svg')"];

[@react.component]
let make = () => 
  <>
    <Seperator title="Projects"/>

    <div className=Styles.root>
      <h2 className=Styles.projectTitle>{React.string("GeoBingAn: Web GIS ")}</h2>

      <div className=Styles.flexRow>
        <div className=Styles.detail>
          <div dangerouslySetInnerHTML={ 
            "__html": "<iframe width=\"100%\" height=\"280px\" className=Styles.smt src=\"https://www.youtube.com/embed/hCDjTz-z9_U\" frameborder=\"0\" allow=\"accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture\" allowfullscreen></iframe>" 
          }></div>
          
          <img src=geobingan0/>
          <img src=geobingan1/>

          <div className=Styles.textDetail>
            {React.string("
              GeoBingAn web platform is used to visualize and analyze location-aware data, which in terms of its humanitarian usecases was oriented towards natural-disasters prevention/relief activities.
              Notable applications include townwatching (field validation), evacuation planning, crisis mapping, shelter management, damage assessment and crisis mapping.
              In addition to those the platform has been used as a swiss army knife to a range of B2B collaborations usually centered around data collection and information coordination.
              "
            )}
          </div>
        </div>

        <div className=Styles.description>
          <h4 className=Styles.descriptionHeader>{React.string("Description")}</h4>

          <div className=Styles.iconBlock>
            <div className=Styles.iconDetail>
              <img src=teamIcon/>{React.string("GeoThings Inc.")}
            </div>
            <div className=Styles.iconDetail>
              <img src=linkIcon/>{React.string("geobingan.info")}
            </div>
            <div className=Styles.iconDetail>
              <img src=todayIcon/>{React.string("Fall 2017 ~")}
            </div>
          </div>

          <div className=Styles.descriptionDetail>
            {React.string("With my switch to full stack role, I inherited the project and undertook a major redesign and incremental frontend rewrite from angularjs to angular4 at that time. 
            Substantial set of GIS functionality was added on top of mapbox-gl.")}
          </div>

          <h4 className=Styles.descriptionHeader>{React.string("Stack")}</h4>
          <div className=Styles.cardList>
            <div className=Styles.stackCard>{React.string("angular")}</div>
            <div className=Styles.stackCard>{React.string("rxjs")}</div>
            <div className=Styles.stackCard>{React.string("redux")}</div>
            <div className=Styles.stackCard>{React.string("webpack")}</div>
            <div className=Styles.stackCard>{React.string("mapboxgl")}</div>
            <div className=Styles.stackCard>{React.string("django")}</div>
            <div className=Styles.stackCard>{React.string("postgresql")}</div>
            <div className=Styles.stackCard>{React.string("postgis")}</div>
          </div>
        </div>
      </div>

    </div>
  </>