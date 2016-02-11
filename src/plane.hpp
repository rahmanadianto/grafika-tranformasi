#ifndef PLANE_H
#define PLANE_H

#include "point.hpp"
#include "circle.hpp"
#include "polygon.hpp"

class plane {

public:
  plane();
  plane(point center, int center_size);
  point get_center();
  int get_size();
  void set_center(point new_center);
  void set_size(int new_size);
  void draw(uint32_t color);

private:
  point center;
  int center_size;
  circle c_center;
  circle c_left;
  circle c_right;
  polygon body;
};

#endif
