type stringDict = Js.Dict.t string;

module Keyboard = {
  type t;
  external down : t => string => options::stringDict? => unit => Js.Promise.t unit = "" [@@bs.send];
  external sendCharacter : t => string => Js.Promise.t unit = "" [@@bs.send];
  external up : t => string => Js.Promise.t unit = "" [@@bs.send];
};

type mouseButton =
  | Left
  | Right
  | Middle;

module MousePressOptions = {
  type t;
  external button : option mouseButton = "" [@@bs.val];
  external clickCount : int = "" [@@bs.val];
};

type clickOptions = {
  .
  /** defaults to left **/
  button : Js.Nullable.t mouseButton,

  /** defaults to 1 **/
  clickCount : Js.Nullable.t int,

  /** Time to wait between mousedown and mouseup in milliseconds.
      Defaults to 0. **/
  delay : Js.Nullable.t float
};

module Mouse = {
  type t;
  external click : x::float => y::float => options::clickOptions? => unit => Js.Promise.t unit =
    "" [@@bs.send];
  external down : options::option MousePressOptions.t => Js.Promise.t unit = "" [@@bs.send];
  external move : x::float => y::float => option (Js.Dict.t int) => Js.Promise.t unit = "" [@@bs.send];
  external up : options::option MousePressOptions.t => Js.Promise.t unit = "" [@@bs.send];
};

module Touchscreen = {
  type t;
  external tap : x::float => y::float => Js.Promise.t unit = "" [@@bs.send];
};

type tracingOptions = {
  path: string,
  screenshots: option bool
};

module Tracing = {
  external start : options::tracingOptions => Js.Promise.t unit = "" [@@bs.send];
  external stop : unit => Js.Promise.t unit = "" [@@bs.send];
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

module AuthOptions = {
  external username : string = "" [@@bs.val];
  external password : string = "" [@@bs.val];
};

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
  external path : option string = "" [@@bs.val];
  external scale : option float = "" [@@bs.val];
  external displayHeaderFooter : option bool = "" [@@bs.val];
  external printBackground : option bool = "" [@@bs.val];
  external landscape : option bool = "" [@@bs.val];
  /* TODO: rest of PDFOptions */
};

/*
   export interface PDFOptions {
     /** If no path is provided, the PDF won't be saved to the disk. */
     path?: string;
     scale?: number;
     displayHeaderFooter?: boolean;
     printBackground?: boolean;
     landscape?: boolean;
     /**
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
     /** The quality of the image, between 0-100. Not applicable to png images. */
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
  external click : options::clickOptions? => unit => Js.Promise.t unit = "" [@@bs.send];
  external dispose : t => Js.Promise.t unit = "" [@@bs.send];
  external hover : t => Js.Promise.t unit = "" [@@bs.send];
  external tap : t => Js.Promise.t unit = "" [@@bs.send];
  external uploadFile : filePaths::array string => Js.Promise.t unit = "" [@@bs.send];
};

/* export type Headers = Record<string, string>; */
type headers = Js.Dict.t string;

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
  url: Js.Nullable.t  string,
  method_: Js.Nullable.t  httpMethod,
  postData: Js.Nullable.t  string,
  headers: Js.Nullable.t  headers
};

module Request = {
  type t;
  external abort : unit => Js.Promise.t unit = "" [@@bs.send];
  external continue : overrides::overrides? => unit => Js.Promise.t unit = "" [@@bs.send];
  external headers : headers = "" [@@bs.val];
  external method_ : httpMethod = "" [@@bs.val];
  external postData : string = "" [@@bs.val]; /* TODO: or undefined */
  external resourceType : resourceType = "" [@@bs.val];
  external response : unit => t = "" [@@bs.get]; /* TODO: can be null */
  external url : string = "" [@@bs.val];
};

module Response = {
  type t;
  external buffer : t => Js.Promise.t Buffer.t = "" [@@bs.get];
  external ok : t => bool = "" [@@bs.get];
  external headers : t => headers = "" [@@bs.get];
  external request : t => Request.t = "" [@@bs.get];
  external status : t => int = "" [@@bs.get];
  external text : t => Js.Promise.t string = "" [@@bs.get];
  external url : t => string = "" [@@bs.get];
  external json : t  => Js.Promise.t Js.Json.t = "" [@@bs.get];
};

type serializable =
  | Bool
  | Number
  | String
  | Object;

module FrameBase = {
  type t;
  external select : selector::string => Js.Promise.t ElementHandle.t = "$" [@@bs.val];
  external selectAll : selector::string => Js.Promise.t (array ElementHandle.t) = "$$" [@@bs.val];
  /*
   $eval(
     selector: string,
     fn: (...args: Array<Serializable | ElementHandle>) => void
   ): Promise<Serializable>; */
  /* external $eval : selector::string => (fn::fun ...args : array serializable => unit) => promise serializable = "$eval" [@@bs.val]; */
};

module Frame = {
  include FrameBase;
  external childFrames : unit => array t = "" [@@bs.get];
  external isDetached : unit => bool = "" [@@bs.get];
  external name : unit => string = "" [@@bs.get];
  external parentFrame : unit => t = "" [@@bs.get]; /* TODO: can be undefined as well */
  external addScriptTag : url::string => Js.Promise.t unit = "" [@@bs.send];
  external injectFile : filePath::string => Js.Promise.t unit = "" [@@bs.send];
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
type navigationOptions = Js.t {
  .
  timeout: Js.Nullable.t float,
  waitUntil: Js.Nullable.t waitEvent,
  networkIdleInflight: Js.Nullable.t float,
  networkIdleTimeout: Js.Nullable.t float
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
  external click : t => selector::string => options::clickOptions? => Js.Promise.t unit =
    "" [@@bs.send];
  external close : t => unit => Js.Promise.t unit = "" [@@bs.send];
  external content : t => Js.Promise.t string = "" [@@bs.get]; /* send? */
  external setExtraHTTPHeaders : t => headers::headers => unit => Js.Promise.t unit = "" [@@bs.send];
  /*goto(url: string, options?: Partial<NavigationOptions>): Promise<Response>;*/

  external goto : t => url::string => options::navigationOptions? => unit => Js.Promise.t Response.t = "" [@@bs.send];
  
  /* TODO: the rest of Page */
  /* cookies(...urls: string[]): Promise<Cookie[]>; */
  /*  type 'cookie;
        external cookies : urls::array string => promise (array 'cookie) = "" [@@bs.send];
        /*
         deleteCookie(
           ...cookies: Array<{
             name: string;
             url?: string;
             domain?: string;
             path?: string;
             secure?: boolean;
           }>
         ): Promise<void>; */
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
  external close : t => Js.Promise.t unit = "" [@@bs.send];
  external newPage : t => Js.Promise.t Page.t = "" [@@bs.send];
  external version : t => Js.Promise.t string = "" [@@bs.send];
  external wsEndpoint : t => string = "" [@@bs.send];
};

type launchOptions = Js.t {
  .
  /** Whether to ignore HTTPS errors during navigation. Defaults to false. **/
  ignoreHTTPSErrors : Js.Nullable.t bool,

  /** Whether to run Chromium in headless mode. Defaults to true. */
  headless : Js.Nullable.t bool,

  /**
   * Path to a Chromium executable to run instead of bundled Chromium. If
   * executablePath is a relative path, then it is resolved relative to current
   * working directory.
   */
  executablePath : Js.Nullable.t string,

  /**
   * Slows down Puppeteer operations by the specified amount of milliseconds.
   * Useful so that you can see what is going on.
   */
  slowMo : Js.Nullable.t float,

  /**
   * Additional arguments to pass to the Chromium instance. List of Chromium
   * flags can be found here.
   */
  args : Js.Nullable.t (array string),

  /** Close chrome process on Ctrl-C. Defaults to true. */
  handleSIGINT : Js.Nullable.t bool,

  /**
   * Maximum time in milliseconds to wait for the Chrome instance to start.
   * Defaults to 30000 (30 seconds). Pass 0 to disable timeout.
   */
  timeout : Js.Nullable.t int,

  /**
   * Whether to pipe browser process stdout and stderr into process.stdout and
   * process.stderr. Defaults to false.
   */
  dumpio : Js.Nullable.t bool,

  /** Path to a User Data Directory. */
  userDataDir : Js.Nullable.t string
};

/*module ConnectOptions = {
  type t;
  external browserWSEndpoint : option string = "" [@@bs.val];
  external ignoreHTTPSErrors : option bool = "" [@@bs.val];
};*/
type connectOptions = Js.t {
  .
  browserWSEndpoint: Js.Nullable.t string,
  ignoreHTTPSErrors: Js.Nullable.t bool
};

/** Attaches Puppeteer to an existing Chromium instance **/
external connect : options::connectOptions? => unit => Js.Promise.t Browser.t = "" [@@bs.val];

/** Path where Puppeteer expects to find bundled Chromium **/
external executablePath : string = "" [@@bs.val] [@@bs.module "puppeteer"];

external launch : options::launchOptions? => unit => Js.Promise.t Browser.t =
  "" [@@bs.val] [@@bs.module "puppeteer"];