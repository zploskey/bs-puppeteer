type t;

[@bs.send] external detach: t => Js.Promise.t(unit) = "detach";

[@bs.send]
external send:
  (t, string, ~params: Js.t({..})=?, unit) => Js.Promise.t(Js.t({..})) =
  "send";
