type t = Types.elementHandle;

include
  JSHandle.Impl(
    {
      type nonrec t = t;
    },
  );

external empty : unit => t = "%identity";

[@bs.send.pipe: t]
external selectOne : (~selector: string) => Js.Promise.t(Js.Nullable.t(t)) =
  "$";

[@bs.send.pipe: t]
external selectAll : (~selector: string) => Js.Promise.t(array(t)) = "$$";

[@bs.send.pipe: t]
external selectXPath : (~xpath: string) => Js.Promise.t(array(t)) = "$x";

[@bs.send.pipe: t]
external boundingBox : Js.Promise.t(Js.Nullable.t(BoundingBox.t)) = "";

[@bs.send.pipe: t]
external click : (~options: Click.clickOptions=?, unit) => Js.Promise.t(unit) =
  "";

[@bs.send] external focus : t => Js.Promise.t(unit) = "";

[@bs.send.pipe: t] external hover : Js.Promise.t(unit) = "";

[@bs.send.pipe: t]
external press :
  (~key: string, ~options: Keyboard.options=?, unit) => Js.Promise.t(unit) =
  "";

[@bs.send.pipe: t]
external screenshot :
  (~options: Screenshot.options=?, unit) =>
  Js.Promise.t(Js.Typed_array.ArrayBuffer.t) =
  "";

[@bs.send.pipe: t] external tap : Js.Promise.t(unit) = "";

[@bs.send.pipe: t] external toString : string = "";

[@bs.send.pipe: t]
external type_ :
  (~text: string, ~options: {. "delay": float}=?, unit) => Js.Promise.t(unit) =
  "type";

[@bs.send.pipe: t] [@bs.splice]
external uploadFile : (~filePaths: array(string)) => Js.Promise.t(unit) = "";

[@bs.send.pipe: t]
external contentFrame : Js.Promise.t(Js.Nullable.t(Types.frameBase)) = "";
