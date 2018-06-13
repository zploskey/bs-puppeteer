'use strict';

var FrameBase$BsPuppeteer = require("./FrameBase.js");

function setBypassCSP(enabled, page) {
  return page.setBypassCSP(enabled);
}

exports.setBypassCSP = setBypassCSP;
/* FrameBase-BsPuppeteer Not a pure module */
