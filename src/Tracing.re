type t;

type tracingOptions = {
  .
  "path": Js.nullable(string),
  "screenshots": Js.nullable(bool),
  "categories": Js.nullable(array(string)),
};

[@bs.obj]
external makeTracingOptions :
  (
    ~path: string=?,
    ~screenshots: bool=?,
    ~categories: array(string)=?,
    unit
  ) =>
  tracingOptions =
  "";

[@bs.send.pipe: t]
external start : (~options: tracingOptions=?, unit) => Js.Promise.t(unit) =
  "";

[@bs.send]
external stop : t => Js.Promise.t(Js.Typed_array.ArrayBuffer.t) = "";
