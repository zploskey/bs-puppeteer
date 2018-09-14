module Impl = (T: {type t('a);}) => {
  [@bs.send] [@bs.return nullable]
  external asElement: T.t('a) => option(Types.elementHandle('a)) = "";

  [@bs.send] external dispose: T.t('a) => Js.Promise.t(unit) = "";

  [@bs.send]
  external executionContext: T.t('a) => Types.executionContext = "";

  [@bs.send]
  external getProperties: T.t('a) => Js.Promise.t(JSMap.t(string, T.t('b))) =
    "";

  [@bs.send]
  external getProperty:
    (T.t('a), ~propertyName: string) => Js.Promise.t(T.t('b)) =
    "";

  [@bs.send] external jsonValue: T.t('a) => Js.Promise.t(Js.t({..})) = "";
};

type t('a) = Types.jsHandle('a);

include Impl({
  type nonrec t('a) = t('a);
});
