#include "ColorArranger.h"

Action::ColorArranger::ColorArranger()
{
	whichWall = NONE;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int c = 0; c < 4; c++) {
				colors[i][j][c] = glm::vec4(1.0, 1.0, 1.0, 1.0);
			}
		}
	}
}

Action::ColorArranger::ColorArranger(Cube *cube, orientation_type whichWall)
{
	this->whichWall = whichWall;

}

Action::ColorArranger::~ColorArranger()
{

}
