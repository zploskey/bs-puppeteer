/** Configuration options for [connect]. */
type connectOptions = {
  .
  "browserWSEndpoint": Js.nullable(string),
  "ignoreHTTPSErrors": Js.nullable(bool),
};

[@bs.obj]
external makeConnectOptions :
  (~browserWSEndpoint: string=?, ~ignoreHTTPSErrors: Js.boolean=?, unit) =>
  connectOptions =
  "";

let makeConnectOptions = (~browserWSEndpoint=?, ~ignoreHTTPSErrors=?, ()) =>
  makeConnectOptions(
    ~browserWSEndpoint?,
    ~ignoreHTTPSErrors=?Util.optBoolToJs(ignoreHTTPSErrors),
    (),
  );

/** Attach Puppeteer to an existing Chromium instance.              */
[@bs.val]
[@bs.module "puppeteer"]
external connect :
  (~options: connectOptions=?, unit) => Js.Promise.t(Browser.t) =
  "";

/** Path where Puppeteer expects to find bundled Chromium. */
[@bs.val]
[@bs.module "puppeteer"]
external executablePath : unit => string = "";

type launchOptions = {
  .
  "ignoreHTTPSErrors": Js.undefined(Js.boolean),
  "headless": Js.undefined(Js.boolean),
  "executablePath": Js.undefined(string),
  "slowMo": Js.undefined(float),
  "args": Js.undefined(array(string)),
  "handleSIGINT": Js.undefined(Js.boolean),
  "handleSIGTERM": Js.undefined(Js.boolean),
  "handleSIGHUP": Js.undefined(Js.boolean),
  "timeout": Js.undefined(int),
  "dumpio": Js.undefined(Js.boolean),
  "userDataDir": Js.undefined(string),
  "env": Js.undefined(Js.Dict.t(string)),
  "devtools": Js.undefined(Js.boolean),
};

[@bs.obj]
external makeLaunchOptions :
  (
    ~ignoreHTTPSErrors: Js.boolean=?,
    ~headless: Js.boolean=?,
    ~executablePath: string=?,
    ~slowMo: float=?,
    ~args: array(string)=?,
    ~ignoreDefaultArgs: Js.boolean=?,
    ~handleSIGINT: Js.boolean=?,
    ~handleSIGTERM: Js.boolean=?,
    ~handleSIGHUP: Js.boolean=?,
    ~timeout: float=?,
    ~dumpio: Js.boolean=?,
    ~userDataDir: string=?,
    ~env: Js.Dict.t(string)=?,
    ~devtools: Js.boolean=?,
    unit
  ) =>
  launchOptions =
  "";

let makeLaunchOptions =
    (
      ~ignoreHTTPSErrors=?,
      ~headless=?,
      ~executablePath=?,
      ~slowMo=?,
      ~args=?,
      ~ignoreDefaultArgs=?,
      ~handleSIGINT=?,
      ~handleSIGTERM=?,
      ~handleSIGHUP=?,
      ~timeout=?,
      ~dumpio=?,
      ~userDataDir=?,
      ~env=?,
      ~devtools=?,
      (),
    )
    : launchOptions =>
  makeLaunchOptions(
    ~ignoreHTTPSErrors=?Util.optBoolToJs(ignoreHTTPSErrors),
    ~headless=?Util.optBoolToJs(headless),
    ~executablePath?,
    ~slowMo?,
    ~args?,
    ~ignoreDefaultArgs=?Util.optBoolToJs(ignoreDefaultArgs),
    ~handleSIGINT=?Util.optBoolToJs(handleSIGINT),
    ~handleSIGTERM=?Util.optBoolToJs(handleSIGTERM),
    ~handleSIGHUP=?Util.optBoolToJs(handleSIGHUP),
    ~timeout?,
    ~dumpio=?Util.optBoolToJs(dumpio),
    ~userDataDir?,
    ~env?,
    ~devtools=?Util.optBoolToJs(devtools),
    (),
  );

/** Launch a browser instance.                                      */
[@bs.val]
[@bs.module "puppeteer"]
external launch : (~options: launchOptions=?, unit) => Js.Promise.t(Browser.t) =
  "";

/** The default flags that Chromium will launch with. */
[@bs.val]
[@bs.module "puppeteer"]
external defaultArgs : unit => array(string) = "";

type browserFetcherOptions = {
  .
  "host": Js.undefined(string),
  "path": Js.undefined(string),
  "platform": Js.undefined(string),
};

[@bs.obj]
external makeBrowserFetcherOption :
  (~host: string=?, ~path: string=?, ~platform: string=?, unit) =>
  browserFetcherOptions =
  "";

let makeBrowserFetcherOption =
    (~host=?, ~path=?, ~platform=?, ())
    : browserFetcherOptions =>
  makeBrowserFetcherOption(
    ~host?,
    ~path?,
    ~platform=?
      platform |> Js.Option.map((. v) => v |> BrowserFetcher.platformToJs),
    (),
  );

[@bs.val] [@bs.module "puppeteer"]
external createBrowserFetcher :
  (~options: browserFetcherOptions=?, unit) => BrowserFetcher.t =
  "";
