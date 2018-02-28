include FrameBase;

external empty : unit => t = "%identity";

type pageEvents =
  | Console
  | Dialog
  | Error
  | FrameAttached
  | FrameDetached
  | FrameNavigated
  | Load
  | PageError
  | Request
  | RequestFailed
  | RequestFinished
  | Response;

type authOptions = {. "username": string, "password": string};

[@bs.send.pipe : t]
external click : (string, ~options: Click.clickOptions=?, unit) => Js.Promise.t(unit) =
  "";

[@bs.send.pipe : t] external close : Js.Promise.t(unit) = "";

[@bs.send] external content : t => Js.Promise.t(string) = "";

[@bs.send.pipe : t] external setContent : string => Js.Promise.t(unit) = "";

[@bs.send.pipe : t]
external goto : (string, ~options: Navigation.options=?, unit) => Js.Promise.t(Response.t) =
  "";

[@bs.send.pipe : t]
external screenshot :
  (~options: Screenshot.options=?, unit) => Js.Promise.t(Js.Typed_array.ArrayBuffer.t) =
  "";

[@bs.send.pipe : t]
external setExtraHTTPHeaders : (~headers: Js.Dict.t(string), unit) => Js.Promise.t(unit) =
  "";

type typeOptions = {. "delay": float};

[@bs.send.pipe : t]
external type_ : (string, string, ~options: typeOptions=?, unit) => Js.Promise.t(unit) =
  "type";
