#include "Player.h"

using namespace MazeModel;

Player::Player()
{
	camera = new CameraFPSEuler(0,0,glm::vec3(0,0,0));
	position = glm::vec2(0, 0);
}

MazeModel::Player::Player(glm::vec2 position)
{
	this->position = position;
	camera = new CameraFPSEuler(0, 0, glm::vec3(position.x, 0, position.y));
}

Player::~Player()
{
	if(camera)
		delete camera;
}

void MazeModel::Player::notifyMouseMovePressed(int x, int y)
{
	camera->MousePressed(x, y);
}

void MazeModel::Player::notifyMouseMove(int x, int y)
{
	camera->MouseMove(x, y);
}

void MazeModel::Player::notifyKeyDown(const char key)
{
	float dx = 0;
	float dz = 0;
	switch (key)
	{
	case 'w':
	{
		dz = -2;
		break;
	}
	case 's':
	{
		dz = 2;
		break;
	}
	case 'a':
	{
		dx = -2;
		break;
	}
	case 'd':
	{
		dx = 2;
		break;
	}
	default:
		break;
	}

	const float speed = 0.12f;

	position += glm::vec2(dx*speed, dz*speed);

	camera->setEyeVector(glm::vec3(position.x, 0, position.y));
}

CameraFPSEuler * MazeModel::Player::GetCamera()
{
	return camera;
}

void MazeModel::Player::setPosition(glm::vec2 position)
{
	this->position = position;
	this->camera->setEyeVector(glm::vec3(position.x, 0, position.y));
}
