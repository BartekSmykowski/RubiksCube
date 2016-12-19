#include "Translation.h"
#include <iostream>

RubicsCube::Action::Translation::Translation()
{
	translation = glm::vec3(0, 0, 0);
}

RubicsCube::Action::Translation::~Translation()
{
	std::cout << "Destructor of translation: " << this << std::endl;
}

glm::vec3 RubicsCube::Action::Translation::GetTranslation()
{
	return translation;
}

void RubicsCube::Action::Translation::SetTranslation(glm::vec3 translation)
{
	this->translation = translation;
}
