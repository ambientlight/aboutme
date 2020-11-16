open Css;

module Styles {
  let root = style([
    display(`flex),
    flexWrap(`wrap),
    width(`percent(100.)),
    justifyContent(`center)
  ]);
};

[@react.component]
let make = () => 
  <>
    <Seperator navId="lang" title="Languages"/>
    <div className=Styles.root>
    {
      Data.languages
      |> Array.map(lang => <StackCard info=lang isCompact=false/>)
      |> React.array
    }
    </div>
    <Seperator navId="stacks" title="Stacks"/>
    <div className=Styles.root>
    {
      Data.stacks
      |> Array.map(lang => <StackCard info=lang isCompact=true/>)
      |> React.array
    }
    </div>
  </>