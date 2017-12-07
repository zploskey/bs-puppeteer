open Puppeteer;

open Js.Promise;

Js.log("Executable: " ++ executablePath());

let search = () =>
  launch()
  |> then_((browser) => browser |> Browser.newPage)
  |> then_(
       (page) => {
         let navOptions = Navigation.make_navigationOptions(~timeout=20000., ());
         page
         |> Page.goto("https://google.com", ~options=navOptions, ())
         |> then_((_) => page |> Page.type_("puppeteer", ()))
         |> then_(() => page |> Page.click("input[type='submit']", ()))
         |> then_(() => page |> Page.waitForSelector("h3 a", ()))
       }
     );

/* TODO: select elements matching "h3 a" and get their text */
search();
