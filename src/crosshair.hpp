#ifndef CROSSHAIR_H
#define CROSSHAIR_H

#include <vector>
#include "include.hpp"
#include "canvas.hpp"
#include "color.hpp"
#include "line.hpp"

class crosshair {
public:
	crosshair();
	std::vector<point> get_points();
	void reset();

	void draw_stroke(uint32_t color = 0xffffffff);
	void draw_horizontal(uint32_t color = 0xffffffff);
	void draw_vertical(uint32_t color = 0xffffffff);

	int getX();
	int getY();

	// Transformation
	void scale(float scale);
	void scaleOutline(float outline_scale);
	void rotate(float rotate);

	void setX(int x);
	void setY(int y);

	void moveX(int dx);
	void moveY(int dy);

private:
	int x_pos;
	int y_pos;
	float outline_scale;
	float rotate_factor;
	std::vector<line> lines;
};

#endif
