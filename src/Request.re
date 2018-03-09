type t = RequestResponse.request;

type response = RequestResponse.response;

type headers = Js.Dict.t(string);

type resourceType =
  | Document
  | Stylesheet
  | Image
  | Media
  | Font
  | Script
  | TextTrack
  | XHR
  | Fetch
  | EventSource
  | WebSocket
  | Manifest
  | Other;

type overrides = {
  .
  url: Js.Nullable.t(string),
  method_: Js.Nullable.t(string),
  postData: Js.Nullable.t(string),
  headers: Js.Nullable.t(headers),
};

[@bs.obj]
external makeOverrides :
  (
    ~url: string=?,
    ~method_: [@bs.string] [
                | `GET
                | `POST
                | `PATCH
                | `PUT
                | `DELETE
                | `OPTIONS
              ]
                =?,
    ~postData: string=?,
    ~headers: headers=?,
    unit
  ) =>
  overrides =
  "";

[@bs.send.pipe: t]
external abort :
  (
    ~errorCode: [@bs.string] [
                  | `aborted
                  | `accessdenied
                  | `addressunreachable
                  | `connectionaborted
                  | `connectionclosed
                  | `connectionfailed
                  | `connectionrefused
                  | `connectionreset
                  | `internetdisconnected
                  | `namenotresolved
                  | `timedout
                  | `failed
                ]
                  =?,
    unit
  ) =>
  Js.Promise.t(unit) =
  "";

[@bs.send.pipe: t]
external continue : (~overrides: overrides=?, unit) => Js.Promise.t(unit) =
  "";

[@bs.send] [@bs.return nullable]
external failure : t => option({. "errorText": string}) = "";

[@bs.send] [@bs.return nullable]
external frame : t => option(FrameBase.t) = "";

[@bs.send] external headers : t => headers = "";

[@bs.send] external method_ : t => string = "";

[@bs.send] [@bs.return nullable] external postData : t => option(string) = "";

/**
 * The request's resource type as it was perceived by the rendering engine.
 * ResourceType will be one of the following:
 * document, stylesheet, image, media, font, script, texttrack, xhr, fetch,
 * eventsource, websocket, manifest, other.
 */
[@bs.send]
external resourceType : t => string = "";

let resourceType = req =>
  switch (resourceType(req)) {
  | "document" => Document
  | "stylesheet" => Stylesheet
  | "image" => Image
  | "media" => Media
  | "font" => Font
  | "script" => Script
  | "texttrack" => TextTrack
  | "xhr" => XHR
  | "fetch" => Fetch
  | "eventsource" => EventSource
  | "websocket" => WebSocket
  | "manifest" => Manifest
  | "other" => Other
  | _ as s => Js.Exn.raiseError("Unknown resource type received:" ++ s)
  };

type respondOptions = {
  .
  "status": Js.undefined(float),
  "headers": Js.undefined(headers),
  "contentType": Js.undefined(string),
  "body": Js.undefined(Js_typed_array.ArrayBuffer.t),
};

[@bs.obj]
external makeRespondOptions :
  (
    ~status: float=?,
    ~headers: headers=?,
    ~contentType: string=?,
    ~body: Js_typed_array.ArrayBuffer.t=?,
    unit
  ) =>
  respondOptions =
  "";

[@bs.send.pipe: t]
external respond : respondOptions => Js.Promise.t(unit) = "";

[@bs.send] [@bs.return nullable]
external response : t => option(response) = "";

[@bs.send] external url : t => string = "";
