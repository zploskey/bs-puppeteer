/* TODO: allow calling makeOptions with waitUntil: array(string), an array of load event */

[@bs.deriving jsConverter]
type loadEvent = [ | `load | `domcontentloaded | `networkidle0 | `networkidle2];

type loadEvents =
  | LoadEvent(loadEvent)
  | LoadEvents(array(loadEvent));

[@bs.obj]
external makeOptions :
  (
    ~timeout: float=?,
    ~waitUntil: [@bs.string] [ | `load | `domcontentloaded | `networkidle0 | `networkidle2]=?,
    unit
  ) =>
  _ =
  "";

type options = {. "timeout": Js.undefined(float), "waitUntil": Js.undefined(string)};
