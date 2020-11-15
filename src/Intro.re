open Css;

module Style {
  let root = style([
    display(`flex),
    flexWrap(`wrap),
    alignItems(`center),
  ]);

  // compensate absense of design grid by making sure text and avatar left and right empty space allign
  let introMargin = 32

  let textInfo = style([
    display(`flex),
    flexDirection(`column),
    justifyContent(`center),
    
    Media.atMost(Media.Breakpoint.Phone, [
      width(`percent(100.)),
      alignItems(`center),
      // padding2(~v=`zero, ~h=px(introMargin * 2))
    ]),
    Media.atLeast(Media.Breakpoint.Tablet, [
      width(`percent(50.0)),
      paddingRight(px(introMargin))
    ]),
    Media.atLeast(Media.Breakpoint.Laptop, [
      width(px(400))
    ]),
    Media.atLeast(Media.Breakpoint.Desktop, [
      width(px(600))
    ])
  ]);

  let avatar = style([
    flexShrink(0.),

    backgroundColor(white),
    borderRadius(`percent(50.)),
    margin(px(introMargin)),

    border(px(16), `solid, rgb(65, 65, 65)),
    backgroundImage(url(Data.avatar)),
    backgroundSize(`contain),

    ...Media.define(
      ~smallPhone=[width(px(200)), height(px(200))],
      ~phone=[width(px(250)), height(px(250))],
      ~tablet=[width(px(300)), height(px(300))],
      ~default=[width(px(400)), height(px(400))],
      ()
    ),
  ]);

  let avatarWrap = style([
    display(`flex),
    alignItems(`center),
    justifyContent(`center),

    Media.atMost(Media.Breakpoint.Phone, [
      width(`percent(100.))
    ])
  ]);

  let jobTitle = style([
    color(grey),
    fontWeight(`semiBold),
    // marginBottom(px(8))
  ]);

  let mainInfo = style([
    marginTop(px(16)),
    fontSize(px(16)),

    Media.atMost(Media.Breakpoint.Phone, [
      padding2(~v=`zero, ~h=px(introMargin))
    ])
  ]);

  let flex1 = style([
    flex(`num(1.))
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
      marginTop(px(0)),
      marginBottom(px(0)),
      marginRight(px(16)),

      Media.atMost(Media.Breakpoint.SmallPhone, [
        fontSize(px(20))
      ])
    ]),

    selector("& > a", [
      display(`flex),
      alignItems(`center),

      //animation(moveInBottom, ~duration=500, ~timingFunction=Types.TimingFunction.easeOut, ~delay=750),
      
      selector("&:hover", [
        transform(translateY(px(-3)))
      ]),
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
    margin4(~top=px(8), ~bottom=px(8), ~right=px(16), ~left=`zero),
    padding2(~v=px(9), ~h=px(26)),
    border(px(3), `solid, grey),
    borderRadius(px(20)),
    background(rgb(51, 51, 51)),
    
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
  ]);
};

[@react.component]
let make = () => 
  <div className=Style.root>
    <div className=Style.flex1/>
    <div className=Style.avatarWrap>
      <div className=Style.avatar></div>
    </div>
    <div className=Style.textInfo>
      <h4 className=Style.jobTitle>
        {React.string(Data.jobTitle)}
        <br/>
        {React.string(Data.companyTitle)}
      </h4>
      <div className=Style.helloBlock>
        <h1>{React.string(Data.fullName)}</h1>
        <a href=Data.githubHref><img src=Icons.cGithub/></a>
        <a href=Data.soHref><img src=Icons.cStackOverflow/></a>
        <a href=Data.linkedInHref><img src=Icons.cLinkedIn/></a>
      </div>
      <section className=Style.mainInfo>
        {React.string(Data.intro)}
      </section>
      <div className=Style.ctaButtonsBlock>
        <button className=Style.ctaButton>{React.string("Download CV")}</button>
        <button className=Style.ctaButton2>{React.string("Get In Touch")}</button>
      </div>
    </div>
    <div className=Style.flex1/>
  </div>