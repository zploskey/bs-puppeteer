type t;

external makeUnit : string => t = "%identity";

let px = (value: float) : t =>
  [string_of_float(value), "px"] |> String.concat("") |> makeUnit;

let in_ = (value: float) : t =>
  [string_of_float(value), "in"] |> String.concat("") |> makeUnit;

let cm = (value: float) : t =>
  [string_of_float(value), "cm"] |> String.concat("") |> makeUnit;

let mm = (value: float) : t =>
  [string_of_float(value), "mm"] |> String.concat("") |> makeUnit;
