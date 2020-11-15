open Css;

[@react.component]
let make = () => 
  <>
    <Seperator navId="proj" title=Data.projectsTitle/>
    {
      Data.projects
      |> Array.mapi((idx, info) => <ProjectInfo key={j|proj$idx|j} info/>)
      |> React.array
    }
  </>