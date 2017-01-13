#pragma once
#include <glm\glm.hpp>

namespace MazeModel {
	class Collider {
	public:
		Collider();
		Collider(char **mazeMap, int x, int y);
		~Collider();
		bool checkCollision(glm::vec2 newPosition);

	private:
		bool **collisionMap;
		int width; 
		int height;
	};
}