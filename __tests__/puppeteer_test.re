open Jest;

open BsPuppeteer;

open Expect;

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
      Page.select(page^, ~selector="body")
      |> then_(elementHandle =>
           elementHandle |> expect |> ExpectJs.toBeTruthy |> Js.Promise.resolve
         )
    )
  );
  testPromise("content()", () =>
    Js.Promise.(
      Page.content(page^)
      |> then_(content =>
           expect(content)
           |> ExpectJs.toBe("<html><head></head><body></body></html>")
           |> Js.Promise.resolve
         )
    )
  );
  testPromise("$$()", () =>
    Js.Promise.(
      Page.selectAll(page^, ~selector="html,body")
      |> then_(elementHandles =>
           expect(elementHandles)
           |> ExpectJs.toHaveLength(2)
           |> Js.Promise.resolve
         )
    )
  );
  testPromise("click()", () =>
    Js.Promise.(
      page^
      |> Page.click("body", ())
      |> then_(() => pass |> Js.Promise.resolve)
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
           |> Js.Promise.resolve
         )
    )
  );
  afterAllPromise(() =>
    Js.Promise.(Page.close(page^) |> then_(() => Browser.close(browser^)))
  );
});
