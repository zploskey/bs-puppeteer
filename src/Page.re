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

type boxModel = {
  .
  "top": Js.undefined(Unit.t),
  "right": Js.undefined(Unit.t),
  "bottom": Js.undefined(Unit.t),
  "left": Js.undefined(Unit.t),
};

type pdfOptions = {
  .
  "path": Js.undefined(string),
  "scale": Js.undefined(int),
  "displayHeaderFooter": Js.undefined(Js.boolean),
  "headerTemplate": Js.undefined(string),
  "footerTemplate": Js.undefined(string),
  "printBackground": Js.undefined(Js.boolean),
  "landscape": Js.undefined(Js.boolean),
  "pageRanges": Js.undefined(string),
  "format": Js.undefined(string),
  "width": Js.undefined(Unit.t),
  "height": Js.undefined(Unit.t),
  "margin": Js.undefined(boxModel),
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

[@bs.obj]
external makeBoxModel :
  (
    ~top: Unit.t=?,
    ~right: Unit.t=?,
    ~bottom: Unit.t=?,
    ~left: Unit.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.obj]
external makePDFOptions :
  (
    ~path: string=?,
    ~scale: int=?,
    ~displayHeaderFooter: Js.boolean=?,
    ~headerTemplate: string=?,
    ~footerTemplate: string=?,
    ~printBackground: Js.boolean=?,
    ~landscape: Js.boolean=?,
    ~pageRanges: string=?,
    ~format: [@bs.string] [
               | `Letter
               | `Legal
               | `Tabload
               | `Ledger
               | `A0
               | `A1
               | `A2
               | `A3
               | `A4
               | `A5
             ]
               =?,
    ~width: Unit.t=?,
    ~height: Unit.t=?,
    ~margin: boxModel=?,
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

[@bs.send.pipe: t]
external pdf : pdfOptions => Js.Promise.t(Js_typed_array.ArrayBuffer.t) = "";
