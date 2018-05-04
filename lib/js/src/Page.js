'use strict';


function setBypassCSP(enabled, page) {
  return page.setBypassCSP(enabled);
}

exports.setBypassCSP = setBypassCSP;
/* No side effect */
