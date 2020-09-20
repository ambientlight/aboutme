open Css;

/****
 * IMPORTANT: needs to be defined as seperate typeotherwise while 
 * otherwise reasonml will generate ReactHotLoader.make as 
 * function make(param) {
 *   return Root.hot(FormationContainer$Formationembedcore.make, param);
 * }
 * 
 * rather then var make = Root.hot(FormationContainer$Formationembedcore.make);
 * when seperate componentFunc type is defined as below
 */
type componentFunc = ({. }) => React.element;

module ReactHotLoader {
  [@bs.obj]
  external makeProps: (~key: string=?, unit) => {. } = "";

  [@bs.module "react-hot-loader/root"]
  external make: ([@bs.uncurry] Js.t({..}) => React.element) => componentFunc = "hot";
};

module Hot {
  let makeProps = ReactHotLoader.makeProps;
  let make = ReactHotLoader.make(Landing.make);
};

let inject = () => {
  global("body", [
    margin(px(0)),
    selector("*", [boxSizing(`borderBox)]),
    unsafe("overscrollBehaviorY", "none")
  ])
};

ReactDOMRe.renderToElementWithId(<Hot/>, "root");
inject()