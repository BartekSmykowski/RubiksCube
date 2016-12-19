#pragma once
#include <glm/glm.hpp>
#include "../Enums.h"

namespace RubicsCube {
	namespace Action {
		class Translation {
		public:
			Translation();
			~Translation();

			glm::vec3 GetTranslation();
			void SetTranslation(glm::vec3 translation);

		private:
			glm::vec3 translation;

		};
	}
}