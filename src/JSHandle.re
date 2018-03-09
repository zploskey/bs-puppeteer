type t = Types.jsHandle;

/* TODO:
 * Should be Js.null(ElementHandle.t) but these aren't currently distinct types.
 * This will more than likely cause problems. */
[@bs.send] external asElement : t => Js.null(t) = "";

[@bs.send] external dispose : t => Js.Promise.t(unit) = "";

[@bs.send] external executionContext : t => Types.executionContext = "";

[@bs.send]
external getProperties : t => Js.Promise.t(JSMap.t(string, t)) = "";

[@bs.send.pipe: t]
external getProperty : (~propertyName: string) => Js.Promise.t(t) = "";

[@bs.send] external jsonValue : t => Js.Promise.t(Js.t({..})) = "";
