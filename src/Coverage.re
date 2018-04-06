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
external makeJsCoverageOptions :
  (~resetOnNavigation: Js.boolean=?, unit) => jsCoverageOptions =
  "";

[@bs.send]
external startCSSCoverage : (t, cssCoverageOptions) => Js.Promise.t(unit) =
  "";

[@bs.send]
external startJsCoverage : (t, jsCoverageOptions) => Js.Promise.t(unit) = "";

[@bs.send] external stopCssCoverage : t => Js.Promise.t(array(report)) = "";

[@bs.send] external stopJsCoverage : t => Js.Promise.t(array(report)) = "";
