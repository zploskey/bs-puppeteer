/** Represents a context for JavaScript execution. */
type t = Types.executionContext;

include Evaluator.Impl({
  type nonrec t = t;
});

[@bs.send] [@bs.return nullable]
external frame : t => option(FrameBase.t) = "";

/**
 * Iterates the JavaScript heap and finds all the objects with the given
 * prototype. Returns a handle to an array of objects with this prototype.
 */
[@bs.send.pipe: t]
external queryObjects : (~prototypeHandle: JSHandle.t) => JSHandle.t = "";
