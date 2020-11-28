open Css;

module Montserrat {
  let thin = fontFace(
    ~fontFamily="Montserrat",
    ~src=[`url([%bs.raw "require('assets/fonts/Montserrat/Montserrat-Thin.ttf')"])],
    ~fontStyle=normal,
    ~fontWeight=`num(100),
    ()
  );

  let extraLight = fontFace(
    ~fontFamily="Montserrat",
    ~src=[`url([%bs.raw "require('assets/fonts/Montserrat/Montserrat-ExtraLight.ttf')"])],
    ~fontStyle=normal,
    ~fontWeight=`num(200),
    ()
  );

  let light = fontFace(
    ~fontFamily="Montserrat",
    ~src=[`url([%bs.raw "require('assets/fonts/Montserrat/Montserrat-Light.ttf')"])],
    ~fontStyle=normal,
    ~fontWeight=`num(300),
    ()
  );

  let regular = fontFace(
    ~fontFamily="Montserrat",
    ~src=[`url([%bs.raw "require('assets/fonts/Montserrat/Montserrat-Regular.ttf')"])],
    ~fontStyle=normal,
    ~fontWeight=`num(400),
    ()
  );

  let medium = fontFace(
    ~fontFamily="Montserrat",
    ~src=[`url([%bs.raw "require('assets/fonts/Montserrat/Montserrat-Medium.ttf')"])],
    ~fontStyle=normal,
    ~fontWeight=`num(500),
    ()
  );

  let semiBold = fontFace(
    ~fontFamily="Montserrat",
    ~src=[`url([%bs.raw "require('assets/fonts/Montserrat/Montserrat-SemiBold.ttf')"])],
    ~fontStyle=normal,
    ~fontWeight=`num(600),
    ()
  );

  let bold = fontFace(
    ~fontFamily="Montserrat",
    ~src=[`url([%bs.raw "require('assets/fonts/Montserrat/Montserrat-Bold.ttf')"])],
    ~fontStyle=normal,
    ~fontWeight=`num(700),
    ()
  );

  let extraBold = fontFace(
    ~fontFamily="Montserrat",
    ~src=[`url([%bs.raw "require('assets/fonts/Montserrat/Montserrat-ExtraBold.ttf')"])],
    ~fontStyle=normal,
    ~fontWeight=`num(800),
    ()
  );

  let black = fontFace(
    ~fontFamily="Montserrat",
    ~src=[`url([%bs.raw "require('assets/fonts/Montserrat/Montserrat-Black.ttf')"])],
    ~fontStyle=normal,
    ~fontWeight=`num(900),
    ()
  );
};

module Jost {
  let hairline = fontFace(
    ~fontFamily="Jost",
    ~src=[`url([%bs.raw "require('assets/fonts/Jost/Jost-100-Hairline.ttf')"])],
    ~fontStyle=normal,
    ~fontWeight=`num(100),
    ()
  );

  let hairlineItalic = fontFace(
    ~fontFamily="Jost",
    ~src=[`url([%bs.raw "require('assets/fonts/Jost/Jost-100-HairlineItalic.ttf')"])],
    ~fontStyle=italic,
    ~fontWeight=`num(100),
    ()
  );

  let thin = fontFace(
    ~fontFamily="Jost",
    ~src=[`url([%bs.raw "require('assets/fonts/Jost/Jost-200-Thin.ttf')"])],
    ~fontStyle=normal,
    ~fontWeight=`num(200),
    ()
  );

  let thinItalic = fontFace(
    ~fontFamily="Jost",
    ~src=[`url([%bs.raw "require('assets/fonts/Jost/Jost-200-ThinItalic.ttf')"])],
    ~fontStyle=italic,
    ~fontWeight=`num(200),
    ()
  );

  let light = fontFace(
    ~fontFamily="Jost",
    ~src=[`url([%bs.raw "require('assets/fonts/Jost/Jost-300-Light.ttf')"])],
    ~fontStyle=normal,
    ~fontWeight=`num(300),
    ()
  );

  let lightItalic = fontFace(
    ~fontFamily="Jost",
    ~src=[`url([%bs.raw "require('assets/fonts/Jost/Jost-300-LightItalic.ttf')"])],
    ~fontStyle=italic,
    ~fontWeight=`num(300),
    ()
  );

  let book = fontFace(
    ~fontFamily="Jost",
    ~src=[`url([%bs.raw "require('assets/fonts/Jost/Jost-400-Book.ttf')"])],
    ~fontStyle=normal,
    ~fontWeight=`num(400),
    ()
  );

  let bookItalic = fontFace(
    ~fontFamily="Jost",
    ~src=[`url([%bs.raw "require('assets/fonts/Jost/Jost-400-BookItalic.ttf')"])],
    ~fontStyle=italic,
    ~fontWeight=`num(400),
    ()
  );

  let medium = fontFace(
    ~fontFamily="Jost",
    ~src=[`url([%bs.raw "require('assets/fonts/Jost/Jost-500-Medium.ttf')"])],
    ~fontStyle=normal,
    ~fontWeight=`num(500),
    ()
  );

  let mediumItalic = fontFace(
    ~fontFamily="Jost",
    ~src=[`url([%bs.raw "require('assets/fonts/Jost/Jost-500-MediumItalic.ttf')"])],
    ~fontStyle=italic,
    ~fontWeight=`num(500),
    ()
  );

  let semi = fontFace(
    ~fontFamily="Jost",
    ~src=[`url([%bs.raw "require('assets/fonts/Jost/Jost-600-Semi.ttf')"])],
    ~fontStyle=normal,
    ~fontWeight=`num(600),
    ()
  );

  let semiItalic = fontFace(
    ~fontFamily="Jost",
    ~src=[`url([%bs.raw "require('assets/fonts/Jost/Jost-600-SemiItalic.ttf')"])],
    ~fontStyle=italic,
    ~fontWeight=`num(600),
    ()
  );

  let bold = fontFace(
    ~fontFamily="Jost",
    ~src=[`url([%bs.raw "require('assets/fonts/Jost/Jost-700-Bold.ttf')"])],
    ~fontStyle=normal,
    ~fontWeight=`num(700),
    ()
  );

  let boldItalic = fontFace(
    ~fontFamily="Jost",
    ~src=[`url([%bs.raw "require('assets/fonts/Jost/Jost-700-BoldItalic.ttf')"])],
    ~fontStyle=italic,
    ~fontWeight=`num(700),
    ()
  );

  let heavy = fontFace(
    ~fontFamily="Jost",
    ~src=[`url([%bs.raw "require('assets/fonts/Jost/Jost-800-Heavy.ttf')"])],
    ~fontStyle=normal,
    ~fontWeight=`num(800),
    ()
  );

  let heavyItalic = fontFace(
    ~fontFamily="Jost",
    ~src=[`url([%bs.raw "require('assets/fonts/Jost/Jost-800-HeavyItalic.ttf')"])],
    ~fontStyle=italic,
    ~fontWeight=`num(800),
    ()
  );

  let black = fontFace(
    ~fontFamily="Jost",
    ~src=[`url([%bs.raw "require('assets/fonts/Jost/Jost-900-Black.ttf')"])],
    ~fontStyle=normal,
    ~fontWeight=`num(900),
    ()
  );

  let blackItalic = fontFace(
    ~fontFamily="Jost",
    ~src=[`url([%bs.raw "require('assets/fonts/Jost/Jost-900-BlackItalic.ttf')"])],
    ~fontStyle=italic,
    ~fontWeight=`num(900),
    ()
  );
};

let montserrat = Montserrat.regular ++ ", sans-serif";
let jost = Jost.medium ++ ", sans-serif";