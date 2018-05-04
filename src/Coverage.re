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

type jsCoverageOptions = {. "resetOnNavigation": Js.Nullable.t(bool)};

[@bs.obj]
external makeCSSCoverageOptions :
  (~resetOnNavigation: bool=?, unit) => cssCoverageOptions =
  "";

[@bs.obj]
external makeJSCoverageOptions :
  (~resetOnNavigation: bool=?, unit) => jsCoverageOptions =
  "";

[@bs.send]
external startCSSCoverage :
  (t, Js.Undefined.t(cssCoverageOptions)) => Js.Promise.t(unit) =
  "";

let startCSSCoverage = (~options=?, t) =>
  startCSSCoverage(t, options |> Js.Undefined.fromOption);

[@bs.send]
external startJSCoverage :
  (t, Js.Undefined.t(jsCoverageOptions)) => Js.Promise.t(unit) =
  "";

let startJSCoverage = (~options=?, t) =>
  startJSCoverage(t, options |> Js.Undefined.fromOption);

[@bs.send] external stopCSSCoverage : t => Js.Promise.t(array(report)) = "";

[@bs.send] external stopJSCoverage : t => Js.Promise.t(array(report)) = "";
