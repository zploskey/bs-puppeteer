# bs-puppeteer

BuckleScript bindings to
[Puppeteer](https://github.com/GoogleChrome/puppeteer)
(the Headless Chrome Node API)
written in [ReasonML](https://reasonml.github.io).
This allows programmatic control of an instance of the Chrome or Chromium browser
from BuckleScript or Reason.

[![NPM bs-puppeteer package](https://img.shields.io/npm/v/bs-puppeteer.svg)](https://npmjs.org/package/bs-puppeteer)
[![Travis build status](https://travis-ci.org/bs-puppeteer/bs-puppeteer.svg?branch=master)](https://travis-ci.org/bs-puppeteer/bs-puppeteer) [![Greenkeeper badge](https://badges.greenkeeper.io/bs-puppeteer/bs-puppeteer.svg)](https://greenkeeper.io/)

## Status

These bindings are a work in progress.
Most bindings for navigation and interaction with web pages have been implemented.
There may be some minor breaking changes as we refine the API.
Bindings to the the page events API are planned for a future version.
See [examples](examples/) and the [test suite](__tests__/puppeteer_test.re)
for examples of usage.
Features of the Puppeteer API are implemented as we need or get to them.
We do our best to track upstream API changes.
If you would like to add or fix some bindings, see [Contributing](#contributing).

Changes are documented in [HISTORY.md](HISTORY.md).

## Creating a project using bs-puppeteer

Create a new BuckleScript project if you have not already:

```sh
bsb -init my-project -theme basic-reason
cd my-project
```

See the
[BuckleScript documentation](https://bucklescript.github.io/docs/en/installation.html)
for more information about starting a project.

Add bs-puppeteer as a dependency.
This will install the currently supported version of Puppeteer.

```sh
yarn
yarn add bs-puppeteer
```

Edit your `bsconfig.json` file to add `bs-puppeteer` to `bs-dependencies`:

```sh
  "bs-dependencies" : [
    "bs-puppeteer",
  ],
```

Now run:

```sh
yarn start
```

The `Puppeteer` module should now be available in your Reason source files.
While the `start` command is running, it will attempt to recompile your code each time you save it.
One-off builds can be done with `yarn build`.

## Contributing

Contributions are welcome.
Get started by cloning the respository and starting the compiler in watch mode.
We recommend using [yarn](https://yarnpkg.com/), but `npm` should also work.

```sh
git clone https://github.com/bs-puppeteer/bs-puppeteer.git
cd bs-puppeteer
yarn
yarn start
```

Any changes should pass the test suite (`yarn test`).
One great way to contribute is by writing tests for features that don't yet have them.
Tests can be found in the `__tests__` directory.

A git hook will automatically run `refmt` on your code and run the test suite each time you commit.
Contributors should have the latest release version of `refmt`, which is included with Reason.
See the [Reason Global Installation](https://reasonml.github.io/docs/en/global-installation.html) instructions.

Good references for writing bindings are:

- [BuckleScript Interop Cheatsheet](https://bucklescript.github.io/docs/en/interop-cheatsheet.html)
- [Puppeteer API Docs](https://pptr.dev)
- [Puppeteer TypeScript Definitions](https://github.com/DefinitelyTyped/DefinitelyTyped/blob/master/types/puppeteer/index.d.ts)

## Projects using bs-puppeteer

- [Hamilton Lottery](https://github.com/jrdrg/hamilton-lottery)
