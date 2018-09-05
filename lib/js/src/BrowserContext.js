'use strict';

var $$Array = require("bs-platform/lib/js/array.js");
var Js_mapperRt = require("bs-platform/lib/js/js_mapperRt.js");

var jsMapperConstantArray = /* array */[
  /* tuple */[
    -970104761,
    "accesibilityEvents"
  ],
  /* tuple */[
    -956395323,
    "gyroscope"
  ],
  /* tuple */[
    -933476895,
    "midi"
  ],
  /* tuple */[
    -899608102,
    "push"
  ],
  /* tuple */[
    -617037192,
    "ambient-light-sensor"
  ],
  /* tuple */[
    -533823412,
    "clipboard-read"
  ],
  /* tuple */[
    151985871,
    "accelerometer"
  ],
  /* tuple */[
    185694564,
    "payment-handler"
  ],
  /* tuple */[
    315713478,
    "geolocation"
  ],
  /* tuple */[
    451566879,
    "midi-sysex"
  ],
  /* tuple */[
    544868713,
    "background-sync"
  ],
  /* tuple */[
    612348388,
    "magnetometer"
  ],
  /* tuple */[
    727379946,
    "microphone"
  ],
  /* tuple */[
    764221224,
    "notifications"
  ],
  /* tuple */[
    840994601,
    "clipboard-write"
  ],
  /* tuple */[
    931940005,
    "camera"
  ]
];

function permissionToJs(param) {
  return Js_mapperRt.binarySearch(16, param, jsMapperConstantArray);
}

function permissionFromJs(param) {
  return Js_mapperRt.revSearch(16, jsMapperConstantArray, param);
}

function overridePermissions(ctx, origin, permissions) {
  var permissions$1 = $$Array.map(permissionToJs, permissions);
  return ctx.overridePermissionsUnsafe(origin, permissions$1);
}

exports.permissionToJs = permissionToJs;
exports.permissionFromJs = permissionFromJs;
exports.overridePermissions = overridePermissions;
/* No side effect */
