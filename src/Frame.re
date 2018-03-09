include FrameBase;

[@bs.get] external childFrames : t => array(t) = "";

[@bs.get] external isDetached : t => bool = "";

[@bs.get] external name : t => string = "";

[@bs.get] external parentFrame : t => t = ""; /* TODO: can be undefined as well */

[@bs.send.pipe: t]
external addScriptTag : (~url: string) => Js.Promise.t(unit) = "";

[@bs.send.pipe: t]
external injectFile : (~filePath: string) => Js.Promise.t(unit) = "";
