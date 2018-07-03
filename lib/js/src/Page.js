'use strict';

var FrameBase$BsPuppeteer = require("./FrameBase.js");

function setBypassCSP(enabled, page) {
  return page.setBypassCSP(enabled);
}

function waitForNavigation(options, page) {
  return page.waitForNavigation(options).then((function (response) {
                return Promise.resolve((response == null) ? /* None */0 : [response]);
              }));
}

exports.setBypassCSP = setBypassCSP;
exports.waitForNavigation = waitForNavigation;
/* FrameBase-BsPuppeteer Not a pure module */
