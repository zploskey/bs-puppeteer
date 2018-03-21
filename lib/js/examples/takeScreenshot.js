'use strict';

var Process = require("process");
var Puppeteer = require("puppeteer");
var Screenshot$BsPuppeteer = require("../src/Screenshot.js");

function takeScreenshot() {
  return Puppeteer.launch(undefined).then((function (browser) {
                return browser.newPage().then((function (page) {
                                  return page.goto("https://google.com", undefined).then((function () {
                                                console.log("screenshotting");
                                                var options = Screenshot$BsPuppeteer.makeOptions(/* Some */["./screenshot.png"], /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* () */0);
                                                return page.screenshot(options);
                                              }));
                                })).then((function () {
                                return browser.close();
                              })).then((function () {
                              return Promise.resolve((Process.exit(0), /* () */0));
                            }));
              }));
}

takeScreenshot(/* () */0);

exports.takeScreenshot = takeScreenshot;
/*  Not a pure module */
