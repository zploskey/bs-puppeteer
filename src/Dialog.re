type t;

[@bs.deriving jsConverter]
type dialogType = [ | `alert | `beforeunload | `confirm | `prompt];

[@bs.send]
external accept: (t, ~promptText: string=?, unit) => Js.Promise.t(unit) =
  "accept";

[@bs.send] external defaultValue: t => string = "defaultValue";

[@bs.send] external dismiss: t => Js.Promise.t(unit) = "dismiss";

[@bs.send] external message: t => string = "message";

[@bs.send] external typeString: t => string = "type";

let type_ = dialog => dialogTypeFromJs(typeString(dialog));
