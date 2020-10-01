open Css;

module Styles {
  let root = style([
    display(`flex),
    flexDirection(`column)
  ]);
};

let geothings: PositionInfo.jobInfo = {
  companyName: "GeoThings Inc.",
  jobTitle: "Software Architect, Development Lead",
  duration: "since July 2015",
  imgUrl: [%bs.raw "require('assets/imgs/geothings_logo.png')"],
  description: 
    "I have joined GeoThings as our mission with social impact got me really bought in to the idea." ++
    "I started as an iOS developer working on OSM map-oriented application." ++ 
    "I was always willing to help in any way I could and I loved exploring new stacks," ++ 
    "so I quickly became involved in our other areas: map servers, front-end, some android." ++
    "Since fall 2017 my focus was shifted towards full stack development and cloud architecture which would account for most of my development time." ++
    "Second part of 2019 was an exception which I spend building a deep learning pipeline capable of extracting streetlights locations from windshield camera videos." ++
    "As of now (September 2020), I am working on RDF-oriented graph backend on-premise deployment for our B2B customer.
  
    Without overstatement, it has thus far been a roller coaster ride for our team, we've worked hard, pivoted a few times, but it is an incredible experience nonetheless."
};

let sixnology: PositionInfo.jobInfo = {
  companyName: "Sixnology Inc.",
  jobTitle: "iOS Developer",
  duration: "May 2013 - September 2014",
  imgUrl: [%bs.raw "require('assets/imgs/sixnology.png')"],
  description: 
    "Really grateful for the given opportunity at such a young age, " ++ 
    "I've joined in my junior year and was tasked with building a iOS player that would stream audio to a DLNA-compliant speaker we were developing. " ++ 
    "DLNA/UPnP was still pretty much alive at that time and since there was no support for it in iOS, it was really fun to develop. " ++ 
    "I've learned a lot overall, build my iOS background and had some great time."
};

[@react.component]
let make = () => 
  <div className=Styles.root>
    <PositionInfo info=geothings/>
    <PositionInfo info=sixnology/>
  </div>;