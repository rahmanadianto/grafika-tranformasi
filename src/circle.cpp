#include "circle.hpp"

circle::circle() {
    this->radius = 1;
}

circle::circle(point center, int radius) {
  this->center = center;
  this->radius = radius;
}

int circle::get_radius() {
  return this->radius;
}

point circle::get_center() {
  return this->center;
}


void circle::set_center(point new_center) {
  this->center = new_center;
}

void circle::set_radius(int new_radius) {
  this->radius = new_radius;
}

void circle::draw_stroke(uint32_t color) {
  int P;
  int x, y;
  P = 1 - radius;
  x = 0;
  y = radius;

  draw(x, y, center.get_x(), center.get_y(), color);
  while (x <= y) {
    x++;
    if (P<0) {
      P += 2 * x + 1;
    }
    else {
      P += 2 * (x - y) + 1;
      y--;
    }
    draw(x, y, center.get_x(), center.get_y(), color);
  }
}

void circle::draw_fill(uint32_t color) {
  draw_fill_rec(center.get_x(), center.get_y(), color);
}

void circle::draw_fill_rec(int x, int y, uint32_t color) {
  if (((x > 0) && (x < (int) canvas::get_instance()->get_var_info().xres)) ||
      ((y > 0) && (y < (int) canvas::get_instance()->get_var_info().yres))) {
		if (canvas::get_instance()->get_color(x, y) != color) {
			canvas::get_instance()->draw_pixel(x, y, color);
			draw_fill_rec(x + 1, y, color);
			draw_fill_rec(x - 1, y, color);
			draw_fill_rec(x, y + 1, color);
			draw_fill_rec(x, y - 1, color);
		}
	}
}


void circle::draw(int x, int y, int xC, int yC, uint32_t color) {
  canvas::get_instance()->draw_pixel(xC + x, yC + y, color);
  canvas::get_instance()->draw_pixel(xC + x, yC - y, color);
  canvas::get_instance()->draw_pixel(xC - x, yC + y, color);
  canvas::get_instance()->draw_pixel(xC - x, yC - y, color);
  canvas::get_instance()->draw_pixel(xC + y, yC + x, color);
  canvas::get_instance()->draw_pixel(xC - y, yC + x, color);
  canvas::get_instance()->draw_pixel(xC + y, yC - x, color);
  canvas::get_instance()->draw_pixel(xC - y, yC - x, color);
}
