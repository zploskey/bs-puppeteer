module Arg = {
  type t;
  external float : float => t = "%identity";
  external string : string => t = "%identity";
  external bool : Js.boolean => t = "%identity";
  external obj : Js.t({..}) => t = "%identity";
  external fn0 : (unit => 'a) => t = "%identity";
  external fn1 : ('a => 'b) => t = "%identity";
  external fn2 : (('a, 'b) => 'c) => t = "%identity";
  external fn3 : (('a, 'b, 'c) => 'd) => t = "%identity";
  external fn4 : (('a, 'b, 'c, 'd) => 'd) => t = "%identity";
};

module Fn = {
  type t;
  external string : string => t = "%identity";
  external fn0 : (unit => 'a) => t = "%identity";
  external fn1 : ('a => 'b) => t = "%identity";
  external fn2 : (('a, 'b) => 'c) => t = "%identity";
  external fn3 : (('a, 'b, 'c) => 'd) => t = "%identity";
  external fn4 : (('a, 'b, 'c, 'd) => 'd) => t = "%identity";
};
