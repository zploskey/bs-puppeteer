type t;

type revisionInfo = {
  .
  "revision": string,
  "folderPath": string,
  "executablePath": string,
  "url": string,
  "local": Js.boolean,
};

external empty : unit => t = "%identity";

[@bs.send]
external canDownload : (t, string) => Js.Promise.t(Js.boolean) = "";

[@bs.send]
external download :
  (t, string, Js.Undefined.t((float, float) => unit)) =>
  Js.Promise.t(revisionInfo) =
  "";

let download =
    (~revision, ~progressCallback=?, t)
    : Js.Promise.t(revisionInfo) =>
  download(t, revision, progressCallback |> Js.Undefined.fromOption);

[@bs.send] external localRevisions : t => Js.Promise.t(array(string)) = "";

[@bs.deriving jsConverter]
type platform = [
  | [@bs.as "mac"] `Mac
  | [@bs.as "linux"] `Linux
  | [@bs.as "win32"] `Win32
  | [@bs.as "win64"] `Win64
];

/* Returns one of mac, linux, win32 or win64. */
[@bs.send] external platform : t => platform = "";

[@bs.send] external remove : (t, string) => Js.Promise.t(unit) = "";

[@bs.send]
external revisionInfo : (t, string) => Js.Promise.t(revisionInfo) = "";
