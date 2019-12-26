type t = Types.request;

type headers = Js.Dict.t(string);

[@bs.deriving jsConverter]
type method = [ | `GET | `POST | `PATCH | `PUT | `DELETE | `OPTIONS];

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

[@bs.send]
external abort:
  (
    t,
    ~errorCode: [@bs.string] [
                  | `aborted
                  | `accessdenied
                  | `addressunreachable
                  | `blockedbyclient
                  | `blockedbyresponse
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
  "abort";

module Overrides = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    url: string,
    [@bs.optional] [@bs.as "method"]
    requestMethod: string,
    [@bs.optional]
    postData: string,
    [@bs.optional]
    headers,
  };

  let make = (~url=?, ~method_=?, ~postData=?, ~headers=?, ()) => {
    let requestMethod = method_->Belt.Option.map(method_ToJs);
    t(~url?, ~requestMethod?, ~postData?, ~headers?, ());
  };
};

type overrides = Overrides.t;

[@bs.send]
external continue: (t, ~overrides: overrides=?, unit) => Js.Promise.t(unit) =
  "continue";

[@bs.send] [@bs.return nullable]
external failure: t => option({. "errorText": string}) = "failure";

[@bs.send] [@bs.return nullable]
external frame: t => option(FrameBase.t) = "frame";

[@bs.send] external headers: t => headers = "headers";

[@bs.send] external isNavigationRequest: t => bool = "isNavigationRequest";

[@bs.send] external method_: t => string = "method";

[@bs.send] [@bs.return nullable]
external postData: t => option(string) = "postData";

/**
 * The chain of requests initiated to fetch a resource. If there were no
 * redirects the chain will be empty.
 */
[@bs.send]
external redirectChain: t => array(t) = "redirectChain";

/**
 * The request's resource type as it was perceived by the rendering engine.
 * ResourceType will be one of the following:
 * document, stylesheet, image, media, font, script, texttrack, xhr, fetch,
 * eventsource, websocket, manifest, other.
 */
[@bs.send]
external resourceType: t => string = "resourceType";

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
  /* TODO: body can also be a string */
  "body": Js.undefined(Js_typed_array.ArrayBuffer.t),
};

[@bs.obj]
external makeRespondOptions:
  (
    ~status: float=?,
    ~headers: headers=?,
    ~contentType: string=?,
    ~body: Js_typed_array.ArrayBuffer.t=?,
    unit
  ) =>
  respondOptions =
  "";

[@bs.send]
external respond: (t, respondOptions) => Js.Promise.t(unit) = "respond";

[@bs.send] [@bs.return nullable]
external response: t => option(Types.response) = "response";

[@bs.send] external url: t => string = "url";
