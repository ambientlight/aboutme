open Css;

module Style {
  let root = style([
    display(`flex),
    flexWrap(`wrap),
    alignItems(`center),
  ]);

  // compensate absense of actuaal grid by making sure text and avatar left and right empty space allign
  let introMargin = SDefs.primaryPaddingPx * 2;

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
      width(SDefs.introTextMaxBaseWidth)
    ]),
    Media.atLeast(Media.Breakpoint.Desktop, [
      width(pxFloat(float_of_int(SDefs.introTextMaxBaseWidthPx) *. 1.5))
    ])
  ]);

  let avatar = style([
    flexShrink(0.),

    backgroundColor(white),
    borderRadius(`percent(50.)),
    margin(px(introMargin)),

    border(SDefs.avatarBorderWidth, `solid, SDefs.baseGray),
    backgroundImage(url(Data.avatar)),
    backgroundSize(`contain),

    ...SDefs.avatarSizes,
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
    fontWeight(`semiBold)
  ]);

  let mainInfo = style([
    marginTop(SDefs.introMarginTop),
    fontSize(SDefs.introFontSize),

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
        transform(SDefs.helloLinkHoverTransform)
      ]),
    ]),

    selector("& > a > img", [
      margin(SDefs.helloLinkMargin),
      
      width(SDefs.helloLinkImgSize),
      height(SDefs.helloLinkImgSize),
    ])
  ]);

  let ctaButtonsBlock = style([
    margin2(~v=SDefs.ctaBlockVMargin, ~h=SDefs.ctaBlockHMargin)
  ]);

  let button = style([
    margin4(~top=SDefs.ctaButtonVMargin, ~bottom=SDefs.ctaButtonVMargin, ~right=SDefs.ctaButtonRightMargin, ~left=SDefs.ctaButtonLeftMargin),
    padding2(~v=SDefs.ctaButtonVPadding, ~h=SDefs.ctaButtonHPadding),

    border(SDefs.ctaButtonBorderWidth, `solid, SDefs.selectionGray),
    borderRadius(SDefs.ctaButtonBorderRadius),
    background(SDefs.buttonBgGray),
    
    fontSize(SDefs.ctaButtonFontSize),
    fontFamily(`custom(Fonts.jost)),
    cursor(`pointer),
    color(white),

    selector("&:hover, &:visited, &:link, &:active", [
      textDecoration(`none)
    ]),

    selector("&:focus", [
      outline(`zero, `none, `currentColor)
    ]),

    selector("&:active", [
      color(SDefs.selectionGray)
    ])
  ]);

  let ctaButton = merge([
    button,
    style([
      borderColor(SDefs.primaryColor),

      selector("&:hover", [
        backgroundColor(SDefs.primaryColor)
      ])
    ])
  ])

  let ctaButton2 = merge([
    button,
    style([
      selector("&:hover", [
        backgroundColor(SDefs.selectionGray),
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
        <button className=Style.ctaButton onClick=(_ev => { Webapi.Dom.window |> Webapi.Dom.Window.print})>{React.string("Download CV")}</button>
        <a className=Style.ctaButton2 href=Data.mailHref>{React.string("Get In Touch")}</a>
      </div>
    </div>
    <div className=Style.flex1/>
  </div>