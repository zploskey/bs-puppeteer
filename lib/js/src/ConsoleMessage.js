'use strict';

var Js_mapperRt = require("bs-platform/lib/js/js_mapperRt.js");

var jsMapperConstantArray = /* array */[
  /* tuple */[
    -977586066,
    "info"
  ],
  /* tuple */[
    -933531251,
    "clear"
  ],
  /* tuple */[
    -899463985,
    "count"
  ],
  /* tuple */[
    -685813165,
    "debug"
  ],
  /* tuple */[
    -656984626,
    "timeEnd"
  ],
  /* tuple */[
    -600255950,
    "profileEnd"
  ],
  /* tuple */[
    -471045350,
    "startGroupCollapsed"
  ],
  /* tuple */[
    -215364664,
    "error"
  ],
  /* tuple */[
    -213300951,
    "profile"
  ],
  /* tuple */[
    4996429,
    "dir"
  ],
  /* tuple */[
    5395588,
    "log"
  ],
  /* tuple */[
    164354652,
    "warning"
  ],
  /* tuple */[
    182695950,
    "table"
  ],
  /* tuple */[
    371166853,
    "trace"
  ],
  /* tuple */[
    401753444,
    "endGroup"
  ],
  /* tuple */[
    906726269,
    "startGroup"
  ],
  /* tuple */[
    920299225,
    "assert"
  ],
  /* tuple */[
    1014546090,
    "dirxml"
  ]
];

function messageTypeToJs(param) {
  return Js_mapperRt.binarySearch(18, param, jsMapperConstantArray);
}

function messageTypeFromJs(param) {
  return Js_mapperRt.revSearch(18, jsMapperConstantArray, param);
}

function type_(t) {
  return messageTypeFromJs(t.type());
}

exports.messageTypeToJs = messageTypeToJs;
exports.messageTypeFromJs = messageTypeFromJs;
exports.type_ = type_;
/* No side effect */
