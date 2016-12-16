#pragma once
#include "..\Tile.h"
#include "glm\glm.hpp"
#include "../Action/Animator.h"


using namespace RubicsCube::Action;

namespace RubiksCube
{
	namespace Elements
	{
		class Brick {
		public:
			Brick();
			virtual Color_t get_color(orientation_type which) = 0;
			virtual void rotate(orientation_type color, rotate_direction_t direction) = 0;
			void StartAnimate(orientation_type orientation, rotate_direction_t direction);
			void Animate();
			bool IsRotating();
			void setLengthOfEdge(double length);
			double getLengthOfEdge();

			glm::vec3 getAnimationAngle();

		private:
			Animator animator;
			double lengthOfEdge;
		};
	}
}
