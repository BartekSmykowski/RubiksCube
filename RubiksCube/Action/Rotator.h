#pragma once
#include "..\Elements\Brick.h"
#include <vector>


namespace RubiksCube {

	using namespace Elements;
	typedef std::vector<std::vector<Brick*>> Bricks_surface_t;

	namespace Action {
		class Rotator {
		public:
			Rotator();
			Rotator(int size_of_cube);
			Bricks_surface_t rotate(Bricks_surface_t in_surface);

		private:
			Bricks_surface_t surface;

		};
	}
}