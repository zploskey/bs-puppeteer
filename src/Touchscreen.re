type t;

[@bs.send]
external tap: (t, ~x: float, ~y: float) => Js.Promise.t(unit) = "tap";
