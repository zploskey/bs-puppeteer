'use strict';

var Js_exn = require("bs-platform/lib/js/js_exn.js");
var Belt_Option = require("bs-platform/lib/js/belt_Option.js");
var Js_mapperRt = require("bs-platform/lib/js/js_mapperRt.js");
var Js_primitive = require("bs-platform/lib/js/js_primitive.js");

var jsMapperConstantArray = /* array */[
  /* tuple */[
    -539883714,
    "OPTIONS"
  ],
  /* tuple */[
    3546230,
    "GET"
  ],
  /* tuple */[
    3997359,
    "PUT"
  ],
  /* tuple */[
    492530731,
    "DELETE"
  ],
  /* tuple */[
    891112544,
    "POST"
  ],
  /* tuple */[
    994393768,
    "PATCH"
  ]
];

function methodToJs(param) {
  return Js_mapperRt.binarySearch(6, param, jsMapperConstantArray);
}

function methodFromJs(param) {
  return Js_mapperRt.revSearch(6, jsMapperConstantArray, param);
}

function make(url, method__, postData, headers, _) {
  var method__$1 = Belt_Option.map(method__, methodToJs);
  var tmp = { };
  if (url !== undefined) {
    tmp.url = Js_primitive.valFromOption(url);
  }
  if (method__$1 !== undefined) {
    tmp.method = Js_primitive.valFromOption(method__$1);
  }
  if (postData !== undefined) {
    tmp.postData = Js_primitive.valFromOption(postData);
  }
  if (headers !== undefined) {
    tmp.headers = Js_primitive.valFromOption(headers);
  }
  return tmp;
}

var Overrides = /* module */[/* make */make];

function resourceType(req) {
  var s = req.resourceType();
  switch (s) {
    case "document" : 
        return /* Document */0;
    case "eventsource" : 
        return /* EventSource */9;
    case "fetch" : 
        return /* Fetch */8;
    case "font" : 
        return /* Font */4;
    case "image" : 
        return /* Image */2;
    case "manifest" : 
        return /* Manifest */11;
    case "media" : 
        return /* Media */3;
    case "other" : 
        return /* Other */12;
    case "script" : 
        return /* Script */5;
    case "stylesheet" : 
        return /* Stylesheet */1;
    case "texttrack" : 
        return /* TextTrack */6;
    case "websocket" : 
        return /* WebSocket */10;
    case "xhr" : 
        return /* XHR */7;
    default:
      return Js_exn.raiseError("Unknown resource type received:" + s);
  }
}

exports.methodToJs = methodToJs;
exports.methodFromJs = methodFromJs;
exports.Overrides = Overrides;
exports.resourceType = resourceType;
/* No side effect */
