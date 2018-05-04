'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var Js_option = require("bs-platform/lib/js/js_option.js");

function optToJs(toJsFn, opt) {
  return Js_option.map(Curry.__1(toJsFn), opt);
}

exports.optToJs = optToJs;
/* No side effect */
