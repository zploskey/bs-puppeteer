type t = string;

let px = (value: float): t =>
  [Js.Float.toString(value), "px"] |> String.concat("");

let in_ = (value: float): t =>
  [Js.Float.toString(value), "in"] |> String.concat("");

let cm = (value: float): t =>
  [Js.Float.toString(value), "cm"] |> String.concat("");

let mm = (value: float): t =>
  [Js.Float.toString(value), "mm"] |> String.concat("");
