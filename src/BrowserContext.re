type t;

[@bs.send] external browser : t => Types.browser = "";

[@bs.send] external close : t => Js.Promise.t(unit) = "";

[@bs.send] external isIncognito : t => bool = "";

[@bs.send] external newPage : t => Js.Promise.t(Page.t) = "";

[@bs.send] external pages : t => Js.Promise.t(array(Page.t)) = "";

[@bs.send] external targets : t => array(Types.target) = "";
