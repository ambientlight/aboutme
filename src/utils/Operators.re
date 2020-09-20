/* options */
let (|?) = (opt, default) => Belt.Option.getWithDefault(opt, default);
let (!?) = opt => opt == None ? false : true;
let (??) = value => Some(value);
let (?!!) = anything => anything |. Belt.Option.getExn;

let (>|<) = (list, seperator) => Utils.List.join(~seperator, list);

let (!!) = anything => Obj.magic(anything);

/* misc */
let (~~) = anything => Console.log(anything);
let (!#) = rule => Css.important(rule);

let (|@) = (a1, a2) => Array.concat([a1, a2]);
let (<..) = (st, ed) => Belt.Array.range(st, ed - 1); 
