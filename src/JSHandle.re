module Impl = (T: {type t;}) => {
  [@bs.send] [@bs.return nullable]
  external asElement: T.t => option(Types.elementHandle) = "";

  [@bs.send] external dispose: T.t => Js.Promise.t(unit) = "";

  [@bs.send] external executionContext: T.t => Types.executionContext = "";

  [@bs.send]
  external getProperties: T.t => Js.Promise.t(JSMap.t(string, T.t)) = "";

  [@bs.send.pipe: T.t]
  external getProperty: (~propertyName: string) => Js.Promise.t(T.t) = "";

  [@bs.send] external jsonValue: T.t => Js.Promise.t(Js.t({..})) = "";
};

type t = Types.jsHandle;

include Impl({
  type nonrec t = t;
});
