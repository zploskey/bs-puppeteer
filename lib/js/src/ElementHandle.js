'use strict';

var JSHandle$BsPuppeteer = require("./JSHandle.js");

JSHandle$BsPuppeteer.Impl(/* module */[]);

function boxModel(handle) {
  return handle.boxModel().then((function (handle) {
                return Promise.resolve((handle == null) ? /* None */0 : [handle]);
              }));
}

exports.boxModel = boxModel;
/*  Not a pure module */
