#include "Animator.h"

using namespace RubicsCube::Action;

Animator::Animator()
{
	isRotating = false;
	rotationAngle = glm::vec3(0, 0, 0);
	animationDelta = glm::vec3(0, 0, 0);
}

Animator::~Animator()
{

}

void Animator::StartAnimation(orientation_type side, rotate_direction_t direction)
{
	if (isRotating == false) {
		isRotating = true;
		switch (side) {
		case UP:
			rotationAngle.y = 90;
			break;
		case LEFT:
			rotationAngle.x = -90;
			break;
		case FRONT:
			rotationAngle.z = -90;
			break;
		case DOWN:
			rotationAngle.y = -90;
			break;
		case RIGHT:
			rotationAngle.x = 90;
			break;
		case BACK:
			rotationAngle.z = 90;
			break;
		}
		if (direction == REVERSE_CLOCK) {
			rotationAngle *= -1;
		}
		animationDelta = rotationAngle / (float)180;
		this->side = side;
		this->directon = direction;
	}
}

void RubicsCube::Action::Animator::CountAnimationAngle()
{
	if(rotationAngle.x != 0 || rotationAngle.y != 0 || rotationAngle.z != 0)
		rotationAngle -= animationDelta;
	else if (rotationAngle.x == 0 || rotationAngle.y == 0 || rotationAngle.z == 0)
		isRotating = false;
}


glm::vec3 Animator::GetRotationAngle()
{
	return rotationAngle;
}

void RubicsCube::Action::Animator::setRotationAngle(glm::vec3 rotationAngle)
{
	this->rotationAngle = rotationAngle;
}

bool Animator::IsRotating()
{
	return isRotating;
}
