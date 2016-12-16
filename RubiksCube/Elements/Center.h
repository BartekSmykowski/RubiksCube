#pragma once
#include "Brick.h"

namespace RubiksCube
{
	namespace Elements
	{
		class Center : public Brick {
		public:
			Center();
			Center(orientation_type up);
			Color_t get_color(orientation_type which);
			void rotate(orientation_type color, rotate_direction_t direction);

		private:
			Tile tile_;
		};
	}
}