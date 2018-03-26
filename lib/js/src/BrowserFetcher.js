'use strict';

var Js_mapperRt = require("bs-platform/lib/js/js_mapperRt.js");
var Js_undefined = require("bs-platform/lib/js/js_undefined.js");

function download(revision, progressCallback, t) {
  return t.download(revision, Js_undefined.fromOption(progressCallback));
}

var jsMapperConstantArray = /* array */[
  /* tuple */[
    -577272933,
    "win32"
  ],
  /* tuple */[
    -577272262,
    "win64"
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

function platform(t) {
  return platformFromJs(t.platform());
}

exports.download = download;
exports.platformToJs = platformToJs;
exports.platformFromJs = platformFromJs;
exports.platform = platform;
/* No side effect */
