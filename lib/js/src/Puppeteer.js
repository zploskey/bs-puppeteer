'use strict';

var Js_option = require("bs-platform/lib/js/js_option.js");
var Belt_Option = require("bs-platform/lib/js/belt_Option.js");
var Js_primitive = require("bs-platform/lib/js/js_primitive.js");
var BrowserFetcher$BsPuppeteer = require("./BrowserFetcher.js");

function encode(param) {
  return param[0];
}

function encodeOpt(__x) {
  return Belt_Option.map(__x, encode);
}

var IgnoreDefaultArgs = /* module */[
  /* encode */encode,
  /* encodeOpt */encodeOpt
];

function makeLaunchOptions(ignoreHTTPSErrors, headless, executablePath, slowMo, defaultViewport, args, ignoreDefaultArgs, handleSIGINT, handleSIGTERM, handleSIGHUP, timeout, dumpio, userDataDir, env, devtools, pipe, _) {
  var tmp = { };
  if (ignoreHTTPSErrors !== undefined) {
    tmp.ignoreHTTPSErrors = Js_primitive.valFromOption(ignoreHTTPSErrors);
  }
  if (headless !== undefined) {
    tmp.headless = Js_primitive.valFromOption(headless);
  }
  if (executablePath !== undefined) {
    tmp.executablePath = Js_primitive.valFromOption(executablePath);
  }
  if (slowMo !== undefined) {
    tmp.slowMo = Js_primitive.valFromOption(slowMo);
  }
  if (defaultViewport !== undefined) {
    tmp.defaultViewport = Js_primitive.valFromOption(defaultViewport);
  }
  if (args !== undefined) {
    tmp.args = Js_primitive.valFromOption(args);
  }
  var tmp$1 = Belt_Option.map(ignoreDefaultArgs, encode);
  if (tmp$1 !== undefined) {
    tmp.ignoreDefaultArgs = Js_primitive.valFromOption(tmp$1);
  }
  if (handleSIGINT !== undefined) {
    tmp.handleSIGINT = Js_primitive.valFromOption(handleSIGINT);
  }
  if (handleSIGTERM !== undefined) {
    tmp.handleSIGTERM = Js_primitive.valFromOption(handleSIGTERM);
  }
  if (handleSIGHUP !== undefined) {
    tmp.handleSIGHUP = Js_primitive.valFromOption(handleSIGHUP);
  }
  if (timeout !== undefined) {
    tmp.timeout = Js_primitive.valFromOption(timeout);
  }
  if (dumpio !== undefined) {
    tmp.dumpio = Js_primitive.valFromOption(dumpio);
  }
  if (userDataDir !== undefined) {
    tmp.userDataDir = Js_primitive.valFromOption(userDataDir);
  }
  if (env !== undefined) {
    tmp.env = Js_primitive.valFromOption(env);
  }
  if (devtools !== undefined) {
    tmp.devtools = Js_primitive.valFromOption(devtools);
  }
  if (pipe !== undefined) {
    tmp.pipe = Js_primitive.valFromOption(pipe);
  }
  return tmp;
}

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

exports.IgnoreDefaultArgs = IgnoreDefaultArgs;
exports.makeLaunchOptions = makeLaunchOptions;
exports.DefaultArgsOptions = DefaultArgsOptions;
exports.makeBrowserFetcherOptions = makeBrowserFetcherOptions;
/* No side effect */
