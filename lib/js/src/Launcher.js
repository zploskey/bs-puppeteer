'use strict';

var Js_primitive = require("bs-platform/lib/js/js_primitive.js");

function makeLaunchOptions(prim, prim$1, prim$2, prim$3, prim$4, prim$5, prim$6, prim$7, prim$8, prim$9, prim$10, prim$11, prim$12, prim$13, prim$14, _) {
  var tmp = { };
  if (prim !== undefined) {
    tmp.ignoreHTTPSErrors = Js_primitive.valFromOption(prim);
  }
  if (prim$1 !== undefined) {
    tmp.headless = Js_primitive.valFromOption(prim$1);
  }
  if (prim$2 !== undefined) {
    tmp.executablePath = Js_primitive.valFromOption(prim$2);
  }
  if (prim$3 !== undefined) {
    tmp.slowMo = Js_primitive.valFromOption(prim$3);
  }
  if (prim$4 !== undefined) {
    tmp.args = Js_primitive.valFromOption(prim$4);
  }
  if (prim$5 !== undefined) {
    tmp.ignoreDefaultArgs = Js_primitive.valFromOption(prim$5);
  }
  if (prim$6 !== undefined) {
    tmp.handleSIGINT = Js_primitive.valFromOption(prim$6);
  }
  if (prim$7 !== undefined) {
    tmp.handleSIGTERM = Js_primitive.valFromOption(prim$7);
  }
  if (prim$8 !== undefined) {
    tmp.handleSIGHUP = Js_primitive.valFromOption(prim$8);
  }
  if (prim$9 !== undefined) {
    tmp.timeout = Js_primitive.valFromOption(prim$9);
  }
  if (prim$10 !== undefined) {
    tmp.dumpio = Js_primitive.valFromOption(prim$10);
  }
  if (prim$11 !== undefined) {
    tmp.userDataDir = Js_primitive.valFromOption(prim$11);
  }
  if (prim$12 !== undefined) {
    tmp.env = Js_primitive.valFromOption(prim$12);
  }
  if (prim$13 !== undefined) {
    tmp.devtools = Js_primitive.valFromOption(prim$13);
  }
  if (prim$14 !== undefined) {
    tmp.pipe = Js_primitive.valFromOption(prim$14);
  }
  return tmp;
}

exports.makeLaunchOptions = makeLaunchOptions;
/* No side effect */
