open Css;

module Styles {
  let root = style([
    display(`flex),
    flexDirection(`column),
  ]);
};

[@react.component]
let make = () => 
  <>
    <Seperator navId="journey" title="My Journey"/>
    <div className=Styles.root>
      {
        Data.journey
        |> Array.mapi((idx, info) => <PositionInfo key={j|journ$idx|j} info/>)
        |> React.array
      }
    </div>
  </>