type waitEvent =
  | Load
  | Networkidle
  | NetworkIdleTimeout;

type navigationOptions = {
  .
  "timeout": Js.Nullable.t(float),
  "waitUntil": Js.Nullable.t(waitEvent), /* "load" | "networkidle" | "networkIdleTimeout" */
  "networkIdleInflight": Js.Nullable.t(float),
  "networkIdleTimeout": Js.Nullable.t(float)
};
