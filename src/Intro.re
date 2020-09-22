open Css;

module Style {
  let root = style([
    display(`flex),
    alignItems(`center),

    selector("& > *", [
      margin(px(20))
    ])
  ]);

  let avatar = style([
    flexShrink(0.),

    backgroundColor(white),
    width(px(320)),
    height(px(320)),
    borderRadius(`percent(50.)),

    border(px(16), `solid, rgb(65, 65, 65)),
    backgroundImage(url([%bs.raw "require('assets/imgs/avatar.png')"])),
    backgroundSize(`contain)
  ]);

  let jobTitle = style([
    color(grey),
    fontWeight(`semiBold)
  ])
};

[@react.component]
let make = () => 
  <div className=Style.root>
    <div className=Style.avatar></div>
    <div>
      <h4 className=Style.jobTitle>
        {ReasonReact.string("Software Architect, Development Lead")}
        <br/>
        {ReasonReact.string("GeoThings Inc, Taiwan")}
      </h4>
      <h1>{ReasonReact.string("Hey, I'm Taras Vozniuk")}</h1>
      <section>
        {ReasonReact.string("
          Extremely fortunate as my work has been greatly cross-functional.
          After starting as an iOS Developer, I have been involved in full-stack development, deveops, cloud architecture and deep-learning.
          I lead development at GeoThings Inc, in my spare time I love experimenting with various stacks, with ReasonML being my  
        ")}
      </section>
    </div>
  </div>