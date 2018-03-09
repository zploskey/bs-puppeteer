/** Represents a context for JavaScript execution. */
type t = Types.executionContext;

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
 * Evaluates a JavaScript expression in context and returns result in a promise.
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
 * Evaluates a string of a JavaScript expression in context.
 * Returns a promise containing a JSHandle.
 */
[@bs.send.pipe: t]
external evaluateStringHandle : string => Js.Promise.t(JSHandle.t) =
  "evaluateHandle";
