#pragma once
#include "Enums.h"


namespace RubiksCube
{
	class Tile {
	public:
		Tile();
		Tile(orientation_type orientation, Color_t color);
		void rotate(orientation_type orientation, rotate_direction_t direction);
		orientation_type get_orientation();
		Color_t get_color();
		~Tile();

	private:
		char name_;
		orientation_type orientation_;
		Color_t color_;
	};
}