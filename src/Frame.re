include FrameBase;

[@bs.send] external childFrames: t => array(t) = "";

/** Promise of the frame's default execution context. */
[@bs.send]
external executionContext: t => Js.Promise.t(ExecutionContext.t) = "";

[@bs.send] external isDetached: t => bool = "";

[@bs.send] external name: t => string = "";

[@bs.send] [@bs.return nullable] external parentFrame: t => option(t) = "";

[@bs.send]
external injectFile: (t, ~filePath: string) => Js.Promise.t(unit) = "";
