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
    backgroundColor(white),
    width(px(320)),
    height(px(320)),
    borderRadius(`percent(50.)),

    border(px(16), `solid, rgb(65, 65, 65)),
    backgroundImage(url([%bs.raw "require('assets/imgs/avatar.png')"])),
    backgroundSize(`contain)
  ]);

  let jobTitle = style([
    color(grey)
  ])
};

[@react.component]
let make = () => 
  <div className=Style.root>
    <div className=Style.avatar></div>
    <div>
      <h4 className=Style.jobTitle>
        {ReasonReact.string("Software Architect, Tech Lead")}
        <br/>
        {ReasonReact.string("GeoThings Inc, Taiwan")}
      </h4>
      <h1>{ReasonReact.string("Hey, I'm Taras Vozniuk")}</h1>
      <section>
        {ReasonReact.string("
          I am very lucky.
        ")}
      </section>
    </div>
  </div>