#include "CameraFPSEuler.h"
#include <glm\gtx\rotate_vector.hpp>
#include <glm\gtx\quaternion.hpp>
#include <iostream>
#include <freeglut\freeglut.h>
using namespace std;

using namespace BasicEngine::Camera;

CameraFPSEuler::CameraFPSEuler()
{
	eyeVector = glm::vec3(0,0,-5);
	pitch = -3.14159265;
	yaw = -3.14159265;
	mousePosition = glm::vec2(glutGet(GLUT_WINDOW_WIDTH)/2, glutGet(GLUT_WINDOW_HEIGHT)/2);

	UpdateView();
}

BasicEngine::Camera::CameraFPSEuler::CameraFPSEuler(float pitch, float yaw, glm::vec3 eyeVector)
{
	this->eyeVector = eyeVector;
	this->pitch = yaw;
	this->yaw = pitch;
	mousePosition = glm::vec2(glutGet(GLUT_WINDOW_WIDTH) / 2, glutGet(GLUT_WINDOW_HEIGHT) / 2);
	UpdateView();
}

BasicEngine::Camera::CameraFPSEuler::~CameraFPSEuler()
{
}

void CameraFPSEuler::UpdateView()
{
	//cout << "Yaw: " << yaw << endl;
	//cout << "Pitch: " << pitch << endl;
	glm::mat4 matPitch = glm::mat4(1.0f);
	glm::mat4 matYaw = glm::mat4(1.0f);

	matPitch = glm::rotate(matPitch, pitch, glm::vec3(1.0f, 0.0f, 0.0f));
	matYaw = glm::rotate(matYaw, yaw, glm::vec3(0.0f, 1.0f, 0.0f));

	glm::mat4 rotate =  matPitch * matYaw;

	glm::mat4 translate = glm::mat4(1.0f);
	translate = glm::translate(translate, -eyeVector);

	viewMatrix = rotate * translate;

	//glm::mat4 mirror = glm::mat4(1.0f);
	//mirror[2][2] = 1.0;
	//mirror[1][1] = 1.0;
	//mirror[0][0] = 1.0;

	//viewMatrix = rotate * translate * mirror;
}

glm::mat4 CameraFPSEuler::GetViewMatrix() const
{
	return viewMatrix;
}

void CameraFPSEuler::KeyPressed(const unsigned char key)
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

	double tmp = pitch;
	pitch = -3.14159265;
	UpdateView();
	pitch = tmp;

	glm::mat4 mat = GetViewMatrix();
	glm::vec3 forward(mat[0][2], mat[1][2], mat[2][2]);
	glm::vec3 strafe(mat[0][0], mat[1][0], mat[2][0]);

	const float speed = 0.12f;
	
	eyeVector += (dz * forward + dx * strafe) * speed;

	UpdateView();
}

void CameraFPSEuler::MouseMove(int x, int y)
{
	glm::vec2 mouse_delta = glm::vec2(x, y) - mousePosition;

	const float mouseX_Sensitivity = 0.01f;
	const float mouseY_Sensitivity = 0.01f;
	yaw -= mouseX_Sensitivity * mouse_delta.x;
	pitch -= mouseY_Sensitivity * mouse_delta.y;

	mousePosition = glm::vec2(x, y);
	UpdateView();
}

void CameraFPSEuler::MousePressed(int x, int y)
{
	mousePosition.x = x;
	mousePosition.y = y;
}

glm::vec3 BasicEngine::Camera::CameraFPSEuler::GetEyeVector()
{
	return eyeVector;
}

void BasicEngine::Camera::CameraFPSEuler::setEyeVector(glm::vec3 eyeVector)
{
	this->eyeVector = eyeVector;
}
