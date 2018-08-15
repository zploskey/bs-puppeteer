'use strict';

var Js_mapperRt = require("bs-platform/lib/js/js_mapperRt.js");

var jsMapperConstantArray = /* array */[
  /* tuple */[
    -899017797,
    "win32"
  ],
  /* tuple */[
    -899017126,
    "win64"
  ],
  /* tuple */[
    -184423436,
    "linux"
  ],
  /* tuple */[
    5442191,
    "mac"
  ]
];

function platformToJs(param) {
  return Js_mapperRt.binarySearch(4, param, jsMapperConstantArray);
}

function platformFromJs(param) {
  return Js_mapperRt.revSearch(4, jsMapperConstantArray, param);
}

function platform(t) {
  return platformFromJs(t.platform());
}

exports.platformToJs = platformToJs;
exports.platformFromJs = platformFromJs;
exports.platform = platform;
/* No side effect */
