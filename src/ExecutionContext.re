/** Represents a context for JavaScript execution. */
type t = Types.executionContext;

include Evaluator.Impl({
  type nonrec t = t;
});

[@bs.send] [@bs.return nullable]
external frame: t => option(FrameBase.t) = "";

/** True if the execution context is the main one for a frame. */
[@bs.send]
external isDefault: t => bool = "";

/** Name of the execution context. */
[@bs.send]
external name: t => string = "";

/**
 * Iterates the JavaScript heap and finds all the objects with the given
 * prototype. Returns a handle to an array of objects with this prototype.
 */
[@bs.send]
external queryObjects:
  (t, ~prototypeHandle: JSHandle.t('a)) => JSHandle.t(array('b)) =
  "";
