#include "EventReceiver.h"
#include <iostream>
#include <glm\glm.hpp>

using namespace std;

vector<Cube *> EventReceiver::cubes = {};
Engine *EventReceiver::engine = NULL;
vector<BricksModelsManager *> EventReceiver::bricksModelsManagers = {};
int EventReceiver::x = 0;
int EventReceiver::y = 0;

EventReceiver::EventReceiver() {

}

EventReceiver::~EventReceiver() {

}

void EventReceiver::setCube(Cube *cubep) {
	cubes.push_back(cubep);
}

void EventReceiver::setEngine(Engine *enginep) {
	engine = enginep;
}

void EventReceiver::setModelsManager(BricksModelsManager *bmm) {
	bricksModelsManagers.push_back(bmm);
}

void EventReceiver::KeyCallback(unsigned char key, int x, int y){
	for (int i = 0; i < cubes.size(); i++) {
		switch (key) {
		case 'a':case 'w':case 'd':case 's':case 'e':
			engine->GetScene_Manager()->notifyKeyDown(key, x, y);
			break;
		case 'u':
			cubes[i]->rotate_wall(UP, CLOCK);
			break;
		case 'n':
			cubes[i]->rotate_wall(DOWN, CLOCK);
			break;
		case 'y':
			cubes[i]->rotate_wall(LEFT, CLOCK);
			break;
		case 'i':
			cubes[i]->rotate_wall(RIGHT, CLOCK);
			break;
		case 'h':
			cubes[i]->rotate_wall(FRONT, CLOCK);
			break;
		case 'k':
			cubes[i]->rotate_wall(BACK, CLOCK);
			break;
		}
		bricksModelsManagers[i]->updateBricksModels();
	}
}

void EventReceiver::MouseMoveCallback(int x, int y) {
	for (int i = 0; i < cubes.size(); i++) {
		int mod = 0;
		engine->GetScene_Manager()->notifyMouseMove(x, y);
		glm::vec3 rotationOld = cubes[i]->getRotation();
		i % 2 == 0 ? mod = -1 : mod = 1;
		glm::vec3 newRotation = rotationOld + glm::vec3(mod*(y - EventReceiver::y), mod*(x - EventReceiver::x), 0);
		cubes[i]->setRotation(newRotation);
		bricksModelsManagers[i]->updateBricksModels();
	}
	EventReceiver::x = x;
	EventReceiver::y = y;
}

void EventReceiver::PassiveMouseMoveCallback(int x, int y)
{
	engine->GetScene_Manager()->notifyPassiveMouseMove(x, y);
	EventReceiver::x = x;
	EventReceiver::y = y;
}
