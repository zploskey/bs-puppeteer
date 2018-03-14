type t;

type tracingOptions = {
  .
  "path": string,
  "screenshots": Js.Nullable.t(bool),
};

[@bs.obj]
external makeTracingOptions :
  (~path: string=?, ~screenshots: Js.Nullable.t(Js.boolean)=?, unit) =>
  tracingOptions =
  "";

[@bs.send.pipe: t]
external start : (~options: tracingOptions=?, unit) => Js.Promise.t(unit) =
  "";

[@bs.send.pipe: t] external stop : Js.Promise.t(unit) = "";
