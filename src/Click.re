type clickOptions = {
  .
  "button": Js.undefined(string),
  "clickCount": Js.undefined(int),
  "delay": Js.undefined(float),
};

[@bs.obj]
external makeClickOptions:
  (
    ~button: [@bs.string] [ | `left | `middle | `right]=?,
    ~clickCount: int=?,
    ~delay: float=?,
    unit
  ) =>
  clickOptions =
  "";
