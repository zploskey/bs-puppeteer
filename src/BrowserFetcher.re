type t;

type revisionInfo = {
  .
  "revision": string,
  "folderPath": string,
  "executablePath": string,
  "url": string,
  "local": bool,
};

external empty: unit => t = "%identity";

[@bs.send] external canDownload: (t, string) => Js.Promise.t(bool) = "";

[@bs.send]
external download:
  (t, ~revision: string, ~progressCallback: (float, float) => unit=?, unit) =>
  Js.Promise.t(revisionInfo) =
  "";

[@bs.send] external localRevisions: t => Js.Promise.t(array(string)) = "";

[@bs.deriving jsConverter]
type platform = [ | `mac | `linux | `win32 | `win64];

[@bs.send] external platform: t => string = "";

let platform = t => platform(t) |> platformFromJs;

[@bs.send] external remove: (t, string) => Js.Promise.t(unit) = "";

[@bs.send] external revisionInfo: (t, string) => revisionInfo = "";
