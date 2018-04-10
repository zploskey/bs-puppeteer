type t;

[@bs.send] external detach : t => Js.Promise.t(unit) = "";

[@bs.send]
external send :
  (t, string, Js.Undefined.t(Js.t({..}))) => Js.Promise.t(Js.t({..})) =
  "";

let send = (~method_, ~params=?, t) =>
  send(t, method_, params |> Js.Undefined.fromOption);
