#pragma once
#include "Elements\Brick.h"
#include "Elements\Edge.h"
#include "Elements\Corner.h"
#include "Elements\Center.h"
#include <glm\glm.hpp>


namespace RubiksCube {
	using namespace Elements;
	class BricksContainer {
	public:
		BricksContainer();
		BricksContainer(int size);
		BricksContainer(int size, glm::vec3 translation);
		BricksContainer(const BricksContainer& bricksContainer);
		~BricksContainer();
		Brick* getBrick(glm::vec3 wspolzedne);
		void setBrick(glm::vec3 wspolzedne, Brick *brick);
		int getSize();
		bool IsRotating();
		void fill(int size);

	private:
		Brick ****bricks_;
		int size;
		glm::vec3 translation;
	};

}