'use strict';

var Js_undefined = require("bs-platform/lib/js/js_undefined.js");

function startCSSCoverage(options, t) {
  return t.startCSSCoverage(Js_undefined.fromOption(options));
}

function startJSCoverage(options, t) {
  return t.startJSCoverage(Js_undefined.fromOption(options));
}

exports.startCSSCoverage = startCSSCoverage;
exports.startJSCoverage = startJSCoverage;
/* No side effect */
