#include "Edge.h"

using namespace RubiksCube;
using namespace Elements;

Edge::Edge() {
	tile_[0] = Tile();
	tile_[1] = Tile();
};

Edge::Edge(orientation_type up, orientation_type front) {
	orientation_type orientations[2] = { up, front };
	Color_t color = N;
	for (int i = 0; i < 2; i++) {
		switch (orientations[i]) {
		case UP: color = Y; break;
		case DOWN: color = W; break;
		case LEFT: color = O; break;
		case RIGHT: color = R; break;
		case BACK: color = G; break;
		case FRONT: color = B; break;
		}
		tile_[i] = Tile(orientations[i], color);
	}
};

Color_t Edge::get_color(orientation_type which) {
	for (int i = 0; i < 2; i++) {
		if (tile_[i].get_orientation() == which) {
			return tile_[i].get_color();
		}
	}
	return N;
}


void Edge::rotate(orientation_type color, rotate_direction_t direction) {
	for (int i = 0; i < 2; i++) {
		tile_[i].rotate(color, direction);
	}
};