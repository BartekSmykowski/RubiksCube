#pragma once
#include <glm\glm.hpp>

namespace BasicEngine {
	namespace Camera {
		class CameraFPSEuler {
		public:
			CameraFPSEuler();
			CameraFPSEuler(float pitch, float yaw, glm::vec3 eyeVector);
			~CameraFPSEuler();
			void UpdateView();
			glm::mat4 GetViewMatrix() const;
			void KeyPressed(const unsigned char key);
			void MouseMove(int x, int y);
			void MousePressed(int x, int y);
			glm::vec3 GetEyeVector();
			void setEyeVector(glm::vec3 eyeVector);

		private:
			glm::mat4 viewMatrix;
			glm::vec3 eyeVector;
			float pitch;
			float yaw;
			glm::vec2 mousePosition;

		};

	}
}