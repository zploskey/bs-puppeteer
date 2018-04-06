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
  "margin": Js.undefined(margin),
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
  cookie =
  "";

[@bs.obj]
external makeMargin :
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
    ~margin: margin=?,
    unit
  ) =>
  pdfOptions =
  "";

[@bs.send.pipe: t]
external authenticate : Js.Null.t(authOptions) => Js.Promise.t(unit) = "";

/** Bring the page to front (activate the tab).                    */
[@bs.send]
external bringToFront : t => Js.Promise.t(unit) = "";

[@bs.send.pipe: t]
external click :
  (string, ~options: Click.clickOptions=?, unit) => Js.Promise.t(unit) =
  "";

[@bs.send.pipe: t] external close : Js.Promise.t(unit) = "";

[@bs.send] external content : t => Js.Promise.t(string) = "";

[@bs.send] external coverage : t => Js.Promise.t(Coverage.t) = "";

/* TODO: versions handling args */
[@bs.send.pipe: t]
external evaluateOnNewDocument : (unit => unit) => Js.Promise.t(unit) = "";

/* TODO: exposeFunction */
[@bs.send.pipe: t]
external focus : (~selector: string) => Js.Promise.t(unit) = "";

/** Array of all frames attached to the page.                         */
[@bs.send]
external frames : t => array(Frame.t) = "";

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

/**
 * Fetches the first element matching `selector`, scrolls it into view if not
 * already visible, then hovers over the center of the element using
 * [Page.mouse]. Throws an error if no element matches `selector`.
 */
[@bs.send.pipe: t]
external hover : (~selector: string) => Js.Promise.t(unit) = "";

/** The page's virtual keyboard.                                    */
[@bs.get]
external keyboard : t => Keyboard.t = "";

/**
 * The main Frame that a page is guaranteed to have which persists during
 * navigation.
 */
[@bs.send]
external mainFrame : t => Frame.t = "";

/** Gets the page metrics.                                          */
[@bs.send]
external metrics : t => Js.Promise.t(Metrics.t) = "";

/** Get the virtual mouse.                                          */
[@bs.get]
external mouse : t => Mouse.t = "";

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

/* TODO: change return type to "Node.buffer" when its ready */
[@bs.send.pipe: t]
external pdf : pdfOptions => Js.Promise.t(Js_typed_array.ArrayBuffer.t) = "";

/* TODO:
      external on
      external once
   */
/** Iterates the JS heap finding all the objects with the given prototype. */
[@bs.send.pipe: t]
external queryObjects :
  (~prototypeHandle: JSHandle.t) => Js.Promise.t(JSHandle.t) =
  "";

/** Reload the current page.                               */
[@bs.send.pipe: t]
external reload :
  (~options: Navigation.options=?, unit) => Js.Promise.t(Response.t) =
  "";

/**
 * Selects options in a `<select>` tag. Triggers a `change` and `input` event
 * once all the provided options have been selected. If there's no `<select>`
 * element matching selector it throws an error.
 */
[@bs.send.pipe: t]
external select :
  (~selector: string, ~values: array(string)) => Js.Promise.t(array(string)) =
  "";

[@bs.send.pipe: t]
external setCacheEnabled : (~enabled: Js.boolean) => Js.Promise.t(unit) = "";

/**
 * Toggles ignoring cache for each request based on the enabled state.
 * Caching is enabled by default.
 */
let setCacheEnabled = (~enabled, ~page) =>
  page |> setCacheEnabled(~enabled=Js.Boolean.to_js_boolean(enabled));

/**
 * Change the default maximum navigation time of 30 seconds for the following:
 * - `Page.goto`
 * - `Page.goBack`
 * - `Page.goForward`
 * - `Page.reload`
 * - `Page.waitForNavigation`
 */
[@bs.send.pipe: t]
external setDefaultNavigationTimeout : (~timeout: float) => unit = "";

[@bs.send.pipe: t]
external setJavaScriptEnabled : (~enabled: Js.boolean) => Js.Promise.t(unit) =
  "";

/** Set whether to enable JavaScript on the page. */
let setJavaScriptEnabled = (~enabled, ~page) =>
  setJavaScriptEnabled(~enabled=Js.Boolean.to_js_boolean(enabled), page);

[@bs.send.pipe: t]
external setOfflineMode : (~enabled: Js.boolean) => Js.Promise.t(unit) = "";

/** Set whether to enable offline mode for the page. */
let setOfflineMode = (~enabled, ~page) =>
  setOfflineMode(~enabled=Js.Boolean.to_js_boolean(enabled), page);

[@bs.send.pipe: t]
external setRequestInterception : (~enabled: Js.boolean) => Js.Promise.t(unit) =
  "";

/** Set whether to enable request interception for the page. */
let setRequestInterception = (~enabled, ~page) =>
  setRequestInterception(~enabled=Js.Boolean.to_js_boolean(enabled), page);

[@bs.send.pipe: t]
external setUserAgent : (~userAgent: string) => Js.Promise.t(unit) = "";

[@bs.send.pipe: t]
external tap : (~selector: string) => Js.Promise.t(unit) = "";

[@bs.send] external target : t => Target.t = "";

[@bs.send] external title : t => Js.Promise.t(string) = "";

[@bs.get] external touchscreen : t => Touchscreen.t = "";

[@bs.get] external tracing : t => Tracing.t = "";

[@bs.send] external url : t => string = "";

[@bs.send.pipe: t]
external waitForNavigation :
  (~options: Navigation.options) => Js.Promise.t(Response.t) =
  "";
