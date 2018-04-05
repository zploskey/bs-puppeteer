type t;

[@bs.send] external listenerCount : (t, string) => int = "";

[@bs.send]
external on : (t, string, [@bs.uncurry] (unit => unit)) => unit = "";
