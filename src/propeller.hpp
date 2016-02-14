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
		float size;
		float rotation;

	public:
		propeller();
		void draw(point n_center, float n_size, float n_rotation);

};

#endif