include JSHandle;

/* TODO: $, $$, $x */
[@bs.send.pipe : t]
external boundingBox : Js.Promise.t(Js.null(BoundingBox.t)) = "";

[@bs.send.pipe : t]
external click : (~options: Click.clickOptions=?, unit) => Js.Promise.t(unit) =
  "";

[@bs.send] external focus : t => Js.Promise.t(unit) = "";

[@bs.send.pipe : t] external hover : Js.Promise.t(unit) = "";

[@bs.send.pipe : t]
external press :
  (~key: string, ~options: Keyboard.options=?, unit) => Js.Promise.t(unit) =
  "";

[@bs.send.pipe : t]
external screenshot :
  (~options: Screenshot.options=?, unit) =>
  Js.Promise.t(Js.Typed_array.ArrayBuffer.t) =
  "";

[@bs.send.pipe : t] external tap : Js.Promise.t(unit) = "";

[@bs.send.pipe : t] external toString : string = "";

[@bs.send.pipe : t]
external type_ :
  (~text: string, ~options: {. "delay": float}=?, unit) => Js.Promise.t(unit) =
  "type";

[@bs.send.pipe : t] [@bs.splice]
external uploadFile : (~filePaths: array(string)) => Js.Promise.t(unit) = "";
