open Puppeteer;

open Js.Promise;

Js.log("Executable: " ++ executablePath());

let fetchGoogle = () => launch() |> then_((browser) => browser |> Browser.newPage |> resolve);
/*|> then_((page) => page |> Page.goto(~url:"google.com") |> resolve);*/
