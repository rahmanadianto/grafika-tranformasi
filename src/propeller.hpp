#ifndef PROPELLER_H
#define PROPELLER_H

#include "canvas.hpp"
#include "point.hpp"
#include "color.hpp"
#include "circle.hpp"
#include "polygon.hpp"

class propeller {
	private:
		point center;
		int size;

	public:
		propeller();
		void set_center(point c);
		void set_size(int s);
		void draw();

};

#endif