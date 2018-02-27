type t;

[@bs.send.pipe : t] external boundingBox : Js.Promise.t(Js.null(BoundingBox.t)) = "";

[@bs.send.pipe : t] external click : (~options: Click.clickOptions=?, unit) => Js.Promise.t(unit) =
  "";

[@bs.send.pipe : t] external dispose : Js.Promise.t(unit) = "";

[@bs.send.pipe : t] external hover : Js.Promise.t(unit) = "";

[@bs.send.pipe : t] external tap : Js.Promise.t(unit) = "";

[@bs.send.pipe : t] external uploadFile : (~filePaths: array(string)) => Js.Promise.t(unit) = "";

[@bs.send.pipe : t] external toString : string = "";

[@bs.send] external jsonValue : t => Js.Promise.t(Js.t({..})) = "";

