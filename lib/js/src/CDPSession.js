'use strict';

var Js_undefined = require("bs-platform/lib/js/js_undefined.js");

function send(method__, params, t) {
  return t.send(method__, Js_undefined.fromOption(params));
}

exports.send = send;
/* No side effect */
