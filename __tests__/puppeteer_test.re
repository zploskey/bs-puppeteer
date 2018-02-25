open Jest;

open BsPuppeteer;

open Expect;

let getElementValueJs = [%raw
  {| function (element) { return element.value; } |}
];

let testPagePath =
  Node.Path.resolve(
    [%bs.node __dirname] |> Js.Option.getWithDefault(""),
    "../../../__tests__/fixtures/testPage.html"
  );

let testPageContent = Node.Fs.readFileAsUtf8Sync(testPagePath);

describe("Puppeteer", () =>
  test("executablePath", () =>
    Puppeteer.executablePath() |> expect |> toContainString("/Chromium")
  )
);

describe("Browser", () => {
  let browser = ref(Browser.empty());
  beforeAllPromise(() =>
    Js.Promise.(
      Puppeteer.launch()
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
      Puppeteer.launch()
      |> then_(res => {
           browser := res;
           Browser.newPage(browser^);
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
           expect(elementHandles)
           |> ExpectJs.toHaveLength(2)
           |> resolve
         )
    )
  );
  testPromise("$x", () =>
    Js.Promise.(
      Page.selectXPath(page^, ~xpath="/html/body")
      |> then_(elementHandles =>
           expect(elementHandles)
           |> ExpectJs.toHaveLength(1)
           |> resolve
         )
    )
  );
  testPromise("click()", () =>
    Js.Promise.(
      page^
      |> Page.click("body", ())
      |> then_(() => pass |> resolve)
    )
  );
  testPromise("goto()", () =>
    Js.Promise.(
      Browser.newPage(browser^)
      |> then_(page => {
           let options = Navigation.makeOptions(~timeout=25000., ());
           page |> Page.goto("https://google.com", ~options, ());
         })
      |> then_(res => res |> Response.text)
      |> then_(text =>
           text
           |> expect
           |> toContainString("<title>Google</title>")
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
           ()
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
           ()
         )
      /* TODO: Better way to verify extra HTTP headers */
      |> then_(() => pass |> resolve)
    )
  );
  testPromise("type()", () =>
    Js.Promise.(
      Browser.newPage(browser^)
      |> then_(page =>
           all2((resolve(page), Page.setContent(page, testPageContent)))
         )
      |> then_(((page, _)) =>
           all2((resolve(page), Page.type_(page, "#input", "hello world", ())))
         )
      |> then_(((page, _)) =>
           Page.selectOneEval(page, "#input", getElementValueJs)
         )
      |> then_(value => value |> expect |> toBe("hello world") |> resolve)
    )
  );
  afterAllPromise(() =>
    Js.Promise.(Page.close(page^) |> then_(() => Browser.close(browser^)))
  );
});
