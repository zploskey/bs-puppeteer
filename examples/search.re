open Puppeteer;

open Js.Promise;

Js.log("Executable: " ++ executablePath());

let search = () =>
  launch()
  |> then_((browser) => browser |> Browser.newPage)
  |> then_(
       (page) => {
         let _ = page |> Page.goto("https://google.com", ());
         page |> resolve
       }
     )
  |> then_(
       (page) => {
         let _ = page |> Page.type_("puppeteer", ());
         page |> resolve
       }
     )
  |> then_(
       (page) => {
         let _ = page |> Page.click("input[type='submit']", ());
         page |> resolve
       }
     )
  |> then_(
       (page) => {
         let _ = page |> Page.waitForSelector("h3 a", ());
         page |> resolve
       }
     );

/* TODO: get evaluate working
|> then((page) => {
    page |> Page.evaluate()
  })*/

search();