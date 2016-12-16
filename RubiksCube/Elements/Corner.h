#pragma once
#include "Brick.h"

namespace RubiksCube
{
	namespace Elements
	{
		class Corner : public Brick {
		public:
			Corner();
			Corner(orientation_type up, orientation_type left, orientation_type right);
			Color_t get_color(orientation_type which);
			void rotate(orientation_type color, rotate_direction_t direction);

		private:
			Tile tile_[3];
		};
	}
}