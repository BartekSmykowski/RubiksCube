#include "Tile.h"

using namespace RubiksCube;

Tile::Tile() {
	orientation_ = UP;
	color_ = N;
}

Tile::Tile(orientation_type orientation, Color_t color) {
	orientation_ = orientation;
	color_ = color;
}

void Tile::rotate(orientation_type orientation, rotate_direction_t direction) {
	switch (orientation) {
	case UP: 	
		switch (orientation_) {
		case UP: orientation_ = UP; break;
		case DOWN: orientation_ = DOWN; break;
		case LEFT: orientation_ = BACK; break;
		case RIGHT: orientation_ = FRONT; break;
		case BACK: orientation_ = RIGHT; break;
		case FRONT: orientation_ = LEFT; break;
		}
		break;
	case DOWN:
		switch (orientation_) {
		case UP: orientation_ = UP; break;
		case DOWN: orientation_ = DOWN; break;
		case LEFT: orientation_ = FRONT; break;
		case RIGHT: orientation_ = BACK; break;
		case BACK: orientation_ = LEFT; break;
		case FRONT: orientation_ = RIGHT; break;
		}
		break;
	case LEFT:
		switch (orientation_) {
		case UP: orientation_ = FRONT; break;
		case DOWN: orientation_ = BACK; break;
		case LEFT: orientation_ = LEFT; break;
		case RIGHT: orientation_ = RIGHT; break;
		case BACK: orientation_ = UP; break;
		case FRONT: orientation_ = DOWN; break;
		}
		break;
	case RIGHT:
		switch (orientation_) {
		case UP: orientation_ = BACK; break;
		case DOWN: orientation_ = FRONT; break;
		case LEFT: orientation_ = LEFT; break;
		case RIGHT: orientation_ = RIGHT; break;
		case BACK: orientation_ = DOWN; break;
		case FRONT: orientation_ = UP; break;
		}
		break;
	case BACK:
		switch (orientation_) {
		case UP: orientation_ = LEFT; break;
		case DOWN: orientation_ = RIGHT; break;
		case LEFT: orientation_ = DOWN; break;
		case RIGHT: orientation_ = UP; break;
		case BACK: orientation_ = BACK; break;
		case FRONT: orientation_ = FRONT; break;
		}
		break;
	case FRONT:
		switch (orientation_) {
		case UP: orientation_ = RIGHT; break;
		case DOWN: orientation_ = LEFT; break;
		case LEFT: orientation_ = UP; break;
		case RIGHT: orientation_ = DOWN; break;
		case BACK: orientation_ = BACK; break;
		case FRONT: orientation_ = FRONT; break;
		}
		break;
	}
}

orientation_type Tile::get_orientation() {
	return orientation_;
}

Color_t Tile::get_color() {
	return color_;
}

Tile::~Tile() {

}