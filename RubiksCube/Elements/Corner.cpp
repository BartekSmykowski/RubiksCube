#include "Corner.h"

using namespace RubiksCube;
using namespace Elements;

Corner::Corner() {
	tile_[0] = Tile();
	tile_[1] = Tile();
	tile_[2] = Tile();
};

Corner::Corner(orientation_type up, orientation_type left, orientation_type right) {
	orientation_type orientations[3] = { up, left, right };
	Color_t color = N;
	for (int i = 0; i < 3; i++) {
		switch (orientations[i]) {
		case UP   : color = Y; break;
		case DOWN : color = W; break;
		case LEFT : color = O; break;
		case RIGHT: color = R; break;
		case BACK : color = G; break;
		case FRONT: color = B; break;
		}
		tile_[i] = Tile(orientations[i], color);
	}
};

Color_t Corner::get_color(orientation_type which) {
	for (int i = 0; i < 3; i++) {
		if (tile_[i].get_orientation() == which) {
			return tile_[i].get_color();
		}
	}
	return N;
}

void Corner::rotate(orientation_type color, rotate_direction_t direction) {
	for (int i = 0; i < 3; i++) {
		tile_[i].rotate(color, direction);
	}
};