type t = Types.target;

external empty : unit => t = "%identity";

[@bs.deriving jsConverter]
type pageType = [ | `page | `service_worker | `browser | `other];

[@bs.send] external createCDPSession : t => Js.Promise.t(CDPSession.t) = "";

[@bs.send] external page : t => Js.Promise.t(Js.Nullable.t(Page.t)) = "";

[@bs.send] external typeString : t => string = "type";

let type_ = t => t |> typeString |> pageTypeFromJs;

[@bs.send] external url : t => string = "";
