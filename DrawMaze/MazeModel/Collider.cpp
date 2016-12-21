#include "Collider.h"
#include <iostream>

MazeModel::Collider::Collider()
{
	collisionMap = nullptr;
	width = 0;
	height = 0;
}

MazeModel::Collider::Collider(char ** mazeMap, int x, int y)
{
	this->width = 2 * x + 1;
	this->height = 2 * y + 1;
	collisionMap = new bool*[width];
	for (int i = 0; i < width; i++) {
		collisionMap[i] = new bool[height];
	}


	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			collisionMap[i][j] = true;
		}
	}

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (mazeMap[i][j] != ' ') {
				for (int ip = -1; ip < 2; ip++) {
					for (int jp = -1; jp < 2; jp++) {
						collisionMap[2 * i + 1 + ip][2 * j + 1 + jp] = false;
					}
				}
			}
		}
	}
	std::cout << "Konstruktor Collider:" << std::endl;
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			if(collisionMap[i][j] == true)
				std::cout << ".";
			else
				std::cout << "#";
		}
		std::cout << std::endl;
	}
}

MazeModel::Collider::~Collider()
{
	for (int i = 0; i < width; i++) {
		delete[] collisionMap[i];
	}
	delete[] collisionMap;
}

bool MazeModel::Collider::checkCollision(glm::vec2 newPosition)
{
	bool wynik = false;

	int x_index = (int)(newPosition.x + 1.5);
	int y_index = (int)(newPosition.y + 1.5);

	if (collisionMap[x_index][y_index] == true)
		wynik = true;

	return wynik;
}
