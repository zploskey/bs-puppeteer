type t = Types.target;

external empty : unit => t = "%identity";

[@bs.deriving jsConverter]
type targetType = [
  | `page
  | `background_page
  | `service_worker
  | `browser
  | `other
];

[@ocaml.deprecated "pageType has been renamed to targetType"]
type pageType = targetType;

[@ocaml.deprecated "pageTypeToJs has been renamed to targetTypeToJs"]
let pageTypeToJs = targetTypeToJs;

[@ocaml.deprecated "pageTypeFromJs has been renamed to targetTypeFromJs"]
let pageTypeFromJs = targetTypeFromJs;

[@bs.send] external browser : t => Types.browser = "";

/* TODO: browserContext() */

[@bs.send] external createCDPSession : t => Js.Promise.t(CDPSession.t) = "";

/** Target that opened this target. Top-level targets don't have an opener. */
[@bs.send]
[@bs.return nullable]
external opener : t => option(t) = "";

[@bs.send] external page : t => Js.Promise.t(Js.Nullable.t(Page.t)) = "";

[@bs.send] external typeString : t => string = "type";

let type_ = t => t |> typeString |> targetTypeFromJs;

[@bs.send] external url : t => string = "";
