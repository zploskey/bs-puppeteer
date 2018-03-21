'use strict';

var Js_exn = require("bs-platform/lib/js/js_exn.js");

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

exports.resourceType = resourceType;
/* No side effect */
