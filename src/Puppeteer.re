type promise 'a = Js.Promise.t 'a;

module Keyboard = {
  type t;
  external down : t => string => option (Js.Dict.t string) => promise unit = "" [@@bs.send];
  external sendCharacter : t => string => promise unit = "" [@@bs.send];
  external up : t => string => promise unit = "" [@@bs.send];
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

module ClickOptions = {
  type t;
  /* defaults to left */
  external button : option mouseButton = "" [@@bs.val];

  /** defaults to 1 */
  external clickCount : option int = "" [@@bs.val];

  /** Time to wait between mousedown and mouseup in milliseconds.
   *  Defaults to 0. **/
  external delay : option float = "" [@@bs.val];
};

module Mouse = {
  type t;
  external click : x::float => y::float => options::ClickOptions.t => promise unit =
    "" [@@bs.send];
  external down : options::option MousePressOptions.t => promise unit = "" [@@bs.send];
  external move : x::float => y::float => option (Js.Dict.t int) => promise unit = "" [@@bs.send];
  external up : options::option MousePressOptions.t => promise unit = "" [@@bs.send];
};

module Touchscreen = {
  type t;
  external tap : x::float => y::float => promise unit = "" [@@bs.send];
};

type tracingOptions = {
  path: string,
  screenshots: option bool
};

module Tracing = {
  external start : options::tracingOptions => promise unit = "" [@@bs.send];
  external stop : unit => promise unit = "" [@@bs.send];
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

module NavigationOptions = {
  external timeout : option float = "" [@@bs.val];
  external waitUntil : option waitEvent = "" [@@bs.val];
  external networkIdleInflight : option float = "" [@@bs.val];
  external networkIdleTimeout : option float = "" [@@bs.val];
};

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
  external click : options::option ClickOptions.t => promise unit = "" [@@bs.send];
  external dispose : unit => promise unit = "" [@@bs.send];
  external hover : unit => promise unit = "" [@@bs.send];
  external tap : unit => promise unit = "" [@@bs.send];
  external uploadFile : filePaths::array string => promise unit = "" [@@bs.send];
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

module Overrides = {
  type t;
  external url : option string = "" [@@bs.val];
  external method_ : option httpMethod = "" [@@bs.val];
  external postData : option string = "" [@@bs.val];
  external headers : option headers = "" [@@bs.val];
};

module Request = {
  type t;
  external abort : unit => promise unit = "" [@@bs.send];
  external continue : overrides::option Overrides.t => promise unit = "" [@@bs.send];
  external headers : headers = "" [@@bs.val];
  external method_ : httpMethod = "" [@@bs.val];
  external postData : string = "" [@@bs.val]; /* TODO: or undefined */
  external resourceType : resourceType = "" [@@bs.val];
  external response : unit => t = "" [@@bs.get]; /* TODO: can be null */
  external url : string = "" [@@bs.val];
};

module Response = {
  type t;
  external buffer : unit => promise Buffer.t = "" [@@bs.val];
  external ok : bool = "" [@@bs.val];
  external headers : headers = "" [@@bs.val];
  external request : unit => Request.t = "" [@@bs.get];
  external status : int = "" [@@bs.val];
  external text : unit => promise string = "" [@@bs.get];
  external url : string = "" [@@bs.val];
  external json : unit => promise Js.Json.t = "" [@@bs.get];
};

type serializable =
  | Bool
  | Number
  | String
  | Object;

module FrameBase = {
  type t;
  external select : selector::string => promise ElementHandle.t = "$" [@@bs.val];
  external selectAll : selector::string => promise (array ElementHandle.t) = "$$" [@@bs.val];
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
  external addScriptTag : url::string => promise unit = "" [@@bs.send];
  external injectFile : filePath::string => promise unit = "" [@@bs.send];
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
module Page = {
  include FrameBase;
  /* authenticate(credentials: AuthOptions | null): Promise<void>; */
  /*
   on(event: "console", handler: (...args: any[]) => void): void;
   on<K extends keyof EventObj>(
     event: K,
     handler: (e: EventObj[K], ...args: any[]) => void
   ): void; */
  external click : selector::string => options::option ClickOptions.t => promise unit =
    "" [@@bs.send];
  external close : unit => promise unit = "" [@@bs.send];
  external content : unit => promise string = "" [@@bs.get]; /* send? */
  external setExtraHTTPHeaders : headers::headers => promise unit = "" [@@bs.send];
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
           goto(url: string, options?: Partial<NavigationOptions>): Promise<Response>;
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
  external close : unit => promise unit = "" [@@bs.send];
  external newPage : unit => promise Page.t = "" [@@bs.send];
  external version : unit => promise string = "" [@@bs.send];
  external wsEndpoint : unit => string = "" [@@bs.send];
};

module LaunchOptions = {
  type t;

  /** Whether to ignore HTTPS errors during navigation. Defaults to false. **/
  external ignoreHTTPSErrors : option bool = "" [@@bs.val];

  /** Whether to run Chromium in headless mode. Defaults to true. */
  external headless : option bool = "" [@@bs.val];

  /**
   * Path to a Chromium executable to run instead of bundled Chromium. If
   * executablePath is a relative path, then it is resolved relative to current
   * working directory.
   */
  external executablePath : option string = "" [@@bs.val];

  /**
   * Slows down Puppeteer operations by the specified amount of milliseconds.
   * Useful so that you can see what is going on.
   */
  external slowMo : option float = "" [@@bs.val];

  /**
   * Additional arguments to pass to the Chromium instance. List of Chromium
   * flags can be found here.
   */
  external args : option (array string) = "" [@@bs.val];

  /** Close chrome process on Ctrl-C. Defaults to true. */
  external handleSIGINT : option bool = "" [@@bs.val];

  /**
   * Maximum time in milliseconds to wait for the Chrome instance to start.
   * Defaults to 30000 (30 seconds). Pass 0 to disable timeout.
   */
  external timeout : option int = "" [@@bs.val];

  /**
   * Whether to pipe browser process stdout and stderr into process.stdout and
   * process.stderr. Defaults to false.
   */
  external dumpio : option bool = "" [@@bs.val];

  /** Path to a User Data Directory. */
  external userDataDir : option string = "" [@@bs.val];
};

module ConnectOptions = {
  type t;
  external browserWSEndpoint : option string = "" [@@bs.val];
  external ignoreHTTPSErrors : option bool = "" [@@bs.val];
};


/** Attaches Puppeteer to an existing Chromium instance **/
external connect : options::option ConnectOptions.t => promise Browser.t = "" [@@bs.val];


/** Path where Puppeteer expects to find bundled Chromium **/
external executablePath : string => unit = "" [@@bs.val];

external launchWithOpts : options::LaunchOptions.t => promise Browser.t =
  "puppeteer.launch" [@@bs.val];

let launch ::options=? =>
  /*promise Browser.t = */
  switch options {
  | Some opts => launchWithOpts options::opts
  | None => launchWithOpts options::()
  };
