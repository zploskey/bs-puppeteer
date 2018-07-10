'use strict';

var Js_primitive = require("bs-platform/lib/js/js_primitive.js");
var JSHandle$BsPuppeteer = require("./JSHandle.js");

JSHandle$BsPuppeteer.Impl(/* module */[]);

function boxModel(handle) {
  return handle.boxModel().then((function (handle) {
                return Promise.resolve((handle == null) ? undefined : Js_primitive.some(handle));
              }));
}

exports.boxModel = boxModel;
/*  Not a pure module */
