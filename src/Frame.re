include FrameBase;

[@bs.send] external childFrames: t => array(t) = "childFrames";

/** Promise of the frame's default execution context. */
[@bs.send]
external executionContext: t => Js.Promise.t(ExecutionContext.t) =
  "executionContext";

/** Array of execution contexts associated with the frame. */
[@bs.send]
external executionContexts: t => array(ExecutionContext.t) =
  "executionContexts";

[@bs.send] external isDetached: t => bool = "isDetached";

[@bs.send] external name: t => string = "name";

[@bs.send] [@bs.return nullable]
external parentFrame: t => option(t) = "parentFrame";

[@bs.send]
external injectFile: (t, ~filePath: string) => Js.Promise.t(unit) =
  "injectFile";
