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

type authOptions = {
  .
  "username": string,
  "password": string,
};

type cookie = {
  .
  "name": string,
  "value": string,
  "domain": Js.undefined(string),
  "url": Js.undefined(string),
  "path": Js.undefined(string),
  "expires": Js.undefined(float),
  "httpOnly": Js.undefined(Js.boolean),
  "secure": Js.undefined(Js.boolean),
  "session": Js.undefined(Js.boolean),
  "sameSite": Js.undefined(string),
};

type viewport = {
  .
  "width": int,
  "height": int,
  "deviceScaleFactor": int,
  "isMobile": Js.boolean,
  "hasTouch": Js.boolean,
  "isLandscape": Js.boolean,
};

type emulateOption = {
  .
  "viewport": viewport,
  "userAgent": string,
};

[@bs.obj]
external makeCookie :
  (
    ~name: string,
    ~value: string,
    ~domain: string=?,
    ~url: string=?,
    ~path: string=?,
    ~expires: float=?,
    ~httpOnly: Js.boolean=?,
    ~secure: Js.boolean=?,
    ~session: Js.boolean=?,
    ~sameSite: string=?,
    unit
  ) =>
  _ =
  "";

[@bs.send.pipe: t]
external authenticate : Js.Null.t(authOptions) => Js.Promise.t(unit) = "";

[@bs.send.pipe: t]
external click :
  (string, ~options: Click.clickOptions=?, unit) => Js.Promise.t(unit) =
  "";

[@bs.send.pipe: t] external close : Js.Promise.t(unit) = "";

[@bs.send] external content : t => Js.Promise.t(string) = "";

[@bs.send.pipe: t] external setContent : string => Js.Promise.t(unit) = "";

[@bs.send.pipe: t]
external goBack :
  (~options: Navigation.options=?, unit) => Js.Promise.t(Js.null(Response.t)) =
  "";

[@bs.send.pipe: t]
external goForward :
  (~options: Navigation.options=?, unit) => Js.Promise.t(Js.null(Response.t)) =
  "";

[@bs.send.pipe: t]
external goto :
  (string, ~options: Navigation.options=?, unit) =>
  Js.Promise.t(Js.null(Response.t)) =
  "";

[@bs.send.pipe: t]
external screenshot :
  (~options: Screenshot.options=?, unit) =>
  Js.Promise.t(Js.Typed_array.ArrayBuffer.t) =
  "";

[@bs.send.pipe: t]
external setExtraHTTPHeaders :
  (~headers: Js.Dict.t(string), unit) => Js.Promise.t(unit) =
  "";

type typeOptions = {. "delay": float};

[@bs.send.pipe: t]
external type_ :
  (string, string, ~options: typeOptions=?, unit) => Js.Promise.t(unit) =
  "type";

[@bs.send.pipe: t] [@bs.splice]
external deleteCookie : array(cookie) => Js.Promise.t(unit) = "";

[@bs.send.pipe: t] [@bs.splice]
external cookies : array(string) => Js.Promise.t(array(cookie)) = "";

[@bs.send.pipe: t] [@bs.splice]
external setCookie : array(cookie) => Js.Promise.t(unit) = "";

[@bs.send.pipe: t]
external emulate : emulateOption => Js.Promise.t(unit) = "";

[@bs.send.pipe: t] external viewport : unit => viewport = "";

[@bs.send.pipe: t]
external emulateMedia :
  ([@bs.string] [ | `screen | `print]) => Js.Promise.t(unit) =
  "";

[@bs.send.pipe: t]
external emulateMediaDisable :
  ([@bs.as {json|null|json}] _) => Js.Promise.t(unit) =
  "emulateMedia";
