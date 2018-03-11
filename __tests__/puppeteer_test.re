open Jest;

open BsPuppeteer;

open Expect;

let getElementValueJs: Dom.element => string = [%raw
  {| function (element) { return element.value; } |}
];

let getLengthOfElementsJs = [%raw
  {| function (elements) { return elements.length; } |}
];

let getElementOuterHTMLJs: Dom.element => string = [%raw
  {| function (element) { return element.outerHTML; } |}
];

let getElementOuterHTMLJsPromise: Dom.element => Js.Promise.t(string) = [%raw
  {| function (element) { return Promise.resolve(element.outerHTML); } |}
];

let fixturesPath =
  Node.Path.resolve(
    [%bs.node __dirname] |> Js.Option.getWithDefault(""),
    "../../../__tests__/fixtures/",
  );

let testPagePath = Node.Path.resolve(fixturesPath, "./testPage.html");

let testPageJsPath = Node.Path.resolve(fixturesPath, "./testPage.js");

let testPageCssPath = Node.Path.resolve(fixturesPath, "./testPage.css");

let testPageContent = Node.Fs.readFileAsUtf8Sync(testPagePath);

let noSandbox =
  Puppeteer.makeLaunchOptions(
    ~args=[|"--no-sandbox", "--disable-setuid-sandbox"|],
    (),
  );

describe("Puppeteer", () => {
  test("executablePath", () =>
    Puppeteer.executablePath() |> expect |> toContainString("chromium")
  );
  test("defaultArgs()", () =>
    Puppeteer.defaultArgs() |> Array.length |> expect |> toBeGreaterThan(0)
  );
});

describe("Browser", () => {
  let browser = ref(Browser.empty());
  beforeAllPromise(() =>
    Js.Promise.(
      Puppeteer.launch(~options=noSandbox, ())
      |> then_(res => {
           browser := res;
           resolve();
         })
    )
  );
  test("wsEndpoint()", () =>
    Browser.wsEndpoint(browser^)
    |> expect
    |> toContainString("ws://127.0.0.1:")
  );
  testPromise("userAgent()", () =>
    Js.Promise.(
      Browser.userAgent(browser^)
      |> then_(userAgent =>
           userAgent |> expect |> toContainString("HeadlessChrome") |> resolve
         )
    )
  );
  testPromise("version()", () =>
    Js.Promise.(
      Browser.version(browser^)
      |> then_(version =>
           version
           |> expect
           |> toMatchRe([%bs.re "/^HeadlessChrome/"])
           |> resolve
         )
    )
  );
  afterAllPromise(() => Browser.close(browser^));
});

describe("Page", () => {
  let browser = ref(Browser.empty());
  let page = ref(Page.empty());
  beforeAllPromise(() =>
    Js.Promise.(
      Puppeteer.launch(~options=noSandbox, ())
      |> then_(res => {
           browser := res;
           browser^ |> Browser.newPage;
         })
      |> then_(res => {
           page := res;
           resolve();
         })
    )
  );
  testPromise("$()", () =>
    Js.Promise.(
      Page.selectOne(page^, ~selector="body")
      |> then_(elementHandle =>
           elementHandle |> expect |> ExpectJs.toBeTruthy |> resolve
         )
    )
  );
  testPromise("content()", () =>
    Js.Promise.(
      Page.content(page^)
      |> then_(content =>
           expect(content)
           |> ExpectJs.toBe("<html><head></head><body></body></html>")
           |> resolve
         )
    )
  );
  testPromise("$$()", () =>
    Js.Promise.(
      Page.selectAll(page^, ~selector="html,body")
      |> then_(elementHandles =>
           expect(elementHandles) |> ExpectJs.toHaveLength(2) |> resolve
         )
    )
  );
  testPromise("$x", () =>
    Js.Promise.(
      Page.selectXPath(page^, ~xpath="/html/body")
      |> then_(elementHandles =>
           expect(elementHandles) |> ExpectJs.toHaveLength(1) |> resolve
         )
    )
  );
  testPromise("$$eval()", () =>
    Js.Promise.(
      page^
      |> Page.selectAllEval("html,body", getLengthOfElementsJs)
      |> then_(length => length |> expect |> toBe(2.0) |> resolve)
    )
  );
  testPromise("$eval() with 0 args", () =>
    Js.Promise.(
      page^
      |> Page.selectOneEval("html", getElementOuterHTMLJs)
      |> then_(html =>
           html
           |> expect
           |> toBe("<html><head></head><body></body></html>")
           |> resolve
         )
    )
  );
  testPromise("$eval() with 0 args returning a promise", () =>
    Js.Promise.(
      page^
      |> Page.selectOneEvalPromise("html", getElementOuterHTMLJsPromise)
      |> then_(h =>
           h
           |> expect
           |> toBe("<html><head></head><body></body></html>")
           |> resolve
         )
    )
  );
  testPromise("$eval() with 1 arg", () =>
    Js.Promise.(
      page^
      |> Page.setContent(testPageContent)
      |> then_(() =>
           page^
           |> Page.selectOneEval1(
                "input",
                [%raw
                  {| function (el, prop) { return el.getAttribute(prop); } |}
                ],
                "id",
              )
         )
      |> then_(id => id |> expect |> toBe("input") |> resolve)
    )
  );
  testPromise("click()", () =>
    Js.Promise.(
      page^ |> Page.click("body", ()) |> then_(() => pass |> resolve)
    )
  );
  testPromise("goto()", () =>
    Js.Promise.(
      browser^
      |> Browser.newPage
      |> then_(page => {
           let options = Navigation.makeOptions(~timeout=25000., ());
           page |> Page.goto("file://" ++ testPagePath, ~options, ());
         })
      |> then_(res => res |> Js.Null.getExn |> Response.text)
      |> then_(text =>
           text
           |> expect
           |> toContainString("<title>Test Page</title>")
           |> resolve
         )
    )
  );
  testPromise("screenshot()", () =>
    Js.Promise.(
      page^
      |> Page.screenshot()
      |> then_(buf =>
           buf
           |> Js_typed_array.ArrayBuffer.byteLength
           |> expect
           |> toBeGreaterThanOrEqual(3236)
           |> resolve
         )
    )
  );
  testPromise("waitForSelector()", () =>
    Js.Promise.(
      page^
      |> Page.waitForSelector("body", ())
      |> then_(() => pass |> resolve)
    )
  );
  testPromise("waitForXPath()", () =>
    Js.Promise.(
      page^
      |> Page.waitForXPath(
           ~xpath="/html/body",
           ~options=Page.makeSelectorOptions(~timeout=100., ()),
           (),
         )
      |> then_(elementHandle =>
           elementHandle |> expect |> ExpectJs.toBeTruthy |> resolve
         )
    )
  );
  testPromise("setExtraHTTPHeaders", () =>
    Js.Promise.(
      page^
      |> Page.setExtraHTTPHeaders(
           ~headers=Js.Dict.fromList([("extra-http-header", "header01")]),
           (),
         )
      /* TODO: Better way to verify extra HTTP headers */
      |> then_(() => pass |> resolve)
    )
  );
  testPromise("type()", () =>
    Js.Promise.(
      browser^
      |> Browser.newPage
      |> then_(page =>
           page
           |> Page.setContent(testPageContent)
           |> then_(() => page |> Page.type_("#input", "hello world", ()))
           |> then_(() =>
                page |> Page.selectOneEval("#input", getElementValueJs)
              )
         )
      |> then_(value => value |> expect |> toBe("hello world") |> resolve)
    )
  );
  testPromise("addScriptTag()", () =>
    Js.Promise.(
      browser^
      |> Browser.newPage
      |> then_(page =>
           page
           |> Page.addScriptTag(
                Page.makeTagOptions(~path=testPageJsPath, ()),
              )
           |> then_(_elementHandle => Page.content(page))
           |> then_(content =>
                Page.close(page)
                |> then_(() =>
                     content
                     |> expect
                     |> toContainString("// This is \"testPage.js\"")
                     |> resolve
                   )
              )
         )
    )
  );
  testPromise("addStyleTag()", () =>
    Js.Promise.(
      browser^
      |> Browser.newPage
      |> then_(page =>
           page
           |> Page.addStyleTag(
                Page.makeTagOptions(~path=testPageCssPath, ()),
              )
           |> then_(_elementHandle => Page.content(page))
           |> then_(content =>
                Page.close(page)
                |> then_(() =>
                     content
                     |> expect
                     |> toContainString("/* This is \"testPage.css\" */")
                     |> resolve
                   )
              )
         )
    )
  );
  testPromise("authenticate()", () =>
    Js.Promise.(
      page^
      |> Page.authenticate(
           Js.Null.return({"username": "foo", "password": "bar"}),
         )
      |> then_(() => pass |> resolve)
    )
  );
  testPromise("cookies()", () =>
    Js.Promise.(
      page^
      |> Page.setCookie([|
           Page.makeCookie(
             ~name="foo",
             ~value="bar",
             ~url="http://localhost",
             (),
           ),
         |])
      |> then_(() => page^ |> Page.cookies([|"http://localhost"|]))
      |> then_(cookies => cookies |> expect |> toHaveLength(1) |> resolve)
    )
  );
  testPromise("setCookie()", () =>
    Js.Promise.(
      page^
      |> Page.setCookie([|
           Page.makeCookie(
             ~name="foo",
             ~value="bar",
             ~url="http://localhost",
             (),
           ),
           Page.makeCookie(
             ~name="foo2",
             ~value="bar2",
             ~url="http://localhost2",
             (),
           ),
         |])
      |> then_(() =>
           page^ |> Page.cookies([|"http://localhost", "http://localhost2"|])
         )
      |> then_(cookies => cookies |> expect |> toHaveLength(2) |> resolve)
    )
  );
  testPromise("deleteCookie()", () =>
    Js.Promise.(
      page^
      |> Page.setCookie([|
           Page.makeCookie(
             ~name="foo",
             ~value="bar",
             ~url="http://localhost",
             (),
           ),
         |])
      |> then_(() => page^ |> Page.deleteCookie([||]))
      |> then_(() => page^ |> Page.cookies([||]))
      |> then_(cookies => cookies |> expect |> toHaveLength(0) |> resolve)
    )
  );
  testPromise("emulate()", () =>
    Js.Promise.(
      page^
      |> Page.emulate({
           "viewport": {
             "width": 320,
             "height": 480,
             "deviceScaleFactor": 2,
             "isMobile": Js.true_,
             "hasTouch": Js.true_,
             "isLandscape": Js.true_,
           },
           "userAgent": "",
         })
      |> then_(() =>
           page^
           |> Page.viewport()
           |> expect
           |> ExpectJs.toMatchObject({
                "width": 320,
                "height": 480,
                "deviceScaleFactor": 2,
                "isMobile": Js.true_,
                "hasTouch": Js.true_,
                "isLandscape": Js.true_,
              })
           |> resolve
         )
    )
  );
  testPromise("emulateMedia()", () =>
    Js.Promise.(
      page^ |> Page.emulateMedia(`print) |> then_(() => pass |> resolve)
    )
  );
  testPromise("emulateMediaDisable()", () =>
    Js.Promise.(
      page^ |> Page.emulateMediaDisable |> then_(() => pass |> resolve)
    )
  );
  testPromise("evaluate()", () =>
    Js.Promise.(
      {
        let eval = () => "ok";
        page^ |> Page.evaluate(eval);
      }
      |> then_(res => res |> expect |> toBe("ok") |> resolve)
    )
  );
  testPromise("evaluate() with 1 arg", () =>
    Js.Promise.(
      {
        let eval = arg => arg ++ "iedoke";
        page^ |> Page.evaluate1(eval, "ok");
      }
      |> then_(res => res |> expect |> toBe("okiedoke") |> resolve)
    )
  );
  testPromise("evaluate1() and a curried function", () =>
    Js.Promise.(
      {
        let eval = (arg1, arg2) => arg1 ++ " " ++ arg2;
        page^ |> Page.evaluate1(eval("hello"), "world");
      }
      |> then_(res => res |> expect |> toBe("hello world") |> resolve)
    )
  );
  testPromise("evaluatePromise1() with a curried function", () =>
    Js.Promise.(
      {
        let eval = (arg1, arg2) => resolve(arg1 ++ " " ++ arg2);
        page^ |> Page.evaluatePromise1(eval("hello"), "world");
      }
      |> then_(res => res |> expect |> toBe("hello world") |> resolve)
    )
  );
  testPromise("evaluatePromise2() with a curried function", () =>
    Js.Promise.(
      {
        let eval = (arg1, arg2, arg3) => resolve(arg1 ++ " " ++ arg2 ++ arg3);
        page^ |> Page.evaluatePromise2(eval("hello"), "world", "!");
      }
      |> then_(res => res |> expect |> toBe("hello world!") |> resolve)
    )
  );
  testPromise("evaluate() with 2 args", () =>
    Js.Promise.(
      {
        let eval = (arg1, arg2) =>
          (arg1 |> String.length |> Js.Int.toString) ++ arg1 ++ " " ++ arg2;
        page^ |> Page.evaluate2(eval, "hello", "world");
      }
      |> then_(res => res |> expect |> toBe("5hello world") |> resolve)
    )
  );
  testPromise("evaluateString()", () => {
    let getTitleStr = {| document.getElementsByTagName("title")[0].innerHTML; |};
    page^
    |> Page.setContent(testPageContent)
    |> Js.Promise.then_(() =>
         page^
         |> Page.evaluateString(getTitleStr)
         |> Js.Promise.then_(title =>
              title |> expect |> toBe("Test Page") |> Js.Promise.resolve
            )
       );
  });
  testPromise("evaluateHandle()", () =>
    Js.Promise.(
      {
        let eval = () => [%raw {| document |}];
        page^ |> Page.evaluateHandle(eval);
      }
      |> then_(jsHandler =>
           jsHandler |> expect |> ExpectJs.toBeTruthy |> Js.Promise.resolve
         )
    )
  );
  testPromise("pdf()", () =>
    Js.Promise.(
      page^
      |> Page.pdf(
           Page.makePDFOptions(
             ~scale=1,
             ~displayHeaderFooter=Js.true_,
             ~headerTemplate="[[header]]",
             ~footerTemplate="[[footer]]",
             ~printBackground=Js.true_,
             ~landscape=Js.true_,
             ~pageRanges="",
             ~format=`A0,
             ~width=10.0 |> Unit.cm,
             ~height=200.0 |> Unit.mm,
             ~margin=
               Page.makeMargin(
                 ~top=0.1 |> Unit.cm,
                 ~right=10.0 |> Unit.px,
                 ~bottom=1.0 |> Unit.mm,
                 ~left=0.01 |> Unit.in_,
                 (),
               ),
             (),
           ),
         )
      |> then_(buffer =>
           buffer
           |> Js_typed_array.ArrayBuffer.byteLength
           |> expect
           |> toBeGreaterThan(20000)
           |> Js.Promise.resolve
         )
    )
  );
  afterAllPromise(() =>
    Js.Promise.(Page.close(page^) |> then_(() => Browser.close(browser^)))
  );
});
