#include "Brick.h"

using namespace RubiksCube;
using namespace Elements;

Brick::Brick()
{
}

void Brick::StartAnimate(orientation_type orientation, rotate_direction_t direction)
{
	animator.StartAnimation(orientation, direction);
}

void Brick::Animate()
{
	animator.CountAnimationAngle();
}

bool RubiksCube::Elements::Brick::IsRotating()
{
	return animator.IsRotating();
}

void RubiksCube::Elements::Brick::setLengthOfEdge(double length)
{
	this->lengthOfEdge = length;
}

double RubiksCube::Elements::Brick::getLengthOfEdge()
{
	return lengthOfEdge;
}

glm::vec3 RubiksCube::Elements::Brick::getAnimationAngle()
{
	return animator.GetRotationAngle();
}
