#ifndef LINE_H
#define LINE_H

#include "include.hpp"
#include "canvas.hpp"
#include "point.hpp"

class line {
public:
	line(int x1, int y1, int x2, int y2);
	line(point p1, point p2);
	void set_point(int x1, int y1, int x2, int y2);
	void set_point(point p1, point p2);
	void draw(uint32_t color = 0xffffffff);
	void move(int x, int y);
	void scale(int scale);
private:
	point p1;
	point p2;
};

#endif