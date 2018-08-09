type t;

type options = {
  .
  "text": Js.nullable(string),
  "delay": Js.nullable(float),
};

[@bs.obj]
external makeOptions: (~text: string=?, ~delay: float=?, unit) => options = "";

[@bs.send.pipe: t]
external down: (~key: string, ~options: options=?, unit) => Js.Promise.t(unit) =
  "";

[@bs.send.pipe: t]
external press:
  (~key: string, ~options: options=?, unit) => Js.Promise.t(unit) =
  "";

[@bs.send.pipe: t] external sendCharacter: string => Js.Promise.t(unit) = "";

[@bs.send.pipe: t]
external type_:
  (~text: string, ~options: options=?, unit) => Js.Promise.t(unit) =
  "type";

[@bs.send.pipe: t] external up: string => Js.Promise.t(unit) = "";
