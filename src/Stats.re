module Styles {
  open Css;

  let statsGroup = style([
    display(`flex),
    flexDirection(`column),

    Media.atLeast(Media.Breakpoint.Tablet, [
      flexDirection(`row),
    ]),

    selector("& > *", [
      padding(px(8)),
      margin(px(4))
    ])
  ])

  let embedBase = style([
    backgroundColor(SDefs.buttonBgGray),
    border(px(2), `solid, SDefs.baseGray)
  ])

  let chartEffects = style([
    unsafe("filter", "grayscale(0.5)")
  ])
}

[@react.component]
let make = () => 
  <>
    <Seperator navId="stats" title=Data.statsTitle/>
    <div className=Styles.statsGroup>
      <div className=Styles.embedBase dangerouslySetInnerHTML={ 
        "__html": "<codersrank-summary style=\"--header-bg-color: #333; --badge-bg-color: #999; --bg-color: #333; --border-radius: 0px;\" username=\"ambientlight\"></codersrank-summary>" 
      }></div>
      <div className={Css.merge([Styles.embedBase, Styles.chartEffects])} dangerouslySetInnerHTML={ 
        "__html": "<codersrank-skills-chart username=\"ambientlight\" skills=\"Swift,Python,TypeScript,Objective-C,JavaScript,C#,Reason,Java,Kotlin,C++\" legend=\"\" labels=\"\" tooltip=\"\" show-other-skills=\"\"></codersrank-skills-chart>" 
      }></div>
    </div>
    // <div className=Styles.statsGroup>
    //   <div className=Styles.embedBase dangerouslySetInnerHTML={ 
    //     "__html": "<codersrank-timeline type=\"technologies\" username=\"ambientlight\"></codersrank-timeline>" 
    //   }></div>
    // </div>
  </>