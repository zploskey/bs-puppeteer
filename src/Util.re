let optToJs = (toJsFn, opt) => Js.Option.map((. opt) => toJsFn(opt), opt);

let optBoolToJs = optBool => optToJs(Js.Boolean.to_js_boolean, optBool);
