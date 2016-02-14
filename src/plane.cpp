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

  // body
  polygon body;
  body.add_point(point(60, 0));
  body.add_point(point(62, 1));
  body.add_point(point(63, 2));
  body.add_point(point(63, 8));
  body.add_point(point(66, 8));
  body.add_point(point(67, 9));
  body.add_point(point(71, 20));
  body.add_point(point(118, 20));
  body.add_point(point(120, 21));
  body.add_point(point(120, 22));
  body.add_point(point(118, 23));
  body.add_point(point(69, 23));
  body.add_point(point(65, 11));
  body.add_point(point(55, 11));
  body.add_point(point(51, 23));
  body.add_point(point(2, 23));
  body.add_point(point(0, 22));
  body.add_point(point(0, 21));
  body.add_point(point(2, 20));
  body.add_point(point(49, 20));
  body.add_point(point(53, 9));
  body.add_point(point(54, 8));
  body.add_point(point(57, 8));
  body.add_point(point(57, 2));
  body.add_point(point(58, 1));
  body.scale(center_size * 0.08);
  body.draw_stroke(center.get_x() - 60, center.get_y() - (int)(center_size * 2.2));
}
