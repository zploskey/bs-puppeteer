'use strict';

var $$String = require("bs-platform/lib/js/string.js");
var Pervasives = require("bs-platform/lib/js/pervasives.js");

function px(value) {
  return $$String.concat("", /* :: */[
              Pervasives.string_of_float(value),
              /* :: */[
                "px",
                /* [] */0
              ]
            ]);
}

function in_(value) {
  return $$String.concat("", /* :: */[
              Pervasives.string_of_float(value),
              /* :: */[
                "in",
                /* [] */0
              ]
            ]);
}

function cm(value) {
  return $$String.concat("", /* :: */[
              Pervasives.string_of_float(value),
              /* :: */[
                "cm",
                /* [] */0
              ]
            ]);
}

function mm(value) {
  return $$String.concat("", /* :: */[
              Pervasives.string_of_float(value),
              /* :: */[
                "mm",
                /* [] */0
              ]
            ]);
}

exports.px = px;
exports.in_ = in_;
exports.cm = cm;
exports.mm = mm;
/* No side effect */
