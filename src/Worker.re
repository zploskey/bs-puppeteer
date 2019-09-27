type t;

include Evaluator.Impl({
  type nonrec t = t;
});

[@bs.send]
external executionContext: t => Js.Promise.t(ExecutionContext.t) =
  "executionContext";

[@bs.send] external url: t => string = "url";
