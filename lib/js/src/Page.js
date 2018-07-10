'use strict';

var Js_primitive = require("bs-platform/lib/js/js_primitive.js");
var FrameBase$BsPuppeteer = require("./FrameBase.js");

function setBypassCSP(enabled, page) {
  return page.setBypassCSP(enabled);
}

function waitForNavigation(options, page) {
  return page.waitForNavigation(options).then((function (response) {
                return Promise.resolve((response == null) ? undefined : Js_primitive.some(response));
              }));
}

exports.setBypassCSP = setBypassCSP;
exports.waitForNavigation = waitForNavigation;
/* FrameBase-BsPuppeteer Not a pure module */
