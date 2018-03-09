/** [ConsoleMessage] sent by [Page] through the "console" event. */
type t;

/** The message arguments.                                                  */
[@bs.send]
external args : t => array(JSHandle.t) = "";

/** The message text.                                                       */
[@bs.send]
external text : t => string = "";

[@bs.deriving jsConverter]
type messageType = [
  | `log
  | `debug
  | `info
  | `error
  | `warning
  | `dir
  | `dirxml
  | `table
  | `trace
  | `clear
  | `startGroup
  | `startGroupCollapsed
  | `endGroup
  | [@bs.as "assert"] `assert_
  | `profile
  | `profileEnd
  | `count
  | `timeEnd
];

/** The type of console message as a string.                                 */
[@bs.send]
external typeString : t => string = "type";

/** The console message's [messageType]. */
let type_ = t => messageTypeFromJs(typeString(t));
