type t = Types.frameBase;

include Evaluator.Impl({
  type nonrec t = t;
});

type tagOptions = {
  .
  "url": Js.undefined(string),
  "path": Js.undefined(string),
  "content": Js.undefined(string),
  "_type": Js.undefined(string),
};

[@bs.obj]
external makeTagOptions:
  (
    ~url: string=?,
    ~path: string=?,
    ~content: string=?,
    ~_type: string=?,
    unit
  ) =>
  tagOptions =
  "";

[@bs.send]
external goto:
  (t, string, ~options: Navigation.options=?, unit) =>
  Js.Promise.t(Js.null(Response.t)) =
  "";

[@bs.send]
external selectOne:
  (t, ~selector: string) => Js.Promise.t(Js.Null.t(ElementHandle.t('a))) =
  "$";

[@bs.send]
external selectAll:
  (t, ~selector: string) => Js.Promise.t(array(ElementHandle.t('a))) =
  "$$";

[@bs.send]
external selectXPath:
  (t, ~xpath: string) => Js.Promise.t(array(ElementHandle.t('a))) =
  "$x";

type selectorOptions = {
  .
  "visible": Js.nullable(bool),
  "hidden": Js.nullable(bool),
  "timeout": Js.nullable(float),
};

[@bs.obj]
external makeSelectorOptions:
  (~visible: bool=?, ~hidden: bool=?, ~timeout: float=?, unit) =>
  selectorOptions =
  "";

/* TODO: waitForFunction */

[@bs.send]
external waitForNavigation:
  (t, ~options: Navigation.options) => Js.Promise.t(Js.nullable(Response.t)) =
  "";

let waitForNavigation = (page, ~options) =>
  waitForNavigation(page, ~options)
  |> Js.Promise.(then_(response => response |> Js.toOption |> resolve));

[@bs.send]
external waitForSelector:
  (t, string, ~options: selectorOptions=?, unit) => Js.Promise.t(unit) =
  "";

[@bs.send]
external waitForXPath:
  (t, ~xpath: string, ~options: selectorOptions=?, unit) =>
  Js.Promise.t(ElementHandle.t('a)) =
  "";

/**
 * selectOneEval(page, selector, fn)
 * Runs document.querySelector in the page and passes it as the first
 * argument to `fn`. If there's no element matching selector, the function
 * throws an error.
 */
[@bs.send]
external selectOneEval:
  (t, string, [@bs.uncurry] (Dom.element => 'r)) => Js.Promise.t('r) =
  "$eval";

/**
 * selectOneEvalPromise(page, selector, fn)
 * Runs document.querySelector in the page and passes it as the first
 * argument to `fn`. If there's no element matching selector, the function
 * throws an error. `fn` must return a promise.
 */
[@bs.send]
external selectOneEvalPromise:
  (t, string, [@bs.uncurry] (Dom.element => Js.Promise.t('r))) =>
  Js.Promise.t('r) =
  "$eval";

/**
 * selectOneEval(page, selector, fn, arg1)
 * Runs document.querySelector in the page and passes it as the first
 * argument to `fn`. Additional argument `arg1` is passed to `fn`.
 * If there's no element matching selector, the method throws an
 * error.
 */
[@bs.send]
external selectOneEval1:
  (t, string, [@bs.uncurry] ((Dom.element, 'a) => 'r), 'a) => Js.Promise.t('r) =
  "$eval";

/**
 * selectOneEvalPromise(selector, fn, arg1, page)
 * Runs document.querySelector in the page and passes it as the first
 * argument to `fn`. Additional argument `arg1` is passed to `fn`.
 * If there's no element matching selector, the method throws an
 * error. `fn` must return a promise.
 */
[@bs.send]
external selectOneEvalPromise1:
  (t, string, [@bs.uncurry] ((Dom.element, 'a) => Js.Promise.t('r)), 'a) =>
  Js.Promise.t('r) =
  "$eval";

[@bs.send]
external selectOneEval2:
  (t, string, [@bs.uncurry] ((Dom.element, 'a, 'b) => 'r), 'a, 'b) =>
  Js.Promise.t('r) =
  "$eval";

[@bs.send]
external selectOneEvalPromise2:
  (
    t,
    string,
    [@bs.uncurry] ((Dom.element, 'a, 'b) => Js.Promise.t('r)),
    'a,
    'b
  ) =>
  Js.Promise.t('r) =
  "$eval";

[@bs.send]
external selectOneEval3:
  (t, string, [@bs.uncurry] ((Dom.element, 'a, 'b, 'c) => 'r), 'a, 'b, 'c) =>
  Js.Promise.t('r) =
  "$eval";

[@bs.send]
external selectOneEvalPromise3:
  (
    t,
    string,
    [@bs.uncurry] ((Dom.element, 'a, 'b, 'c) => Js.Promise.t('r)),
    'a,
    'b,
    'c
  ) =>
  Js.Promise.t('r) =
  "$eval";

[@bs.send]
external selectOneEval4:
  (
    t,
    string,
    [@bs.uncurry] ((Dom.element, 'a, 'b, 'c, 'd) => 'r),
    'a,
    'b,
    'c,
    'd
  ) =>
  Js.Promise.t('r) =
  "$eval";

[@bs.send]
external selectOneEvalPromise4:
  (
    t,
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
 * selectAllEval(page, selector, fn)
 * Runs document.querySelectorAll in the page and passes it as an argument to
 * `fn`.
 */
[@bs.send]
external selectAllEval:
  (t, string, [@bs.uncurry] (Dom.nodeList => 'r)) => Js.Promise.t('r) =
  "$$eval";

/** Runs document.querySelectorAll in the page and passes it as an argument to
 * `fn`. `fn` must return a promise.
 * */
[@bs.send]
external selectAllEvalPromise:
  (t, string, [@bs.uncurry] (Dom.nodeList => Js.Promise.t('r))) =>
  Js.Promise.t('r) =
  "$$eval";

/**
 * selectAllEval1(page, selector, fn, arg1)
 * Runs document.querySelectorAll in the page and passes the result as the
 * first argument to `fn`. It passes `arg1` as the second argument to `fn`.
 */
[@bs.send]
external selectAllEval1:
  (t, string, [@bs.uncurry] ((Dom.nodeList, 'a) => 'r), 'a) =>
  Js.Promise.t('r) =
  "$$eval";

[@bs.send]
external selectAllEvalPromise1:
  (t, string, [@bs.uncurry] ((Dom.nodeList, 'a) => 'r), Js.Promise.t('a)) =>
  Js.Promise.t('r) =
  "$$eval";

[@bs.send]
external selectAllEval2:
  (t, string, [@bs.uncurry] ((Dom.nodeList, 'a, 'b) => 'r), 'a, 'b) =>
  Js.Promise.t('r) =
  "$$eval";

[@bs.send]
external selectAllEvalPromise2:
  (
    t,
    string,
    [@bs.uncurry] ((Dom.nodeList, 'a, 'b) => Js.Promise.t('r)),
    'a,
    'b
  ) =>
  Js.Promise.t('r) =
  "$$eval";

[@bs.send]
external selectAllEval3:
  (t, string, [@bs.uncurry] ((Dom.nodeList, 'a, 'b, 'c) => 'r), 'a, 'b, 'c) =>
  Js.Promise.t('r) =
  "$$eval";

[@bs.send]
external selectAllEvalPromise3:
  (
    t,
    string,
    [@bs.uncurry] ((Dom.nodeList, 'a, 'b, 'c) => Js.Promise.t('r)),
    'a,
    'b,
    'c
  ) =>
  Js.Promise.t('r) =
  "$$eval";

[@bs.send]
external selectAllEval4:
  (
    t,
    string,
    [@bs.uncurry] ((Dom.nodeList, 'a, 'b, 'c, 'd) => 'r),
    'a,
    'b,
    'c,
    'd
  ) =>
  Js.Promise.t('r) =
  "$$eval";

[@bs.send]
external selectAllEvalPromise4:
  (
    t,
    string,
    [@bs.uncurry] ((Dom.nodeList, 'a, 'b, 'c, 'd) => Js.Promise.t('r)),
    'a,
    'b,
    'c,
    'd
  ) =>
  Js.Promise.t('r) =
  "$$eval";

[@bs.send]
external addScriptTag:
  (t, tagOptions) => Js.Promise.t(ElementHandle.t(Dom.element)) =
  "";

[@bs.send]
external addStyleTag:
  (t, tagOptions) => Js.Promise.t(ElementHandle.t(Dom.element)) =
  "";

[@bs.send]
external click:
  (t, string, ~options: Click.clickOptions=?, unit) => Js.Promise.t(unit) =
  "";

[@bs.send] external content: t => Js.Promise.t(string) = "";

[@bs.send] external focus: (t, ~selector: string) => Js.Promise.t(unit) = "";

/**
 * Fetches the first element matching `selector`, scrolls it into view if not
 * already visible, then hovers over the center of the element using
 * [Page.mouse]. Throws an error if no element matches `selector`.
 */
[@bs.send]
external hover: (t, ~selector: string) => Js.Promise.t(unit) = "";

/**
 * Selects options in a `<select>` tag. Triggers a `change` and `input` event
 * once all the provided options have been selected. If there's no `<select>`
 * element matching selector it throws an error.
 */
[@bs.send]
external select:
  (t, ~selector: string, ~values: array(string)) =>
  Js.Promise.t(array(string)) =
  "";

[@bs.send] external tap: (t, ~selector: string) => Js.Promise.t(unit) = "";

type typeOptions = {. "delay": float};

[@bs.send]
external type_:
  (t, string, string, ~options: typeOptions=?, unit) => Js.Promise.t(unit) =
  "type";

[@bs.send] external url: t => string = "";
