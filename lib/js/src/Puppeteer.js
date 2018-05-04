'use strict';

var Js_option = require("bs-platform/lib/js/js_option.js");
var BrowserFetcher$BsPuppeteer = require("./BrowserFetcher.js");

function makeBrowserFetcherOptions(host, path, platform, _) {
  var tmp = { };
  if (host) {
    tmp.host = host[0];
  }
  if (path) {
    tmp.path = path[0];
  }
  var tmp$1 = Js_option.map(BrowserFetcher$BsPuppeteer.platformToJs, platform);
  if (tmp$1) {
    tmp.platform = tmp$1[0];
  }
  return tmp;
}

exports.makeBrowserFetcherOptions = makeBrowserFetcherOptions;
/* No side effect */
