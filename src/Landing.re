module Styles {
  open Css;

  let root = style([
    display(`flex),
    alignItems(`center),
    flexDirection(`column),

    overflowX(Css.Types.Overflow.hidden),
    // overflowY(Css.Types.Overflow.scroll),

    backgroundColor(SDefs.backgroundColor),

    fontFamily(`custom(Fonts.jost)),
    color(white)
  ]);

  let innerContent = style([
    display(`flex),
    alignItems(`center),
    flexDirection(`column),
    width(`percent(100.0)),

    Media.exactly(Media.Breakpoint.Tablet, [
      padding2(~v=`zero, ~h=SDefs.primaryPadding)
    ]),
    Media.atLeast(Media.Breakpoint.Laptop, [
      width(SDefs.maxContextWidth)
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
        <img src={Icons.octocatRight}/>
      </a>

      <Header/>
      <Intro/>
      
      <div className=Styles.innerContent>
        // <Stacks/>
        // <Journey/>
        // <Contributions/>
        // <Projects/>
        // <Awards/>
        <Stats/>
      </div>
      
      <Footer/>
      <ImageDetail/>
    </div>
  </ImageDetail.Context>
}