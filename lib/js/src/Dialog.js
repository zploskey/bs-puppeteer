'use strict';

var Js_mapperRt = require("bs-platform/lib/js/js_mapperRt.js");

var jsMapperConstantArray = /* array */[
  /* tuple */[
    -581181762,
    "beforeunload"
  ],
  /* tuple */[
    272211200,
    "confirm"
  ],
  /* tuple */[
    562976604,
    "alert"
  ],
  /* tuple */[
    894980516,
    "prompt"
  ]
];

function dialogTypeToJs(param) {
  return Js_mapperRt.binarySearch(4, param, jsMapperConstantArray);
}

function dialogTypeFromJs(param) {
  return Js_mapperRt.revSearch(4, jsMapperConstantArray, param);
}

function type_(dialog) {
  return dialogTypeFromJs(dialog.type());
}

exports.dialogTypeToJs = dialogTypeToJs;
exports.dialogTypeFromJs = dialogTypeFromJs;
exports.type_ = type_;
/* No side effect */
