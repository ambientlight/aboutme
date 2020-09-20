[@bs.val][@bs.scope "console"]
external log: 'a => unit = "log";
[@bs.val][@bs.scope "console"]
external debug: 'a => unit = "debug";
[@bs.val][@bs.scope "console"]
external info: 'a => unit = "info";
[@bs.val][@bs.scope "console"]
external warn: 'a => unit = "warn";
[@bs.val][@bs.scope "console"]
external error: 'a => unit = "error";

[@bs.val][@bs.scope "console"]
external trace: 'a => unit = "trace";

[@bs.val][@bs.scope "console"]
external time: string => unit = "time";
[@bs.val][@bs.scope "console"]
external timeEnd: string => unit = "timeEnd";
