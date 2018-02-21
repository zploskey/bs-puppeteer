open Jest;

open BsPuppeteer;

open Expect;

describe("Puppeteer", () => {
  test("defaultArgs()", () =>
    expect(Puppeteer.defaultArgs(puppeteer, ())) |> toHaveLength(17)
  );
  test("executablePath()", () =>
    expect(Puppeteer.executablePath(puppeteer, ()))
    |> toContainString("chromium")
  );
});

describe("Browser", () => {
  let browser = ref(Puppeteer.Browser.empty());
  beforeAllPromise(() =>
    Js.Promise.(
      Puppeteer.launch(puppeteer)
      |> then_(res => {
           browser := res;
           resolve();
         })
    )
  );
  test("wsEndpoint()", () =>
    Puppeteer.Browser.wsEndpoint(browser^, ())
    |> expect
    |> toContainString("ws://127.0.0.1:")
  );
  testPromise("userAgent()", () =>
    Js.Promise.(
      Puppeteer.Browser.userAgent(browser^, ())
      |> then_(userAgent =>
           userAgent |> expect |> toContainString("HeadlessChrome") |> resolve
         )
    )
  );
  testPromise("version()", () =>
    Js.Promise.(
      Puppeteer.Browser.version(browser^, ())
      |> then_(version =>
           version |> expect |> toContainString("HeadlessChrome") |> resolve
         )
    )
  );
  afterAllPromise(() => Puppeteer.Browser.close(browser^, ()));
});

describe("Page", () => {
  let browser = ref(Puppeteer.Browser.empty());
  let page = ref(Puppeteer.Page.empty());
  beforeAllPromise(() =>
    Js.Promise.(
      Puppeteer.launch(puppeteer)
      |> then_(res => {
           browser := res;
           Puppeteer.Browser.newPage(browser^, ());
         })
      |> then_(res => {
           page := res;
           resolve();
         })
    )
  );
  testPromise("$()", () =>
    Js.Promise.(
      Puppeteer.Page.dollar(page^, "body")
      |> then_(elementHandle =>
           elementHandle |> expect |> ExpectJs.toBeTruthy |> Js.Promise.resolve
         )
    )
  );
  testPromise("content()", () =>
    Js.Promise.(
      Puppeteer.Page.content(page^, ())
      |> then_(content =>
           expect(content)
           |> ExpectJs.toBe("<html><head></head><body></body></html>")
           |> Js.Promise.resolve
         )
    )
  );
  testPromise(
    "$$()", () =>
    Js.Promise.(
      Puppeteer.Page.dollarDollar(page^, "html,body")
      |> then_(elementHandles =>
           expect(elementHandles)
           |> ExpectJs.toHaveLength(2)
           |> Js.Promise.resolve
         )
    )
  );
  testPromise(
    "$$eval()",
    () =>
    Js.Promise.(
      {
        let eval = [%raw {| function (elements) { return elements.length; } |}];
        Puppeteer.Page.dollarDollarEval(page^, "html,body", eval, [||]);
      }
      |> then_(serializable =>
           expect(serializable) |> toBe(2) |> Js.Promise.resolve
         )
    )
  );
  testPromise(
    "$eval()",
    () =>
    Js.Promise.(
      {
        let eval = [%raw
          {| function (element) { return element.outerHTML; } |}
        ];
        Puppeteer.Page.dollarEval(page^, "html", eval, [||]);
      }
      |> then_(serializable =>
           expect(serializable)
           |> toBe("<html><head></head><body></body></html>")
           |> Js.Promise.resolve
         )
    )
  );
  testPromise("$x()", () =>
    Js.Promise.(
      Puppeteer.Page.dollarX(page^, "/html/body")
      |> then_(elementHandles =>
           expect(elementHandles) |> toHaveLength(1) |> Js.Promise.resolve
         )
    )
  );
  testPromise(
    "addScriptTag()",
    () =>
    Js.Promise.(
      Puppeteer.Browser.newPage(browser^, ())
      |> then_(page =>
           all2((
             Puppeteer.Page.addScriptTag(
               ~url=
                 "https://cdnjs.cloudflare.com/ajax/libs/jquery/3.3.1/jquery.min.js",
               page
             ),
             resolve(page)
           ))
         )
      |> then_(((_elementHandle, page)) =>
           all2((Puppeteer.Page.content(page, ()), resolve(page)))
         )
      |> then_(((content, page)) =>
           all2((Puppeteer.Page.close(page, ()), resolve(content)))
         )
      |> then_(((_nothing, content)) =>
           expect(content)
           |> toBe(
                "<html><head><script src=\"https://cdnjs.cloudflare.com/ajax/libs/jquery/3.3.1/jquery.min.js\"></script></head><body></body></html>"
              )
           |> Js.Promise.resolve
         )
    )
  );
  testPromise(
    "addStyleTag()",
    () =>
    Js.Promise.(
      Puppeteer.Browser.newPage(browser^, ())
      |> then_(page =>
           all2((
             Puppeteer.Page.addStyleTag(
               ~url=
                 "https://cdnjs.cloudflare.com/ajax/libs/twitter-bootstrap/4.0.0/css/bootstrap.min.css",
               page
             ),
             resolve(page)
           ))
         )
      |> then_(((_elementHandle, page)) =>
           all2((Puppeteer.Page.content(page, ()), resolve(page)))
         )
      |> then_(((content, page)) =>
           all2((Puppeteer.Page.close(page, ()), resolve(content)))
         )
      |> then_(((_nothing, content)) =>
           expect(content)
           |> toBe(
                "<html><head><link rel=\"stylesheet\" href=\"https://cdnjs.cloudflare.com/ajax/libs/twitter-bootstrap/4.0.0/css/bootstrap.min.css\"></head><body></body></html>"
              )
           |> Js.Promise.resolve
         )
    )
  );
  testPromise(
    "authenticate()", () =>
    Js.Promise.(
      Puppeteer.Page.authenticate(
        page^,
        Js.Null.return({"username": "foo", "password": "bar"})
      )
      |> then_(() => pass |> Js.Promise.resolve)
    )
  );
  testPromise(
    "click()",
    () =>
    Js.Promise.(
      Puppeteer.Page.click(page^, "body", Js.undefined)
      |> then_(() => pass |> Js.Promise.resolve)
    )
  );
  test("coverage", () => {
    let p = page^;
    expect(p##coverage) |> ExpectJs.toBeTruthy;
  });
  testPromise("deleteCookie()", () =>
    Js.Promise.(
      Puppeteer.Page.deleteCookie(page^, [||])
      |> then_(() => pass |> Js.Promise.resolve)
    )
  );
  testPromise(
    "emulate()", () =>
    Js.Promise.(
      Puppeteer.Page.emulate(
        page^,
        {
          "viewport": {
            "width": 320,
            "height": 480,
            "deviceScaleFactor": 2,
            "isMobile": Js.true_,
            "hasTouch": Js.true_,
            "isLandscape": Js.true_
          },
          "userAgent": ""
        }
      )
      |> then_(() =>
           Puppeteer.Page.viewport(page^, ())
           |> expect
           |> ExpectJs.toMatchObject({
                "width": 320,
                "height": 480,
                "deviceScaleFactor": 2,
                "isMobile": Js.true_,
                "hasTouch": Js.true_,
                "isLandscape": Js.true_
              })
           |> Js.Promise.resolve
         )
    )
  );
  testPromise(
    "emulateMedia()",
    () =>
    Js.Promise.(
      Puppeteer.Page.emulateMedia(page^, "print")
      |> then_(() => pass |> Js.Promise.resolve)
    )
  );
  testPromise(
    "evaluate()",
    () =>
    Js.Promise.(
      {
        let eval = [%raw {| function () { return Promise.resolve("ok"); } |}];
        Puppeteer.Page.evaluate(page^, eval, [||]);
      }
      |> then_(serializable =>
           serializable
           |> Js.Json.decodeString
           |> Js.Option.getWithDefault("")
           |> expect
           |> toBe("ok")
           |> Js.Promise.resolve
         )
    )
  );
  testPromise(
    "evaluateHandle()",
    () =>
    Js.Promise.(
      {
        let eval = [%raw
          {| function () { return Promise.resolve(document); } |}
        ];
        Puppeteer.Page.evaluateHandle(page^, eval, [||]);
      }
      |> then_(jsHandler =>
           jsHandler |> expect |> ExpectJs.toBeTruthy |> Js.Promise.resolve
         )
    )
  );
  afterAllPromise(() =>
    Js.Promise.(
      Puppeteer.Page.close(page^, ())
      |> then_(() => Puppeteer.Browser.close(browser^, ()))
    )
  );
});
