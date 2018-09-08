type t = Types.response;

/** Promise which resolves to a buffer with response body. */
[@bs.send]
external buffer: t => Js.Promise.t(Node.Buffer.t) = "";

/** If the response was served from the disk cache or memory cache. */
[@bs.send]
external fromCache: t => bool = "";

/** If the response was served by a service worker. */
[@bs.send]
external fromServiceWorker: t => bool = "";

/** HTTP headers associated with the response. Header names are lower-case. */
[@bs.send]
external headers: t => Js.Dict.t(string) = "";

/**
 * Promise which resolves to a JSON representation of response body.
 * Throws an exception if the response body is not parsable by JSON.parse.
 */
[@bs.send]
external json: t => Js.Promise.t(Js.Json.t) = "";

/** True if the response was successful (status in the range 200-299). */
[@bs.send]
external ok: t => bool = "";

/** A matching Request object. */
[@bs.send]
external request: t => Types.request = "";

/** Security details if the response was received over the secure connection. */
[@bs.send] [@bs.return nullable]
external securityDetails: t => option(SecurityDetails.t) = "";

/** The status code of the response. */
[@bs.send]
external status: t => int = "";

/** The status text of the response. Typically success is "OK". */
[@bs.send]
external statusText: t => string = "";

/** Promise which resolves to the text of the response body. */
[@bs.send]
external text: t => Js.Promise.t(string) = "";

/** The url of the response. */ [@bs.send] external url: t => string = "";
