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

/** Launch a browser instance.                                      */
[@bs.val]
[@bs.module "puppeteer"]
external launch :
  (~options: Launcher.launchOptions=?, unit) => Js.Promise.t(Browser.t) =
  "";

/** The default flags that Chromium will launch with. */
[@bs.val]
[@bs.module "puppeteer"]
external defaultArgs : unit => array(string) = "";
