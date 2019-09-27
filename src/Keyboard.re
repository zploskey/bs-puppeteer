type t;

type options = {
  .
  "text": Js.nullable(string),
  "delay": Js.nullable(float),
};

[@bs.obj]
external makeOptions: (~text: string=?, ~delay: float=?, unit) => options = "";

[@bs.send]
external down:
  (t, ~key: string, ~options: options=?, unit) => Js.Promise.t(unit) =
  "down";

[@bs.send]
external press:
  (t, ~key: string, ~options: options=?, unit) => Js.Promise.t(unit) =
  "press";

[@bs.send]
external sendCharacter: (t, string) => Js.Promise.t(unit) = "sendCharacter";

[@bs.send]
external type_:
  (t, ~text: string, ~options: options=?, unit) => Js.Promise.t(unit) =
  "type";

[@bs.send] external up: (t, string) => Js.Promise.t(unit) = "up";
