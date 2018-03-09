type options = {
  .
  "path": Js.Nullable.t(string),
  "_type": Js.Nullable.t(string), /* "jpeg" | "png" (default) */
  "quality": Js.Nullable.t(float),
  "fullPage": Js.Nullable.t(bool),
  "clip": Js.Nullable.t(BoundingBox.t),
  "omitBackground": Js.Nullable.t(bool),
  /* TODO: Should handle the two options. */
};

[@bs.obj]
external makeOptions :
  (
    ~path: string=?,
    ~_type: string=?,
    ~quality: float=?,
    ~fullPage: Js.boolean=?,
    ~clip: BoundingBox.t=?,
    ~omitBackground: Js.boolean=?,
    unit
  ) =>
  options =
  "";

let makeOptions =
    (
      ~path: option(string)=?,
      ~_type: option(string)=?,
      ~quality: option(float)=?,
      ~fullPage: option(bool)=?,
      ~clip: option(BoundingBox.t)=?,
      ~omitBackground: option(bool)=?,
      (),
    ) =>
  makeOptions(
    ~path?,
    ~_type?,
    ~quality?,
    ~fullPage=?Util.optBoolToJs(fullPage),
    ~clip?,
    ~omitBackground=?Util.optBoolToJs(omitBackground),
    (),
  );
