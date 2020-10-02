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
  ]);

  let mainInfo = style([
    fontSize(px(15))
  ]);

  /*
  let moveInBottom = keyframes([
    (0, [opacity(0.), transform(translateY(px(10)))]),
    (100, [opacity(1.), transform(translate(`zero, `zero))])
  ])
  */

  let helloBlock = style([
    display(`flex),
    alignItems(`center),

    selector("& > h1", [
      marginRight(px(16))
    ]),

    selector("& > a", [
      display(`flex),
      alignItems(`center),

      //animation(moveInBottom, ~duration=500, ~timingFunction=Types.TimingFunction.easeOut, ~delay=750),
      
      selector("&:hover", [
        transform(translateY(px(-3)))
      ])
    ]),

    selector("& > a > img", [
      margin(px(2)),
      
      width(px(30)),
      height(px(30)),
    ])
  ]);

  let ctaButtonsBlock = style([
    margin2(~v=px(20), ~h=px(0))
  ]);

  let button = style([
    margin(px(8)),
    padding2(~v=px(9), ~h=px(26)),
    border(px(2), `solid, grey),
    borderRadius(px(20)),
    background(`none),

    fontSize(px(15)),
    fontFamily(`custom(Fonts.jost)),
    cursor(`pointer),
    color(white),

    selector("&:focus", [
      outline(`zero, `none, `currentColor)
    ]),

    selector("&:active", [
      color(darkgrey)
    ])
  ]);

  let ctaButton = merge([
    button,
    style([
      borderColor(blue),

      selector("&:hover", [
        backgroundColor(blue)
      ])
    ])
  ])

  let ctaButton2 = merge([
    button,
    style([
      selector("&:hover", [
        backgroundColor(grey),
        color(black)
      ])
    ])
  ])
};

let githubIcon = [%bs.raw "require('assets/svgs/c_github.svg')"];
let stackOverflowIcon = [%bs.raw "require('assets/svgs/c_stackoverflow.svg')"];
let linkedInIcon = [%bs.raw "require('assets/svgs/c_linkedin.svg')"];

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
      <div className=Style.helloBlock>
        <h1>{ReasonReact.string("Hey, I'm Taras Vozniuk")}</h1>
        <a href="https://github.com/ambientlight"><img src=githubIcon/></a>
        <a href="https://stackoverflow.com/users/2380455/ambientlight"><img src=stackOverflowIcon/></a>
        <a href="https://www.linkedin.com/in/tarasvozniuk/"><img src=linkedInIcon/></a>
      </div>
      <section className=Style.mainInfo>
        {ReasonReact.string("
          My work has been greatly cross-functional up to this point.
          After starting as an iOS Developer, I have been involved in full-stack development, cloud architecture, deep-learning among other things. 
          I lead development at GeoThings Inc. My open-source contribution is primarily centered around redux and ReasonML(ReScript) ecosystem. 
        ")}
      </section>
      <div className=Style.ctaButtonsBlock>
        <button className=Style.ctaButton>{ReasonReact.string("Download CV")}</button>
        <button className=Style.ctaButton2>{ReasonReact.string("Get In Touch")}</button>
      </div>
    </div>
  </div>