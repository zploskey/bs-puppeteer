'use strict';


function makeLaunchOptions(prim, prim$1, prim$2, prim$3, prim$4, prim$5, prim$6, prim$7, prim$8, prim$9, prim$10, prim$11, prim$12, prim$13, prim$14, _) {
  var tmp = { };
  if (prim) {
    tmp.ignoreHTTPSErrors = prim[0];
  }
  if (prim$1) {
    tmp.headless = prim$1[0];
  }
  if (prim$2) {
    tmp.executablePath = prim$2[0];
  }
  if (prim$3) {
    tmp.slowMo = prim$3[0];
  }
  if (prim$4) {
    tmp.args = prim$4[0];
  }
  if (prim$5) {
    tmp.ignoreDefaultArgs = prim$5[0];
  }
  if (prim$6) {
    tmp.handleSIGINT = prim$6[0];
  }
  if (prim$7) {
    tmp.handleSIGTERM = prim$7[0];
  }
  if (prim$8) {
    tmp.handleSIGHUP = prim$8[0];
  }
  if (prim$9) {
    tmp.timeout = prim$9[0];
  }
  if (prim$10) {
    tmp.dumpio = prim$10[0];
  }
  if (prim$11) {
    tmp.userDataDir = prim$11[0];
  }
  if (prim$12) {
    tmp.env = prim$12[0];
  }
  if (prim$13) {
    tmp.devtools = prim$13[0];
  }
  if (prim$14) {
    tmp.pipe = prim$14[0];
  }
  return tmp;
}

exports.makeLaunchOptions = makeLaunchOptions;
/* No side effect */
