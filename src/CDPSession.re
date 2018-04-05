include EventEmitter;

external empty : unit => t = "%identity";

[@bs.send] external detach : t => Js.Promise.t(unit) = "";

[@bs.send]
external send : (t, string, Js.t({..})) => Js.Promise.t(Js.t({..})) = "";
