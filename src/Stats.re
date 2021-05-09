module Styles {
  open Css;

  let statsGroup = style([
    display(`flex),
    flexDirection(`column),

    Media.atLeast(Media.Breakpoint.Tablet, [
      flexDirection(`row),
    ]),

    selector("& > *", [
      padding(px(8))
    ])
  ])
}

[@react.component]
let make = () => 
  <>
    <Seperator navId="stats" title=Data.statsTitle/>
    <div className=Styles.statsGroup>
      <div dangerouslySetInnerHTML={ 
        "__html": "<codersrank-summary username=\"ambientlight\"></codersrank-summary>" 
      }></div>
      <div dangerouslySetInnerHTML={ 
        "__html": "<codersrank-skills-chart username=\"ambientlight\" skills=\"Swift,Python,TypeScript,Objective-C,JavaScript,C#,Reason,Java,Kotlin,C++\" legend=\"\" labels=\"\" tooltip=\"\" show-other-skills=\"\"></codersrank-skills-chart>" 
      }></div>
    </div>
  </>