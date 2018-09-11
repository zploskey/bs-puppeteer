open BsPuppeteer;

open Js.Promise;

Js.log("Executable: " ++ Puppeteer.executablePath());

let search = () =>
  Puppeteer.launch()
  |> then_(browser =>
       browser
       |> Browser.newPage
       |> then_(page => {
            let allResultsSelector = ".devsite-suggest-all-results";
            let options =
              Navigation.makeOptions(~timeout=20000., ~waitUntil=`load, ());
            page
            ->Page.goto("https://developers.google.com/web/", ~options, ())
            /* Type into the search box */
            |> then_(_ =>
                 page->Page.type_("#searchbox input", "puppeteer", ())
               )
            /* Wait for suggestion overlay to show up then click "all results". */
            |> then_(_ => page->Page.waitForSelector(allResultsSelector, ()))
            |> then_(() => page->Page.click(allResultsSelector, ()))
            /* Wait for load of results page. */
            |> then_(() => {
                 let resultsSelector = ".gsc-results .gsc-thumbnail-inside a.gs-title";
                 page->Page.waitForSelector(resultsSelector, ());
               })
            /* Get the title of the first result. */
            |> then_(() =>
                 page
                 ->Page.selectOneEval(
                     "a.gs-title",
                     Webapi.Dom.Element.textContent,
                   )
               )
            /* Log the result title. */
            |> then_(text =>
                 Js.log2("First result title: ", text) |> resolve
               )
            |> then_(_ => Browser.close(browser))
            |> then_(_ => Node.Process.exit(0) |> resolve);
          })
     );

search();
