'use strict';

var Util$BsPuppeteer = require("./Util.js");

function makeTracingOptions(path, screenshots, categories, _) {
  var tmp = { };
  if (path) {
    tmp.path = path[0];
  }
  var tmp$1 = Util$BsPuppeteer.optBoolToJs(screenshots);
  if (tmp$1) {
    tmp.screenshots = tmp$1[0];
  }
  if (categories) {
    tmp.categories = categories[0];
  }
  return tmp;
}

exports.makeTracingOptions = makeTracingOptions;
/* No side effect */
