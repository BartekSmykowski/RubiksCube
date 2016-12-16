#include "BricksContainer.h"

using namespace RubiksCube;

BricksContainer::BricksContainer() {
	size = 3;

	bricks_ = new Brick***[size];
	for (int i = 0; i < size; i++)
		bricks_[i] = new Brick**[size];
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			bricks_[i][j] = new Brick*[size];
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			for (int k = 0; k < size; k++) {
				bricks_[i][j][k] = nullptr;
			}
		}
	}

};


BricksContainer::BricksContainer(int size) {
	this->size = size;

	bricks_ = new Brick***[size];
	for (int i = 0; i < size; i++)
		bricks_[i] = new Brick**[size];
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			bricks_[i][j] = new Brick*[size];
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			for (int k = 0; k < size; k++) {
				bricks_[i][j][k] = nullptr;
			}
		}
	}

};

BricksContainer::BricksContainer(const BricksContainer& bricksContainer) {
	this->size = bricksContainer.size;

	bricks_ = new Brick***[size];
	for (int i = 0; i < size; i++)
		bricks_[i] = new Brick**[size];
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			bricks_[i][j] = new Brick*[size];
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			for (int k = 0; k < size; k++) {
				bricks_[i][j][k] = nullptr;
			}
		}
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			for (int k = 0; k < size; k++) {
				this->setBrick(glm::vec3(i, j, k), bricksContainer.bricks_[i][j][k]);
			}
		}
	}
}

BricksContainer::~BricksContainer() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			for (int k = 0; k < size; k++) {
				delete bricks_[i][j][k];
			}
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			delete[] bricks_[i][j];
		}
	}
	for (int i = 0; i < size; i++)
		delete[] bricks_[i];
	delete[] bricks_;
}
		

Brick* BricksContainer::getBrick(glm::vec3 w) {
	int x = (int)(w.x);
	int y = (int)(w.y);
	int z = (int)(w.z);
	return bricks_[x][y][z];
}

void BricksContainer::setBrick(glm::vec3 w, Brick *brick) {
	bricks_[(int)(w.x)][(int)(w.y)][(int)(w.z)] = brick;
}

int BricksContainer::getSize() {
	return size;
}

bool RubiksCube::BricksContainer::IsRotating()
{
	bool isRotating = false;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			for (int k = 0; k < size; k++) {
				if (this->getBrick(glm::vec3(i, j, k)) != nullptr)
					if (this->getBrick(glm::vec3(i, j, k))->IsRotating())
						isRotating = true;
			}
		}
	}
	return isRotating;
}

void RubiksCube::BricksContainer::fill(int size)
{
	int indexOfEnd = size - 1;
	this->setBrick(glm::vec3(0, 0, 0), new Corner(DOWN, LEFT, BACK));
	for (int i = 1; i < size - 1; i++) {
		this->setBrick(glm::vec3(0, 0, i), new Edge(DOWN, LEFT));
	}
	this->setBrick(glm::vec3(0, 0, indexOfEnd), new Corner(DOWN, FRONT, LEFT));
	for (int i = 1; i < size - 1; i++) {
		this->setBrick(glm::vec3(0, i, 0), new Edge(BACK, LEFT));
	}
	for (int i = 1; i < size - 1; i++) {
		for (int j = 1; j < size - 1; j++) {
			this->setBrick(glm::vec3(0, i, j), new Center(LEFT));
		}
	}
	for (int i = 1; i < size - 1; i++) {
		this->setBrick(glm::vec3(0, i, indexOfEnd), new Edge(FRONT, LEFT));
	}
	this->setBrick(glm::vec3(0, indexOfEnd, 0), new Corner(UP, BACK, LEFT));
	for (int i = 1; i < size - 1; i++) {
		this->setBrick(glm::vec3(0, indexOfEnd, i), new Edge(UP, LEFT));
	}
	this->setBrick(glm::vec3(0, indexOfEnd, indexOfEnd), new Corner(UP, LEFT, FRONT));
	for (int i = 1; i < size - 1; i++) {
		this->setBrick(glm::vec3(i, 0, 0), new Edge(DOWN, BACK));
	}
	for (int i = 1; i < size - 1; i++) {
		for (int j = 1; j < size - 1; j++) {
			this->setBrick(glm::vec3(i, 0, j), new Center(DOWN));
		}
	}
	for (int i = 1; i < size - 1; i++) {
		this->setBrick(glm::vec3(i, 0, indexOfEnd), new Edge(DOWN, FRONT));
	}
	for (int i = 1; i < size - 1; i++) {
		for (int j = 1; j < size - 1; j++) {
			this->setBrick(glm::vec3(i, j, 0), new Center(BACK));
		}
	}
	for (int i = 1; i < size - 1; i++) {
		for (int j = 1; j < size - 1; j++) {
			this->setBrick(glm::vec3(i, j, indexOfEnd), new Center(FRONT));
		}
	}
	for (int i = 1; i < size - 1; i++) {
		this->setBrick(glm::vec3(i, indexOfEnd, 0), new Edge(UP, BACK));
	}
	for (int i = 1; i < size - 1; i++) {
		for (int j = 1; j < size - 1; j++) {
			this->setBrick(glm::vec3(i, indexOfEnd, j), new Center(UP));
		}
	}
	for (int i = 1; i < size - 1; i++) {
		this->setBrick(glm::vec3(i, indexOfEnd, indexOfEnd), new Edge(UP, FRONT));
	}
	this->setBrick(glm::vec3(indexOfEnd, 0, 0), new Corner(DOWN, BACK, RIGHT));
	for (int i = 1; i < size - 1; i++) {
		this->setBrick(glm::vec3(indexOfEnd, 0, i), new Edge(DOWN, RIGHT));
	}
	this->setBrick(glm::vec3(indexOfEnd, 0, indexOfEnd), new Corner(DOWN, RIGHT, FRONT));
	for (int i = 1; i < size - 1; i++) {
		this->setBrick(glm::vec3(indexOfEnd, i, 0), new Edge(BACK, RIGHT));
	}
	for (int i = 1; i < size - 1; i++) {
		for (int j = 1; j < size - 1; j++) {
			this->setBrick(glm::vec3(indexOfEnd, i, j), new Center(RIGHT));
		}
	}
	for (int i = 1; i < size - 1; i++) {
		this->setBrick(glm::vec3(indexOfEnd, i, indexOfEnd), new Edge(FRONT, RIGHT));
	}
	this->setBrick(glm::vec3(indexOfEnd, indexOfEnd, 0), new Corner(UP, RIGHT, BACK));
	for (int i = 1; i < size - 1; i++) {
		this->setBrick(glm::vec3(indexOfEnd, indexOfEnd, i), new Edge(UP, RIGHT));
	}
	this->setBrick(glm::vec3(indexOfEnd, indexOfEnd, indexOfEnd), new Corner(UP, FRONT, RIGHT));


	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			for (int k = 0; k < size; k++) {
				if (this->getBrick(glm::vec3(i, j, k)) != nullptr)
					this->getBrick(glm::vec3(i, j, k))->setLengthOfEdge(1.0/(double)size*2.0);
			}
		}
	}

}
