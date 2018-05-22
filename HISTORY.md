# History

## 0.7.0

Support for Puppeteer 1.4.

- Upgrade to bs-platform 3
  ([#55](https://github.com/bs-puppeteer/bs-puppeteer/pull/55))
- Add Page.close option "runBeforeUnload"
  ([936da1b](https://github.com/bs-puppeteer/bs-puppeteer/commit/936da1b19fc024382ff678d8a76c58cbab86ab9d))
- Add Page.browser() and Target.browser()
  ([28a58c0](https://github.com/bs-puppeteer/bs-puppeteer/commit/28a58c0fde4f46d1791364d28fc4edb3d249b8d3))

## 0.6.0

Support for Puppeteer version 1.3.

- Add Request.redirectChain()
  ([e85dbe5](https://github.com/bs-puppeteer/bs-puppeteer/commit/e85dbe5e5973bc94a892ec7f880290b142d3606f))
- Browser: bind to disconnect() and pages()
  ([cdc47e3](https://github.com/bs-puppeteer/bs-puppeteer/commit/cdc47e39d6fb7e1ad33197ebb59d7fea749795d1))
- Remove Pdf module, all handled by Page.pdf() now
  ([da71d9e](https://github.com/bs-puppeteer/bs-puppeteer/commit/da71d9ebadc19b37bfc242a5eabf7b94af833708))
- Bindings for Dialog
  ([1b9594b](https://github.com/bs-puppeteer/bs-puppeteer/commit/1b9594bb07ac66d8beba22a87194e0fd8b5ba377))
- Add BrowserFetcher bindings
  ([#42](https://github.com/bs-puppeteer/bs-puppeteer/pull/42))
- Add bindings for CDPSession and Target
  ([#43](https://github.com/bs-puppeteer/bs-puppeteer/pull/43))
- Add bindings for Coverage
  ([#44](https://github.com/bs-puppeteer/bs-puppeteer/pull/44))
- Add pipe option to Puppeteer.launch
  ([#50](https://github.com/bs-puppeteer/bs-puppeteer/pull/50))
- Add Page.setBypassCSP()
  ([#51](https://github.com/bs-puppeteer/bs-puppeteer/pull/51))
- Fix tracing options and make Tracing.stop return a buffer
  ([#53](https://github.com/bs-puppeteer/bs-puppeteer/pull/53))
- Add ElementHandle.boxModel() and BoxModel module
  ([#54](https://github.com/bs-puppeteer/bs-puppeteer/pull/54))

## 0.5.0

- Add binding for ElementHandle.contentFrame() (new in Puppeteer 1.2)
  ([#34](https://github.com/bs-puppeteer/bs-puppeteer/pull/34))
- Upgrade Puppeteer to 1.2.0
  ([11e7474](https://github.com/bs-puppeteer/bs-puppeteer/commit/11e74747d90bb6fe04f5fc1d9abe70a2b0c66a87))
- Add binding for metrics object (Metrics.t)
  ([#32](https://github.com/bs-puppeteer/bs-puppeteer/pull/33))
- Add "type" key to FrameBase.tagOptions
  ([8d42628](https://github.com/bs-puppeteer/bs-puppeteer/commit/8d42628258a0b5ba92680858af461f1b2d6c4392))
- Add Page.setCacheEnabled()
  ([eb6e83b](https://github.com/bs-puppeteer/bs-puppeteer/commit/eb6e83bf54cc088d57c81f5d8d2184b4fd0ba8f9))
- Add makeTracingOptions() and "content" to tracing type
  ([#32](https://github.com/bs-puppeteer/bs-puppeteer/pull/32))
- Add vast majority of remaining Page functions
  ([#30](https://github.com/bs-puppeteer/bs-puppeteer/pull/30))
- Add missing keys "env" and "devtools" to Puppeteer.launchOptions
  ([#27](https://github.com/bs-puppeteer/bs-puppeteer/pull/27))
- Add bindings for Page.pdf()
  ([#26](https://github.com/bs-puppeteer/bs-puppeteer/pull/26))
- Move Launcher.launchOptions and Launcher.makeLaunchOptions to Puppeteer module.
  They remain in Launcher as aliases but are deprecated.
  The Launcher module will be removed in a future version.
  ([a19ae2f](https://github.com/bs-puppeteer/bs-puppeteer/commit/a19ae2f6a0b34ce738414c3f6a63341591f51a4f))
- Complete bindings for Request ([#22](https://github.com/bs-puppeteer/bs-puppeteer/pull/22))
- Complete bindings for page/frame evaluation functions ([#21](https://github.com/bs-puppeteer/bs-puppeteer/pull/21))

## 0.4.1

- Fix usage of splice in evaluate functions ([821f0b0](https://github.com/bs-puppeteer/bs-puppeteer/commit/821f0b0ceb1ad342fd554192fcce65b84cf906f1))

## 0.4.0

- Many additional Page and Frame bindings ([#14](https://github.com/bs-puppeteer/bs-puppeteer/pull/14))
- Add bindings for JSHandle, ES6 Map and more ElementHandle bindings ([#15](https://github.com/bs-puppeteer/bs-puppeteer/pull/15))
- Add page selector functions and waitFor ([c7ec94e](https://github.com/bs-puppeteer/bs-puppeteer/commit/c7ec94eb6abf7c75b235358f5b5b0b7c654d8dd7))
- Added a unit test suite ([#11](https://github.com/bs-puppeteer/bs-puppeteer/pull/11))
- Add rest of keyboard bindings ([#10](https://github.com/bs-puppeteer/bs-puppeteer/pull/10))
- Add boundingBox function for ElementHandle ([#8](https://github.com/bs-puppeteer/bs-puppeteer/pull/8))
- FrameBase: add selectors / waitFor / XPath ([#7](https://github.com/bs-puppeteer/bs-puppeteer/pull/7))
