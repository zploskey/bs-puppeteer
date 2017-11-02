
open Puppeteer;
open Js.Promise;

Js.log("Executable: " ++ executablePath());
/*
let fetchGoogle = () => {
  launch()
  |> then_((browser) => Browser.newPage(browser) |> resolve)
  |> then_((page) => Page.goto(page, ~url="https://www.google.com", ()) |> resolve
  |> then_((response) => response |> Response.text |> resolve)
};
*/
