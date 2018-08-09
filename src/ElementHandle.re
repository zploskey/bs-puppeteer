type t = Types.elementHandle;

include JSHandle.Impl({
  type nonrec t = t;
});

external empty: unit => t = "%identity";

/* Overrides asElement of JSHandle. Guaranteed to return an ElementHandle. */
[@bs.send] external asElement: t => Types.elementHandle = "";

[@bs.send]
external boundingBox: t => Js.Promise.t(Js.Null.t(BoundingBox.t)) = "";

[@bs.send]
external boxModel: t => Js.Promise.t(Js.nullable(BoxModel.t)) = "";

let boxModel = handle =>
  boxModel(handle)
  |> Js.Promise.(then_(handle => Js.toOption(handle) |> resolve));

[@bs.send.pipe: t]
external click: (~options: Click.clickOptions=?, unit) => Js.Promise.t(unit) =
  "";

[@bs.send] external focus: t => Js.Promise.t(unit) = "";

[@bs.send] external hover: t => Js.Promise.t(unit) = "";

[@bs.send] external isIntersectingViewport: t => Js.Promise.t(bool) = "";

[@bs.send.pipe: t]
external press:
  (~key: string, ~options: Keyboard.options=?, unit) => Js.Promise.t(unit) =
  "";

[@bs.send.pipe: t]
external screenshot:
  (~options: Screenshot.options=?, unit) => Js.Promise.t(Node.Buffer.t) =
  "";

[@bs.send.pipe: t]
external selectOne: (~selector: string) => Js.Promise.t(Js.Null.t(t)) = "$";

[@bs.send.pipe: t]
external selectAll: (~selector: string) => Js.Promise.t(array(t)) = "$$";

[@bs.send.pipe: t]
external selectXPath: (~xpath: string) => Js.Promise.t(array(t)) = "$x";

[@bs.send] external tap: t => Js.Promise.t(unit) = "";

[@bs.send] external toString: t => string = "";

[@bs.send.pipe: t]
external type_:
  (~text: string, ~options: {. "delay": float}=?, unit) => Js.Promise.t(unit) =
  "type";

[@bs.send.pipe: t] [@bs.splice]
external uploadFile: (~filePaths: array(string)) => Js.Promise.t(unit) = "";

[@bs.send]
external contentFrame: t => Js.Promise.t(Js.Null.t(Types.frameBase)) = "";
