'use strict';

var Js_mapperRt = require("bs-platform/lib/js/js_mapperRt.js");

var jsMapperConstantArray = /* array */[
  /* tuple */[
    -577272933,
    "win32"
  ],
  /* tuple */[
    -577272262,
    "Win64"
  ],
  /* tuple */[
    3850863,
    "mac"
  ],
  /* tuple */[
    137321428,
    "linux"
  ]
];

function platformToJs(param) {
  return Js_mapperRt.binarySearch(4, param, jsMapperConstantArray);
}

function platformFromJs(param) {
  return Js_mapperRt.revSearch(4, jsMapperConstantArray, param);
}

exports.platformToJs = platformToJs;
exports.platformFromJs = platformFromJs;
/* No side effect */
