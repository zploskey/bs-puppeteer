type t('a) = Types.elementHandle('a);

include JSHandle.Impl({
  type nonrec t('a) = t('a);
});

external empty: unit => t('a) = "%identity";

/* Overrides asElement of JSHandle. Guaranteed to return an ElementHandle. */
[@bs.send]
external asElement: t('a) => Types.elementHandle('a) = "asElement";

[@bs.send]
external boundingBox: t('a) => Js.Promise.t(Js.Null.t(BoundingBox.t)) =
  "boundingBox";

[@bs.send]
external boxModel: t('a) => Js.Promise.t(Js.nullable(BoxModel.t)) =
  "boxModel";

let boxModel = handle =>
  boxModel(handle)
  |> Js.Promise.(then_(handle => Js.toOption(handle) |> resolve));

[@bs.send]
external click:
  (t('a), ~options: Click.clickOptions=?, unit) => Js.Promise.t(unit) =
  "click";

[@bs.send] external focus: t('a) => Js.Promise.t(unit) = "focus";

[@bs.send] external hover: t('a) => Js.Promise.t(unit) = "hover";

[@bs.send]
external isIntersectingViewport: t('a) => Js.Promise.t(bool) =
  "isIntersectingViewport";

[@bs.send]
external press:
  (t('a), ~key: string, ~options: Keyboard.options=?, unit) =>
  Js.Promise.t(unit) =
  "press";

[@bs.send]
external screenshot:
  (t('a), ~options: Screenshot.options=?, unit) =>
  Js.Promise.t(Node.Buffer.t) =
  "screenshot";

[@bs.send]
external selectOne:
  (t('a), ~selector: string) => Js.Promise.t(Js.Null.t(t('b))) =
  "$";

[@bs.send]
external selectAll:
  (t('a), ~selector: string) => Js.Promise.t(array(t('b))) =
  "$$";

[@bs.send]
external selectXPath: (t('a), ~xpath: string) => Js.Promise.t(array(t('b))) =
  "$x";

[@bs.send] external tap: t('a) => Js.Promise.t(unit) = "tap";

[@bs.send] external toString: t('a) => string = "toString";

[@bs.send]
external type_:
  (t('a), ~text: string, ~options: {. "delay": float}=?, unit) =>
  Js.Promise.t(unit) =
  "type";

[@bs.send] [@bs.splice]
external uploadFile:
  (t('a), ~filePaths: array(string)) => Js.Promise.t(unit) =
  "uploadFile";

[@bs.send]
external contentFrame: t('a) => Js.Promise.t(Js.Null.t(Types.frameBase)) =
  "contentFrame";
