#pragma once
#include <BasicEngine\Engine.h>
#include <vector>
#include "MazeModel\Player.h"

using namespace BasicEngine;
using namespace MazeModel;

class EventReceiver {
public:
	EventReceiver();
	~EventReceiver();
	static void setPlayer(Player *player);
	static void setEngine(Engine *engine);
	static void KeyCallback(unsigned char key, int x, int y);
	static void MouseMoveCallback(int x, int y);
	static void PassiveMouseMoveCallback(int x, int y);
private:

	static Player *player;
	static Engine *engine;
	static int x;
	static int y;

};