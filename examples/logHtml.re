/** Navigate to a page and log the html from the response. */
open Puppeteer;

open Js.Promise;

Js.log("Executable: " ++ executablePath());

let logHtml = () =>
  launch()
  |> then_((browser) => browser |> Browser.newPage)
  |> then_(
       (page) =>
         page |> Page.goto("https://google.com", ()) |> then_((res) => res |> Response.text)
     )
  |> then_((text) => Js.log(text) |> resolve)
  |> then_(() => Node.Process.exit(0) |> resolve);

logHtml();
