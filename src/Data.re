let avatar = [%bs.raw "require('assets/imgs/avatar.jpeg')"];
let fullName = "Taras Vozniuk";
let mailHref = "mailto:primary.taras.vozniuk@gmail.com";
let jobTitle = "Software Engineer II, Microsoft";
let companyTitle = "";
let cv = [%bs.raw "require('assets/docs/taras_vozniuk.pdf')"];

let intro = "
  While my recent experience involved working on various map interactions and tooling,
  I am fortunate to have worked in various domains including mobile development, full-stack, cloud architecture, devops as 
  well as deep learning. My free time is largely spend tinkering with experimental stacks.
";

let githubHref = "https://github.com/ambientlight";
let soHref = "https://stackoverflow.com/users/2380455/ambientlight";
let linkedInHref = "https://www.linkedin.com/in/tarasvozniuk/";

let awardsTitle = "Indiehacking";
let contribsTitle = "Contributions";
let journeyTitle = "Journey";
let projectsTitle = "Misc";
let stacksTitle = "Stacks";
let statsTitle = "Stats";

let awards: array(ProjectInfo.projectInfo) = [|
  {
    title: "Winning Batch - NCTU Spring foundation seed fund competition",
    media: [|
      ProjectInfo.Image([%bs.raw "require('assets/screenshots/sf_award.jpg')"])
    |],
    duration: "Fall 2018",
    team: Some({ title: "Ballcast team", href: None }),
    href: None,
    stackDescription:
      "While we've managed to get through entire competition and get into the winning batch, the memories are rather bittersweat. " ++
      "We've tailored our PoC to the competition filling our early prototype with fancy image recognition and deep learning " ++ 
      "giving us good chance to win which felt like validation while it was the opposite. Countless nights and weekends spend coding for more then a year after the competition " ++
      "were absolutely misaligned to what could appeal to our early users and resulted in nothing but the burnout. Lesson learned. ",
    stackComponents: [||]
  },
  {
    title: "Best Potential Team Award - Beyond Future Mobility: MIT Media Lab X NCTU",
    media: [|
      ProjectInfo.Image([%bs.raw "require('assets/screenshots/mit_award.jpg')"])
    |],
    duration: "Summer 2015",
    team: Some({ title: "Ambientlight team", href: None }),
    href: None,
    stackDescription: 
      "Our helium drone and its application have been honored by the MIT Media Lab judges, which allowed us to get 'Best Potential Team' award among 31 teams participating in the workshop. " ++
      "Ultimately, we've failed to turn our prototype into real product, though it was really fun.",
    stackComponents: [||]
  }    
|];

let contribs: array(ContributionInfo.t) = [|
  {
    href: "https://github.com/ReKotlin/ReKotlin",
    title: "ReKotlin",
    description: "
      spent a night to port ReSwift to Kotlin to make a better pitch to our team 
      about redux architecture parity for our iOS and Android app, was nice to see a community fork made with some traction from android folks.
    "
  },
  {
    href: "https://github.com/aws-amplify/amplify-cli/pulls?q=is%3Apr+author%3Aambientlight",
    title: "amplify-cli",
    description: "
      AWS-Amplify (originated from scaphold) brought GQL schema-driven provisioning to AWS which was interesting to explore, yet at that time some key features were missing, so I thought to work on few. 
      Special thanks to AWS Amplify team who were very helpful in the process.
    "
  },
  {
    href: "https://github.com/tilezen/tilequeue/pull/204",
    title: "tilequeue/#204",
    description: "
      we relied on tilezen's tilequeue for generating map tiles and we needed to extend the functionality for removing cached tiles generated while user browses around the map.
    "
  },
  {
    href: "https://github.com/ambientlight/reductive-dev-tools",
    title: "reductive-dev-tools",
    description: "redux-dev-tools integration with reasonml reductive"
  },
  {
    href: "https://github.com/ambientlight/bs-rx",
    title: "bs-rx",
    description: "I rely on rxjs on all platforms and I missed it in reasonml ecosystem. Native currying makes rxjs syntax delightful there."
  },
  {
    href: "https://github.com/ambientlight/reductive-observable",
    title: "reductive-observable",
    description: "rxjs middleware for reductive with additional sugar. "
  },
  {
    href: "https://github.com/ambientlight/amplify-cli-action",
    title: "amplify-cli-action",
    description: "github action to deploy amplify"
  },
  {
    href: "https://github.com/ambientlight/GithubIssuesExtension",
    title: "GithubIssuesExtension",
    description: "tiny handy xcode extension that converts source comments into github issues"
  }
|];

let footerLinks = [|
  (githubHref, "github"),
  (soHref, "stackoverflow"),
  (linkedInHref, "linkedin"),
  (mailHref, "contact")
|];

let journey: array(PositionInfo.jobInfo) = [|
  {
    companyName: "Microsoft, Taiwan",
    jobTitle: "Software Engineer II",
    duration: "since April 2021",
    imgUrl: [%bs.raw "require('assets/imgs/microsoft_logo.png')"],
    href: "https://microsoft.com",
    bgCover: true,
    description:
      "Building various GIS-related tooling as part of incredible team at Microsoft. " ++
      "Curious to see what impact will I make over the long term, but the range of things the one can work on is fascinating."
  },
  {
    companyName: "GeoThings Inc., Taiwan",
    jobTitle: "Software Architect, Development Lead",
    duration: "Sept 2015 - Apr 2021",
    imgUrl: [%bs.raw "require('assets/imgs/geothings_logo.png')"],
    href: "https://geothings.tw/",
    bgCover: true,
    description: 
      "I have joined GeoThings as our mission with social impact got me really bought in to the idea. " ++
      "I started as an iOS developer working on OSM map-oriented application. " ++ 
      "Gradually, I transitioned away from mobile and became involved in other areas: server-side for maps, front-end, as well as machine learning. " ++
      "The last project I was involved in was a scalable distributed data pipeline build for on-premise Kubernetes for processing and collection of large volume of IoT sensor data.  
    
      Without overstatement, it was a roller coaster ride for our team, we've worked hard, pivoted a few times, but it was an incredible experience nonetheless."
  },
  {
    companyName: "Sixnology Inc., Taiwan",
    jobTitle: "iOS Developer",
    duration: "May 2013 - Sept 2014",
    imgUrl: [%bs.raw "require('assets/imgs/sixnology.png')"],
    href: "https://www.sixnology.com/",
    bgCover: true,
    description: 
      "Grateful for the given opportunity at such a young age, " ++ 
      "I've joined in my junior year and was tasked with building a iOS player that would stream audio to a DLNA-compliant speaker we were developing. " ++ 
      "DLNA/UPnP was still pretty much alive at that time and since there was no support for it in iOS, it was really fun to develop. " ++ 
      "I've learned a lot overall, build my iOS background and had some great time."
  },
  {
    companyName: "National Chiao Tung University, Taiwan",
    jobTitle: "BS Computer Science, BS Finance and Information Management",
    duration: "earned in June 2015",
    imgUrl: [%bs.raw "require('assets/imgs/NCTU_emblem.png')"],
    href: "https://www.nctu.edu.tw/",
    bgCover: true,
    description: 
      "Fortunate to come and study in Taiwan, I have to give great credit to NCTU. Before starting my first iOS development job, I spend long nights educating myself about FX and stock trading so I decided to get a double degree. "
  }
|];

let projects: array(ProjectInfo.projectInfo) = [|
  {
    title: "The origin of @ambientlight alias",
    media: [|
      Youtube("https://www.youtube.com/embed/wBriMhGLYWQ"),
      Text("
        @ambientlight alias I often use came from the project I've worked on with my talented friends from NCTU for the beyond future mobile workshop. 
        We've built a couple of flying prototypes that are safe to operate in indoor environment, which basically involved swapping quad-copter with helium airship. 
        We were experimenting by purchasing various small drones, reverse engineering and stripping them apart, and then fitting some of their components to our helium balloons, which was ultimate fun. 
      ")
    |],
    duration: "Summer 2015",
    team: Some({ title: "Team Ambientlight", href: None }),
    href: None,
    stackDescription: "Helium-powered drone(airship) with arduino which communicates with iOS app via bluetooth. IOS app is used as a remote which can also send the accelerometer and bearing data to allow drone to follow the person with the phone.",
    stackComponents: [|"arduino", "ios", "ble4.0"|]
  },
|];

let languages: array(StackCard.info) = [|
  {
    name: "typescript",
    imgUrl: [%bs.raw "require('assets/imgs/typescript_logo.jpg')"],
    href: "https://stackshare.io/typescript"
  },
  {
    name: "javascript",
    imgUrl: [%bs.raw "require('assets/imgs/javascript_logo.jpg')"],
    href: "https://stackshare.io/javascript"
  },
  {
    name: "c#",
    imgUrl: [%bs.raw "require('assets/imgs/csharp_logo.png')"],
    href: "https://stackshare.io/c-sharp"
  },
  {
    name: "reasonml",
    imgUrl: [%bs.raw "require('assets/imgs/reasonml_logo.jpg')"],
    href: "https://stackshare.io/reasonml"
  },
  {
    name: "swift",
    imgUrl: [%bs.raw "require('assets/imgs/swift_logo.png')"],
    href: "https://stackshare.io/swift"
  },
  {
    name: "python",
    imgUrl: [%bs.raw "require('assets/imgs/python_logo.png')"],
    href: "https://stackshare.io/python"
  },
  {
    name: "java",
    imgUrl: [%bs.raw "require('assets/imgs/java_logo.png')"],
    href: "https://stackshare.io/java"
  },
  { 
    name: "kotlin",
    imgUrl: [%bs.raw "require('assets/imgs/kotlin_logo.png')"],
    href: "https://stackshare.io/kotlin"
  },
  // {
  //   name: "ocaml",
  //   imgUrl: [%bs.raw "require('assets/imgs/ocaml_logo.jpg')"],
  //   href: "https://stackshare.io/ocaml"
  // },
  { 
    name: "c++",
    imgUrl: [%bs.raw "require('assets/imgs/cpp_logo.png')"],
    href: "https://stackshare.io/cplusplus"
  },
  {
    name: "objective-c",
    imgUrl: [%bs.raw "require('assets/imgs/objc_logo.png')"],
    href: "https://stackshare.io/objective-c"
  }
|]; 

/*
let stacks: array(StackCard.info) = [|
  { 
    name: "react",
    imgUrl: [%bs.raw "require('assets/imgs/react_logo.png')"],
    href: "https://stackshare.io/react"
  },
  {
    name: "angular",
    imgUrl: [%bs.raw "require('assets/imgs/angular_logo.jpg')"],
    href: "https://stackshare.io/angular"
  },
  {
    name: "react-native",
    imgUrl: [%bs.raw "require('assets/imgs/reactnative_logo.jpg')"],
    href: "https://stackshare.io/react-native"
  },
  {
    name: "electron",
    imgUrl: [%bs.raw "require('assets/imgs/electron_logo.jpg')"],
    href: "https://stackshare.io/electron"
  },
  {
    name: "django",
    imgUrl: [%bs.raw "require('assets/imgs/django_logo.png')"],
    href: "https://stackshare.io/django"
  },
  {
    name: "aws amplify",
    imgUrl: [%bs.raw "require('assets/imgs/awsamplify_logo.png')"],
    href: "https://stackshare.io/aws-amplify"
  },
  {
    name: "serverless",
    imgUrl: [%bs.raw "require('assets/imgs/serverless_logo.png')"],
    href: "https://stackshare.io/serverless"
  },
  {
    name: "aws lambda",
    imgUrl: [%bs.raw "require('assets/imgs/awslambda_logo.png')"],
    href: "https://stackshare.io/aws-lambda"
  },
  {
    name: "cloudformation",
    imgUrl: [%bs.raw "require('assets/imgs/awscloudformation_logo.png')"],
    href: "https://stackshare.io/aws-cloudformation"
  },
  {
    name: "docker",
    imgUrl: [%bs.raw "require('assets/imgs/docker_logo.png')"],
    href: "https://stackshare.io/docker"
  },
  {
    name: "aws ecs",
    imgUrl: [%bs.raw "require('assets/imgs/awsecs_logo.png')"],
    href: "https://stackshare.io/amazon-ec2-container-service"
  },
  {
    name: "kubernetes",
    imgUrl: [%bs.raw "require('assets/imgs/kubernetes_logo.png')"],
    href: "https://stackshare.io/kubernetes"
  },
  {
    name: "postgresql",
    imgUrl: [%bs.raw "require('assets/imgs/postgresql_logo.png')"],
    href: "https://stackshare.io/postgresql"
  },
  {
    name: "dynamodb",
    imgUrl: [%bs.raw "require('assets/imgs/awsdynamodb_logo.png')"],
    href: "https://stackshare.io/amazon-dynamodb"
  },
  {
    name: "sqlite",
    imgUrl: [%bs.raw "require('assets/imgs/sqlite_logo.jpg')"],
    href: "https://stackshare.io/sqlite"
  },
  {
    name: "neo4j",
    imgUrl: [%bs.raw "require('assets/imgs/neo4j_logo.png')"],
    href: "https://stackshare.io/neo4j"
  },
  {
    name: "redis",
    imgUrl: [%bs.raw "require('assets/imgs/redis_logo.png')"],
    href: "https://stackshare.io/redis"
  },
  { 
    name: "realm",
    imgUrl: [%bs.raw "require('assets/imgs/realm_logo.png')"],
    href: "https://stackshare.io/realm"
  },
  {
    name: "redux",
    imgUrl: [%bs.raw "require('assets/imgs/redux_logo.png')"],
    href: "https://stackshare.io/redux"
  },
  {
    name: "rxjs",
    imgUrl: [%bs.raw "require('assets/imgs/rxjs_logo.png')"],
    href: "https://stackshare.io/rxjs"
  },
  {
    name: "graphql",
    imgUrl: [%bs.raw "require('assets/imgs/graphql_logo.png')"],
    href: "https://stackshare.io/graphql"
  },
  {
    name: "logux",
    imgUrl: [%bs.raw "require('assets/svgs/logux_logo.svg')"],
    href: "https://logux.io/"
  },
  {
    name: "pixijs",
    imgUrl: [%bs.raw "require('assets/imgs/pixijs_logo.png')"],
    href: "https://www.pixijs.com/"
  },
  {
    name: "jest",
    imgUrl: [%bs.raw "require('assets/imgs/jest_logo.png')"],
    href: "https://stackshare.io/jest"
  },
  {
    name: "selenium",
    imgUrl: [%bs.raw "require('assets/imgs/selenium_logo.jpg')"],
    href: "https://stackshare.io/selenium"
  },
  {
    name: "webpack",
    imgUrl: [%bs.raw "require('assets/imgs/webpack_logo.png')"],
    href: "https://stackshare.io/webpack"
  },
  {
    name: "fastlane",
    imgUrl: [%bs.raw "require('assets/imgs/fastlane_logo.png')"],
    href: "https://stackshare.io/fastlane"
  },
  {
    name: "bitrise",
    imgUrl: [%bs.raw "require('assets/imgs/bitrise_logo.jpg')"],
    href: "https://stackshare.io/bitrise"
  },
  {
    name: "githubactions",
    imgUrl: [%bs.raw "require('assets/imgs/githubactions_logo.png')"],
    href: "https://stackshare.io/github-actions"
  },
  {
    name: "keras",
    imgUrl: [%bs.raw "require('assets/imgs/keras_logo.png')"],
    href: "https://stackshare.io/keras"
  },
  {
    name: "tensorflow",
    imgUrl: [%bs.raw "require('assets/imgs/tensorflow_logo.png')"],
    href: "https://stackshare.io/tensorflow"
  },
  {
    name: "opencv",
    imgUrl: [%bs.raw "require('assets/imgs/opencv_logo.png')"],
    href: "https://stackshare.io/opencv"
  }
|];
*/