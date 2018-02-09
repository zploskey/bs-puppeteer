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
  "userDataDir": Js.Nullable.t(string)
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
      ~ignoreHTTPSErrors: option(bool)=?,
      ~headless: option(bool)=?,
      ~executablePath: option(string)=?,
      ~slowMo: option(float)=?,
      ~args: option(array(string))=?,
      ~ignoreDefaultArgs: option(bool)=?,
      ~handleSIGINT: option(bool)=?,
      ~handleSIGTERM: option(bool)=?,
      ~handleSIGHUP: option(bool)=?,
      ~timeout: option(float)=?,
      ~dumpio: option(bool)=?,
      ~userDataDir: option(string)=?,
      ~env: option(Js.t('a))=?,
      ~devtools: option(bool)=?,
      ()
    )
    : launchOptions => {
  let optBoolToJs = (optBool) =>
    Js.Option.map([@bs] ((opt) => Js.Boolean.to_js_boolean(opt)), optBool);
  makeLaunchOptions(
    ~ignoreHTTPSErrors=?optBoolToJs(ignoreHTTPSErrors),
    ~headless=?optBoolToJs(headless),
    ~executablePath?,
    ~slowMo?,
    ~args?,
    ~ignoreDefaultArgs=?optBoolToJs(ignoreDefaultArgs),
    ~handleSIGINT=?optBoolToJs(handleSIGINT),
    ~handleSIGTERM=?optBoolToJs(handleSIGTERM),
    ~handleSIGHUP=?optBoolToJs(handleSIGHUP),
    ~timeout?,
    ~dumpio=?optBoolToJs(dumpio),
    ~userDataDir?,
    ~env?,
    ~devtools=?optBoolToJs(devtools),
    ()
  )
};
