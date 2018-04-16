type point = {
  .
  "x": float,
  "y": float,
};

type quad = (point, point, point, point);

type t = {
  .
  "content": quad,
  "padding": quad,
  "border": quad,
  "margin": quad,
  "width": float,
  "height": float,
};
