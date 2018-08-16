type t;

/* Possibly useful for handling button preferences, but currently unused. */
type mouseButton =
  | Left
  | Right
  | Middle;

/* TODO: handle options "left", "right", "middle" only */
type mousePressOptions = {
  .
  "button": Js.Nullable.t(string),
  "clickCount": int,
};

[@bs.send]
external click:
  (t, ~x: float, ~y: float, ~options: Click.clickOptions=?, unit) =>
  Js.Promise.t(unit) =
  "";

[@bs.send]
external down: (t, ~options: mousePressOptions=?, unit) => Js.Promise.t(unit) =
  "";

type moveOptions = {. "steps": int};

[@bs.send]
external move:
  (t, ~x: float, ~y: float, ~options: moveOptions=?, unit) =>
  Js.Promise.t(unit) =
  "";

[@bs.send]
external up: (t, ~options: mousePressOptions=?, unit) => Js.Promise.t(unit) =
  "";
