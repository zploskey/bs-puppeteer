'use strict';

var Js_mapperRt = require("bs-platform/lib/js/js_mapperRt.js");

var jsMapperConstantArray = /* array */[
  /* tuple */[
    -900605361,
    "page"
  ],
  /* tuple */[
    -512407928,
    "service_worker"
  ],
  /* tuple */[
    913729232,
    "other"
  ],
  /* tuple */[
    945879976,
    "browser"
  ]
];

function pageTypeToJs(param) {
  return Js_mapperRt.binarySearch(4, param, jsMapperConstantArray);
}

function pageTypeFromJs(param) {
  return Js_mapperRt.revSearch(4, jsMapperConstantArray, param);
}

function type_(t) {
  return pageTypeFromJs(t.type());
}

exports.pageTypeToJs = pageTypeToJs;
exports.pageTypeFromJs = pageTypeFromJs;
exports.type_ = type_;
/* No side effect */
