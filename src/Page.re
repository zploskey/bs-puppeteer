include FrameBase;

external empty: unit => t = "%identity";

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
  "url": Js.undefined(string),
  "domain": Js.undefined(string),
  "path": Js.undefined(string),
  "expires": Js.undefined(float),
  "httpOnly": Js.undefined(bool),
  "secure": Js.undefined(bool),
  "session": Js.undefined(bool),
  "sameSite": Js.undefined(string),
};

type viewport = Viewport.t;

type emulateOptions = {
  .
  "viewport": viewport,
  "userAgent": string,
};

[@ocaml.deprecated "emulateOption has been renamed emulateOptions"]
type emulateOption = emulateOptions;

type margin = {
  .
  "top": Js.undefined(Unit.t),
  "right": Js.undefined(Unit.t),
  "bottom": Js.undefined(Unit.t),
  "left": Js.undefined(Unit.t),
};

type pdfOptions = {
  .
  "path": Js.undefined(string),
  "scale": Js.undefined(float),
  "displayHeaderFooter": Js.undefined(bool),
  "headerTemplate": Js.undefined(string),
  "footerTemplate": Js.undefined(string),
  "printBackground": Js.undefined(bool),
  "landscape": Js.undefined(bool),
  "pageRanges": Js.undefined(string),
  "format": Js.undefined(string),
  "width": Js.undefined(Unit.t),
  "height": Js.undefined(Unit.t),
  "margin": Js.undefined(margin),
  "preferCSSPageSize": Js.undefined(bool),
};

[@bs.obj]
external makeCookie:
  (
    ~name: string,
    ~value: string,
    ~url: string=?,
    ~domain: string=?,
    ~path: string=?,
    ~expires: float=?,
    ~httpOnly: bool=?,
    ~secure: bool=?,
    ~sameSite: [@bs.string] [ | `Strict | `Lax]=?,
    unit
  ) =>
  cookie =
  "";

[@bs.obj]
external makeMargin:
  (
    ~top: Unit.t=?,
    ~right: Unit.t=?,
    ~bottom: Unit.t=?,
    ~left: Unit.t=?,
    unit
  ) =>
  margin =
  "";

[@bs.obj]
external makePDFOptions:
  (
    ~path: string=?,
    ~scale: float=?,
    ~displayHeaderFooter: bool=?,
    ~headerTemplate: string=?,
    ~footerTemplate: string=?,
    ~printBackground: bool=?,
    ~landscape: bool=?,
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
    ~margin: margin=?,
    ~preferCSSPageSize: bool=?,
    unit
  ) =>
  pdfOptions =
  "";

[@bs.send.pipe: t]
external authenticate: Js.Null.t(authOptions) => Js.Promise.t(unit) = "";

/** Bring the page to front (activate the tab). */
[@bs.send]
external bringToFront: t => Js.Promise.t(unit) = "";

[@bs.send] external browser: t => Types.browser = "";

type closeOptions = {. "runBeforeUnload": Js.nullable(bool)};

[@bs.obj]
external makeCloseOptions: (~runBeforeUnload: bool=?, unit) => closeOptions =
  "";

[@bs.send.pipe: t]
external close: (~options: closeOptions=?) => Js.Promise.t(unit) = "";

[@bs.get] external coverage: t => Coverage.t = "";

/* TODO: versions handling args */
[@bs.send.pipe: t]
external evaluateOnNewDocument: (unit => unit) => Js.Promise.t(unit) = "";

/* TODO: exposeFunction */

/** Array of all frames attached to the page. */
[@bs.send]
external frames: t => array(Frame.t) = "";

[@bs.send] external setContent: (t, string) => Js.Promise.t(unit) = "";

[@bs.send]
external goBack:
  (t, ~options: Navigation.options=?, unit) =>
  Js.Promise.t(Js.null(Response.t)) =
  "";

[@bs.send]
external goForward:
  (t, ~options: Navigation.options=?, unit) =>
  Js.Promise.t(Js.null(Response.t)) =
  "";

[@bs.send]
external goto:
  (t, string, ~options: Navigation.options=?, unit) =>
  Js.Promise.t(Js.null(Response.t)) =
  "";

[@bs.send] external isClosed: t => bool = "";

/** The page's virtual keyboard. */
[@bs.get]
external keyboard: t => Keyboard.t = "";

/**
 * The main Frame that a page is guaranteed to have which persists during
 * navigation.
 */
[@bs.send]
external mainFrame: t => Frame.t = "";

/** Gets the page metrics. */
[@bs.send]
external metrics: t => Js.Promise.t(Metrics.t) = "";

/** Get the page's virtual mouse. */
[@bs.get]
external mouse: t => Mouse.t = "";

[@bs.send]
external screenshot:
  (t, ~options: Screenshot.options=?, unit) => Js.Promise.t(Node.Buffer.t) =
  "";

[@bs.send]
external setExtraHTTPHeaders:
  (t, ~headers: Js.Dict.t(string), unit) => Js.Promise.t(unit) =
  "";

[@bs.send] [@bs.splice]
external deleteCookie: (t, array(cookie)) => Js.Promise.t(unit) = "";

[@bs.send] [@bs.splice]
external cookies: (t, array(string)) => Js.Promise.t(array(cookie)) = "";

[@bs.send] [@bs.splice]
external setCookie: (t, array(cookie)) => Js.Promise.t(unit) = "";

[@bs.send] external emulate: (t, emulateOptions) => Js.Promise.t(unit) = "";

[@bs.send] [@bs.return nullable]
external viewport: t => option(viewport) = "";

[@bs.send]
external emulateMedia:
  (t, [@bs.string] [ | `screen | `print]) => Js.Promise.t(unit) =
  "";

[@bs.send]
external emulateMediaDisable:
  (t, [@bs.as {json|null|json}] _) => Js.Promise.t(unit) =
  "emulateMedia";

[@bs.send] external pdf: (t, pdfOptions) => Js.Promise.t(Node.Buffer.t) = "";

/* TODO:
      external on
      external once
   */
/** Iterates the JS heap finding all the objects with the given prototype. */
[@bs.send]
external queryObjects:
  (t, ~prototypeHandle: JSHandle.t) => Js.Promise.t(JSHandle.t) =
  "";

/** Reload the current page. */
[@bs.send]
external reload:
  (t, ~options: Navigation.options=?, unit) => Js.Promise.t(Response.t) =
  "";

/**
 * Toggles ignoring cache for each request based on the enabled state.
 * Caching is enabled by default.
 */
[@bs.send]
external setCacheEnabled: (t, ~enabled: bool) => Js.Promise.t(unit) = "";

/**
 * Change the default maximum navigation time of 30 seconds for the following:
 * - `Page.goto`
 * - `Page.goBack`
 * - `Page.goForward`
 * - `Page.reload`
 * - `Page.waitForNavigation`
 */
[@bs.send]
external setDefaultNavigationTimeout: (t, ~timeout: float) => unit = "";

/** Set whether to enable JavaScript on the page. */
[@bs.send]
external setJavaScriptEnabled: (t, ~enabled: bool) => Js.Promise.t(unit) = "";

/** Set whether to enable offline mode for the page. */
[@bs.send]
external setOfflineMode: (t, ~enabled: bool) => Js.Promise.t(unit) = "";

/** Set whether to enable request interception for the page. */
[@bs.send]
external setRequestInterception: (t, ~enabled: bool) => Js.Promise.t(unit) =
  "";

[@bs.send]
external setUserAgent: (t, ~userAgent: string) => Js.Promise.t(unit) = "";

/** Toggle bypassing page's Content-Security-Policy. */
[@bs.send]
external setBypassCSP: (t, ~enabled: bool) => Js.Promise.t(unit) = "";

let setBypassCSP = (~enabled, page) => setBypassCSP(page, ~enabled);

[@bs.send]
external setViewport: (t, ~viewport: viewport) => Js.Promise.t(unit) = "";

[@bs.send] external target: t => Types.target = "";

[@bs.send] external title: t => Js.Promise.t(string) = "";

[@bs.get] external touchscreen: t => Touchscreen.t = "";

[@bs.get] external tracing: t => Tracing.t = "";

[@bs.send]
external waitForNavigation:
  (t, ~options: Navigation.options) => Js.Promise.t(Js.nullable(Response.t)) =
  "";

let waitForNavigation = (page, ~options) =>
  waitForNavigation(page, ~options)
  |> Js.Promise.(then_(response => response |> Js.toOption |> resolve));

module WaitForRequest = {
  [@bs.deriving abstract]
  type options = {
    [@bs.optional]
    timeout: float,
  };

  [@bs.send]
  external waitForRequest:
    (t, Request.t => bool, ~options: options=?, unit) =>
    Js.Promise.t(Request.t) =
    "";

  [@bs.send]
  external waitForRequestRe:
    (t, Request.t => Js.Re.t, ~options: options=?, unit) =>
    Js.Promise.t(Request.t) =
    "waitForRequest";

  [@bs.send]
  external waitForRequestUrl:
    (t, string, ~options: options=?, unit) => Js.Promise.t(Request.t) =
    "waitForRequest";
};

module WaitForResponse = {
  [@bs.deriving abstract]
  type options = {
    [@bs.optional]
    timeout: float,
  };

  [@bs.send]
  external waitForResponse:
    (t, Response.t => bool, ~options: options=?, unit) =>
    Js.Promise.t(Response.t) =
    "";

  [@bs.send]
  external waitForResponseRe:
    (t, Response.t => Js.Re.t, ~options: options=?, unit) =>
    Js.Promise.t(Response.t) =
    "waitForResponse";

  [@bs.send]
  external waitForResponseUrl:
    (t, string, ~options: options=?, unit) => Js.Promise.t(Response.t) =
    "waitForResponse";
};

let waitForRequest = WaitForRequest.waitForRequest;
let waitForRequestRe = WaitForRequest.waitForRequestRe;
let waitForRequestUrl = WaitForRequest.waitForRequestUrl;
let waitForResponse = WaitForResponse.waitForResponse;
let waitForResponseRe = WaitForResponse.waitForResponseRe;
let waitForResponseUrl = WaitForResponse.waitForResponseUrl;

[@bs.send] external workers: t => array(Worker.t) = "";
