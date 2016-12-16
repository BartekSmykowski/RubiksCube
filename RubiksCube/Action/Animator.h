#pragma once
#include <glm/glm.hpp>
#include "../Enums.h"

namespace RubicsCube {
	namespace Action {
		class Animator {
		public:
			Animator();
			~Animator();

			void StartAnimation(orientation_type side, rotate_direction_t direction);
			void CountAnimationAngle();
			glm::vec3 GetRotationAngle();
			void setRotationAngle(glm::vec3 rotationAngle);
			bool IsRotating();

		private:
			glm::vec3 rotationAngle;
			glm::vec3 animationDelta;
			orientation_type side;
			rotate_direction_t directon;
			bool isRotating;

		};
	}
}