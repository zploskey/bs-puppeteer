module Impl = (T: {type t;}) => {
  [@bs.send]
  external evaluate: (T.t, unit => 'r) => Js.Promise.t('r) = "evaluate";

  [@bs.send]
  external evaluatePromise:
    (T.t, unit => Js.Promise.t('r)) => Js.Promise.t('r) =
    "evaluatePromise";

  [@bs.send]
  external evaluate1: (T.t, [@bs.uncurry] ('a => 'r), 'a) => Js.Promise.t('r) =
    "evaluate";

  [@bs.send]
  external evaluatePromise1:
    (T.t, [@bs.uncurry] ('a => Js.Promise.t('r)), 'a) => Js.Promise.t('r) =
    "evaluate";

  [@bs.send]
  external evaluate2:
    (T.t, [@bs.uncurry] (('a, 'b) => 'r), 'a, 'b) => Js.Promise.t('r) =
    "evaluate";

  [@bs.send]
  external evaluatePromise2:
    (T.t, [@bs.uncurry] (('a, 'b) => Js.Promise.t('r)), 'a, 'b) =>
    Js.Promise.t('r) =
    "evaluate";

  [@bs.send]
  external evaluate3:
    (T.t, [@bs.uncurry] (('a, 'b, 'c) => 'r), 'a, 'b, 'c) => Js.Promise.t('r) =
    "evaluate";

  [@bs.send]
  external evaluatePromise3:
    (T.t, [@bs.uncurry] (('a, 'b, 'c) => Js.Promise.t('r)), 'a, 'b, 'c) =>
    Js.Promise.t('r) =
    "evaluate";

  [@bs.send]
  external evaluate4:
    (T.t, [@bs.uncurry] (('a, 'b, 'c, 'd) => 'r), 'a, 'b, 'c, 'd) =>
    Js.Promise.t('r) =
    "evaluate";

  [@bs.send]
  external evaluatePromise4:
    (
      T.t,
      [@bs.uncurry] (('a, 'b, 'c, 'd) => Js.Promise.t('r)),
      'a,
      'b,
      'c,
      'd
    ) =>
    Js.Promise.t('r) =
    "evaluate";

  /** Evaluate a js expression in context. Returns the result in a promise. */
  [@bs.send]
  external evaluateString: (T.t, string) => Js.Promise.t('r) = "evaluate";

  [@bs.send]
  external evaluateHandle: (T.t, unit => 'r) => Js.Promise.t(JSHandle.t('r)) =
    "evaluateHandle";

  [@bs.send]
  external evaluateHandlePromise:
    (T.t, unit => Js.Promise.t('r)) => Js.Promise.t(JSHandle.t('r)) =
    "evaluateHandlePromise";

  [@bs.send]
  external evaluateHandle1:
    (T.t, [@bs.uncurry] ('a => 'r), 'a) => Js.Promise.t(JSHandle.t('r)) =
    "evaluateHandle";

  [@bs.send]
  external evaluateHandlePromise1:
    (T.t, [@bs.uncurry] ('a => Js.Promise.t('r)), 'a) =>
    Js.Promise.t(JSHandle.t('r)) =
    "evaluateHandle";

  [@bs.send]
  external evaluateHandle2:
    (T.t, [@bs.uncurry] (('a, 'b) => 'r), 'a, 'b) =>
    Js.Promise.t(JSHandle.t('r)) =
    "evaluateHandle";

  [@bs.send]
  external evaluateHandlePromise2:
    (T.t, [@bs.uncurry] (('a, 'b) => Js.Promise.t('r)), 'a, 'b) =>
    Js.Promise.t(JSHandle.t('r)) =
    "evaluateHandle";

  [@bs.send]
  external evaluateHandle3:
    (T.t, [@bs.uncurry] (('a, 'b, 'c) => 'r), 'a, 'b, 'c) =>
    Js.Promise.t(JSHandle.t('r)) =
    "evaluateHandle";

  [@bs.send]
  external evaluateHandlePromise3:
    (T.t, [@bs.uncurry] (('a, 'b, 'c) => Js.Promise.t('r)), 'a, 'b, 'c) =>
    Js.Promise.t(JSHandle.t('r)) =
    "evaluateHandle";

  [@bs.send]
  external evaluateHandle4:
    (T.t, [@bs.uncurry] (('a, 'b, 'c, 'd) => 'r), 'a, 'b, 'c, 'd) =>
    Js.Promise.t(JSHandle.t('r)) =
    "evaluateHandle";

  [@bs.send]
  external evaluateHandlePromise4:
    (
      T.t,
      [@bs.uncurry] (('a, 'b, 'c, 'd) => Js.Promise.t('r)),
      'a,
      'b,
      'c,
      'd
    ) =>
    Js.Promise.t(JSHandle.t('r)) =
    "evaluateHandle";

  /**
   * Evaluates a string of a JavaScript expression in context.
   * Returns a promise containing a JSHandle.
   */
  [@bs.send]
  external evaluateStringHandle:
    (T.t, string) => Js.Promise.t(JSHandle.t('r)) =
    "evaluateHandle";
};

type t;

include Impl({
  type nonrec t = t;
});
