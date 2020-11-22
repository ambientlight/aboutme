let avatar = [%bs.raw "require('assets/imgs/avatar.png')"];
let fullName = "Taras Vozniuk";
let mailHref = "mailto:primary.taras.vozniuk@gmail.com";
let jobTitle = "Software Architect, Development Lead";
let companyTitle = "GeoThings Inc, Taiwan";

let intro = "
  My work has been greatly cross-functional up to this point.
  After starting as an iOS Developer, I have been involved in full-stack development, cloud architecture, deep-learning among other things. 
  I am a lead developer at GeoThings Inc. My open-source contribution is primarily centered around redux and ReasonML(ReScript) ecosystem. 
";

let githubHref = "https://github.com/ambientlight";
let soHref = "https://stackoverflow.com/users/2380455/ambientlight";
let linkedInHref = "https://www.linkedin.com/in/tarasvozniuk/";

let awardsTitle = "Awards";
let contribsTitle = "Contributions";
let journeyTitle = "Journey";
let projectsTitle = "Projects";
let stacksTitle = "Stacks";

let awards: array(ProjectInfo.projectInfo) = [|
  {
    title: "Best Potential Team Award - Beyond Future Mobility: MIT Media Lab X NCTU",
    media: [|
      ProjectInfo.Image([%bs.raw "require('assets/screenshots/mit_award.jpg')"])
    |],
    duration: "Summer 2015",
    team: Some({ title: "Team Ambientlight", href: None }),
    href: None,
    stackDescription: "Our helium drone and its application have been honored by the MIT Media Lab judges, which allowed us to get 'Best Potential Team' award among 31 teams participating in the workshop.",
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
      AWS-Amplify (originated from scaphold) brought GQL schema-defined provisioning to AWS which was interesting to explore, yet at that time some key features were missing, so I thought to work on few. 
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
    companyName: "GeoThings Inc., Taiwan",
    jobTitle: "Software Architect, Development Lead",
    duration: "since July 2015",
    imgUrl: [%bs.raw "require('assets/imgs/geothings_logo.png')"],
    href: "https://geothings.tw/",
    description: 
      "I have joined GeoThings as our mission with social impact got me really bought in to the idea. " ++
      "I started as an iOS developer working on OSM map-oriented application. " ++ 
      "I was always willing to help in any way I could and I loved exploring new stacks, " ++ 
      "so I quickly became involved in our other areas: map servers, front-end, some android. " ++
      "Since fall 2017 my focus was shifted towards full stack development and cloud architecture which would account for most of my development time. " ++
      "Second part of 2019 was an exception which I spend building a deep learning pipeline capable of extracting streetlights locations from windshield camera videos. " ++
      "Most recently I am involved in building a scalable distributed data pipeline on Kubernetes for processing Civil IoT Taiwan data.  
    
      Without overstatement, it has thus far been a roller coaster ride for our team, we've worked hard, pivoted a few times, but it is an incredible experience nonetheless."
  },
  {
    companyName: "Sixnology Inc., Taiwan",
    jobTitle: "iOS Developer",
    duration: "May 2013 - September 2014",
    imgUrl: [%bs.raw "require('assets/imgs/sixnology.png')"],
    href: "https://www.sixnology.com/",
    description: 
      "Really grateful for the given opportunity at such a young age, " ++ 
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
    description: 
      "Fortunate to come and study in Taiwan, I have to give great credit to NCTU for who I am now. Development career was my ultimate goal, but as I was also curious to explore stock trading, I decided to get a double degree. "
  }
|];

let projects: array(ProjectInfo.projectInfo) = [|
  {
    title: "GeoBingAn: Web GIS",
    media: [|
      Youtube("https://www.youtube.com/embed/hCDjTz-z9_U"),
      Carousel("geobingan", [|
        [%bs.raw "require('assets/screenshots/geobingan_0.png')"], 
        [%bs.raw "require('assets/screenshots/geobingan_1.png')"], 
        [%bs.raw "require('assets/screenshots/geobingan_2.png')"]
      |], false),
      Text("
        GeoBingAn web platform is used to visualize and analyze location-aware data, which in terms of its humanitarian usecases was oriented towards natural-disasters prevention/relief activities.
        Notable applications include townwatching (field validation), evacuation planning, crisis mapping, shelter management, damage assessment and crisis mapping.
        In addition to those the platform has been used as a swiss army knife to a range of B2B collaborations usually centered around data collection and information coordination."
      )
    |],
    team: Some({ title: "GeoThings Inc.", href: Some("https://geothings.tw/") }),
    href: Some({ title: "geobingan.info", href: Some("https://geobingan.info/")}),
    duration: "Fall 2017 ~",
    stackDescription: "
      Redesigned and performed incremental rewrite from angularjs to angular4 at that time. 
      Substantial set of GIS functionality was added on top of mapbox-gl. 
      Apart from increasing our backend api surface area, the stack has been extended to support graphql and its subscription real-time functionality.",
    stackComponents: [|"angular", "rxjs", "redux", "webpack", "mapboxgl", "django", "graphql", "apollo", "postgresql", "postgis"|]
  },

  {
    title: "ML Streetlight Survey Extraction Pipeline",
    media: [|
      Youtube("https://youtube.com/embed/8dWihq0Ix6Q"),
      Image([%bs.raw "require('assets/screenshots/depth.png')"]),
      Image([%bs.raw "require('assets/screenshots/ml_spot_pipeline.png')"]),
      Text("
        We needed to perform region-wide roadside surveys. 
        To collect data on such scale, machine learning pipeline has been developed to extract streelights with types and coordinates from windshield camera videos.
        The integration with our platform features automatic object extraction for garmin/gopro video uploads, with map flythrough playback build to analyze the results. 
        The pipeline was used to collect the data from 3 countries to inspect the state of roadside lighting infrastructure. 
      ")
    |],
    team: Some({ title: "GeoThings Inc.", href: Some("https://geothings.tw/") }),
    href: Some({ title: "geobingan.info", href: Some("https://geobingan.info/")}),
    duration: "March 2019 - October 2019",
    stackDescription: "
      Pipeline features recognition performed by yoloV3 powered by its original darknet. 
      Object tracking is done via deep-sort algorithm.
      Each task relies on a chain of two AWS Spot instances: G4dn is used to perform the detection and c5d to execute tracking and yield resulting point estimates. 
      Depth estimation has also been developed, sadly It hasn't been applied much.
    ",
    stackComponents: [|"yolov3", "deep-sort", "tensorflow", "opencv"|]
  },

  {
    title: "Serverless Infrastructure on AWS",
    media: [|
      Image([%bs.raw "require('assets/screenshots/aws_infra.png')"]),
      Text("
        Building a scalable cloud infrastructure for our service on AWS happend to be my first major task when I jumped to full stack. 
        AWS Lambdas looked reasonably attractive at that time given its cost / easy scalability(accounting for cold starts) and provisioning. 
        Our django app was tuned to run within AWS lambda initially with zappa(and later with serverless-wsgi) and so our REST endpoints would consist of lambdas running alongside ECS-managed containers multi AZ behind ALB with lambdas handling most of our traffic. 
        We could not rely exclusively on lambda deployment mainly due to its duration and traffic limitations, so ECS(Fargate Spot) containers were used to handle long-running tasks as well as serving legacy APIs for existing apps. 
        AWS Aurora Postgres powers our backend database, our cache(django-cacheops) uses redis on spot ec2 instances, and our frontend as well as other assets are hosted on S3 behind AWS CloudFront CDN.
      ")
    |],
    team: Some({ title: "GeoThings Inc.", href: Some("https://geothings.tw/") }),
    href: None,
    duration: "Sept 2018 - March 2019",
    stackDescription: "",
    stackComponents: [|"lambda", "severless", "cloudformation", "ecs", "rds", "s3", "cloudfront"|]
  },

  {
    title: "Ballcast",
    media: [|
      Youtube("https://www.youtube.com/embed/0w-7xMFuAtw"),
      Youtube("https://www.youtube.com/embed/MfbruOORez0"),
      Youtube("https://www.youtube.com/embed/WZDJ8FzjDxc"),
      Carousel("ballcast", [|
        [%bs.raw "require('assets/screenshots/ballcast_1.png')"], 
        [%bs.raw "require('assets/screenshots/ballcast_0.png')"], 
        [%bs.raw "require('assets/screenshots/ballcast_2.png')"]
      |], false),
      Text("
        As an avid football fan, I was curious to explore what can be done in terms of real-time data collection from live football game broadcasts. 
        High-speed of football game and frequently changing cameras poses decent challenges to automated data collection and makes it tricky to replace human in a wide range of use cases that involve game data collection. 
        I started with non-supervised approach for camera reconstruction which loosely speaking was built around least-square fitting of pitch model to detected pitch lines after initial camera parameters are guessed by a CNN. 
        This exploration around football data brought me to places I kinda did not anticipate - I experimented with react-native and spritekit to render real-time ball movement traces, used electron/react/three.js to build tagging application to gather data for supervised learning 
        and got drowned into reasonml that I used to build single-state 2d-renderer which parses SVGs to object graphs and renders to webGL with pixi.js.
      ")
    |],
    duration: "Fall 2017 ~ ",
    team: None,
    href: None,
    stackDescription: "Collection of tooling. Image processing done with opencv, supervised learning on top of keras. 
  Backend tooling included python data crawlers running on AWS Lambdas, I also used AWS Amplify managed AWS AppSync for real-time graphql subscriptions. React and React was used on the client side where three.js and pixi.js was leveraged for several 3d and 2d visualization tasks.",
    stackComponents: [|"opencv", "keras", "react", "electron", "reasonml", "pixi.js", "three.js", "aws-amplify"|]
  },

  {
    title: "A-Mi Project",
    media: [|
      Youtube("https://www.youtube.com/embed/g1y87lZ0r-4"),
      Carousel("ami", [|
        [%bs.raw "require('assets/screenshots/ami_0.jpg')"], 
        [%bs.raw "require('assets/screenshots/ami_1.jpg')"], 
        [%bs.raw "require('assets/screenshots/ami_2.jpg')"], 
        [%bs.raw "require('assets/screenshots/ami_3.jpg')"], 
        [%bs.raw "require('assets/screenshots/ami_4.jpg')"], 
        [%bs.raw "require('assets/screenshots/ami_6.png')"]
      |], true),
      Text("
        A-Mi Project was a croudfunding platform made for WorldVision Taiwan. 
        The app featured the concept of life circles - donation goals tied to WorldVision croudfunding projects that have been centered around helping vulnerable children around the globe. 
        Incentive mechanisms included in-app reward badges with backer profiles being visible within life circles and facebook friends activity pushed to the user. 
      ")
    |],
    duration: "Sept 2015 - Jan 2016",
    team: Some({ title: "GeoThings Inc.", href: Some("https://geothings.tw/") }),
    href: None,
    stackDescription: "Native iOS swift app with data persistence via CoreData.",
    stackComponents: [|"ios", "UIKit", "swift"|]
  },

  {
    title: "GeoBingAn: iOS",
    media: [|
      Carousel("geoIOS", [|
        [%bs.raw "require('assets/screenshots/geobingan_ios_0.jpg')"], 
        [%bs.raw "require('assets/screenshots/geobingan_ios_1.jpg')"], 
        [%bs.raw "require('assets/screenshots/geobingan_ios_2.jpg')"], 
        [%bs.raw "require('assets/screenshots/geobingan_ios_3.jpg')"]
      |], true),
      Text("
        GeoBingAn iOS is designated for collection of location-aware surveys, crowdsourcing reports, gps traces for geoBingAn platform and comes with offline support that is built for scenarios where connectivity may be absent for long time. 
        Survey collection in remote areas also leverages offline maps functionality. 
        Notable additional features include task coordination, full customization of surveys and map object creation. 
      ")
    |],
    duration: "2016 - 2017",
    team: Some({ title: "GeoThings Inc.", href: Some("https://geothings.tw/") }),
    href: Some({ title: "geoBingAn iOS", href: Some("https://apps.apple.com/tw/app/geobingan/id719858654#?platform=iphone")}),
    stackDescription: "Native iOS app with data persistence via Realm. Mapbox.gl is used for map rendering. Utilizes RxSwift and ReSwift(swift redux implementation). REST APIs are built on top of Moya.",
    stackComponents: [|"ios", "swift", "realm", "rxswift", "reswift", "moya"|]
  },

  {
    title: "Ambientlight",
    media: [|
      Youtube("https://www.youtube.com/embed/wBriMhGLYWQ"),
      Text("
        Our idea for beyond future mobile workshop held by MIT Media Labs & NCTU involved crafting a personal flying assistant that is safe to operate in indoor environment, swapping quad-copter with helium airship was our approach for that, also potentially unlocking longer flight durations then those offered by conventional quad-copters. 
        The project got us Best Potential Team Award. 
      ")
    |],
    duration: "Summer 2015",
    team: Some({ title: "Team Ambientlight", href: None }),
    href: None,
    stackDescription: "Helium-powered drone(airship) with arduino which communicates with iOS app via bluetooth. IOS app is used as a remote which can also send the accelerometer and bearing data to allow drone to follow the person with the phone.",
    stackComponents: [|"arduino", "ios", "ble4.0"|]
  },

  /*
  {
    title: "6Media",
    media: [|
      Carousel("sixmedia", [|
        [%bs.raw "require('assets/screenshots/6media_0.png')"], 
        [%bs.raw "require('assets/screenshots/6media_1.png')"], 
        [%bs.raw "require('assets/screenshots/6media_2.png')"], 
        [%bs.raw "require('assets/screenshots/6media_3.png')"]
      |], true),
      Text("
        The very first app I have built. 
        6Media was designated to be an audio player built for an early iteration of the wireless speaker we were developing at that time. 
        In addition to built-in audio session playback, audio streaming to DLNA-complaint devices was developed. 
        Except internal media library, media sources included UPNP Media Servers and Spotify. 
      ")
    |],
    duration: "May 2013 - Sept 2014",
    team: Some({ title: "Sixnology", href: Some("https://www.sixnology.com/") }),
    href: None,
    stackDescription: "Native iOS objective-c app with data persistence via CoreData. Supports UPnP/DLNA audio streaming and features Spotify integration.",
    stackComponents: [|"ios", "upnp/dlna", "objective-c"|]
  }
  */
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
    name: "reasonml(rescript)",
    imgUrl: [%bs.raw "require('assets/imgs/reasonml_logo.jpg')"],
    href: "https://stackshare.io/reasonml"
  },
  {
    name: "python",
    imgUrl: [%bs.raw "require('assets/imgs/python_logo.png')"],
    href: "https://stackshare.io/python"
  },
  {
    name: "swift",
    imgUrl: [%bs.raw "require('assets/imgs/swift_logo.png')"],
    href: "https://stackshare.io/swift"
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
  {
    name: "ocaml",
    imgUrl: [%bs.raw "require('assets/imgs/ocaml_logo.jpg')"],
    href: "https://stackshare.io/ocaml"
  },
  {
    name: "objective-c",
    imgUrl: [%bs.raw "require('assets/imgs/objc_logo.png')"],
    href: "https://stackshare.io/objective-c"
  },
  { 
    name: "c/c++",
    imgUrl: [%bs.raw "require('assets/imgs/cpp_logo.png')"],
    href: "https://stackshare.io/cplusplus"
  }
|]; 

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
  /*
  {
    name: "apache",
    imgUrl: [%bs.raw "require('assets/imgs/apache_logo.jpg')"],
    href: "https://stackshare.io/apache"
  },
  */
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
  /*
  {
    name: "threejs",
    imgUrl: [%bs.raw "require('assets/imgs/threejs_logo.jpg')"]
  },
  {
    name: "mapboxgl",
    imgUrl: [%bs.raw "require('assets/imgs/mapboxgl_logo.png')"],
    href: "https://stackshare.io/mapbox"
  },
  */
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
