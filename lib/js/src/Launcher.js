'use strict';

var Js_primitive = require("bs-platform/lib/js/js_primitive.js");

function makeLaunchOptions(prim, prim$1, prim$2, prim$3, prim$4, prim$5, prim$6, prim$7, prim$8, prim$9, prim$10, prim$11, prim$12, prim$13, prim$14, _) {
  var tmp = { };
  if (prim) {
    tmp.ignoreHTTPSErrors = Js_primitive.valFromOption(prim);
  }
  if (prim$1) {
    tmp.headless = Js_primitive.valFromOption(prim$1);
  }
  if (prim$2) {
    tmp.executablePath = Js_primitive.valFromOption(prim$2);
  }
  if (prim$3) {
    tmp.slowMo = Js_primitive.valFromOption(prim$3);
  }
  if (prim$4) {
    tmp.args = Js_primitive.valFromOption(prim$4);
  }
  if (prim$5) {
    tmp.ignoreDefaultArgs = Js_primitive.valFromOption(prim$5);
  }
  if (prim$6) {
    tmp.handleSIGINT = Js_primitive.valFromOption(prim$6);
  }
  if (prim$7) {
    tmp.handleSIGTERM = Js_primitive.valFromOption(prim$7);
  }
  if (prim$8) {
    tmp.handleSIGHUP = Js_primitive.valFromOption(prim$8);
  }
  if (prim$9) {
    tmp.timeout = Js_primitive.valFromOption(prim$9);
  }
  if (prim$10) {
    tmp.dumpio = Js_primitive.valFromOption(prim$10);
  }
  if (prim$11) {
    tmp.userDataDir = Js_primitive.valFromOption(prim$11);
  }
  if (prim$12) {
    tmp.env = Js_primitive.valFromOption(prim$12);
  }
  if (prim$13) {
    tmp.devtools = Js_primitive.valFromOption(prim$13);
  }
  if (prim$14) {
    tmp.pipe = Js_primitive.valFromOption(prim$14);
  }
  return tmp;
}

exports.makeLaunchOptions = makeLaunchOptions;
/* No side effect */
