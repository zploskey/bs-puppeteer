type t;

type serializable = Js.Json.t;

[@bs.val] external select : (~selector: string) => Js.Promise.t(ElementHandle.t) = "$";

[@bs.val] external selectAll : (~selector: string) => Js.Promise.t(array(ElementHandle.t)) = "$$";
/*
 $eval(
   selector: string,
   fn: (...args: Array<Serializable | ElementHandle>) => void
 ): Promise<Serializable>; */
/* external $eval : selector::string => (fn::fun ...args : array serializable => unit) => promise serializable = "$eval" [@@bs.val]; */
