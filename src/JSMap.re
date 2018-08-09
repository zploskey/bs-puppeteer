/** Module for using the JavaScript ES6 Map collection. */
/** Javascript's mutable Map collection. */
type t('key, 'value) =
  | JSMap('key, 'value);

/* TODO: can optionally take an iterable of key value pairs */
[@bs.new] external make: unit => t('key, 'value) = "Map";

[@bs.get] [@bs.return nullable]
external length: t('key, 'value) => option(int) = "";

[@bs.send] external clear: t('key, 'value) => unit = "";

[@bs.send] external delete: (t('key, 'value), 'key) => bool = "";

[@bs.send] [@bs.return nullable]
external get: (t('key, 'value), 'key) => option('value) = "";

[@bs.send] external has: (t('key, 'value), 'key) => bool = "";

[@bs.send]
external set: (t('key, 'value), 'key, 'value) => t('key, 'value) = "";

[@bs.send] external toString: t('key, 'value) => string = "";
/*
  TODO: bindings for
     entries https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Map/entries
     forEach https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Map/forEach
     keys    https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Map/keys
     values  https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Map/values
 */
