[@react.component]
let make = () => 
  <>
    <Seperator navId="awards" title=Data.awardsTitle/>
    {
      Data.awards 
      |> Array.mapi((idx, info) => <ProjectInfo key={"award" ++ string_of_int(idx)} info/>)
      |> React.array
    }
  </>;