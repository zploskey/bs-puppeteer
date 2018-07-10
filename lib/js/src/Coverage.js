'use strict';

var Js_primitive = require("bs-platform/lib/js/js_primitive.js");

function startCSSCoverage(options, t) {
  return t.startCSSCoverage(options !== undefined ? Js_primitive.valFromOption(options) : undefined);
}

function startJSCoverage(options, t) {
  return t.startJSCoverage(options !== undefined ? Js_primitive.valFromOption(options) : undefined);
}

exports.startCSSCoverage = startCSSCoverage;
exports.startJSCoverage = startJSCoverage;
/* No side effect */
