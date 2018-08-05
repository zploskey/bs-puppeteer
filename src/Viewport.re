[@bs.deriving abstract]
type t = {
  width: int,
  height: int,
  [@bs.optional]
  deviceScaleFactor: float,
  [@bs.optional]
  isMobile: bool,
  [@bs.optional]
  hasTouch: bool,
  [@bs.optional]
  isLandscape: bool,
};

let make = t;
