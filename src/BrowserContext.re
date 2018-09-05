type t;

[@bs.deriving jsConverter]
type permission = [
  | `geolocation
  | `midi
  | `notifications
  | `push
  | `camera
  | `microphone
  | [@bs.as "background-sync"] `backgroundSync
  | [@bs.as "ambient-light-sensor"] `ambientLightSensor
  | `accelerometer
  | `gyroscope
  | `magnetometer
  | [@bs.as "accesibilityEvents"] `accessibilityEvents
  | [@bs.as "clipboard-read"] `clipboardRead
  | [@bs.as "clipboard-write"] `clipboardWrite
  | [@bs.as "payment-handler"] `paymentHandler
  | [@bs.as "midi-sysex"] `midiSysex
];

[@bs.send] external browser: t => Types.browser = "";

/** Clear permission overrides for the browser context. */
[@bs.send]
external clearPermissionOverrides: t => Js.Promise.t(unit) = "";

[@bs.send] external close: t => Js.Promise.t(unit) = "";

[@bs.send] external isIncognito: t => bool = "";

[@bs.send] external newPage: t => Js.Promise.t(Page.t) = "";

[@bs.send]
external overridePermissionsUnsafe:
  (t, ~origin: string, ~permissions: array(string)) => Js.Promise.t(unit) =
  "";

/** Grant permissions for an origin. All other permissions will be denied. */
let overridePermissions = (ctx, ~origin, ~permissions) => {
  let permissions = Array.map(permissionToJs, permissions);
  overridePermissionsUnsafe(ctx, ~origin, ~permissions);
};

[@bs.send] external pages: t => Js.Promise.t(array(Page.t)) = "";

[@bs.send] external targets: t => array(Types.target) = "";
