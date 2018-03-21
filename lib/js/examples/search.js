'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var Process = require("process");
var Puppeteer = require("puppeteer");

console.log("Executable: " + Puppeteer.executablePath());

function search() {
  return Puppeteer.launch(undefined).then((function (browser) {
                return browser.newPage().then((function (page) {
                              var options = {
                                timeout: 20000,
                                waitUntil: "load"
                              };
                              return page.goto("https://google.com", options).then((function () {
                                                        return page.type("#lst-ib", "puppeteer", undefined);
                                                      })).then((function () {
                                                      return page.click("input[type='submit']", undefined);
                                                    })).then((function () {
                                                    return page.waitForSelector("h3 a", undefined);
                                                  })).then((function () {
                                                  var partial_arg = ( function (element) { return element.textContent; } );
                                                  return page.$eval("h3 a", Curry.__1(partial_arg));
                                                })).then((function (text) {
                                                return Promise.resolve((console.log("Got:", text), /* () */0));
                                              })).then((function () {
                                              return browser.close();
                                            })).then((function () {
                                            return Promise.resolve((Process.exit(0), /* () */0));
                                          }));
                            }));
              }));
}

search(/* () */0);

exports.search = search;
/*  Not a pure module */
