module Event = {
  type t('e, 'v) = ..;
  type t(_, _) +=
    | NewListener: t([> | `EventEmitter], string)
    | RemoveListener: t([> | `EventEmitter], string);
};

module Listener = {
  type t('v) = 'v => unit;

  [@bs.get] external name: t('v) => string = "name";
};

module Emitter = {
  type t('e) = ..;

  [@bs.module "events"] [@bs.new] external make: unit => t('e) = "default";

  [@bs.send]
  external addListener: (t('e), Event.t('e, 'v), Listener.t('v)) => t('e) =
    "";

  [@bs.send] [@bs.splice]
  external emit: (t('e), Event.t('e, 'v), array('a)) => unit = "";

  [@bs.send] external getMaxListeners: t('e) => int = "";

  [@bs.send] external listenerCount: (t('e), Event.t('e, 'v)) => int = "";

  [@bs.send]
  external listeners: (t('e), Event.t('e, 'v)) => array(Listener.t('v)) =
    "";

  [@bs.send] external on: (t('e), Event.t('e, 'v), 'a => unit) => unit = "";

  [@bs.send]
  external once: (t('e), Event.t('e, 'v), 'a => unit) => unit = "";

  [@bs.send]
  external prependListener:
    (t('e), Event.t('e, 'v), Listener.t('v)) => t('e) =
    "";

  [@bs.send]
  external prependOnceListener:
    (t('e), Event.t('e, 'v), Listener.t('v)) => t('e) =
    "";

  [@bs.send]
  external removeAllListeners:
    (t('e), Event.t('e, 'v), Listener.t('v)) => t('e) =
    "";

  [@bs.send]
  external removeListeners:
    (t('e), Event.t('e, 'v), Listener.t('v)) => t('e) =
    "";

  [@bs.send] external setMaxListeners: (t('e), int) => t('e) = "";
};
