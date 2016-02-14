#ifndef _PARACHUTE_H
#define _PARACHUTE_H

#include "polygon.hpp"
#include "point.hpp"
#include "circle.hpp"
#include "line.hpp"
#include <vector>
#include <iostream>

class parachute {

	public:
		parachute(point center);
		void set_center(int x, int y);
		void draw();
		void move(int delta_x, int delta_y);
		void rotate(float angle, int x_origin, int y_origin);

	private:
		int radius;
		point center;
		point point_parachute[7];
		polygon people;

};

#endif