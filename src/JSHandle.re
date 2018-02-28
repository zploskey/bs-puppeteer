type t;

/* Should be Js.null(ElementHandle.t) but these aren't currently distinct types.
 * I think this is ok? */
[@bs.send] external asElement : t => Js.null(t) = "";

[@bs.send] external dispose : t => Js.Promise.t(unit) = "";

/* TODO: executionContext */

[@bs.send] external getProperties : t => Js.Promise.t(Js.Dict.t(t)) = "";

[@bs.send.pipe : t]
external getProperty : (~propertyName: string) => Js.Promise.t(t) = "";

[@bs.send] external jsonValue : t => Js.Promise.t(Js.t({..})) = "";
