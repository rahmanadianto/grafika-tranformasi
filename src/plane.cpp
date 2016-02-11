#include "plane.hpp"

plane::plane() {
  point center(100, 100);

  this->center = center;
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
  this->body.add_point(center.move(0, (int) (-2.2 * center_size)).get_x(),
                       center.move(0, (int) (-2.2 * center_size)).get_y());

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

  // body pesawat
  point top = body.get_points()[0];
  body.add_point(top.get_x() + 2, top.get_y() + 1);
  body.add_point(top.get_x() + 3, top.get_y() + 2);
  body.add_point(top.get_x() + 3, top.get_y() + 8);
  body.add_point(top.get_x() + 6, top.get_y() + 8);
  body.add_point(top.get_x() + 7, top.get_y() + 9);
  body.add_point(top.get_x() + 11, top.get_y() + 20);
  body.add_point(top.get_x() + 58, top.get_y() + 20);
  body.add_point(top.get_x() + 60, top.get_y() + 21);
  body.add_point(top.get_x() + 60, top.get_y() + 22);
  body.add_point(top.get_x() + 58, top.get_y() + 23);
  body.add_point(top.get_x() + 9, top.get_y() + 23);
  body.add_point(top.get_x() + 5, top.get_y() + 11);
  body.add_point(top.get_x() - 5, top.get_y() + 11);
  body.add_point(top.get_x() - 9, top.get_y() + 23);
  body.add_point(top.get_x() - 58, top.get_y() + 23);
  body.add_point(top.get_x() - 60, top.get_y() + 22);
  body.add_point(top.get_x() - 60, top.get_y() + 21);
  body.add_point(top.get_x() - 58, top.get_y() + 20);
  body.add_point(top.get_x() - 11, top.get_y() + 20);
  body.add_point(top.get_x() - 7, top.get_y() + 9);
  body.add_point(top.get_x() - 6, top.get_y() + 8);
  body.add_point(top.get_x() - 3, top.get_y() + 8);
  body.add_point(top.get_x() - 3, top.get_y() + 2);
  body.add_point(top.get_x() - 2, top.get_y() + 1);
  body.scale(center_size / 12);
  body.draw_stroke(0, 0, color);
}
