'use strict';

var Js_primitive = require("bs-platform/lib/js/js_primitive.js");
var FrameBase$BsPuppeteer = require("./FrameBase.js");

function setBypassCSP(enabled, page) {
  return page.setBypassCSP(enabled);
}

function waitForNavigation(page, options) {
  return page.waitForNavigation(options).then((function (response) {
                return Promise.resolve((response == null) ? undefined : Js_primitive.some(response));
              }));
}

var WaitForRequest = /* module */[];

var WaitForResponse = /* module */[];

function waitForRequest(prim, prim$1, prim$2, _) {
  return prim.waitForRequest(prim$1, prim$2 !== undefined ? Js_primitive.valFromOption(prim$2) : undefined);
}

function waitForRequestRe(prim, prim$1, prim$2, _) {
  return prim.waitForRequest(prim$1, prim$2 !== undefined ? Js_primitive.valFromOption(prim$2) : undefined);
}

function waitForRequestUrl(prim, prim$1, prim$2, _) {
  return prim.waitForRequest(prim$1, prim$2 !== undefined ? Js_primitive.valFromOption(prim$2) : undefined);
}

function waitForResponse(prim, prim$1, prim$2, _) {
  return prim.waitForResponse(prim$1, prim$2 !== undefined ? Js_primitive.valFromOption(prim$2) : undefined);
}

function waitForResponseRe(prim, prim$1, prim$2, _) {
  return prim.waitForResponse(prim$1, prim$2 !== undefined ? Js_primitive.valFromOption(prim$2) : undefined);
}

function waitForResponseUrl(prim, prim$1, prim$2, _) {
  return prim.waitForResponse(prim$1, prim$2 !== undefined ? Js_primitive.valFromOption(prim$2) : undefined);
}

exports.setBypassCSP = setBypassCSP;
exports.waitForNavigation = waitForNavigation;
exports.WaitForRequest = WaitForRequest;
exports.WaitForResponse = WaitForResponse;
exports.waitForRequest = waitForRequest;
exports.waitForRequestRe = waitForRequestRe;
exports.waitForRequestUrl = waitForRequestUrl;
exports.waitForResponse = waitForResponse;
exports.waitForResponseRe = waitForResponseRe;
exports.waitForResponseUrl = waitForResponseUrl;
/* FrameBase-BsPuppeteer Not a pure module */
