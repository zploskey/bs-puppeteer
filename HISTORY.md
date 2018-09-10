# History

## 0.11.0 (unreleased)

Update to support Puppeteer 1.8.

### Breaking changes

This release brings some major refactoring to convert all functions to the t-first (object-first) convention.
All functions are now compatible with fast pipe syntax (`->` in Reason, `|.` in BuckleScript).

- Convert to object-first convention for use with fast pipe ([#77](https://github.com/bs-puppeteer/bs-puppeteer/pull/77))
- Remove deprecated `Launcher` module.

#### Upgrade instructions:

Change usage of the `|>` operator to `->` (or `|.` in BS) when applied to bs-puppeteer functions.
Check that use of bs-puppeteer function not using a pipe operator are supplying an instance of the type as their first argument.
Functions which take 1 or no arguments won't require any changes.

### Bug fixes

- Frame.executionContext should return a promise ([#87](https://github.com/bs-puppeteer/bs-puppeteer/pull/87/commits/35b4bedcf505c7b19652393262edd3bbe69c1002))
- fix: remove t-last wrapper for setBypassCSP ([a340d23](https://github.com/bs-puppeteer/bs-puppeteer/commit/a340d23ae5868f4bbe64853688c64b7888c21ed3))
- Fix some issues with Request.continue overrides ([5310e36](https://github.com/bs-puppeteer/bs-puppeteer/commit/5310e36d0fbc45092a98573b67db014d25536ebf), [d422900](https://github.com/bs-puppeteer/bs-puppeteer/commit/d422900d8157595a5692bb8f014e9ea5de30e6c5))
  - *NOTE:*
The API of `Request.continue`'s `overrides` argument was refactored.
While this is technically breaking, the overrides were not previously usable.
- fix: Response.remoteAddress needs to be a Js.t ([2c10aa1](https://github.com/bs-puppeteer/bs-puppeteer/commit/2c10aa199840a03b19de473999c95419e954374c))
  - Previously this was typed incorrectly.

### New features

Bindings to new features introduced upstream.

- Add referer to Navigation.makeOptions() + options type ([#81](https://github.com/bs-puppeteer/bs-puppeteer/pull/81))
- Add BrowserContext permission overrides ([#82](https://github.com/bs-puppeteer/bs-puppeteer/pull/82))
- Expose multiple execution contexts in Frame ([#87](https://github.com/bs-puppeteer/bs-puppeteer/pull/87))
- Add geolocation feature (Page.setGeolocation) ([25003f4](https://github.com/bs-puppeteer/bs-puppeteer/commit/25003f442ab96e2479c3e7a67f1561cc18f2bd8d))
- Add new getters for Response data
  - Add Response.statusText() ([448c1b1](https://github.com/bs-puppeteer/bs-puppeteer/commit/448c1b1905c7cdaa8db62f9e3012046990949216))
  - Add Response.remoteAddress() ([55f4a56](https://github.com/bs-puppeteer/bs-puppeteer/commit/55f4a56f6d6b89ee1a8d7ce5c85985d056fd3105))

## 0.10.0

Updates with new features and changes from Puppeteer 1.7.

- Add waitForRequest and waitForResponse functions ([#67](https://github.com/bs-puppeteer/bs-puppeteer/pull/67))
- Add BrowserContext.pages method ([#69](https://github.com/bs-puppeteer/bs-puppeteer/pull/69))
- Add "preferCSSPageSize" to Page.pdfOptions ([#70](https://github.com/bs-puppeteer/bs-puppeteer/pull/70))
- Fix Page.viewport and Page.emulate ([#71](https://github.com/bs-puppeteer/bs-puppeteer/pull/71))
  - Make all fields in viewport optional except for width and height.
  - Construct the viewport using bs.deriving abstract.
  - Remove unnecessary unit argument to Page.viewport().
  - Rename Page.emulateOption to emulateOptions.
- Add defaultViewport options and handle null viewports ([#73](https://github.com/bs-puppeteer/bs-puppeteer/pull/73))
  - Note: Page.viewport() now may return null
  - Make Viewport a top level module
- Add options arg to Puppeteer.defaultArgs ([0fb495d](https://github.com/bs-puppeteer/bs-puppeteer/commit/0fb495d23bc620d5644e75d3f898ba3f5b16ce20))

## 0.9.0

Bug fixes and new features from Puppeteer 1.6.

### New Features

- Add ElementHandle.isIntersectingViewport()
  ([fa075d6](https://github.com/bs-puppeteer/bs-puppeteer/commit/fa075d6b67ee6cb9a9b3d44cc911f1256f1ebc12))
- Add reportAnonymousScripts option for JS coverage
  ([cd67702](https://github.com/bs-puppeteer/bs-puppeteer/commit/cd67702f950d9db24501d279e0b3c30aaad32c43))
- Add blockedbyclient and blockedbyresponse error codes to Request.abort()
  ([e43b8b5](https://github.com/bs-puppeteer/bs-puppeteer/commit/e43b8b5be08c8ba566bbbd48011adacdb20aece1))

### Bug Fixes / Improvements

- Make waitForNavigation returned response optional
  ([5a62dad](https://github.com/bs-puppeteer/bs-puppeteer/commit/5a62dad37187c01658b76a0f3262268bf0cf8e72))
- Use bs.string for Screenshot.options `_type` field
  ([2e7c567](https://github.com/bs-puppeteer/bs-puppeteer/commit/2e7c5678cc2e387f207c2aa9eda5a1eae9dea1d5))
- Use `Node.Buffer.t` instead of `Typed_array`
  ([5c7ae0d](https://github.com/bs-puppeteer/bs-puppeteer/commit/5c7ae0d085e6c0e41bd120943c4401e112dbd835))

## 0.8.0

Support for Puppeteer 1.5.
User-facing API changes are listed below.
A couple of very minor breaking changes for consistency and correctness are marked as **breaking**.

### New Features

- Rename Target.pageType to targetType
  ([#61](https://github.com/bs-puppeteer/bs-puppeteer/pull/61))
- Add Target type `background_page`
  ([a4c5280](https://github.com/bs-puppeteer/bs-puppeteer/commit/a4c528068c9462b2e943c4714e5143d86f7af047))
- Add slowMo to connectOptions
  ([b9977cb](https://github.com/bs-puppeteer/bs-puppeteer/commit/b9977cb33c2fe8fb98c8c1a9f257c4d4d33fdd7e))
- Add missing ignoreDefaultArgs launch option
  ([8374023](https://github.com/bs-puppeteer/bs-puppeteer/commit/8374023f5b838e8d8d5b2e7215af42b2d9df3a9e))
- Add Browser.process()
  ([db8431c](https://github.com/bs-puppeteer/bs-puppeteer/commit/db8431c14932af05a9bb93c310dc27c60380153e))
- Add Browser.targets()
  ([64f8105](https://github.com/bs-puppeteer/bs-puppeteer/commit/64f8105e7b87d6dc9709b2697967e1c379b93ed4))
- Add Page.isClosed()
  ([6705ec9](https://github.com/bs-puppeteer/bs-puppeteer/commit/6705ec95e462cedeb41cdf0bdaa5a449a7e0be57))
- Add Page.setViewport()
  ([7cc7478](https://github.com/bs-puppeteer/bs-puppeteer/commit/7cc7478be2965fbf71724e1b308d43c510fc4859))
- Add ExecutionContext.frame()
  ([fdaee4a](https://github.com/bs-puppeteer/bs-puppeteer/commit/fdaee4aece687a3164ab10aa9aa4d863d43212d9))
- Make JSHandle.asElement() return an option **breaking**
  ([c6a63ad](https://github.com/bs-puppeteer/bs-puppeteer/commit/c6a63adf5a5e6d647b6481e80d5daae8221b093c))
- Add Request.isNavigationRequest() (new in Puppeteer 1.5)
  ([deb635e](https://github.com/bs-puppeteer/bs-puppeteer/commit/deb635e72facbe22ba295cdcc293c7e8e472b278))
- Add Target.opener() (new in Puppeteer 1.5)
  ([a949007](https://github.com/bs-puppeteer/bs-puppeteer/commit/a9490077c80a52aae023dc32e11cb03612e39d64))
- Support BrowserContext (new in Puppeteer 1.5)
  ([18e2a94](https://github.com/bs-puppeteer/bs-puppeteer/commit/18e2a945f0b586ecd81bb70fd63c1295c7c9647a))
- Add Worker module (Web Workers, new in Puppeteer 1.5)
  ([4160b9b](https://github.com/bs-puppeteer/bs-puppeteer/commit/4160b9b4a914e912e7c15fa4cf4f1341ccfd4808))

### Bug Fixes

- Fix Mouse.move options parameter
  ([9b7c55c](https://github.com/bs-puppeteer/bs-puppeteer/commit/9b7c55c87c9a83cf0ceb6dadb7188629f92db742))
- Tracing.start's options and path aren't optional
  ([88f6f4a](https://github.com/bs-puppeteer/bs-puppeteer/commit/88f6f4ae7bbab4b2cc886060718af232a4fa3ce9))
- Move hover function to FrameBase (You can hover in a frame too)
  ([01b5f51](https://github.com/bs-puppeteer/bs-puppeteer/commit/01b5f510bcdd54ce04fbb6809e2710836e125a57))
- Fixes for Page.cookie type **breaking**
  ([6ea5ddf](https://github.com/bs-puppeteer/bs-puppeteer/commit/6ea5ddf15401e8757b57e55d45d9f12cb5cbf7fd))
- Don't override addScriptTag in Frame (Fixed this external)
  ([b263d86](https://github.com/bs-puppeteer/bs-puppeteer/commit/b263d86bef13b7b077f7f51b3b2ff2e75935248c))
- Move Page.click to FrameBase.click (Frames can be clicked too)
  ([3433ed8](https://github.com/bs-puppeteer/bs-puppeteer/commit/3433ed8ef68c0e7440b3bc2e47e15e8d556ab718))
- Move Page.content() to FrameBase.content() (Frames have content too)
  ([6f1b218](https://github.com/bs-puppeteer/bs-puppeteer/commit/6f1b2188e3c6e08f82162994fefd0945b75ad31b))
- deviceScaleFactor should be a float **breaking**
  ([3b109ac](https://github.com/bs-puppeteer/bs-puppeteer/commit/3b109ace50a1d352eb9f85d19243a738ad69c574))
- Frames can also focus
  ([5d728a4](https://github.com/bs-puppeteer/bs-puppeteer/commit/5d728a45831edfb4eab9e76289b686401d27cdfe))
- pdfOptions##scale should be a float **breaking**
  ([4990439](https://github.com/bs-puppeteer/bs-puppeteer/commit/49904399e916fe1cd62bcb16fb7705b6da458127))
- Move Page.select() to FrameBase (Can now select in a Frame)
  ([6852beb](https://github.com/bs-puppeteer/bs-puppeteer/commit/6852beb41ee6ce0d2a14688904972958a15ceb20))
- Move Page.tap() to FrameBase (Can now tap in a frame)
  ([ee135af](https://github.com/bs-puppeteer/bs-puppeteer/commit/ee135af7ad19018746b969a72d5564df6a742f45))
- Move `Page.type_()` and typeOptions to FrameBase (Can now type into Frames)
  ([840364d](https://github.com/bs-puppeteer/bs-puppeteer/commit/840364d4a7d3fd29e0d4dda73424055af3c816c2))
- Move Page.url() to FrameBase (Frames have urls too)
  ([751bfc8](https://github.com/bs-puppeteer/bs-puppeteer/commit/751bfc85eafd779583b70ebd789b1c9a555261f3))

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
