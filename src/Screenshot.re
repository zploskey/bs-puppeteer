type options = {
  .
  "path": Js.Nullable.t(string),
  "_type": Js.Nullable.t(string),
  "quality": Js.Nullable.t(float),
  "fullPage": Js.Nullable.t(bool),
  "clip": Js.Nullable.t(BoundingBox.t),
  "omitBackground": Js.Nullable.t(bool),
};

/** Create a screenshot options object.
 *
 * If no [path] is provided, the screenshot will not be saved to disk.
 * [_type] defaults to [`png].
 * [quality] should be between 0 and 100. Does not apply to png images.
 * [fullpage]: If true, take screenshot of full scrollable page.
 *             Defaults to false.
 * [clip]: [BoundingBox.t] representing the region to clip the screenshot to.
 * [omitBackground]: Whether to hide default white background.
 *                   Defaults to false.
 */
[@bs.obj]
external makeOptions:
  (
    ~path: string=?,
    ~_type: [@bs.string] [ | `jpeg | `png]=?,
    ~quality: float=?,
    ~fullPage: bool=?,
    ~clip: BoundingBox.t=?,
    ~omitBackground: bool=?,
    unit
  ) =>
  options =
  "";
