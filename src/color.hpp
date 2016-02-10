#ifndef COLOR_H
#define COLOR_H

#include "include.hpp"

class color {
public:
	static uint32_t rgb(int r, int g, int b);
	static uint32_t rgba(int r, int g, int b, int a);
};

#endif