module Impl = (T: {type t('a);}) => {
  [@bs.send] [@bs.return nullable]
  external asElement: T.t('a) => option(Types.elementHandle('a)) =
    "asElement";

  [@bs.send] external dispose: T.t('a) => Js.Promise.t(unit) = "dispose";

  [@bs.send]
  external executionContext: T.t('a) => Types.executionContext =
    "executionContext";

  [@bs.send]
  external getProperties: T.t('a) => Js.Promise.t(JSMap.t(string, T.t('b))) =
    "getProperties";

  [@bs.send]
  external getProperty:
    (T.t('a), ~propertyName: string) => Js.Promise.t(T.t('b)) =
    "getProperty";

  [@bs.send]
  external jsonValue: T.t('a) => Js.Promise.t(Js.t({..})) = "jsonValue";
};

type t('a) = Types.jsHandle('a);

include Impl({
  type nonrec t('a) = t('a);
});
