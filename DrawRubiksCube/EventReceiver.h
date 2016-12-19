#pragma once
#include <BasicEngine\Engine.h>
#include "RubiksCube\Cube.h"
#include "BrickModel.h"
#include "BricksModelsManager.h"
#include <vector>

using namespace BasicEngine;
using namespace RubiksCube;

class EventReceiver {
public:
	EventReceiver();
	~EventReceiver();
	static void setCube(Cube *cube);
	static void setEngine(Engine *engine);
	static void setModelsManager(BricksModelsManager *bmm);
	static void KeyCallback(unsigned char key, int x, int y);
	static void MouseMoveCallback(int x, int y);
	static void PassiveMouseMoveCallback(int x, int y);
private:

	static vector<Cube *> cubes;
	static Engine *engine;
	static vector<BricksModelsManager *> bricksModelsManagers;
	static int x;
	static int y;

};