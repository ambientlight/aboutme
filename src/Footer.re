open Css;

module Styles {
  let root = style([
    marginTop(SDefs.footerMarginTop),
    
    // height(`px(69)),
    width(`percent(100.0)),
    borderTop(SDefs.footerBorderWidth, `solid, SDefs.footerBorderColor),

    display(`flex),
    alignItems(center),
    justifyContent(`spaceBetween)
  ])

  let linksBlock = style([
    display(`none),
    marginLeft(SDefs.footerLinksMarginLeft),

    Media.atLeast(Media.Breakpoint.Tablet, [
      display(`initial)
    ])
  ]);

  let footerLink = style([
    color(SDefs.footerLinkColor),
    textDecoration(`none),
    padding(SDefs.footerLinkPadding),

    selector("&:hover, &:visited, &:link, &:active", [
      textDecoration(`none)
    ]),

    selector("&:hover", [
      color(white)
    ])
  ]);

  let footerInfo = style([
    margin4(~left=SDefs.footerInfoLeftPadding, ~top=SDefs.footerInfoVPadding, ~right=SDefs.footerInfoRightPadding, ~bottom=SDefs.footerInfoVPadding),

    fontSize(SDefs.footerInfoFontSize),
    selector("& > a", [
      color(white)
    ])
  ]);

  let attrib = style([
    color(grey), 
    selector("& > a", [
      color(grey)
    ])
  ]);
};

[@react.component]
let make = () => 
  <div className=Styles.root>
    <div className=Styles.linksBlock>
      {
        Data.footerLinks
        |> Array.mapi((idx, (href, title)) => <a key={j|fl$idx|j} className=Styles.footerLink href>{React.string(title)}</a>)
        |> React.array
      }
    </div>

    <div className=Styles.footerInfo>
      // <a href=Data.mailHref>{React.string(Data.fullName)}</a>
      {React.string("made with ")}
      <span style={ReactDOM.Style.make(~color="#e25555", ())}>{React.string({j|❤|j})}</span>
      {React.string(" in reasonml")}
      
      <div className=Styles.attrib>
        // <a href="https://github.com/ambientlight/aboutme">{React.string("source on github")}</a>{React.string(", ")}
        <a href="https://themeforest.net/user/lmpixels">{React.string("LMPixels")}</a>{React.string(" inspired design")}
      </div>
    </div>
  </div>