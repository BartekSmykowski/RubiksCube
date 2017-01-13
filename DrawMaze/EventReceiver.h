#pragma once
#include <BasicEngine\Engine.h>
#include <vector>
#include "DrawMaze\WallModelsManager.h"
#include "MazeModel\Player.h"

using namespace BasicEngine;
using namespace MazeModel;
using namespace DrawMaze;

class EventReceiver {
public:
	EventReceiver();
	~EventReceiver();
	static void setPlayer(Player *player);
	static void setEngine(Engine *engine);
	static void setModelsManager(WallsModelsManager *wmm);
	static void KeyCallback(unsigned char key, int x, int y);
	static void MouseMoveCallback(int x, int y);
	static void PassiveMouseMoveCallback(int x, int y);
private:

	static Player *player;
	static Engine *engine;
	static WallsModelsManager *wallsModelsManager;
	static int x;
	static int y;

};