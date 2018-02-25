open BsPuppeteer;

open Js.Promise;

Js.log("Executable: " ++ Puppeteer.executablePath());

let search = () =>
  Puppeteer.launch()
  |> then_((browser) => browser |> Browser.newPage)
  |> then_(
       (page) => {
         let options = Navigation.makeOptions(~timeout=20000., ~waitUntil=`load, ());
         page
         |> Page.goto("https://google.com", ~options, ())
         |> then_((_) => Page.type_(page, "#lst-ib", "puppeteer", ()))
         |> then_(() => page |> Page.click("input[type='submit']", ()))
         |> then_(() => page |> Page.waitForSelector("h3 a", ()))
       }
     );

/* TODO: select elements matching "h3 a" and get their text */
search();
