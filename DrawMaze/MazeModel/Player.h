#pragma once
#include <glm\glm.hpp>
#include <BasicEngine\Camera\CameraFPSEuler.h>
#include "Collider.h"

using namespace BasicEngine::Camera;

namespace MazeModel {

	class Player {
	public:
		Player();
		Player(glm::vec2 position);
		~Player();
		void notifyMouseMovePressed(int x, int y);
		void notifyMouseMove(int x, int y);
		void notifyKeyDown(const char key);
		CameraFPSEuler *GetCamera();
		void setPosition(glm::vec2 position);
		void SetCollisionMap(char **colisionMap, int x, int y);

	private:
		CameraFPSEuler *camera;
		glm::vec2 position;
		char **colisionMap;
		Collider *collider;

	};
}