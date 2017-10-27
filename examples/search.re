let browser = Puppeteer.launch ();
/*  |> then_ (fun browser => resolve (browser##newPage))
  |> catch (fun err => resolve (raise "Couldn't get page")) */

Js.log ("Executable: " ^ Puppeteer.executablePath);
/*let page = Browser.newPage |> resolve;*/
/*Page.goto page "www.google.com" |> await |> resolve;*/