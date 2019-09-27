type t;

type tracingOptions = {
  .
  "path": string,
  "screenshots": Js.nullable(bool),
  "categories": Js.nullable(array(string)),
};

[@bs.obj]
external makeTracingOptions:
  (~path: string, ~screenshots: bool=?, ~categories: array(string)=?, unit) =>
  tracingOptions =
  "";

[@bs.send]
external start: (t, ~options: tracingOptions, unit) => Js.Promise.t(unit) =
  "start";

[@bs.send] external stop: t => Js.Promise.t(Node.Buffer.t) = "stop";
