let lmap = List.map;
let lfilter = List.filter;
let lreduce = List.fold_left;
let lfoldRight = List.fold_right;
let lzip = Belt.List.zip;
let llength = List.length;
let lforeach = Belt.List.forEach;
let lkeepmap = (fn, list) => Belt.List.keepMap(list, fn);

let amap = Belt.Array.map;
let amapi = Belt.Array.mapWithIndex;
let aforeach = Belt.Array.forEach;
let afilter = Belt.Array.keep;
let aoptmap = Belt.Array.keepMap;
let areduce = Belt.Array.reduce;
let alength = Array.length;
let azip = Belt.Array.zip;
let asort = Array.sort;

let toopt = Js.toOption;
let utoopt = Js.Undefined.toOption;
let withdef = Belt.Option.getWithDefault;
let getext = Belt.Option.getExn;
let optmap = Belt.Option.map;
let optfmap = Belt.Option.flatMap;

let sstartswith = Js.String.startsWith;