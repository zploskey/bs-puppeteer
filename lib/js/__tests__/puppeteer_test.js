'use strict';

var Fs = require("fs");
var Jest = require("@glennsl/bs-jest/lib/js/src/jest.js");
var Path = require("path");
var Curry = require("bs-platform/lib/js/curry.js");
var Js_exn = require("bs-platform/lib/js/js_exn.js");
var Js_dict = require("bs-platform/lib/js/js_dict.js");
var Js_null = require("bs-platform/lib/js/js_null.js");
var Js_option = require("bs-platform/lib/js/js_option.js");
var Puppeteer = require("puppeteer");
var Caml_array = require("bs-platform/lib/js/caml_array.js");
var Caml_int32 = require("bs-platform/lib/js/caml_int32.js");
var Pervasives = require("bs-platform/lib/js/pervasives.js");
var Js_primitive = require("bs-platform/lib/js/js_primitive.js");
var Page$BsPuppeteer = require("../src/Page.js");
var Unit$BsPuppeteer = require("../src/Unit.js");
var Target$BsPuppeteer = require("../src/Target.js");
var Coverage$BsPuppeteer = require("../src/Coverage.js");
var Puppeteer$BsPuppeteer = require("../src/Puppeteer.js");
var CDPSession$BsPuppeteer = require("../src/CDPSession.js");
var BrowserFetcher$BsPuppeteer = require("../src/BrowserFetcher.js");

function seconds(v) {
  return Caml_int32.imul(v, 1000);
}

var getElementValueJs = ( function (element) { return element.value; } );

var getLengthOfElementsJs = ( function (elements) { return elements.length; } );

var getElementOuterHTMLJs = ( function (element) { return element.outerHTML; } );

var getElementOuterHTMLJsPromise = ( function (element) { return Promise.resolve(element.outerHTML); } );

var fixturesPath = Path.resolve(Js_option.getWithDefault("", Js_primitive.undefined_to_opt(typeof (__dirname) === "undefined" ? undefined : (__dirname))), "../../../__tests__/fixtures/");

var testPagePath = Path.resolve(fixturesPath, "./testPage.html");

var testPageJsPath = Path.resolve(fixturesPath, "./testPage.js");

var testPageCssPath = Path.resolve(fixturesPath, "./testPage.css");

var testPageContent = Fs.readFileSync(testPagePath, "utf8");

var noSandbox = {
  args: /* array */["--no-sandbox"]
};

describe("Puppeteer", (function () {
        Jest.test("executablePath", (function () {
                return Jest.Expect[/* toContainString */11]("chromium", Jest.Expect[/* expect */0](Puppeteer.executablePath()));
              }));
        return Jest.test("defaultArgs()", (function () {
                      return Jest.Expect[/* toBeGreaterThan */5](0, Jest.Expect[/* expect */0](Puppeteer.defaultArgs().length));
                    }));
      }));

describe("BrowserFetcher", (function () {
        var browserFetcher = /* record */[/* contents : () */0];
        beforeAll((function () {
                browserFetcher[0] = Puppeteer.createBrowserFetcher(Puppeteer$BsPuppeteer.makeBrowserFetcherOptions(undefined, undefined, undefined, /* () */0));
                return /* () */0;
              }));
        Jest.testPromise(undefined, "canDownload", (function () {
                return browserFetcher[0].canDownload("533271").then((function ($$boolean) {
                              return Promise.resolve(Jest.Expect[/* toBe */2](true, Jest.Expect[/* expect */0]($$boolean)));
                            }));
              }));
        Jest.testPromise(30000, "download", (function () {
                return (function (eta) {
                              return BrowserFetcher$BsPuppeteer.download("533271", undefined, eta);
                            })(browserFetcher[0]).then((function (info) {
                              return Promise.resolve(Jest.Expect[/* toBe */2]("533271", Jest.Expect[/* expect */0](info.revision)));
                            }));
              }));
        Jest.testPromise(undefined, "localRevisions", (function () {
                return browserFetcher[0].localRevisions().then((function (revisions) {
                              return Promise.resolve(Jest.Expect[/* toHaveLength */13](2, Jest.Expect[/* expect */0](revisions)));
                            }));
              }));
        Jest.test("platform", (function () {
                return Jest.Expect[/* toEqual */12](/* linux */-184423436, Jest.Expect[/* expect */0](BrowserFetcher$BsPuppeteer.platform(browserFetcher[0])));
              }));
        it.skip(30000, "remove", (function () {
                return (function (eta) {
                                  return BrowserFetcher$BsPuppeteer.download("533273", undefined, eta);
                                })(browserFetcher[0]).then((function () {
                                  return browserFetcher[0].remove("533273");
                                })).then((function () {
                                return Promise.resolve(Jest.pass);
                              })).catch((function () {
                              return Promise.resolve(Jest.fail("the revision has not been downloaded"));
                            }));
              }));
        return Jest.test("revisionInfo", (function () {
                      var revisionInfo = browserFetcher[0].revisionInfo("533271");
                      Jest.Expect[/* toBe */2]("533271", Jest.Expect[/* expect */0](revisionInfo.revision));
                      Jest.Expect[/* toContainString */11]("chromium", Jest.Expect[/* expect */0](revisionInfo.executablePath));
                      Jest.Expect[/* toContainString */11]("chromium", Jest.Expect[/* expect */0](revisionInfo.folderPath));
                      Jest.Expect[/* toBe */2](true, Jest.Expect[/* expect */0](revisionInfo.local));
                      return Jest.Expect[/* toContainString */11]("https://storage.googleapis.com/", Jest.Expect[/* expect */0](revisionInfo.url));
                    }));
      }));

describe("Browser", (function () {
        var browser = /* record */[/* contents : () */0];
        Jest.beforeAllPromise(undefined, (function () {
                return Puppeteer.launch(noSandbox).then((function (res) {
                              browser[0] = res;
                              return Promise.resolve(/* () */0);
                            }));
              }));
        Jest.test("wsEndpoint()", (function () {
                return Jest.Expect[/* toContainString */11]("ws://127.0.0.1:", Jest.Expect[/* expect */0](browser[0].wsEndpoint()));
              }));
        Jest.testPromise(undefined, "userAgent()", (function () {
                return browser[0].userAgent().then((function (userAgent) {
                              return Promise.resolve(Jest.Expect[/* toContainString */11]("HeadlessChrome", Jest.Expect[/* expect */0](userAgent)));
                            }));
              }));
        Jest.testPromise(undefined, "version()", (function () {
                return browser[0].version().then((function (version) {
                              return Promise.resolve(Jest.Expect[/* toMatchRe */15]((/^HeadlessChrome/), Jest.Expect[/* expect */0](version)));
                            }));
              }));
        return Jest.afterAllPromise(undefined, (function () {
                      return browser[0].close();
                    }));
      }));

describe("Page", (function () {
        var browser = /* record */[/* contents : () */0];
        var page = /* record */[/* contents : () */0];
        Jest.beforeAllPromise(undefined, (function () {
                return Puppeteer.launch(noSandbox).then((function (res) {
                                browser[0] = res;
                                return browser[0].newPage();
                              })).then((function (res) {
                              page[0] = res;
                              return Promise.resolve(/* () */0);
                            }));
              }));
        Jest.testPromise(undefined, "$()", (function () {
                return page[0].$("body").then((function (elementHandle) {
                              return Promise.resolve(Jest.ExpectJs[/* toBeTruthy */28](Jest.Expect[/* expect */0](elementHandle)));
                            }));
              }));
        Jest.testPromise(undefined, "content()", (function () {
                return page[0].content().then((function (content) {
                              return Promise.resolve(Jest.ExpectJs[/* toBe */2]("<html><head></head><body></body></html>", Jest.Expect[/* expect */0](content)));
                            }));
              }));
        Jest.testPromise(undefined, "$$()", (function () {
                return page[0].$$("html,body").then((function (elementHandles) {
                              return Promise.resolve(Jest.ExpectJs[/* toHaveLength */13](2, Jest.Expect[/* expect */0](elementHandles)));
                            }));
              }));
        Jest.testPromise(undefined, "$x", (function () {
                return page[0].$x("/html/body").then((function (elementHandles) {
                              return Promise.resolve(Jest.ExpectJs[/* toHaveLength */13](1, Jest.Expect[/* expect */0](elementHandles)));
                            }));
              }));
        Jest.testPromise(undefined, "$$eval()", (function () {
                return page[0].$$eval("html,body", Curry.__1(getLengthOfElementsJs)).then((function (length) {
                              return Promise.resolve(Jest.Expect[/* toBe */2](2.0, Jest.Expect[/* expect */0](length)));
                            }));
              }));
        Jest.testPromise(undefined, "$eval() with 0 args", (function () {
                return page[0].$eval("html", Curry.__1(getElementOuterHTMLJs)).then((function (html) {
                              return Promise.resolve(Jest.Expect[/* toBe */2]("<html><head></head><body></body></html>", Jest.Expect[/* expect */0](html)));
                            }));
              }));
        Jest.testPromise(undefined, "$eval() with 0 args returning a promise", (function () {
                return page[0].$eval("html", Curry.__1(getElementOuterHTMLJsPromise)).then((function (h) {
                              return Promise.resolve(Jest.Expect[/* toBe */2]("<html><head></head><body></body></html>", Jest.Expect[/* expect */0](h)));
                            }));
              }));
        Jest.testPromise(undefined, "$eval() with 1 arg", (function () {
                return page[0].setContent(testPageContent).then((function () {
                                var partial_arg = ( function (el, prop) { return el.getAttribute(prop); } );
                                return page[0].$eval("input", Curry.__2(partial_arg), "id");
                              })).then((function (id) {
                              return Promise.resolve(Jest.Expect[/* toBe */2]("input", Jest.Expect[/* expect */0](id)));
                            }));
              }));
        Jest.testPromise(undefined, "click()", (function () {
                return page[0].click("body", undefined).then((function () {
                              return Promise.resolve(Jest.pass);
                            }));
              }));
        Jest.testPromise(undefined, "goto()", (function () {
                return browser[0].newPage().then((function (page) {
                                  var options = {
                                    timeout: 25000
                                  };
                                  return page.goto("file://" + testPagePath, options);
                                })).then((function (res) {
                                return Js_null.getExn(res).text();
                              })).then((function (text) {
                              return Promise.resolve(Jest.Expect[/* toContainString */11]("<title>Test Page</title>", Jest.Expect[/* expect */0](text)));
                            }));
              }));
        Jest.testPromise(undefined, "screenshot()", (function () {
                return page[0].screenshot(undefined).then((function (buf) {
                              return Promise.resolve(Jest.Expect[/* toBeGreaterThanOrEqual */6](3236, Jest.Expect[/* expect */0](buf.toString().length)));
                            }));
              }));
        it.skip(undefined, "waitForResponseUrl()", (function () {
                var url = "file:///" + testPagePath;
                return Promise.all(/* tuple */[
                              Page$BsPuppeteer.waitForResponseUrl(page[0], url, undefined, /* () */0),
                              page[0].evaluate((function () {
                                      return fetch("/testPage.html");
                                    }))
                            ]).then((function (param) {
                              return Promise.resolve(Jest.Expect[/* toEqual */12](url, Jest.Expect[/* expect */0](param[0].url())));
                            }));
              }));
        Jest.testPromise(undefined, "waitForSelector()", (function () {
                return page[0].waitForSelector("body", undefined).then((function () {
                              return Promise.resolve(Jest.pass);
                            }));
              }));
        Jest.testPromise(undefined, "waitForXPath()", (function () {
                return page[0].waitForXPath("/html/body", {
                              timeout: 100
                            }).then((function (elementHandle) {
                              return Promise.resolve(Jest.ExpectJs[/* toBeTruthy */28](Jest.Expect[/* expect */0](elementHandle)));
                            }));
              }));
        Jest.testPromise(undefined, "setExtraHTTPHeaders", (function () {
                return page[0].setExtraHTTPHeaders(Js_dict.fromList(/* :: */[
                                  /* tuple */[
                                    "extra-http-header",
                                    "header01"
                                  ],
                                  /* [] */0
                                ])).then((function () {
                              return Promise.resolve(Jest.pass);
                            }));
              }));
        Jest.testPromise(undefined, "type()", (function () {
                return browser[0].newPage().then((function (page) {
                                return page.setContent(testPageContent).then((function () {
                                                return page.type("#input", "hello world", undefined);
                                              })).then((function () {
                                              return page.$eval("#input", Curry.__1(getElementValueJs));
                                            }));
                              })).then((function (value) {
                              return Promise.resolve(Jest.Expect[/* toBe */2]("hello world", Jest.Expect[/* expect */0](value)));
                            }));
              }));
        Jest.testPromise(undefined, "addScriptTag()", (function () {
                return browser[0].newPage().then((function (page) {
                              return page.addScriptTag({
                                              path: testPageJsPath
                                            }).then((function () {
                                              return page.content();
                                            })).then((function (content) {
                                            return page.close(undefined).then((function () {
                                                          return Promise.resolve(Jest.Expect[/* toContainString */11]("// This is \"testPage.js\"", Jest.Expect[/* expect */0](content)));
                                                        }));
                                          }));
                            }));
              }));
        Jest.testPromise(undefined, "addStyleTag()", (function () {
                return browser[0].newPage().then((function (page) {
                              return page.addStyleTag({
                                              path: testPageCssPath
                                            }).then((function () {
                                              return page.content();
                                            })).then((function (content) {
                                            return page.close(undefined).then((function () {
                                                          return Promise.resolve(Jest.Expect[/* toContainString */11]("/* This is \"testPage.css\" */", Jest.Expect[/* expect */0](content)));
                                                        }));
                                          }));
                            }));
              }));
        Jest.testPromise(undefined, "authenticate()", (function () {
                return page[0].authenticate({
                              username: "foo",
                              password: "bar"
                            }).then((function () {
                              return Promise.resolve(Jest.pass);
                            }));
              }));
        Jest.testPromise(undefined, "cookies()", (function () {
                return page[0].setCookie({
                                name: "foo",
                                value: "bar",
                                url: "http://localhost"
                              }).then((function () {
                                return page[0].cookies("http://localhost");
                              })).then((function (cookies) {
                              return Promise.resolve(Jest.Expect[/* toHaveLength */13](1, Jest.Expect[/* expect */0](cookies)));
                            }));
              }));
        Jest.testPromise(undefined, "setCookie()", (function () {
                return page[0].setCookie({
                                name: "foo",
                                value: "bar",
                                url: "http://localhost"
                              }, {
                                name: "foo2",
                                value: "bar2",
                                url: "http://localhost2"
                              }).then((function () {
                                return page[0].cookies("http://localhost", "http://localhost2");
                              })).then((function (cookies) {
                              return Promise.resolve(Jest.Expect[/* toHaveLength */13](2, Jest.Expect[/* expect */0](cookies)));
                            }));
              }));
        Jest.testPromise(undefined, "deleteCookie()", (function () {
                return page[0].setCookie({
                                  name: "foo",
                                  value: "bar",
                                  url: "http://localhost"
                                }).then((function () {
                                  return page[0].deleteCookie();
                                })).then((function () {
                                return page[0].cookies();
                              })).then((function (cookies) {
                              return Promise.resolve(Jest.Expect[/* toHaveLength */13](0, Jest.Expect[/* expect */0](cookies)));
                            }));
              }));
        Jest.testPromise(undefined, "emulate()", (function () {
                var viewport = Curry._7(Page$BsPuppeteer.Viewport[/* make */0], 320, 480, 2, undefined, true, undefined, /* () */0);
                return page[0].emulate({
                              viewport: viewport,
                              userAgent: ""
                            }).then((function () {
                              return Promise.resolve(Jest.Expect[/* toEqual */12](viewport, Jest.Expect[/* expect */0](page[0].viewport())));
                            }));
              }));
        Jest.testPromise(undefined, "emulateMedia()", (function () {
                return page[0].emulateMedia("print").then((function () {
                              return Promise.resolve(Jest.pass);
                            }));
              }));
        Jest.testPromise(undefined, "emulateMediaDisable()", (function () {
                return page[0].emulateMedia(null).then((function () {
                              return Promise.resolve(Jest.pass);
                            }));
              }));
        Jest.testPromise(undefined, "evaluate()", (function () {
                var $$eval = function () {
                  return "ok";
                };
                return page[0].evaluate($$eval).then((function (res) {
                              return Promise.resolve(Jest.Expect[/* toBe */2]("ok", Jest.Expect[/* expect */0](res)));
                            }));
              }));
        Jest.testPromise(undefined, "evaluate() with 1 arg", (function () {
                var $$eval = function (arg) {
                  return arg + "iedoke";
                };
                return page[0].evaluate($$eval, "ok").then((function (res) {
                              return Promise.resolve(Jest.Expect[/* toBe */2]("okiedoke", Jest.Expect[/* expect */0](res)));
                            }));
              }));
        Jest.testPromise(undefined, "evaluate1() and a curried function", (function () {
                return page[0].evaluate((function (param) {
                                var arg1 = "hello";
                                var arg2 = param;
                                return arg1 + (" " + arg2);
                              }), "world").then((function (res) {
                              return Promise.resolve(Jest.Expect[/* toBe */2]("hello world", Jest.Expect[/* expect */0](res)));
                            }));
              }));
        Jest.testPromise(undefined, "evaluatePromise1() with a curried function", (function () {
                return page[0].evaluate((function (param) {
                                var arg1 = "hello";
                                var arg2 = param;
                                return Promise.resolve(arg1 + (" " + arg2));
                              }), "world").then((function (res) {
                              return Promise.resolve(Jest.Expect[/* toBe */2]("hello world", Jest.Expect[/* expect */0](res)));
                            }));
              }));
        Jest.testPromise(undefined, "evaluatePromise2() with a curried function", (function () {
                return page[0].evaluate((function (param, param$1) {
                                var arg1 = "hello";
                                var arg2 = param;
                                var arg3 = param$1;
                                return Promise.resolve(arg1 + (" " + (arg2 + arg3)));
                              }), "world", "!").then((function (res) {
                              return Promise.resolve(Jest.Expect[/* toBe */2]("hello world!", Jest.Expect[/* expect */0](res)));
                            }));
              }));
        Jest.testPromise(undefined, "evaluate() with 2 args", (function () {
                var $$eval = function (arg1, arg2) {
                  return arg1.length.toString() + (arg1 + (" " + arg2));
                };
                return page[0].evaluate($$eval, "hello", "world").then((function (res) {
                              return Promise.resolve(Jest.Expect[/* toBe */2]("5hello world", Jest.Expect[/* expect */0](res)));
                            }));
              }));
        Jest.testPromise(undefined, "evaluateString()", (function () {
                return page[0].setContent(testPageContent).then((function () {
                              return page[0].evaluate(" document.getElementsByTagName(\"title\")[0].innerHTML; ").then((function (title) {
                                            return Promise.resolve(Jest.Expect[/* toBe */2]("Test Page", Jest.Expect[/* expect */0](title)));
                                          }));
                            }));
              }));
        Jest.testPromise(undefined, "evaluateHandle()", (function () {
                var $$eval = function () {
                  return ( document );
                };
                return page[0].evaluateHandle($$eval).then((function (jsHandler) {
                              return Promise.resolve(Jest.ExpectJs[/* toBeTruthy */28](Jest.Expect[/* expect */0](jsHandler)));
                            }));
              }));
        Jest.testPromise(undefined, "pdf()", (function () {
                return page[0].pdf({
                              scale: 1,
                              displayHeaderFooter: true,
                              headerTemplate: "[[header]]",
                              footerTemplate: "[[footer]]",
                              printBackground: true,
                              landscape: true,
                              pageRanges: "",
                              format: "A0",
                              width: Unit$BsPuppeteer.cm(10.0),
                              height: Unit$BsPuppeteer.mm(200.0),
                              margin: {
                                top: Unit$BsPuppeteer.cm(0.1),
                                right: Unit$BsPuppeteer.px(10.0),
                                bottom: Unit$BsPuppeteer.mm(1.0),
                                left: Unit$BsPuppeteer.in_(0.01)
                              }
                            }).then((function (buffer) {
                              return Promise.resolve(Jest.Expect[/* toBeGreaterThan */5](5000, Jest.Expect[/* expect */0](buffer.toString().length)));
                            }));
              }));
        Jest.test("target()", (function () {
                return Jest.Expect[/* toBe */2]("about:blank", Jest.Expect[/* expect */0](page[0].target().url()));
              }));
        Jest.test("coverage", (function () {
                return Jest.ExpectJs[/* toBeTruthy */28](Jest.Expect[/* expect */0](page[0].coverage));
              }));
        return Jest.afterAllPromise(undefined, (function () {
                      return page[0].close(undefined).then((function () {
                                    return browser[0].close();
                                  }));
                    }));
      }));

describe("ElementHandle", (function () {
        var browser = /* record */[/* contents : () */0];
        var page = /* record */[/* contents : () */0];
        var elementHandle = /* record */[/* contents : () */0];
        Jest.beforeAllPromise(undefined, (function () {
                return Puppeteer.launch(noSandbox).then((function (res) {
                                    browser[0] = res;
                                    return browser[0].newPage();
                                  })).then((function (res) {
                                  page[0] = res;
                                  return page[0].goto("file://" + testPagePath, undefined);
                                })).then((function () {
                                return page[0].$("#iframe");
                              })).then((function (res) {
                              if (res !== null) {
                                elementHandle[0] = res;
                                return Promise.resolve(/* () */0);
                              } else {
                                return Promise.reject(Js_exn.raiseError("failed to initial an elementhandle"));
                              }
                            }));
              }));
        Jest.testPromise(undefined, "contentFrame()", (function () {
                return elementHandle[0].contentFrame().then((function (frame) {
                              if (frame !== null) {
                                return Promise.resolve(Jest.ExpectJs[/* toBeTruthy */28](Jest.Expect[/* expect */0](frame)));
                              } else {
                                return Promise.reject(Js_exn.raiseError("failed to get frame from contentFrame"));
                              }
                            }));
              }));
        return Jest.afterAllPromise(undefined, (function () {
                      return page[0].close(undefined).then((function () {
                                    return browser[0].close();
                                  }));
                    }));
      }));

describe("Target", (function () {
        var browser = /* record */[/* contents : () */0];
        var target = /* record */[/* contents : () */0];
        Jest.beforeAllPromise(undefined, (function () {
                return Puppeteer.launch(noSandbox).then((function (res) {
                                browser[0] = res;
                                return res.newPage();
                              })).then((function (page) {
                              target[0] = page.target();
                              return Promise.resolve(target);
                            }));
              }));
        Jest.testPromise(undefined, "page", (function () {
                return target[0].page().then((function (page) {
                              return Promise.resolve(Jest.ExpectJs[/* toBeTruthy */28](Jest.Expect[/* expect */0](page)));
                            }));
              }));
        Jest.test("type", (function () {
                var match = Target$BsPuppeteer.type_(target[0]);
                return Jest.Expect[/* toBe */2](true, Jest.Expect[/* expect */0](match !== undefined ? match === /* page */-900605361 : false));
              }));
        Jest.test("url", (function () {
                return Jest.Expect[/* toBe */2]("about:blank", Jest.Expect[/* expect */0](target[0].url()));
              }));
        Jest.testPromise(undefined, "createCDPSession", (function () {
                return target[0].createCDPSession().then((function (session) {
                              return Promise.resolve(Jest.ExpectJs[/* toBeTruthy */28](Jest.Expect[/* expect */0](session)));
                            }));
              }));
        return Jest.afterAllPromise(undefined, (function () {
                      return browser[0].close();
                    }));
      }));

describe("CDPSession", (function () {
        var browser = /* record */[/* contents : () */0];
        Jest.beforeAllPromise(undefined, (function () {
                return Puppeteer.launch(noSandbox).then((function (res) {
                              browser[0] = res;
                              return Promise.resolve(res);
                            }));
              }));
        Jest.testPromise(undefined, "detach", (function () {
                return browser[0].newPage().then((function (page) {
                                return page.target().createCDPSession();
                              })).then((function (session) {
                              return session.detach().then((function () {
                                                return (function (eta) {
                                                            return CDPSession$BsPuppeteer.send("Animation.getPlaybackRate", undefined, eta);
                                                          })(session);
                                              })).then((function () {
                                              return Promise.resolve(Pervasives.failwith("expect with exception: Error: Protocol error (Animation.getPlaybackRate): Session closed. Most likely the page has been closed."));
                                            })).catch((function () {
                                            return Promise.resolve(Jest.pass);
                                          }));
                            }));
              }));
        Jest.testPromise(undefined, "send", (function () {
                return browser[0].newPage().then((function (page) {
                                return page.target().createCDPSession();
                              })).then((function (session) {
                              return CDPSession$BsPuppeteer.send("Animation.setPlaybackRate", {
                                              playbackRate: 3.1415926535
                                            }, session).then((function () {
                                              return (function (eta) {
                                                          return CDPSession$BsPuppeteer.send("Animation.getPlaybackRate", undefined, eta);
                                                        })(session);
                                            })).then((function (res) {
                                            return Promise.resolve(Jest.Expect[/* toBe */2](3.1415926535, Jest.Expect[/* expect */0](res.playbackRate)));
                                          }));
                            }));
              }));
        return Jest.afterAllPromise(undefined, (function () {
                      return browser[0].close();
                    }));
      }));

describe("Coverage", (function () {
        var browser = /* record */[/* contents : () */0];
        Jest.beforeAllPromise(undefined, (function () {
                return Puppeteer.launch(noSandbox).then((function (res) {
                              browser[0] = res;
                              return Promise.resolve(res);
                            }));
              }));
        describe("startJSCoverage, stopJSCoverage", (function () {
                var report = /* record */[/* contents : array */[]];
                Jest.beforeAllPromise(undefined, (function () {
                        return browser[0].newPage().then((function (page) {
                                      var coverage = page.coverage;
                                      return Coverage$BsPuppeteer.startJSCoverage({
                                                        resetOnNavigation: true
                                                      }, coverage).then((function () {
                                                        return page.goto("file://" + testPagePath, undefined);
                                                      })).then((function () {
                                                      return coverage.stopJSCoverage();
                                                    })).then((function (res) {
                                                    report[0] = res;
                                                    return Promise.resolve(res);
                                                  }));
                                    }));
                      }));
                Jest.test("report.ranges[0]", (function () {
                        var ranges = Caml_array.caml_array_get(report[0], 0).ranges;
                        return Jest.ExpectJs[/* toMatchObject */31]({
                                    end: 21,
                                    start: 0
                                  }, Jest.Expect[/* expect */0](Caml_array.caml_array_get(ranges, 0)));
                      }));
                Jest.test("report.ranges[1]", (function () {
                        var ranges = Caml_array.caml_array_get(report[0], 0).ranges;
                        return Jest.ExpectJs[/* toMatchObject */31]({
                                    end: 65,
                                    start: 39
                                  }, Jest.Expect[/* expect */0](Caml_array.caml_array_get(ranges, 1)));
                      }));
                Jest.test("report.text", (function () {
                        return Jest.Expect[/* toBe */2]("\n    function foo() {function bar() { } console.log(1); } foo(); ", Jest.Expect[/* expect */0](Caml_array.caml_array_get(report[0], 0).text));
                      }));
                return Jest.test("report.url", (function () {
                              return Jest.Expect[/* toContainString */11]("fixtures/testPage.html", Jest.Expect[/* expect */0](Caml_array.caml_array_get(report[0], 0).url));
                            }));
              }));
        describe("startCSSCoverage, stopCSSCoverage", (function () {
                var report = /* record */[/* contents : array */[]];
                Jest.beforeAllPromise(undefined, (function () {
                        return browser[0].newPage().then((function (page) {
                                      var coverage = page.coverage;
                                      return Coverage$BsPuppeteer.startCSSCoverage({
                                                        resetOnNavigation: true
                                                      }, coverage).then((function () {
                                                        return page.goto("file://" + testPagePath, undefined);
                                                      })).then((function () {
                                                      return coverage.stopCSSCoverage();
                                                    })).then((function (res) {
                                                    report[0] = res;
                                                    return Promise.resolve(res);
                                                  }));
                                    }));
                      }));
                Jest.test("report.ranges[0]", (function () {
                        var ranges = Caml_array.caml_array_get(report[0], 0).ranges;
                        return Jest.ExpectJs[/* toMatchObject */31]({
                                    end: 30,
                                    start: 7
                                  }, Jest.Expect[/* expect */0](Caml_array.caml_array_get(ranges, 0)));
                      }));
                Jest.test("report.text", (function () {
                        return Jest.Expect[/* toBe */2]("\n      input { color: green; }\n      a { color: blue; }\n    ", Jest.Expect[/* expect */0](Caml_array.caml_array_get(report[0], 0).text));
                      }));
                return Jest.test("report.url", (function () {
                              return Jest.Expect[/* toContainString */11]("fixtures/testPage.html", Jest.Expect[/* expect */0](Caml_array.caml_array_get(report[0], 0).url));
                            }));
              }));
        return Jest.afterAllPromise(undefined, (function () {
                      return browser[0].close();
                    }));
      }));

exports.seconds = seconds;
exports.getElementValueJs = getElementValueJs;
exports.getLengthOfElementsJs = getLengthOfElementsJs;
exports.getElementOuterHTMLJs = getElementOuterHTMLJs;
exports.getElementOuterHTMLJsPromise = getElementOuterHTMLJsPromise;
exports.fixturesPath = fixturesPath;
exports.testPagePath = testPagePath;
exports.testPageJsPath = testPageJsPath;
exports.testPageCssPath = testPageCssPath;
exports.testPageContent = testPageContent;
exports.noSandbox = noSandbox;
/* getElementValueJs Not a pure module */
