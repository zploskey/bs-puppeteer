type stringDict = Js.Dict.t(string);

module Keyboard = {
  type t;
  [@bs.send.pipe : t]
  external down : (string, ~options: stringDict=?, unit) => Js.Promise.t(unit) =
    "";
  [@bs.send.pipe : t] external sendCharacter : string => Js.Promise.t(unit) = "";
  [@bs.send.pipe : t] external up : string => Js.Promise.t(unit) = "";
};

/* Possibly useful for handling button preferences, but currently unused. */
type mouseButton =
  | Left
  | Right
  | Middle;

/* TODO: handle options "left", "right", "middle" only */
type mousePressOptions = {. "button": Js.Nullable.t(string), "clickCount": int};

/* TODO: handle options "left", "right", "middle" only */
type clickOptions = {
  .
  "button": Js.Nullable.t(string), "clickCount": Js.Nullable.t(int), "delay": Js.Nullable.t(float)
};

type mouseMovements = Js.Dict.t(int);

module Mouse = {
  type t;
  [@bs.send.pipe : t]
  external click : (~x: float, ~y: float, ~options: clickOptions=?, unit) => Js.Promise.t(unit) =
    "";
  [@bs.send.pipe : t] external down : (~options: mousePressOptions=?, unit) => Js.Promise.t(unit) =
    "";
  [@bs.send.pipe : t]
  external move : (~x: float, ~y: float, ~movements: mouseMovements=?, unit) => Js.Promise.t(unit) =
    "";
  [@bs.send.pipe : t] external up : (~options: mousePressOptions=?, unit) => Js.Promise.t(unit) =
    "";
};

module Touchscreen = {
  type t;
  [@bs.send.pipe : t] external tap : (~x: float, ~y: float) => Js.Promise.t(unit) = "";
};

type tracingOptions = {. "path": string, "screenshots": Js.Nullable.t(bool)};

module Tracing = {
  type t;
  [@bs.send.pipe : t] external start : (~options: tracingOptions=?, unit) => Js.Promise.t(unit) =
    "";
  [@bs.send.pipe : t] external stop : Js.Promise.t(unit) = "";
};

/*
    export interface Dialog {
      accept(promptText?: string): Promise<void>;
      defaultValue(): string;
      dismiss(): Promise<void>;
      message(): string;
      type: "alert" | "beforeunload" | "confirm" | "prompt";
    }
 */
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

/*
    export interface Cookie {
      name: string;
      value: string;
      domain: string;
      path: string;
      expires: number;
      httpOnly: boolean;
      secure: boolean;
      sameSite: "Strict" | "Lax";
    }

    export interface Viewport {
      width: number;
      height: number;
      deviceScaleFactor?: number;
      isMobile?: boolean;
      hasTouch?: boolean;
      isLandscape?: boolean;
    }

    export interface EmulateOptions {
      viewport?: Viewport;
      userAgent?: string;
    }

    export type EvaluateFn<T> = (elem?: ElementHandle) => Promise<T>;
 */
type waitEvent =
  | Load
  | Networkidle
  | NetworkIdleTimeout;

type pdfFormat =
  | Letter
  | Legal
  | Tabload
  | Ledger
  | A0
  | A1
  | A2
  | A3
  | A4
  | A5;

module PDFOptions = {
  [@bs.val] external path : option(string) = "";
  [@bs.val] external scale : option(float) = "";
  [@bs.val] external displayHeaderFooter : option(bool) = "";
  [@bs.val] external printBackground : option(bool) = "";
  [@bs.val] external landscape : option(bool) = "";
  /* TODO: rest of PDFOptions */
};

/*
   export interface PDFOptions {
     /* If no path is provided, the PDF won't be saved to the disk. */
     path?: string;
     scale?: number;
     displayHeaderFooter?: boolean;
     printBackground?: boolean;
     landscape?: boolean;
     /*
      * Paper ranges to print, e.g., '1-5, 8, 11-13'. Defaults to the empty
      * string, which means print all pages.
      */
     pageRanges?: string;
     format?: PDFFormat;
     width?: string;
     height?: string;
     margin?: {
       top?: string;
       right?: string;
       bottom?: string;
       left?: string;
     };
   }

   export interface ScreenshotOptions {
     path?: string;
     type?: "jpeg" | "png";
     /* The quality of the image, between 0-100. Not applicable to png images. */
     quality?: number;
     fullPage?: boolean;
     clip?: {
       x: number;
       y: number;
       width: number;
       height: number;
     };
     omitBackground?: boolean;
   }

   export interface PageFnOptions {
     polling?: "raf" | "mutation" | number;
     timeout?: number;
   }
 */
module ElementHandle = {
  type t;
  [@bs.send.pipe : t] external click : (~options: clickOptions=?, unit) => Js.Promise.t(unit) = "";
  [@bs.send.pipe : t] external dispose : Js.Promise.t(unit) = "";
  [@bs.send.pipe : t] external hover : Js.Promise.t(unit) = "";
  [@bs.send.pipe : t] external tap : Js.Promise.t(unit) = "";
  [@bs.send.pipe : t] external uploadFile : (~filePaths: array(string)) => Js.Promise.t(unit) = "";
};

/* export type Headers = Record<string, string>; */
type headers = stringDict;

type httpMethod =
  | GET
  | POST
  | PATCH
  | PUT
  | DELETE
  | OPTIONS;

type resourceType =
  | Document
  | Stylesheet
  | Image
  | Media
  | Font
  | Script
  | TextTrack
  | XHR
  | Fetch
  | EventSource
  | WebSocket
  | Manifest
  | Other;

type overrides = {
  .
  url: Js.Nullable.t(string),
  method_: Js.Nullable.t(httpMethod),
  postData: Js.Nullable.t(string),
  headers: Js.Nullable.t(headers)
};

module Request = {
  type t;
  [@bs.send.pipe : t] external abort : Js.Promise.t(unit) = "";
  [@bs.send.pipe : t] external continue : (~overrides: overrides=?, unit) => Js.Promise.t(unit) =
    "";
  [@bs.val] external headers : headers = "";
  [@bs.val] external method_ : httpMethod = "";
  [@bs.val] external postData : string = ""; /* TODO: or undefined */
  [@bs.val] external resourceType : resourceType = "";
  [@bs.get] external response : unit => Js.Nullable.t(t) = "";
  [@bs.val] external url : string = "";
};

module Response = {
  type t;
  [@bs.get] external buffer : t => Js.Promise.t(Buffer.t) = "";
  [@bs.get] external ok : t => bool = "";
  [@bs.get] external headers : t => headers = "";
  [@bs.get] external request : t => Request.t = "";
  [@bs.get] external status : t => int = "";
  [@bs.send.pipe : t] external text : t => Js.Promise.t(string) = "";
  [@bs.get] external url : t => string = "";
  [@bs.get] external json : t => Js.Promise.t(Js.Json.t) = "";
};

type serializable =
  | Bool
  | Number
  | String
  | Object;

module FrameBase = {
  type t;
  [@bs.val] external select : (~selector: string) => Js.Promise.t(ElementHandle.t) = "$";
  [@bs.val] external selectAll : (~selector: string) => Js.Promise.t(array(ElementHandle.t)) =
    "$$";
  /*
   $eval(
     selector: string,
     fn: (...args: Array<Serializable | ElementHandle>) => void
   ): Promise<Serializable>; */
  /* external $eval : selector::string => (fn::fun ...args : array serializable => unit) => promise serializable = "$eval" [@@bs.val]; */
};

module Frame = {
  include FrameBase;
  [@bs.get] external childFrames : t => array(t) = "";
  [@bs.get] external isDetached : t => bool = "";
  [@bs.get] external name : t => string = "";
  [@bs.get] external parentFrame : t => t = ""; /* TODO: can be undefined as well */
  [@bs.send.pipe : t] external addScriptTag : (~url: string) => Js.Promise.t(unit) = "";
  [@bs.send.pipe : t] external injectFile : (~filePath: string) => Js.Promise.t(unit) = "";
  /*
      evaluate<T = string>(
        fn: T | EvaluateFn<T>,
        ...args: Array<object | ElementHandle>
      ): Promise<T>;
      title(): Promise<string>;
      url(): string;
      waitFor(
        // fn can be an abritary function
        // tslint:disable-next-line ban-types
        selectorOrFunctionOrTimeout: string | number | Function,
        options?: object
      ): Promise<void>;
      waitForFunction(
        // fn can be an abritary function
        // tslint:disable-next-line ban-types
        fn: string | Function,
        options?: PageFnOptions,
        ...args: any[]
      ): Promise<void>;
      waitForNavigation(options?: NavigationOptions): Promise<Response>;
      waitForSelector(
        selector: string,
        options?: { visible: boolean; timeout: number }
      ): Promise<void>;
   */
};

/*
  export interface EventObj {
    console: string;
    dialog: Dialog;
    error: Error;
    frameattached: Frame;
    framedetached: Frame;
    framenavigated: Frame;
    load: undefined;
    pageerror: string;
    request: Request;
    requestfailed: Request;
    requestfinished: Request;
    response: Response;
  }
 */
/*export interface NavigationOptions {
    timeout?: number;
    waitUntil?: "load" | "networkidle" | "networkIdleTimeout";
    networkIdleInflight?: number;
    networkIdleTimeout?: number;
  }*/
type navigationOptions = {
  .
  "timeout": Js.Nullable.t(float),
  "waitUntil": Js.Nullable.t(waitEvent),
  "networkIdleInflight": Js.Nullable.t(float),
  "networkIdleTimeout": Js.Nullable.t(float)
};

module Page = {
  include FrameBase;
  /* authenticate(credentials: AuthOptions | null): Promise<void>; */
  /*
   on(event: "console", handler: (...args: any[]) => void): void;
   on<K extends keyof EventObj>(
     event: K,
     handler: (e: EventObj[K], ...args: any[]) => void
   ): void; */
  [@bs.send.pipe : t]
  external click : (~selector: string, ~options: clickOptions=?, unit) => Js.Promise.t(unit) =
    "";
  [@bs.send.pipe : t] external close : Js.Promise.t(unit) = "";
  [@bs.get] external content : t => Js.Promise.t(string) = ""; /* send? */
  /*goto(url: string, options?: Partial<NavigationOptions>): Promise<Response>;*/
  [@bs.send.pipe : t]
  external goto : (~url: string, ~options: navigationOptions=?, unit) => Js.Promise.t(Response.t) =
    "";
  [@bs.send.pipe : t]
  external setExtraHTTPHeaders : (~headers: headers, unit) => Js.Promise.t(unit) =
    "";
  /* TODO: the rest of Page */
  /* cookies(...urls: string[]): Promise<Cookie[]>; */
  /*  type 'cookie;
        external cookies : urls::array string => promise (array 'cookie) = "" [@@bs.send];
         deleteCookie(
           ...cookies: Array<{
             name: string;
             url?: string;
             domain?: string;
             path?: string;
             secure?: boolean;
           }>
         ): Promise<void>;
        external focus : selector::string => promise unit = "" [@@bs.send];
        external frames : unit => array Frame.t = "" [@@bs.get]; /* send? */
        /*
           goBack(options?: Partial<NavigationOptions>): Promise<Response>;
           goForward(options?: Partial<NavigationOptions>): Promise<Response>;
         */
        external hover : selector::string => promise unit = "" [@@bs.send];
        external keyboard : Keyboard.t = "" [@@bs.val];
        external mainFrame : unit => Frame.t = "" [@@bs.get];
        external mouse : Mouse.t = "" [@@bs.val];
      /* emulate(options: Partial<EmulateOptions>): Promise<void>;
         emulateMedia(mediaType: string | null): Promise<void>;
         evaluateOnNewDocument(
           fn: EvaluateFn<string>,
           ...args: object[]
         ): Promise<void>;

         // Argument `fn` can be an arbitrary function
         exposeFunction(name: string, fn: any): Promise<void>;

         pdf(options?: Partial<PDFOptions>): Promise<Buffer>;
         plainText(): Promise<string>; */
         type pressOptions = {. "text": string, "delay": float};
         external press : key::string => options::option pressOptions => promise unit = "" [@@bs.send];
         external reload : options::option NavigationOptions.t => promise Response.t = "" [@@bs.send]; /*
         screenshot(options?: ScreenshotOptions): Promise<Buffer>;
         setContent(html: string): Promise<void>;
         setCookie(...cookies: Cookie[]): Promise<void>;
         setJavaScriptEnabled(enabled: boolean): Promise<void>;
         setRequestInterceptionEnabled(value: boolean): Promise<void>;
         setUserAgent(userAgent: string): Promise<void>;
         setViewport(viewport: Viewport): Promise<void>;
         tap(selector: string): Promise<void>;
         touchscreen: Touchscreen;
         tracing: Tracing;
         type(text: string, options?: { delay: number }): Promise<void>;
         viewport(): Viewport;
       } */ */
};

module Browser = {
  type t;
  [@bs.send.pipe : t] external close : Js.Promise.t(unit) = "";
  [@bs.send.pipe : t] external newPage : Js.Promise.t(Page.t) = "";
  [@bs.send.pipe : t] external version : Js.Promise.t(string) = "";
  [@bs.send.pipe : t] external wsEndpoint : string = "";
};

type launchOptions = {
  .
  /* Whether to ignore HTTPS errors during navigation. Defaults to false. */
  "ignoreHTTPSErrors": Js.Nullable.t(bool),
  /* Whether to run Chromium in headless mode. Defaults to true. */
  "headless": Js.Nullable.t(bool),
  /*
   * Path to a Chromium executable to run instead of bundled Chromium. If
   * executablePath is a relative path, then it is resolved relative to current
   * working directory.
   */
  "executablePath": Js.Nullable.t(string),
  /*
   * Slows down Puppeteer operations by the specified amount of milliseconds.
   * Useful so that you can see what is going on.
   */
  "slowMo": Js.Nullable.t(float),
  /*
   * Additional arguments to pass to the Chromium instance. List of Chromium
   * flags can be found here.
   */
  "args": Js.Nullable.t(array(string)),
  /* Close chrome process on Ctrl-C. Defaults to true. */
  "handleSIGINT": Js.Nullable.t(bool),
  /*
   * Maximum time in milliseconds to wait for the Chrome instance to start.
   * Defaults to 30000 (30 seconds). Pass 0 to disable timeout.
   */
  "timeout": Js.Nullable.t(int),
  /*
   * Whether to pipe browser process stdout and stderr into process.stdout and
   * process.stderr. Defaults to false.
   */
  "dumpio": Js.Nullable.t(bool),
  /* Path to a User Data Directory. */
  "userDataDir": Js.Nullable.t(string)
};

type connectOptions = {
  .
  "browserWSEndpoint": Js.Nullable.t(string), "ignoreHTTPSErrors": Js.Nullable.t(bool)
};

/* Attaches Puppeteer to an existing Chromium instance */
[@bs.val] external connect : (~options: connectOptions=?, unit) => Js.Promise.t(Browser.t) = "";

/* Path where Puppeteer expects to find bundled Chromium */
[@bs.val] [@bs.module "puppeteer"] external executablePath : unit => string = "";

[@bs.val] [@bs.module "puppeteer"]
external launch : (~options: launchOptions=?, unit) => Js.Promise.t(Browser.t) =
  "";
