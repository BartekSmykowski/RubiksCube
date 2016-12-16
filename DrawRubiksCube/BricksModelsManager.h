#pragma once
#include <BasicEngine\Engine.h>
#include "RubiksCube\Cube.h"

using namespace RubiksCube;
using namespace BasicEngine;

class BricksModelsManager {
public:
	BricksModelsManager();
	~BricksModelsManager();
	BricksModelsManager(Cube *cube, Engine *engine);
	void updateBricksModels();
	void createBricksModels();

private:
	Cube *cube;
	Engine *engine;
};