'use strict';

var Js_option = require("bs-platform/lib/js/js_option.js");
var Js_primitive = require("bs-platform/lib/js/js_primitive.js");
var BrowserFetcher$BsPuppeteer = require("./BrowserFetcher.js");

function make(prim, prim$1, prim$2, prim$3, _) {
  var tmp = { };
  if (prim !== undefined) {
    tmp.headless = Js_primitive.valFromOption(prim);
  }
  if (prim$1 !== undefined) {
    tmp.args = Js_primitive.valFromOption(prim$1);
  }
  if (prim$2 !== undefined) {
    tmp.userDataDir = Js_primitive.valFromOption(prim$2);
  }
  if (prim$3 !== undefined) {
    tmp.devtools = Js_primitive.valFromOption(prim$3);
  }
  return tmp;
}

var DefaultArgsOptions = /* module */[/* make */make];

function makeBrowserFetcherOptions(host, path, platform, _) {
  var tmp = { };
  if (host !== undefined) {
    tmp.host = Js_primitive.valFromOption(host);
  }
  if (path !== undefined) {
    tmp.path = Js_primitive.valFromOption(path);
  }
  var tmp$1 = Js_option.map(BrowserFetcher$BsPuppeteer.platformToJs, platform);
  if (tmp$1 !== undefined) {
    tmp.platform = Js_primitive.valFromOption(tmp$1);
  }
  return tmp;
}

exports.DefaultArgsOptions = DefaultArgsOptions;
exports.makeBrowserFetcherOptions = makeBrowserFetcherOptions;
/* No side effect */
