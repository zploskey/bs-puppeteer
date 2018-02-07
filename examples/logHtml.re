/** Navigate to a page and log the html from the response. */
open Puppeteer;

open Js.Promise;

Js.log("Executable: " ++ executablePath());

let logHtml = () =>
  launch()
  |> then_((browser) => browser |> Browser.newPage)
  |> then_(
    (page) => {
      let options = Navigation.makeOptions(~timeout=25000., ());
      page |> Page.goto("https://google.com", ~options, ()) |> then_((res) => res |> Response.text)
      }
     )
  |> then_((text) => Js.log(text) |> resolve)
  |> then_(() => Node.Process.exit(0) |> resolve);

logHtml();
