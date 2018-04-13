type t;

type tracingOptions = {
  .
  "path": Js.nullable(string),
  "screenshots": Js.nullable(Js.boolean),
  "categories": Js.nullable(array(string)),
};

[@bs.obj]
external makeTracingOptions :
  (
    ~path: string=?,
    ~screenshots: Js.boolean=?,
    ~categories: array(string)=?,
    unit
  ) =>
  tracingOptions =
  "";

let makeTracingOptions = (~path=?, ~screenshots=?, ~categories=?, ()) =>
  makeTracingOptions(
    ~path?,
    ~screenshots=?Util.optBoolToJs(screenshots),
    ~categories?,
    (),
  );

[@bs.send.pipe: t]
external start : (~options: tracingOptions=?, unit) => Js.Promise.t(unit) =
  "";

[@bs.send]
external stop : t => Js.Promise.t(Js.Typed_array.ArrayBuffer.t) = "";
