type t;

type tracingOptions = {
  .
  "path": string,
  "screenshots": Js.Nullable.t(bool),
  "categories": array(string),
};

[@bs.obj]
external makeTracingOptions :
  (
    ~path: string=?,
    ~screenshots: Js.Nullable.t(Js.boolean)=?,
    ~categories: array(string)=?,
    unit
  ) =>
  tracingOptions =
  "";

[@bs.send.pipe: t]
external start : (~options: tracingOptions=?, unit) => Js.Promise.t(unit) =
  "";

[@bs.send.pipe: t] external stop : Js.Promise.t(unit) = "";
