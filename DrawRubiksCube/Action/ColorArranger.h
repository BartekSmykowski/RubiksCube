#pragma once
#include "RubiksCube\Cube.h"

using namespace RubiksCube;

namespace Action {
	
	class ColorArranger {
		ColorArranger();
		ColorArranger(Cube *cube, orientation_type whichWall);
		~ColorArranger();
		void arrangeColor();
		glm::vec4 getColor(glm::vec2 wspolzedne);

	private:
		glm::vec4 colors[3][3][4];
		orientation_type whichWall;
	};
}