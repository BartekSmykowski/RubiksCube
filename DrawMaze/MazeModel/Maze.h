#pragma once
#include <glm\glm.hpp>
#include <string>
#include "Player.h"

namespace MazeModel {

	class Maze {
	public:
		Maze();
		~Maze();
		void LoadFromFile(char *filename);
		void SaveToFile(const std::string &filename);
		Player *Getplayer();
		glm::ivec2 GetDimensions();
		char GetTypeOfWall(glm::ivec2 coordinates);

	private:
		std::string name;
		char **board;
		glm::ivec2 dimensions;
		Player *player;
	};


}