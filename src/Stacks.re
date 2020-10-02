open Css;

module Styles {
  let root = style([
    display(`flex),
    flexWrap(`wrap),
    width(`percent(100.)),
    justifyContent(`center)
  ]);
};

module StackCard {
  type info = {
    name: string,
    imgUrl: string
  };

  module Styles {
    let card = style([
      display(`flex),
      flexDirection(`column),
      alignItems(`center),

      width(px(160)),
      margin(px(8)),

      backgroundColor(Css.Types.Color.hex("333")),
      border(px(2), `solid, hex("444")),
      borderRadius(px(10)),

      fontWeight(`medium),
      padding(px(16)),

      selector("&:hover", [
        transform(translateY(px(-4)))
      ])
    ]);

    let cardImg = style([
      width(px(64)),
      height(px(64)),
      borderRadius(px(8)),
      marginBottom(px(8))
    ]);

    let cardCompact = merge([
      card,
      style([
        width(px(96)),
        margin(px(4)),
        padding(px(8)),
        fontSize(px(14))
      ])
    ])

    let cardImgCompact = merge([
      cardImg,
      style([
        width(px(32)),
        height(px(32)),
        borderRadius(px(8)),
        marginBottom(px(4))
      ])
    ])
  };

  [@react.component]
  let make = (~info: info, ~isCompact: bool=false) => 
    <div className={isCompact ? Styles.cardCompact : Styles.card}>
      <img className={isCompact ? Styles.cardImgCompact : Styles.cardImg} src=info.imgUrl/>
      {React.string(info.name)}
    </div>;
};

let pythonLogo = [%bs.raw "require('assets/imgs/python_logo.png')"];

let languages: array(StackCard.info) = [|
  {
    name: "typescript",
    imgUrl: [%bs.raw "require('assets/imgs/typescript_logo.jpg')"]
  },
  {
    name: "javascript",
    imgUrl: [%bs.raw "require('assets/imgs/javascript_logo.jpg')"]
  },
  {
    name: "reasonml(rescript)",
    imgUrl: [%bs.raw "require('assets/imgs/reasonml_logo.jpg')"]
  },
  {
    name: "python",
    imgUrl: [%bs.raw "require('assets/imgs/python_logo.png')"]
  },
  {
    name: "swift",
    imgUrl: [%bs.raw "require('assets/imgs/swift_logo.png')"]
  },
  {
    name: "java",
    imgUrl: [%bs.raw "require('assets/imgs/java_logo.png')"]
  },
  { 
    name: "kotlin",
    imgUrl: [%bs.raw "require('assets/imgs/kotlin_logo.png')"]
  },
  {
    name: "ocaml",
    imgUrl: [%bs.raw "require('assets/imgs/ocaml_logo.jpg')"]
  },
  {
    name: "objective-c",
    imgUrl: [%bs.raw "require('assets/imgs/objc_logo.png')"]
  },
  { 
    name: "c/c++",
    imgUrl: [%bs.raw "require('assets/imgs/cpp_logo.png')"]
  }
|]; 

let stacks: array(StackCard.info) = [|
  { 
    name: "react",
    imgUrl: [%bs.raw "require('assets/imgs/react_logo.png')"]
  },
  {
    name: "angular",
    imgUrl: [%bs.raw "require('assets/imgs/angular_logo.jpg')"]
  },
  {
    name: "react-native",
    imgUrl: [%bs.raw "require('assets/imgs/reactnative_logo.jpg')"]
  },
  {
    name: "django",
    imgUrl: [%bs.raw "require('assets/imgs/django_logo.png')"]
  },
  {
    name: "aws amplify",
    imgUrl: [%bs.raw "require('assets/imgs/awsamplify_logo.png')"]
  },
  {
    name: "serverless",
    imgUrl: [%bs.raw "require('assets/imgs/serverless_logo.png')"]
  },
  {
    name: "aws lambda",
    imgUrl: [%bs.raw "require('assets/imgs/awslambda_logo.png')"]
  },
  {
    name: "cloudformation",
    imgUrl: [%bs.raw "require('assets/imgs/awscloudformation_logo.png')"]
  },
  {
    name: "docker",
    imgUrl: [%bs.raw "require('assets/imgs/docker_logo.png')"]
  },
  {
    name: "aws ecs",
    imgUrl: [%bs.raw "require('assets/imgs/awsecs_logo.png')"]
  },
  /*
  {
    name: "kubernetes",
    imgUrl: [%bs.raw "require('assets/imgs/kubernetes_logo.png')"]
  },
  */
  {
    name: "apache",
    imgUrl: [%bs.raw "require('assets/imgs/apache_logo.jpg')"]
  },
  {
    name: "postgresql",
    imgUrl: [%bs.raw "require('assets/imgs/postgresql_logo.png')"]
  },
  {
    name: "dynamodb",
    imgUrl: [%bs.raw "require('assets/imgs/awsdynamodb_logo.png')"]
  },
  {
    name: "sqlite",
    imgUrl: [%bs.raw "require('assets/imgs/sqlite_logo.jpg')"]
  },
  {
    name: "neo4j",
    imgUrl: [%bs.raw "require('assets/imgs/neo4j_logo.png')"]
  },
  {
    name: "redis",
    imgUrl: [%bs.raw "require('assets/imgs/redis_logo.png')"]
  },
  { 
    name: "realm",
    imgUrl: [%bs.raw "require('assets/imgs/realm_logo.png')"]
  },
  {
    name: "redux",
    imgUrl: [%bs.raw "require('assets/imgs/redux_logo.png')"]
  },
  {
    name: "rxjs",
    imgUrl: [%bs.raw "require('assets/imgs/rxjs_logo.png')"]
  },
  {
    name: "graphql",
    imgUrl: [%bs.raw "require('assets/imgs/graphql_logo.png')"]
  },
  {
    name: "logux",
    imgUrl: [%bs.raw "require('assets/svgs/logux_logo.svg')"]
  },
  {
    name: "pixijs",
    imgUrl: [%bs.raw "require('assets/imgs/pixijs_logo.png')"]
  },
  {
    name: "jest",
    imgUrl: [%bs.raw "require('assets/imgs/jest_logo.png')"]
  },
  {
    name: "selenium",
    imgUrl: [%bs.raw "require('assets/imgs/selenium_logo.jpg')"]
  },
  /*
  {
    name: "threejs",
    imgUrl: [%bs.raw "require('assets/imgs/threejs_logo.jpg')"]
  },
  */
  {
    name: "mapboxgl",
    imgUrl: [%bs.raw "require('assets/imgs/mapboxgl_logo.png')"]
  },
  {
    name: "webpack",
    imgUrl: [%bs.raw "require('assets/imgs/webpack_logo.png')"]
  },
  {
    name: "fastlane",
    imgUrl: [%bs.raw "require('assets/imgs/fastlane_logo.png')"]
  },
  {
    name: "bitrise",
    imgUrl: [%bs.raw "require('assets/imgs/bitrise_logo.jpg')"]
  },
  {
    name: "githubactions",
    imgUrl: [%bs.raw "require('assets/imgs/githubactions_logo.png')"]
  },
  {
    name: "keras",
    imgUrl: [%bs.raw "require('assets/imgs/keras_logo.png')"]
  },
  {
    name: "tensorflow",
    imgUrl: [%bs.raw "require('assets/imgs/tensorflow_logo.png')"]
  }
|];

// apache
// jest
// selenium-web-driver


[@react.component]
let make = () => 
  <>
    <Seperator title="Languages"/>
    <div className=Styles.root>
    {
      languages
      |> Array.map(lang => <StackCard info=lang isCompact=false/>)
      |> ReasonReact.array
    }
    </div>
    <Seperator title="Stacks"/>
    <div className=Styles.root>
    {
      stacks
      |> Array.map(lang => <StackCard info=lang isCompact=true/>)
      |> ReasonReact.array
    }
    </div>
  </>