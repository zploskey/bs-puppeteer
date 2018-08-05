'use strict';

var Js_primitive = require("bs-platform/lib/js/js_primitive.js");

function make(prim, prim$1, prim$2, prim$3, prim$4, prim$5, _) {
  var tmp = {
    width: prim,
    height: prim$1
  };
  if (prim$2 !== undefined) {
    tmp.deviceScaleFactor = Js_primitive.valFromOption(prim$2);
  }
  if (prim$3 !== undefined) {
    tmp.isMobile = Js_primitive.valFromOption(prim$3);
  }
  if (prim$4 !== undefined) {
    tmp.hasTouch = Js_primitive.valFromOption(prim$4);
  }
  if (prim$5 !== undefined) {
    tmp.isLandscape = Js_primitive.valFromOption(prim$5);
  }
  return tmp;
}

exports.make = make;
/* No side effect */
