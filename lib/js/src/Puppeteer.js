'use strict';

var Js_option = require("bs-platform/lib/js/js_option.js");
var Util$BsPuppeteer = require("./Util.js");
var BrowserFetcher$BsPuppeteer = require("./BrowserFetcher.js");

function makeConnectOptions(browserWSEndpoint, ignoreHTTPSErrors, _) {
  var tmp = { };
  if (browserWSEndpoint) {
    tmp.browserWSEndpoint = browserWSEndpoint[0];
  }
  var tmp$1 = Util$BsPuppeteer.optBoolToJs(ignoreHTTPSErrors);
  if (tmp$1) {
    tmp.ignoreHTTPSErrors = tmp$1[0];
  }
  return tmp;
}

function makeLaunchOptions(ignoreHTTPSErrors, headless, executablePath, slowMo, args, ignoreDefaultArgs, handleSIGINT, handleSIGTERM, handleSIGHUP, timeout, dumpio, userDataDir, env, devtools, pipe, _) {
  var tmp = { };
  var tmp$1 = Util$BsPuppeteer.optBoolToJs(ignoreHTTPSErrors);
  if (tmp$1) {
    tmp.ignoreHTTPSErrors = tmp$1[0];
  }
  var tmp$2 = Util$BsPuppeteer.optBoolToJs(headless);
  if (tmp$2) {
    tmp.headless = tmp$2[0];
  }
  if (executablePath) {
    tmp.executablePath = executablePath[0];
  }
  if (slowMo) {
    tmp.slowMo = slowMo[0];
  }
  if (args) {
    tmp.args = args[0];
  }
  var tmp$3 = Util$BsPuppeteer.optBoolToJs(ignoreDefaultArgs);
  if (tmp$3) {
    tmp.ignoreDefaultArgs = tmp$3[0];
  }
  var tmp$4 = Util$BsPuppeteer.optBoolToJs(handleSIGINT);
  if (tmp$4) {
    tmp.handleSIGINT = tmp$4[0];
  }
  var tmp$5 = Util$BsPuppeteer.optBoolToJs(handleSIGTERM);
  if (tmp$5) {
    tmp.handleSIGTERM = tmp$5[0];
  }
  var tmp$6 = Util$BsPuppeteer.optBoolToJs(handleSIGHUP);
  if (tmp$6) {
    tmp.handleSIGHUP = tmp$6[0];
  }
  if (timeout) {
    tmp.timeout = timeout[0];
  }
  var tmp$7 = Util$BsPuppeteer.optBoolToJs(dumpio);
  if (tmp$7) {
    tmp.dumpio = tmp$7[0];
  }
  if (userDataDir) {
    tmp.userDataDir = userDataDir[0];
  }
  if (env) {
    tmp.env = env[0];
  }
  var tmp$8 = Util$BsPuppeteer.optBoolToJs(devtools);
  if (tmp$8) {
    tmp.devtools = tmp$8[0];
  }
  var tmp$9 = Util$BsPuppeteer.optBoolToJs(pipe);
  if (tmp$9) {
    tmp.pipe = tmp$9[0];
  }
  return tmp;
}

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

exports.makeConnectOptions = makeConnectOptions;
exports.makeLaunchOptions = makeLaunchOptions;
exports.makeBrowserFetcherOptions = makeBrowserFetcherOptions;
/* No side effect */
