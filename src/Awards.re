let mitAward = [%bs.raw "require('assets/screenshots/mit_award.jpg')"];

let beyondFutureMobility: ProjectInfo.projectInfo = {
  title: "Best Potential Team Award - Beyond Future Mobility: MIT Media Lab X NCTU",
  media: [|
    ProjectInfo.Image(mitAward)
  |],
  duration: "Summer 2015",
  team: Some({ title: "Team Ambientlight", href: None }),
  href: None,
  stackDescription: "Our helium drone and its application have been honored by the MIT Media Lab judges, which allowed us to get 'Best Potential Team' award among 31 teams participating in the workshop.",
  stackComponents: [||]
};

[@react.component]
let make = () => 
  <>
    <Seperator title="Awards"/>
    <ProjectInfo info=beyondFutureMobility/>
  </>;