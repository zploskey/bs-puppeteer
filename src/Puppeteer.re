/** Configuration options for [connect]. */
type connectOptions = {
  .
  "browserWSEndpoint": Js.nullable(string),
  "ignoreHTTPSErrors": Js.nullable(bool),
  "defaultViewport": Js.nullable(Viewport.t),
  "slowMo": Js.nullable(float),
};

[@bs.obj]
external makeConnectOptions:
  (
    ~browserWSEndpoint: string=?,
    ~ignoreHTTPSErrors: bool=?,
    ~defaultViewport: Viewport.t=?,
    ~slowMo: float=?,
    unit
  ) =>
  connectOptions =
  "";

/** Attach Puppeteer to an existing Chromium instance. */
[@bs.val] [@bs.module "puppeteer"]
external connect:
  (~options: connectOptions=?, unit) => Js.Promise.t(Browser.t) =
  "";

/** Path where Puppeteer expects to find bundled Chromium. */
[@bs.val] [@bs.module "puppeteer"]
external executablePath: unit => string = "";

type launchOptions = {
  .
  "ignoreHTTPSErrors": Js.undefined(bool),
  "headless": Js.undefined(bool),
  "executablePath": Js.undefined(string),
  "slowMo": Js.undefined(float),
  "defaultViewport": Js.nullable(Viewport.t),
  "args": Js.undefined(array(string)),
  "ignoreDefaultArgs": Js.undefined(bool),
  "handleSIGINT": Js.undefined(bool),
  "handleSIGTERM": Js.undefined(bool),
  "handleSIGHUP": Js.undefined(bool),
  "timeout": Js.undefined(int),
  "dumpio": Js.undefined(bool),
  "userDataDir": Js.undefined(string),
  "env": Js.undefined(Js.Dict.t(string)),
  "devtools": Js.undefined(bool),
  "pipe": Js.undefined(bool),
};

[@bs.obj]
external makeLaunchOptions:
  (
    ~ignoreHTTPSErrors: bool=?,
    ~headless: bool=?,
    ~executablePath: string=?,
    ~slowMo: float=?,
    ~defaultViewport: Viewport.t=?,
    ~args: array(string)=?,
    ~ignoreDefaultArgs: bool=?,
    ~handleSIGINT: bool=?,
    ~handleSIGTERM: bool=?,
    ~handleSIGHUP: bool=?,
    ~timeout: float=?,
    ~dumpio: bool=?,
    ~userDataDir: string=?,
    ~env: Js.Dict.t(string)=?,
    ~devtools: bool=?,
    ~pipe: bool=?,
    unit
  ) =>
  launchOptions =
  "";

/** Launch a browser instance. */
[@bs.val] [@bs.module "puppeteer"]
external launch: (~options: launchOptions=?, unit) => Js.Promise.t(Browser.t) =
  "";

module DefaultArgsOptions = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    headless: bool,
    [@bs.optional]
    args: array(string),
    [@bs.optional]
    userDataDir: string,
    [@bs.optional]
    devtools: bool,
  };
  let make = t;
};

/** The default flags that Chromium will launch with. */
[@bs.val] [@bs.module "puppeteer"]
external defaultArgs:
  (~options: DefaultArgsOptions.t=?, unit) => array(string) =
  "";

type browserFetcherOptions = {
  .
  "host": Js.undefined(string),
  "path": Js.undefined(string),
  "platform": Js.undefined(string),
};

[@bs.obj]
external makeBrowserFetcherOptions:
  (~host: string=?, ~path: string=?, ~platform: string=?, unit) =>
  browserFetcherOptions =
  "";

let makeBrowserFetcherOptions =
    (~host=?, ~path=?, ~platform=?, ()): browserFetcherOptions =>
  makeBrowserFetcherOptions(
    ~host?,
    ~path?,
    ~platform=?
      platform |> Js.Option.map((. v) => v |> BrowserFetcher.platformToJs),
    (),
  );

[@bs.val] [@bs.module "puppeteer"]
external createBrowserFetcher:
  (~options: browserFetcherOptions=?, unit) => BrowserFetcher.t =
  "";
