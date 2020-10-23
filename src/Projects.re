open Css;

let geobingan0 = [%bs.raw "require('assets/screenshots/geobingan_0.png')"];
let geobingan1 = [%bs.raw "require('assets/screenshots/geobingan_1.png')"];

let geoBingAnWeb: ProjectInfo.projectInfo = {
  title: "GeoBingAn: Web GIS",
  media: [|
    Youtube("https://www.youtube.com/embed/hCDjTz-z9_U"),
    Image(geobingan0),
    Image(geobingan1),
    Text("
      GeoBingAn web platform is used to visualize and analyze location-aware data, which in terms of its humanitarian usecases was oriented towards natural-disasters prevention/relief activities.
      Notable applications include townwatching (field validation), evacuation planning, crisis mapping, shelter management, damage assessment and crisis mapping.
      In addition to those the platform has been used as a swiss army knife to a range of B2B collaborations usually centered around data collection and information coordination."
    )
  |],
  team: Some({ title: "GeoThings Inc.", href: Some("https://geothings.tw/") }),
  href: Some({ title: "geobingan.info", href: Some("https://geobingan.info/")}),
  duration: "Fall 2017 ~",
  stackDescription: "
    Undertook a major redesign and incremental frontend rewrite from angularjs to angular4 at that time. 
    Substantial set of GIS functionality was added on top of mapbox-gl. 
    Apart from increasing our backend api surface area, the stack has been extended to support graphql and its subscription real-time functionality.",
  stackComponents: [|"angular", "rxjs", "redux", "webpack", "mapboxgl", "django", "graphql", "apollo", "postgresql", "postgis"|]
};

[@react.component]
let make = () => 
  <>
    <Seperator title="Projects"/>

    <ProjectInfo info=geoBingAnWeb/>
  </>