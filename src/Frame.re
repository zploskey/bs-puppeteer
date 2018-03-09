include FrameBase;

[@bs.send] external childFrames : t => array(t) = "";

[@bs.send] external isDetached : t => bool = "";

[@bs.send] external name : t => string = "";

[@bs.send] [@bs.return nullable] external parentFrame : t => option(t) = "";

[@bs.send.pipe: t]
external addScriptTag : (~url: string) => Js.Promise.t(unit) = "";

[@bs.send.pipe: t]
external injectFile : (~filePath: string) => Js.Promise.t(unit) = "";
