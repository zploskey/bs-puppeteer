open! BsPuppeteer;

open Js.Promise;

Js.log("Executable: " ++ Puppeteer.executablePath());

let search = () =>
  Puppeteer.launch()
  |> then_(browser =>
       browser
       |> Browser.newPage
       |> then_(page => {
            let options =
              Navigation.makeOptions(~timeout=5000., ~waitUntil=`load, ());
            let allResultsSelector = ".devsite-suggest-all-results";
            let resultsSelector = "a.gs-title";
            page->Page.goto(
              "https://developers.google.com/web/",
              ~options,
              (),
            )
            /* Click search icon to show search box */
            |> then_(_ => page->Page.click(".devsite-search-button", ()))
            /* Type into the search box */
            |> then_(_ => page->Page.type_("input[name=q]", "puppeteer", ()))
            |> then_(_ => page->Page.waitForSelector(allResultsSelector, ()))
            |> then_(_ => page->Page.click(allResultsSelector, ()))
            /* Wait for load of results page. */
            |> then_(() => page->Page.waitForSelector(resultsSelector, ()))
            /* Get the title of the first result. */
            |> then_(_ =>
                 page->Page.selectOneEval(
                   resultsSelector,
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
