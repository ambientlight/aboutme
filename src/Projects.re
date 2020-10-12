open Css;

module Styles {
  let root = style([
    width(`percent(100.)),
    paddingLeft(px(54))
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
    display(`flex)

  ]);

  let detail = style([
    display(`flex),
    flexDirection(`column),

    selector("& > *", [
      width(px(500)),
      height(px(280)),

      marginBottom(px(16))
    ])
  ]);

  let description = style([
    backgroundColor(hex("333")),
    border(px(2), `solid, hex("444")),
    borderRadius(px(10)),

    width(px(180)),
    margin2(~v=`zero, ~h=px(24)),

    padding(px(24)),
    width(`percent(100.)),
    height(`percent(100.))
  ]);
};

let geobingan0 = [%bs.raw "require('assets/screenshots/geobingan_0.png')"];
let geobingan1 = [%bs.raw "require('assets/screenshots/geobingan_1.png')"];

[@react.component]
let make = () => 
  <>
    <Seperator title="Projects"/>

    <div className=Styles.root>
      <h2 className=Styles.projectTitle>{React.string("GeoBingAn: Web GIS ")}</h2>

      <div className=Styles.flexRow>
        <div className=Styles.detail>
          <div dangerouslySetInnerHTML={ 
            "__html": "<iframe width=\"100%\" height=\"100%\" className=Styles.smt src=\"https://www.youtube.com/embed/hCDjTz-z9_U\" frameborder=\"0\" allow=\"accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture\" allowfullscreen></iframe>" 
          }></div>
          
          <img src=geobingan0/>
          <img src=geobingan1/>
        </div>

        <div className=Styles.description>
          {React.string("Description")}


        </div>
      </div>

    </div>
  </>