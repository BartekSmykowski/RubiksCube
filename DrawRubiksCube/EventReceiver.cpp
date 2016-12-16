#include "EventReceiver.h"
#include <iostream>
#include <glm\glm.hpp>

using namespace std;

Cube *EventReceiver::cube = NULL;
Engine *EventReceiver::engine = NULL;
BricksModelsManager *EventReceiver::bricksModelsManager = NULL;
int EventReceiver::x = 0;
int EventReceiver::y = 0;

EventReceiver::EventReceiver() {

}

EventReceiver::~EventReceiver() {

}

void EventReceiver::setCube(Cube *cubep) {
	cube = cubep;
}

void EventReceiver::setEngine(Engine *enginep) {
	engine = enginep;
}

void EventReceiver::setModelsManager(BricksModelsManager *bmm) {
	bricksModelsManager = bmm;
}

void EventReceiver::KeyCallback(unsigned char key, int x, int y){
	BrickModel* brickm = new BrickModel();
	switch (key) {
	case 'a':case 'w':case 'd':case 's':case 'e':
		engine->GetScene_Manager()->notifyKeyDown(key, x, y);
		break;
	case 'u':
		cube->rotate_wall(UP, CLOCK);
		break;
	case 'n':
		cube->rotate_wall(DOWN, CLOCK);
		break;
	case 'y':
		cube->rotate_wall(LEFT, CLOCK);
		break;
	case 'i':
		cube->rotate_wall(RIGHT, CLOCK);
		break;
	case 'h':
		cube->rotate_wall(FRONT, CLOCK);
		break;
	case 'k':
		cube->rotate_wall(BACK, CLOCK);
		break;
	}
	bricksModelsManager->updateBricksModels();
}

void EventReceiver::MouseMoveCallback(int x, int y) {
	engine->GetScene_Manager()->notifyMouseMove(x, y);
	glm::vec3 rotationOld = cube->getRotation();
	glm::vec3 newRotation = rotationOld + glm::vec3(y - EventReceiver::y, x - EventReceiver::x, 0);
	cube->setRotation(newRotation);
	bricksModelsManager->updateBricksModels();
	EventReceiver::x = x;
	EventReceiver::y = y;
}

void EventReceiver::PassiveMouseMoveCallback(int x, int y)
{
	engine->GetScene_Manager()->notifyPassiveMouseMove(x, y);
	EventReceiver::x = x;
	EventReceiver::y = y;
}
