type t;

type range = {
  .
  "start": int,
  "end": int,
};

type report = {
  .
  "url": string,
  "text": string,
  "ranges": array(range),
};

type cssCoverageOptions = {. "resetOnNavigation": Js.Nullable.t(bool)};

type jsCoverageOptions = {
  .
  "resetOnNavigation": Js.Nullable.t(bool),
  "reportAnonymousScripts": Js.Nullable.t(bool),
};

[@bs.obj]
external makeCSSCoverageOptions:
  (~resetOnNavigation: bool=?, unit) => cssCoverageOptions =
  "";

[@bs.obj]
external makeJSCoverageOptions:
  (~resetOnNavigation: bool=?, ~reportAnonymousScripts: bool=?, unit) =>
  jsCoverageOptions =
  "";

[@bs.send]
external startCSSCoverage:
  (t, ~options: cssCoverageOptions=?) => Js.Promise.t(unit) =
  "";

let startCSSCoverage = (~options=?, t) => startCSSCoverage(t, ~options?);

[@bs.send]
external startJSCoverage:
  (t, ~options: jsCoverageOptions=?) => Js.Promise.t(unit) =
  "";

let startJSCoverage = (~options=?, t) => startJSCoverage(t, ~options?);

[@bs.send] external stopCSSCoverage: t => Js.Promise.t(array(report)) = "";

[@bs.send] external stopJSCoverage: t => Js.Promise.t(array(report)) = "";
