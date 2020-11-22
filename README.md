## aboutme

My personal website. Static barebone ReasonReact app without any dependencies except [bs-css](https://github.com/reasonml-labs/bs-css) used for statically typed css in reason.

## Customizing

You can swap all data displayed at [src/Data.re](src/Data.re). The starting point to customize styling is at [src/SDefs.re](src/SDefs.re) 

## Deployment to github pages

Fill in your repository name used to host github pages site at [REPOSITORY_NAME](.github/workflows/deploy.yaml#L36) in [deploy.yaml](.github/workflows/deploy.yaml) (use YOURPROFILE.github.io if you want the exclude the repo name from the github pages url subpath), pushing changes to master will deploy to github pages. 

## Credits

[LMPixels](https://themeforest.net/user/lmpixels) inspired some of the styling used here.