#include "Center.h"

using namespace RubiksCube;
using namespace Elements;

Center::Center() {
	tile_ = Tile();
};

Center::Center(orientation_type up) {
	Color_t color = N;
	switch (up) {
	case UP: color = Y; break;
	case DOWN: color = W; break;
	case LEFT: color = O; break;
	case RIGHT: color = R; break;
	case BACK: color = G; break;
	case FRONT: color = B; break;
	}
	tile_ = Tile(up, color);
};


Color_t Center::get_color(orientation_type which) {
	if (tile_.get_orientation() == which)
		return tile_.get_color();
	return N;
}

void Center::rotate(orientation_type color, rotate_direction_t direction) {
	tile_.rotate(color, direction);
};