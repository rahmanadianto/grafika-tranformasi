#ifndef PLANE_H
#define PLANE_H

#include "point.hpp"
#include "circle.hpp"
#include "polygon.hpp"
#include "propeller.hpp"

class plane {

public:
  plane();
  plane(point center, int center_size);
  point get_center();
  int get_size();
  void set_center(point new_center);
  void set_size(int new_size);
  void rotate_propeller(float rotate_factor);
  void move(int delta_x, int delta_y);
  void draw(uint32_t color);
  void crash();

private:
  point center;
  int center_size;
  float rotate_factor;
  bool is_crash;
  int crash_value;
  circle c_center;
  circle c_left;
  circle c_right;
  //polygon body;
};

#endif
