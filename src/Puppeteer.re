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
  /* Whether to ignore HTTPS errors during navigation. Defaults to false. */
  "ignoreHTTPSErrors": Js.Nullable.t(Js.boolean),
  /* Whether to run Chromium in headless mode. Defaults to true. */
  "headless": Js.Nullable.t(Js.boolean),
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
  "handleSIGINT": Js.Nullable.t(Js.boolean),
  /*
   * Maximum time in milliseconds to wait for the Chrome instance to start.
   * Defaults to 30000 (30 seconds). Pass 0 to disable timeout.
   */
  "timeout": Js.Nullable.t(int),
  /*
   * Whether to pipe browser process stdout and stderr into process.stdout and
   * process.stderr. Defaults to false.
   */
  "dumpio": Js.Nullable.t(Js.boolean),
  /* Path to a User Data Directory. */
  "userDataDir": Js.Nullable.t(string),
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
    ~env: Js.t('a)=?,
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
