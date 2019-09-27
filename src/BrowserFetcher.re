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

[@bs.send]
external canDownload: (t, string) => Js.Promise.t(bool) = "canDownload";

[@bs.send]
external download:
  (t, ~revision: string, ~progressCallback: (float, float) => unit=?, unit) =>
  Js.Promise.t(revisionInfo) =
  "download";

[@bs.send]
external localRevisions: t => Js.Promise.t(array(string)) = "localRevisions";

[@bs.deriving jsConverter]
type platform = [ | `mac | `linux | `win32 | `win64];

[@bs.send] external platform: t => string = "platform";

let platform = t => platform(t) |> platformFromJs;

[@bs.send] external remove: (t, string) => Js.Promise.t(unit) = "remove";

[@bs.send] external revisionInfo: (t, string) => revisionInfo = "revisionInfo";
