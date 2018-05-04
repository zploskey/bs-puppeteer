'use strict';

var Process = require("process");
var Puppeteer = require("puppeteer");

function takeScreenshot() {
  return Puppeteer.launch(undefined).then((function (browser) {
                return browser.newPage().then((function (page) {
                                  return page.goto("https://google.com", undefined).then((function () {
                                                console.log("screenshotting");
                                                var options = {
                                                  path: "./screenshot.png"
                                                };
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
