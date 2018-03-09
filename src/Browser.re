type t;

external empty : unit => t = "%identity";

[@bs.send.pipe: t] external close : Js.Promise.t(unit) = "";

[@bs.send.pipe: t] external newPage : Js.Promise.t(Page.t) = "";

[@bs.send.pipe: t] external version : Js.Promise.t(string) = "";

[@bs.send.pipe: t] external wsEndpoint : string = "";

[@bs.send.pipe: t] external userAgent : Js.Promise.t(string) = "";
