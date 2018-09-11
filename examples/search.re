open BsPuppeteer;

open Js.Promise;

Js.log("Executable: " ++ Puppeteer.executablePath());

let search = () =>
  Puppeteer.launch()
  |> then_(browser =>
       browser
       |> Browser.newPage
       |> then_(page => {
            let options =
              Navigation.makeOptions(~timeout=20000., ~waitUntil=`load, ());
            page->Page.goto("https://google.com", ~options, ())
            |> then_(_ => page->Page.type_("#lst-ib", "puppeteer", ()))
            |> then_(() => page->Page.click("input[type='submit']", ()))
            |> then_(() => page->Page.waitForSelector("h3 a", ()))
            |> then_(() =>
                 page
                 ->Page.selectOneEval("h3 a", Webapi.Dom.Element.textContent)
               )
            |> then_(text => Js.log2("Got:", text) |> resolve)
            |> then_(_ => Browser.close(browser))
            |> then_(_ => Node.Process.exit(0) |> resolve);
          })
     );

search();
