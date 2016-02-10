#include "color.hpp"

uint32_t color::rgb(int r, int g, int b) {
	return rgba(r, g, b, 0xff);
}

uint32_t color::rgba(int r, int g, int b, int a) {
	return ((r & 0xff) << 24) + ((g & 0xff) << 16) + ((b & 0xff) << 8) + (a & 0xff);
}