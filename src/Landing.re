open Css;

let octocat = [%bs.raw "require('assets/svgs/octocat_right.svg')"];

module Styles {
  let root = style([
    display(`flex),
    alignItems(`center),
    flexDirection(`column),

    overflowX(Css.Types.Overflow.hidden),
    // overflowY(Css.Types.Overflow.scroll),

    backgroundColor(rgb(33,33,33)),

    fontFamily(`custom(Fonts.jost)),
    color(white)
  ]);

  let innerContent = style([
    display(`flex),
    alignItems(`center),
    flexDirection(`column),
    width(`percent(100.0)),

    Media.exactly(Media.Breakpoint.Tablet, [
      padding2(~v=`zero, ~h=px(16))
    ]),
    Media.atLeast(Media.Breakpoint.Laptop, [
      width(px(900))
    ])
  ]);

  let octocat = style([
    position(`absolute),
    right(`zero)
  ]);
};

[@react.component]
let make = () => {
  let (imageDetail, setImageDetailState) = React.useState(_ => ImageDetail.Hidden);
  
  <ImageDetail.Context value=(imageDetail, state => setImageDetailState(_ => state))>
    <div className=Styles.root>
      <a className=Styles.octocat href="https://github.com/ambientlight/aboutme">
        <img src={octocat}/>
      </a>

      <Header/>
      <Intro/>
      
      <div className=Styles.innerContent>
        <Stacks/>
        <Journey/>
        <Projects/>
        <Awards/>
        <Contributions/>
      </div>
      
      <Footer/>
      <ImageDetail/>
    </div>
  </ImageDetail.Context>
}