include EventEmitter;

[@bs.send] external detach : t => Js.Promise.t(unit) = "";

[@bs.send]
external send : (t, string, Js.t({..})) => Js.Promise.t(Js.t({..})) = "";
