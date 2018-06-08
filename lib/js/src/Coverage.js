'use strict';


function startCSSCoverage(options, t) {
  return t.startCSSCoverage(options ? options[0] : undefined);
}

function startJSCoverage(options, t) {
  return t.startJSCoverage(options ? options[0] : undefined);
}

exports.startCSSCoverage = startCSSCoverage;
exports.startJSCoverage = startJSCoverage;
/* No side effect */
