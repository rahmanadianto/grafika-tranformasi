#ifndef POLYGON_H
#define POLYGON_H

#include <vector>
#include "include.hpp"
#include "canvas.hpp"
#include "color.hpp"
#include "point.hpp"

class polygon {
public:
	polygon();
	void add_point(int x, int y);
	void add_point(point p);
	void draw_stroke(int x = 0, int y = 0, uint32_t color = 0xffffffff);
	void draw_fill(int x, int y, uint32_t color = 0xffffffff);
	void scale(float scale, int x_origin = 0, int y_origin = 0);
	std::vector<point> get_points();
private:
	int scale_factor;
	std::vector<point> points;
};

#endif