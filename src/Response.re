type t = Types.response;

/** Promise which resolves to a buffer with response body. */
[@bs.send]
external buffer: t => Js.Promise.t(Node.Buffer.t) = "buffer";

/**
 * The frame that initiated the response. Will be null if navigating to
 * error pages.
 */
[@bs.send]
external frame: t => Js.Null.t(Types.frame) = "frame";

/** If the response was served from the disk cache or memory cache. */
[@bs.send]
external fromCache: t => bool = "fromCache";

/** If the response was served by a service worker. */
[@bs.send]
external fromServiceWorker: t => bool = "fromServiceWorker";

/** HTTP headers associated with the response. Header names are lower-case. */
[@bs.send]
external headers: t => Js.Dict.t(string) = "headers";

/**
 * Promise which resolves to a JSON representation of response body.
 * Throws an exception if the response body is not parsable by JSON.parse.
 */
[@bs.send]
external json: t => Js.Promise.t(Js.Json.t) = "json";

/** True if the response was successful (status in the range 200-299). */
[@bs.send]
external ok: t => bool = "ok";

type remoteAddress = {
  .
  "ip": string,
  "port": int,
};

[@bs.send] external remoteAddress: t => remoteAddress = "remoteAddress";

/** A matching Request object. */
[@bs.send]
external request: t => Types.request = "request";

/** Security details if the response was received over the secure connection. */
[@bs.send] [@bs.return nullable]
external securityDetails: t => option(SecurityDetails.t) = "securityDetails";

/** The status code of the response. */
[@bs.send]
external status: t => int = "status";

/** The status text of the response. Typically success is "OK". */
[@bs.send]
external statusText: t => string = "statusText";

/** Promise which resolves to the text of the response body. */
[@bs.send]
external text: t => Js.Promise.t(string) = "text";

/** The url of the response. */ [@bs.send] external url: t => string = "url";
