#pragma once
#include <BasicEngine\Engine.h>
#include "..\MazeModel\maze.h"
#include "..\MazeModel\Enums.h"

using namespace MazeModel;
using namespace BasicEngine;

namespace DrawMaze {
	class WallsModelsManager {
	public:
		WallsModelsManager();
		~WallsModelsManager();
		WallsModelsManager(Maze *maze, Engine *engine);
		void updateBricksModels();
		void createBricksModels();
		colorT PrzypiszKolor(char type);

	private:
		Maze *maze;
		Engine *engine;
	};
}