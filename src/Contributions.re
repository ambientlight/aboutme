open Css;
open Webapi;
open Shortener;

let githubIcon = [%bs.raw "require('assets/svgs/c_github.svg')"];

module ContributionInfo {
  module Styles {
    let root = style([
      marginBottom(px(20))
    ]);


    let link = style([
      display(`flex),
      fontSize(px(18)),
      marginBottom(px(4)),
      
      color(white),

      selector("&:hover, &:visited, &:link, &:active", [
        textDecoration(`underline)
      ]),

      selector("img", [
        margin4(~left=`zero, ~top=px(4), ~right=px(4), ~bottom=px(4)),
        
        width(px(20)),
        height(px(20)),
      ])
    ]);
    
    let description = style([
      color(hex("888"))
    ]);
  }

  type t = {
    href: string,
    title: string,
    description: string
  };

  [@react.component]
  let make = (~info: t) =>
    <div className=Styles.root>
      <a target="_blank" className=Styles.link href={info.href}>
        <img src=githubIcon/>
        {ReasonReact.string(info.title)}
      </a>
      <span className=Styles.description>{ReasonReact.string(info.description)}</span>
    </div>
}

let contribs: array(ContributionInfo.t) = [|
  {
    href: "https://github.com/ReKotlin/ReKotlin",
    title: "ReKotlin",
    description: "
      spent a night to port ReSwift to Kotlin to make a better pitch to our team 
      about redux architecture parity for our iOS and Android app, was nice to see a community fork made with some traction from android folks.
    "
  },
  {
    href: "https://github.com/aws-amplify/amplify-cli/pulls?q=is%3Apr+author%3Aambientlight",
    title: "amplify-cli",
    description: "
      AWS-Amplify (originated from scaphold) brought GQL schema-defined provisioning to AWS which was interesting to explore, yet at that time some key features were missing, so I thought to work on few. 
      Special thanks to AWS Amplify team who were very helpful in the process.
    "
  },
  {
    href: "https://github.com/tilezen/tilequeue/pull/204",
    title: "tilequeue/#204",
    description: "
      we relied on tilezen's tilequeue for generating map tiles and we needed to extend the functionality for removing cached tiles generated while user browses around the map.
    "
  },
  {
    href: "https://github.com/ambientlight/reductive-dev-tools",
    title: "reductive-dev-tools",
    description: "redux-dev-tools integration with reasonml reductive"
  },
  {
    href: "https://github.com/ambientlight/bs-rx",
    title: "bs-rx",
    description: "I rely on rxjs on all platforms and I missed it in reasonml ecosystem. Native currying makes rxjs syntax delightful there."
  },
  {
    href: "https://github.com/ambientlight/reductive-observable",
    title: "reductive-observable",
    description: "rxjs middleware for reductive with additional sugar. "
  },
  {
    href: "https://github.com/ambientlight/amplify-cli-action",
    title: "amplify-cli-action",
    description: "github action to deploy amplify"
  },
  {
    href: "https://github.com/ambientlight/GithubIssuesExtension",
    title: "GithubIssuesExtension",
    description: "tiny handy xcode extension that converts source comments into github issues"
  }
|];

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
        contribs
        |> Array.map(contrib => <ContributionInfo info=contrib/>)
        |> ReasonReact.array
      }
      // {elem}
    </div>
  </>;
}