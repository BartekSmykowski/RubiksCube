#include "Player.h"
#include <iostream>

using namespace MazeModel;

Player::Player()
{
	camera = new CameraFPSEuler(0,0,glm::vec3(0,0,0));
	position = glm::vec2(0, 0);
	collider = new Collider();
}

MazeModel::Player::Player(glm::vec2 position)
{
	this->position = position;
	camera = new CameraFPSEuler(0, 0, glm::vec3(position.x, 0, position.y));
	collider = new Collider();
}

Player::~Player()
{
	if(camera)
		delete camera;
	if (collider)
		delete collider;
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


	glm::mat4 mat = camera->GetViewMatrix();
	glm::vec3 forward(mat[0][2], mat[1][2], mat[2][2]);
	glm::vec3 strafe(mat[0][0], mat[1][0], mat[2][0]);

	glm::vec3 eyeVectorTmp = (-dz * forward + dx * strafe) * speed;

	//int x_index = (int)((position.x + eyeVectorTmp.x + 1) / 2);
	//int y_index = (int)((position.y + eyeVectorTmp.z + 1) / 2);

	//float x_czesc_ulamkowa = (position.x + eyeVectorTmp.x + 1) / 2 - x_index - 0.5;
	//float y_czesc_ulamkowa = (position.y + eyeVectorTmp.z + 1) / 2 - y_index - 0.5;

	//std::cout << "Indexy x i y: " << x_index << ", " << y_index << std::endl;
	//std::cout << "Znak: " << colisionMap[x_index][y_index] << std::endl;
	//std::cout << "Czesci ulamkowe x i y: " << x_czesc_ulamkowa << ", " << y_czesc_ulamkowa << std::endl;

	//if (colisionMap[x_index][y_index] == ' ' && 
	//	x_czesc_ulamkowa > -0.25 && x_czesc_ulamkowa < 0.25 && 
	//	y_czesc_ulamkowa > -0.25 && y_czesc_ulamkowa < 0.25) {
	//	position += glm::vec2(eyeVectorTmp.x, eyeVectorTmp.z);
	//	camera->setEyeVector(glm::vec3(position.x, 0, position.y));
	//	camera->UpdateView();
	//}
	if (collider->checkCollision(glm::vec2(position.x + eyeVectorTmp.x, position.y + eyeVectorTmp.z))) {
		position += glm::vec2(eyeVectorTmp.x, eyeVectorTmp.z);
		camera->setEyeVector(glm::vec3(position.x, 0, position.y));
		camera->UpdateView();
	}
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

void MazeModel::Player::SetCollisionMap(char ** colisionMap, int x, int y)
{
	this->colisionMap = colisionMap;
	delete collider;
	collider = new Collider(colisionMap, x, y);
}

