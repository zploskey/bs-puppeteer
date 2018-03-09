/** [ConsoleMessage] sent by [Page] through the "console" event. */
type t;

/** The message arguments.                                                  */
[@bs.send]
external args : t => array(JSHandle.t) = "";

/** The message text.                                                       */
[@bs.send]
external text : t => string = "";

/** The type of console message.                                            */
[@bs.send]
external type_ :
  t =>
  [@bs.string] [
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
    | `assert_
    | `profile
    | `profileEnd
    | `count
    | `timeEnd
  ] =
  "type";
/* TODO: make sure `assert_ actually compiles to "assert" */
