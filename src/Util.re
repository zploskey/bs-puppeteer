let optToJs = (toJsFn, opt) => Js.Option.map((. opt) => toJsFn(opt), opt);
