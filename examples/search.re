/** Do a search on googs **/
open Puppeteer;

let resolve = Js.Promise.resolve;
let await p => p |> resolve;

Js.log ("Executable: " ^ Puppeteer.executablePath);

/*let unwrap package => switch package {
| Js.Promise.(t payload => then_ payload)
| Js.Promise.t unit => failwith ("There was nothing there")
};*/

let browser = await Puppeteer.launch;
let page = await Browser.newPage;
Page.goto page "www.google.com" |> await |> resolve;




