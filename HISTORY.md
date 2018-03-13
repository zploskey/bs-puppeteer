# History

## 0.5.0 (coming soon)

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
