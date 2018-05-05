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
    ~fullPage: bool=?,
    ~clip: BoundingBox.t=?,
    ~omitBackground: bool=?,
    unit
  ) =>
  options =
  "";
