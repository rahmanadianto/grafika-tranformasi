#include "plane.hpp"

plane::plane() {
  this->center.set_x(100);
  this->center.set_y(100);
  this->center_size = 10;
}

plane::plane(point center, int center_size) {
  this->center = center;
  this->center_size = center_size;
}

point plane::get_center() {
  return c_center.get_center();
}

int plane::get_size() {
  return center_size;
}

void plane::set_center(point new_center) {
  c_center.set_center(new_center);
}

void plane::set_size(int new_size) {
  center_size = new_size;
}

void plane::draw(uint32_t color) {

  this->c_center = circle(center, center_size);
  this->c_left = circle(center.move(-(3 * center_size), 0), (int) (0.5 * center_size));
  this->c_right = circle(center.move((3 * center_size), 0), (int) (0.5 * center_size));

  // Lingkaran pusat
  c_center.draw_stroke(color);
  c_center.draw_fill(color);
  circle c_center_inner(c_center.get_center(), (int) (0.8 * center_size));
  c_center_inner.draw_stroke(0x000000);
  c_center_inner.draw_fill(0x000000);
  circle c_center_inner_inner(c_center.get_center(), (int) (0.2 * center_size));
  c_center_inner_inner.draw_stroke(color);
  c_center_inner_inner.draw_fill(color);

  // Lingkaran kiri
  c_left.draw_stroke(color);
  c_left.draw_fill(color);
  circle c_left_inner(c_left.get_center(), (int) (0.3 * center_size));
  c_left_inner.draw_stroke(0x000000);
  c_left_inner.draw_fill(0x000000);

  // Lingkaran kanan
  c_right.draw_stroke(color);
  c_right.draw_fill(color);
  circle c_right_inner(c_right.get_center(), (int) (0.3 * center_size));
  c_right_inner.draw_stroke(0x000000);
  c_right_inner.draw_fill(0x000000);

  /* body
  int x_c = center.get_x();
  int y_c = center.get_y();
  body.set_point(0, point(x_c, y_c + (int) (-2.2 * center_size)));
  body.set_point(1, point(x_c + 2, y_c + 1));
  body.set_point(2, point(x_c + 3, y_c + 2));
  body.set_point(3, point(x_c + 3, y_c + 8));
  body.set_point(4, point(x_c + 6, y_c + 8));
  body.set_point(5, point(x_c + 7, y_c + 9));
  body.set_point(6, point(x_c + 11, y_c + 20));
  body.set_point(7, point(x_c + 58, y_c + 20));
  body.set_point(8, point(x_c + 60, y_c + 21));
  body.set_point(9, point(x_c + 60, y_c + 22));
  body.set_point(10, point(x_c + 58, y_c + 23));
  body.set_point(11, point(x_c + 9, y_c + 23));
  body.set_point(12, point(x_c + 5, y_c + 11));
  body.set_point(13, point(x_c - 5, y_c + 11));
  body.set_point(14, point(x_c - 9, y_c + 23));
  body.set_point(15, point(x_c - 58, y_c + 23));
  body.set_point(16, point(x_c - 60, y_c + 22));
  body.set_point(17, point(x_c - 60, y_c + 21));
  body.set_point(18, point(x_c - 58, y_c + 20));
  body.set_point(19, point(x_c - 11, y_c + 20));
  body.set_point(20, point(x_c - 7, y_c + 9));
  body.set_point(21, point(x_c - 6, y_c + 8));
  body.set_point(22, point(x_c - 3, y_c + 8));
  body.set_point(23, point(x_c - 3, y_c + 2));
  body.set_point(24, point(x_c - 2, y_c + 1));
  body.draw_stroke(0, 0, color); */
}
