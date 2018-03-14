type t = Types.frameBase;

type tagOptions = {
  .
  "content": Js.undefined(string),
  "path": Js.undefined(string),
  "url": Js.undefined(string),
};

[@bs.obj]
external makeTagOptions :
  (~url: string=?, ~path: string=?, ~content: string=?, unit) => _ =
  "";

[@bs.send.pipe: t]
external selectOne :
  (~selector: string) => Js.Promise.t(Js.Nullable.t(ElementHandle.t)) =
  "$";

[@bs.send.pipe: t]
external selectAll :
  (~selector: string) => Js.Promise.t(array(ElementHandle.t)) =
  "$$";

[@bs.send.pipe: t]
external selectXPath :
  (~xpath: string) => Js.Promise.t(array(ElementHandle.t)) =
  "$x";

type selectorOptions = {
  .
  "visible": Js.nullable(bool),
  "hidden": Js.nullable(bool),
  "timeout": Js.nullable(float),
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
    (),
  );

[@bs.send.pipe: t]
external waitForSelector :
  (string, ~options: selectorOptions=?, unit) => Js.Promise.t(unit) =
  "";

[@bs.send.pipe: t]
external waitForXPath :
  (~xpath: string, ~options: selectorOptions=?, unit) =>
  Js.Promise.t(ElementHandle.t) =
  "";

/**
 * selectOneEval(selector, fn, page)
 * Runs document.querySelector in the page and passes it as the first
 * argument to `fn`. If there's no element matching selector, the function
 * throws an error.
 */
[@bs.send.pipe: t]
external selectOneEval :
  (string, [@bs.uncurry] (Dom.element => 'r)) => Js.Promise.t('r) =
  "$eval";

/**
 * selectOneEvalPromise(selector, fn, page)
 * Runs document.querySelector in the page and passes it as the first
 * argument to `fn`. If there's no element matching selector, the function
 * throws an error. `fn` must return a promise.
 */
[@bs.send.pipe: t]
external selectOneEvalPromise :
  (string, [@bs.uncurry] (Dom.element => Js.Promise.t('r))) =>
  Js.Promise.t('r) =
  "$eval";

/**
 * selectOneEval(selector, fn, arg1, page)
 * Runs document.querySelector in the page and passes it as the first
 * argument to `fn`. Additional argument `arg1` is passed to `fn`.
 * If there's no element matching selector, the method throws an
 * error.
 */
[@bs.send.pipe: t]
external selectOneEval1 :
  (string, [@bs.uncurry] ((Dom.element, 'a) => 'r), 'a) => Js.Promise.t('r) =
  "$eval";

/**
 * selectOneEvalPromise(selector, fn, arg1, page)
 * Runs document.querySelector in the page and passes it as the first
 * argument to `fn`. Additional argument `arg1` is passed to `fn`.
 * If there's no element matching selector, the method throws an
 * error. `fn` must return a promise.
 */
[@bs.send.pipe: t]
external selectOneEvalPromise1 :
  (string, [@bs.uncurry] ((Dom.element, 'a) => Js.Promise.t('r)), 'a) =>
  Js.Promise.t('r) =
  "$eval";

[@bs.send.pipe: t]
external selectOneEval2 :
  (string, [@bs.uncurry] ((Dom.element, 'a, 'b) => 'r), 'a, 'b) =>
  Js.Promise.t('r) =
  "$eval";

[@bs.send.pipe: t]
external selectOneEvalPromise2 :
  (
    string,
    [@bs.uncurry] ((Dom.element, 'a, 'b) => Js.Promise.t('r)),
    'a,
    'b
  ) =>
  Js.Promise.t('r) =
  "$eval";

[@bs.send.pipe: t]
external selectOneEval3 :
  (string, [@bs.uncurry] ((Dom.element, 'a, 'b, 'c) => 'r), 'a, 'b, 'c) =>
  Js.Promise.t('r) =
  "$eval";

[@bs.send.pipe: t]
external selectOneEvalPromise3 :
  (
    string,
    [@bs.uncurry] ((Dom.element, 'a, 'b, 'c) => Js.Promise.t('r)),
    'a,
    'b,
    'c
  ) =>
  Js.Promise.t('r) =
  "$eval";

[@bs.send.pipe: t]
external selectOneEval4 :
  (
    string,
    [@bs.uncurry] ((Dom.element, 'a, 'b, 'c, 'd) => 'r),
    'a,
    'b,
    'c,
    'd
  ) =>
  Js.Promise.t('r) =
  "$eval";

[@bs.send.pipe: t]
external selectOneEvalPromise4 :
  (
    string,
    [@bs.uncurry] ((Dom.element, 'a, 'b, 'c, 'd) => Js.Promise.t('r)),
    'a,
    'b,
    'c,
    'd
  ) =>
  Js.Promise.t('r) =
  "$eval";

/**
 * selectAllEval(selector, fn)
 * Runs document.querySelectorAll in the page and passes it as an argument to
 * `fn`.
 */
[@bs.send.pipe: t]
external selectAllEval :
  (string, [@bs.uncurry] (Dom.nodeList => 'r)) => Js.Promise.t('r) =
  "$$eval";

/** Runs document.querySelectorAll in the page and passes it as an argument to
 * `fn`. `fn` must return a promise.
 * */
[@bs.send.pipe: t]
external selectAllEvalPromise :
  (string, [@bs.uncurry] (Dom.nodeList => Js.Promise.t('r))) =>
  Js.Promise.t('r) =
  "$$eval";

/**
 * selectAllEval1(selector, fn, arg1)
 * Runs document.querySelectorAll in the page and passes the result as the
 * first argument to `fn`. It passes `arg1` as the second argument to `fn`.
 */
[@bs.send.pipe: t]
external selectAllEval1 :
  (string, [@bs.uncurry] ((Dom.nodeList, 'a) => 'r), 'a) => Js.Promise.t('r) =
  "$$eval";

[@bs.send.pipe: t]
external selectAllEvalPromise1 :
  (string, [@bs.uncurry] ((Dom.nodeList, 'a) => 'r), Js.Promise.t('a)) =>
  Js.Promise.t('r) =
  "$$eval";

[@bs.send.pipe: t]
external selectAllEval2 :
  (string, [@bs.uncurry] ((Dom.nodeList, 'a, 'b) => 'r), 'a, 'b) =>
  Js.Promise.t('r) =
  "$$eval";

[@bs.send.pipe: t]
external selectAllEvalPromise2 :
  (
    string,
    [@bs.uncurry] ((Dom.nodeList, 'a, 'b) => Js.Promise.t('r)),
    'a,
    'b
  ) =>
  Js.Promise.t('r) =
  "$$eval";

[@bs.send.pipe: t]
external selectAllEval3 :
  (string, [@bs.uncurry] ((Dom.nodeList, 'a, 'b, 'c) => 'r), 'a, 'b, 'c) =>
  Js.Promise.t('r) =
  "$$eval";

[@bs.send.pipe: t]
external selectAllEvalPromise3 :
  (
    string,
    [@bs.uncurry] ((Dom.nodeList, 'a, 'b, 'c) => Js.Promise.t('r)),
    'a,
    'b,
    'c
  ) =>
  Js.Promise.t('r) =
  "$$eval";

[@bs.send.pipe: t]
external selectAllEval4 :
  (
    string,
    [@bs.uncurry] ((Dom.nodeList, 'a, 'b, 'c, 'd) => 'r),
    'a,
    'b,
    'c,
    'd
  ) =>
  Js.Promise.t('r) =
  "$$eval";

[@bs.send.pipe: t]
external selectAllEvalPromise4 :
  (
    string,
    [@bs.uncurry] ((Dom.nodeList, 'a, 'b, 'c, 'd) => Js.Promise.t('r)),
    'a,
    'b,
    'c,
    'd
  ) =>
  Js.Promise.t('r) =
  "$$eval";

[@bs.send.pipe: t]
external addScriptTag : tagOptions => Js.Promise.t(ElementHandle.t) = "";

[@bs.send.pipe: t]
external addStyleTag : tagOptions => Js.Promise.t(ElementHandle.t) = "";

[@bs.send.pipe: t] external evaluate : (unit => 'r) => Js.Promise.t('r) = "";

[@bs.send.pipe: t]
external evaluatePromise : (unit => Js.Promise.t('r)) => Js.Promise.t('r) =
  "";

[@bs.send.pipe: t]
external evaluate1 : ([@bs.uncurry] ('a => 'r), 'a) => Js.Promise.t('r) =
  "evaluate";

[@bs.send.pipe: t]
external evaluatePromise1 :
  ([@bs.uncurry] ('a => Js.Promise.t('r)), 'a) => Js.Promise.t('r) =
  "evaluate";

[@bs.send.pipe: t]
external evaluate2 :
  ([@bs.uncurry] (('a, 'b) => 'r), 'a, 'b) => Js.Promise.t('r) =
  "evaluate";

[@bs.send.pipe: t]
external evaluatePromise2 :
  ([@bs.uncurry] (('a, 'b) => Js.Promise.t('r)), 'a, 'b) => Js.Promise.t('r) =
  "evaluate";

[@bs.send.pipe: t]
external evaluate3 :
  ([@bs.uncurry] (('a, 'b, 'c) => 'r), 'a, 'b, 'c) => Js.Promise.t('r) =
  "evaluate";

[@bs.send.pipe: t]
external evaluatePromise3 :
  ([@bs.uncurry] (('a, 'b, 'c) => Js.Promise.t('r)), 'a, 'b, 'c) =>
  Js.Promise.t('r) =
  "evaluate";

[@bs.send.pipe: t]
external evaluate4 :
  ([@bs.uncurry] (('a, 'b, 'c, 'd) => 'r), 'a, 'b, 'c, 'd) => Js.Promise.t('r) =
  "evaluate";

[@bs.send.pipe: t]
external evaluatePromise4 :
  ([@bs.uncurry] (('a, 'b, 'c, 'd) => Js.Promise.t('r)), 'a, 'b, 'c, 'd) =>
  Js.Promise.t('r) =
  "evaluate";

/**
 * Evaluates a JavaScript expression in page and returns result in a promise.
 */
[@bs.send.pipe: t]
external evaluateString : string => Js.Promise.t('r) = "evaluate";

[@bs.send.pipe: t]
external evaluateHandle : (unit => JSHandle.t) => Js.Promise.t(JSHandle.t) =
  "";

[@bs.send.pipe: t]
external evaluateHandlePromise :
  (unit => Js.Promise.t(JSHandle.t)) => Js.Promise.t(JSHandle.t) =
  "";

[@bs.send.pipe: t]
external evaluateHandle1 :
  ([@bs.uncurry] ('a => JSHandle.t), 'a) => Js.Promise.t(JSHandle.t) =
  "evaluateHandle";

[@bs.send.pipe: t]
external evaluateHandlePromise1 :
  ([@bs.uncurry] ('a => Js.Promise.t(JSHandle.t)), 'a) =>
  Js.Promise.t(JSHandle.t) =
  "evaluateHandle";

[@bs.send.pipe: t]
external evaluateHandle2 :
  ([@bs.uncurry] (('a, 'b) => JSHandle.t), 'a, 'b) => Js.Promise.t(JSHandle.t) =
  "evaluateHandle";

[@bs.send.pipe: t]
external evaluateHandlePromise2 :
  ([@bs.uncurry] (('a, 'b) => Js.Promise.t(JSHandle.t)), 'a, 'b) =>
  Js.Promise.t(JSHandle.t) =
  "evaluateHandle";

[@bs.send.pipe: t]
external evaluateHandle3 :
  ([@bs.uncurry] (('a, 'b, 'c) => JSHandle.t), 'a, 'b, 'c) => Js.Promise.t('r) =
  "evaluateHandle";

[@bs.send.pipe: t]
external evaluateHandlePromise3 :
  ([@bs.uncurry] (('a, 'b, 'c) => Js.Promise.t(JSHandle.t)), 'a, 'b, 'c) =>
  Js.Promise.t('r) =
  "evaluateHandle";

[@bs.send.pipe: t]
external evaluateHandle4 :
  ([@bs.uncurry] (('a, 'b, 'c, 'd) => JSHandle.t), 'a, 'b, 'c, 'd) =>
  Js.Promise.t('r) =
  "evaluateHandle";

[@bs.send.pipe: t]
external evaluateHandlePromise4 :
  (
    [@bs.uncurry] (('a, 'b, 'c, 'd) => Js.Promise.t(JSHandle.t)),
    'a,
    'b,
    'c,
    'd
  ) =>
  Js.Promise.t('r) =
  "evaluateHandle";

/**
 * Evaluates a string of a JavaScript expression in page context.
 * Returns a promise containing a JSHandle.
 */
[@bs.send.pipe: t]
external evaluateStringHandle : string => Js.Promise.t(JSHandle.t) =
  "evaluateHandle";
