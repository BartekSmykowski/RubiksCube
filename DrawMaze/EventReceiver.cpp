#include "EventReceiver.h"
#include <iostream>
#include <glm\glm.hpp>

using namespace std;

Player * EventReceiver::player = 0;
Engine *EventReceiver::engine = NULL;
int EventReceiver::x = 0;
int EventReceiver::y = 0;

EventReceiver::EventReceiver() {

}

EventReceiver::~EventReceiver() {

}

void EventReceiver::setPlayer(Player * player)
{
	EventReceiver::player = player;
}

void EventReceiver::setEngine(Engine *engine) {
	EventReceiver::engine = engine;
}

void EventReceiver::KeyCallback(unsigned char key, int x, int y){
	//engine->GetScene_Manager()->notifyKeyDown(key, x, y);
	player->notifyKeyDown(key);
}

void EventReceiver::MouseMoveCallback(int x, int y) {
	//engine->GetScene_Manager()->notifyMouseMove(x, y);
	engine->GetScene_Manager()->notifyPassiveMouseMove(x, y);
	player->notifyKeyDown('w');
	//player->notifyMouseMovePressed(x, y);
	EventReceiver::x = x;
	EventReceiver::y = y;
}

void EventReceiver::PassiveMouseMoveCallback(int x, int y)
{
	engine->GetScene_Manager()->notifyPassiveMouseMove(x, y);
	//player->notifyMouseMove(x, y);
	EventReceiver::x = x;
	EventReceiver::y = y;
}
