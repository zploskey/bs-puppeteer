type t;

external empty : unit => t = "%identity";

[@bs.send] external close : t => Js.Promise.t(unit) = "";

[@bs.send] external disconnect : t => unit = "";

[@bs.send] external newPage : t => Js.Promise.t(Page.t) = "";

[@bs.send] external pages : t => Js.Promise.t(array(Page.t)) = "";

[@bs.send] external version : t => Js.Promise.t(string) = "";

[@bs.send] external wsEndpoint : t => string = "";

[@bs.send] external userAgent : t => Js.Promise.t(string) = "";
