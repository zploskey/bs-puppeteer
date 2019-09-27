type t = Types.browser;

external empty: unit => t = "%identity";

[@bs.send]
external browserContexts: t => array(BrowserContext.t) = "browserContexts";

[@bs.send] external close: t => Js.Promise.t(unit) = "close";

[@bs.send]
external createIncognitoBrowserContext: t => Js.Promise.t(BrowserContext.t) =
  "createIncognitoBrowserContext";

[@bs.send]
external defaultBrowserContext: t => BrowserContext.t =
  "defaultBrowserContext";

[@bs.send] external disconnect: t => unit = "disconnect";

[@bs.send] external newPage: t => Js.Promise.t(Page.t) = "newPage";

[@bs.send] external pages: t => Js.Promise.t(array(Page.t)) = "pages";

/* NOTE: This should be Node.Child_process.t but it does not exist. */
[@bs.send] [@bs.return nullable]
external process: t => option(Node.Process.t) = "process";

[@bs.send] external target: t => Target.t = "target";

[@bs.send] external targets: t => array(Target.t) = "targets";

[@bs.send] external userAgent: t => Js.Promise.t(string) = "userAgent";

[@bs.send] external version: t => Js.Promise.t(string) = "version";

[@bs.send] external wsEndpoint: t => string = "wsEndpoint";
