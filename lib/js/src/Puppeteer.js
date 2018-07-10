'use strict';

var Js_option = require("bs-platform/lib/js/js_option.js");
var Js_primitive = require("bs-platform/lib/js/js_primitive.js");
var BrowserFetcher$BsPuppeteer = require("./BrowserFetcher.js");

function makeBrowserFetcherOptions(host, path, platform, _) {
  var tmp = { };
  if (host) {
    tmp.host = Js_primitive.valFromOption(host);
  }
  if (path) {
    tmp.path = Js_primitive.valFromOption(path);
  }
  var tmp$1 = Js_option.map(BrowserFetcher$BsPuppeteer.platformToJs, platform);
  if (tmp$1) {
    tmp.platform = Js_primitive.valFromOption(tmp$1);
  }
  return tmp;
}

exports.makeBrowserFetcherOptions = makeBrowserFetcherOptions;
/* No side effect */
