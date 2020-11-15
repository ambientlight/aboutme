open Css;

module Styles {
  let root = style([
    width(`percent(100.)),
    padding2(~h=px(16), ~v=zero)
  ]);
}

[@react.component]
let make = () => {
  <>
    <Seperator navId="contrib" title="Contributions"/>
    
    <div className=Styles.root>
      {
        Data.contribs
        |> Array.map(contrib => <ContributionInfo info=contrib/>)
        |> React.array
      }
    </div>
  </>;
}