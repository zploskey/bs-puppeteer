type t;

type serializable = Js.Json.t;

type tagOptions = {
  .
  "content": Js.undefined(string),
  "path": Js.undefined(string),
  "url": Js.undefined(string)
};

[@bs.obj]
external makeTagOptions :
  (~url: string=?, ~path: string=?, ~content: string=?, unit) => _ =
  "";

[@bs.send.pipe : t]
external selectOne :
  (~selector: string) => Js.Promise.t(Js.null(ElementHandle.t)) =
  "$";

[@bs.send.pipe : t]
external selectAll :
  (~selector: string) => Js.Promise.t(array(ElementHandle.t)) =
  "$$";

[@bs.send.pipe : t]
external selectXPath : (~xpath: string) => Js.Promise.t(array(ElementHandle.t)) =
  "$x";

type selectorOptions = {
  .
  "visible": Js.nullable(bool),
  "hidden": Js.nullable(bool),
  "timeout": Js.nullable(float)
};

[@bs.obj]
external makeSelectorOptions :
  (~visible: Js.boolean=?, ~hidden: Js.boolean=?, ~timeout: float=?, unit) =>
  selectorOptions =
  "";

let makeSelectorOptions = (~visible=?, ~hidden=?, ~timeout=?, ()) =>
  makeSelectorOptions(
    ~visible=?Util.optBoolToJs(visible),
    ~hidden=?Util.optBoolToJs(hidden),
    ~timeout?,
    ()
  );

[@bs.send.pipe : t]
external waitForSelector :
  (string, ~options: selectorOptions=?, unit) => Js.Promise.t(unit) =
  "";

[@bs.send.pipe : t]
external waitForXPath :
  (~xpath: string, ~options: selectorOptions=?, unit) =>
  Js.Promise.t(ElementHandle.t) =
  "";

/* TODP: Add support [, ...args] */
[@bs.send.pipe : t]
external selectOneEval : (string, unit => unit) => Js.Promise.t('a) =
  "$eval";

/* TODP: Add support [, ...args] */
[@bs.send.pipe : t]
external selectAllEval : (string, unit => unit) => Js.Promise.t('a) =
  "$$eval";

[@bs.send.pipe : t]
external addScriptTag : tagOptions => Js.Promise.t(ElementHandle.t) =
  "";


[@bs.send.pipe : t]
external addStyleTag : tagOptions => Js.Promise.t(ElementHandle.t) =
  "";

[@bs.send.pipe : t]
external evaluate :
  (unit => Js.Promise.t(Js.Json.t), [@bs.splice] array({..})) =>
  Js.Promise.t(Js.Json.t) =
  "";
