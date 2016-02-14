#ifndef _PARACHUTE_H
#define _PARACHUTE_H

#include "gl.hpp"
#include <vector>
#include <iostream>

class parachute {

	public:
		parachute(point center);
		void set_center(int x, int y);
		void draw();

	private:
		int radius;
		point center;
		point point_parachute[7];
		polygon people;

};

#endif