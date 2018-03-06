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

type jsonOrHandle =
  | JSON(serializable)
  | Handle(JSHandle.t);

/**
 * selectOneEval(selector, fn, args, page)
 * Runs document.querySelector in the page and passes it as the first
 * argument to `fn`. Additional arguments to the `fn` can be provides in
 * `args`. If there's no element matching selector, the method throws an
 * error. If the function returns a Promise, it waits for the promise to
 * resolve and returns its value.
 */
[@bs.send.pipe : t]
[@bs.splice]
external selectOneEval :
  (string, 'a => 'b, array(jsonOrHandle)) => Js.Promise.t(serializable) =
  "$eval";

/**
 * selectAllEval(selector, fn)
 * Runs document.querySelectorAll in the page and passes it as the first
 * argument to `fn`. If `fn` returns a Promise, then it waits for
 * the promise to resolve and returns its value.
 */
[@bs.send.pipe : t]
external selectAllEval :
  (string, Dom.element => 'a) => Js.Promise.t(serializable) =
  "$$eval";

[@bs.send.pipe : t] [@bs.splice]
external selectAllEvalWithArgs :
  (string, Dom.element => 'a, array(jsonOrHandle)) =>
  Js.Promise.t(serializable) =
  "$$eval";

[@bs.send.pipe : t]
external addScriptTag : tagOptions => Js.Promise.t(ElementHandle.t) = "";

[@bs.send.pipe : t]
external addStyleTag : tagOptions => Js.Promise.t(ElementHandle.t) = "";

[@bs.send.pipe : t] [@bs.splice]
external evaluate :
  (Eval.Fn.t, array(Eval.Arg.t)) => Js.Promise.t(serializable) =
  "";

/**
 * Evaluates a JavaScript expression in page and returns result in a promise.
 */
[@bs.send.pipe : t]
external evaluateString : string => Js.Promise.t('a) = "evaluate";

[@bs.send.pipe : t] [@bs.splice]
external evaluateHandle :
  ('a => Js.Promise.t(JSHandle.t), array(Eval.Arg.t)) =>
  Js.Promise.t(JSHandle.t) =
  "";

[@bs.send.pipe : t] [@bs.splice]
external evaluateStringHandle :
  (string, array(Eval.Arg.t)) => Js.Promise.t(JSHandle.t) =
  "evaluateHandle";
