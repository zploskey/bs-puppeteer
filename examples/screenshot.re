open Js.Promise;

open Puppeteer;

let takeScreenshot = () =>
  launch()
  |> then_(
       (browser) =>
         browser
         |> Browser.newPage
         |> then_(
              (page) =>
                page
                |> Page.goto("https://google.com", ())
                |> then_(
                     (_) => {
                       Js.log("screenshotting");
                       let options = Page.makeScreenshotOptions(~path="./screenshot.png", ());
                       page |> Page.screenshot(~options, ())
                     }
                   )
            )
         |> then_((_) => Browser.close(browser))
         |> then_((_) => Node.Process.exit(0) |> resolve)
     );

takeScreenshot();
