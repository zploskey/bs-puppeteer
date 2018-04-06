type t;

type range = {
  .
  "start": float,
  "end": float,
};

type report = {
  .
  "url": string,
  "text": string,
  "ranges": array(range),
};

type cssCoverageOptions = {. "resetOnNavigation": Js.nullable(bool)};

type jsCoverageOptions = {. "resetOnNavigation": Js.nullable(bool)};

[@bs.obj]
external makeCSSCoverageOptions :
  (~resetOnNavigation: Js.boolean=?, unit) => cssCoverageOptions =
  "";

[@bs.obj]
external makeJSCoverageOptions :
  (~resetOnNavigation: Js.boolean=?, unit) => jsCoverageOptions =
  "";

[@bs.send]
external startCSSCoverage : (t, cssCoverageOptions) => Js.Promise.t(unit) =
  "";

[@bs.send]
external startJSCoverage : (t, jsCoverageOptions) => Js.Promise.t(unit) = "";

[@bs.send] external stopCSSCoverage : t => Js.Promise.t(array(report)) = "";

[@bs.send] external stopJSCoverage : t => Js.Promise.t(array(report)) = "";
