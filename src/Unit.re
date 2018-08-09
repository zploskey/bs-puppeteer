type t = string;

let px = (value: float): t =>
  [string_of_float(value), "px"] |> String.concat("");

let in_ = (value: float): t =>
  [string_of_float(value), "in"] |> String.concat("");

let cm = (value: float): t =>
  [string_of_float(value), "cm"] |> String.concat("");

let mm = (value: float): t =>
  [string_of_float(value), "mm"] |> String.concat("");
