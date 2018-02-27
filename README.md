# BuckleScript Puppeteer (bs-puppeteer)

BuckleScript bindings to
[Puppeteer](https://github.com/GoogleChrome/puppeteer)
(the Headless Chrome Node API)
written in [Reason](https://reasonml.github.io).
This allows programmatic control of an instance of the Chrome or Chromium browser
from BuckleScript or Reason.

## Status

These bindings are a work in progress.
Many features have no been implemented.
The initial goal is to get basic web-scraping and interaction capabilities.
See [examples](examples/)
for use cases that are being tested.
Features of the Puppeteer API are implemented as we need or get to them.
If you would like to add or fix some bindings, see [contributing](#contributing).

## Creating a project using bs-puppeteer

Create a new BuckleScript project if you have not already:
```
npm install -g bs-platform
bsb -init my-project -theme basic-reason
cd my-project
```
See the
[BuckleScript documentation](https://bucklescript.github.io/docs/en/installation.html)
for more information about starting a project.

Add bs-puppeteer as a dependency.
This will install the currently supported version of Puppeteer.
```
npm add --save https://github.com/bs-puppeteer/bs-puppeteer.git
```

Edit your `bsconfig.json` file to add `bs-puppeteer` to `bs-dependencies`:
```
  "bs-dependencies" : [
    "bs-puppeteer",
  ],
```

Now run:
```
npm install
npm start
```
The `Puppeteer` module should now be available in your Reason source files.
While `npm start` is running, it will attempt to recompile your code each time you save it.
One-off builds can be done with `npm run build`.

## Contributing

Contributions are welcome.
```
git clone https://github.com/bs-puppeteer/bs-puppeteer.git
cd bs-puppeteer
npm install
npm start
```
