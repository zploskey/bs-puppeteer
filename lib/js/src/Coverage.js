'use strict';

var Js_undefined = require("bs-platform/lib/js/js_undefined.js");
var Util$BsPuppeteer = require("./Util.js");

function makeCSSCoverageOptions(resetOnNavigation, _) {
  var tmp = { };
  var tmp$1 = Util$BsPuppeteer.optBoolToJs(resetOnNavigation);
  if (tmp$1) {
    tmp.resetOnNavigation = tmp$1[0];
  }
  return tmp;
}

function makeJSCoverageOptions(resetOnNavigation, _) {
  var tmp = { };
  var tmp$1 = Util$BsPuppeteer.optBoolToJs(resetOnNavigation);
  if (tmp$1) {
    tmp.resetOnNavigation = tmp$1[0];
  }
  return tmp;
}

function startCSSCoverage(options, t) {
  return t.startCSSCoverage(Js_undefined.fromOption(options));
}

function startJSCoverage(options, t) {
  return t.startJSCoverage(Js_undefined.fromOption(options));
}

exports.makeCSSCoverageOptions = makeCSSCoverageOptions;
exports.makeJSCoverageOptions = makeJSCoverageOptions;
exports.startCSSCoverage = startCSSCoverage;
exports.startJSCoverage = startJSCoverage;
/* No side effect */
