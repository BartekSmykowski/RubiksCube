#pragma once
#include "Elements\Brick.h"
#include "Elements\Edge.h"
#include "Elements\Corner.h"
#include "Elements\Center.h"
#include <stdio.h>
#include <glm\glm.hpp>
#include "BricksContainer.h"
#include "Action\Animator.h"
#include "Action\Translation.h"

namespace RubiksCube
{
	using namespace Elements;

	class Cube {
	public:
		Cube();
		Cube(int size);
		Cube(int size, glm::vec3 translation);
		void rotate_wall(orientation_type wall, rotate_direction_t direction);
		void KeyEventCallback(unsigned char key, int x, int y);
		Brick *get_brick(glm::vec3 wpolzedne);
		Color_t get_brick_color(glm::vec3 wpolzedne, orientation_type which);
		void setRotation(glm::vec3 rotation);
		glm::vec3 getRotation();
		int getSize();
		~Cube();

	private:
		BricksContainer *bricksContainer;
		int size;
		Animator animator;
		glm::vec3 translation;

	};
}