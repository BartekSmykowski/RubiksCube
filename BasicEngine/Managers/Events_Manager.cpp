#include "Events_Manager.h"

using namespace BasicEngine;
using namespace Managers;


Events_Manager::Events_Manager()
{
	Core::Init::Init_GLUT::setKeyDownCallback(NULL);
	Core::Init::Init_GLUT::setMouseMoveCallback(NULL);
	Core::Init::Init_GLUT::setPassiveMouseMoveCallback(NULL);

}

Events_Manager::~Events_Manager()
{

}

void Events_Manager::setKeyDownCallback(void(*KeyDownCallback)(unsigned char, int, int)) {
	Core::Init::Init_GLUT::setKeyDownCallback(KeyDownCallback);
}

void Events_Manager::setMouseMoveCallback(void(*MouseMoveCallback)(int, int)) {
	Core::Init::Init_GLUT::setMouseMoveCallback(MouseMoveCallback);
}

void BasicEngine::Managers::Events_Manager::setPassiveMouseMoveCallback(void(*PassiveMouseMoveCallback)(int, int))
{
	Core::Init::Init_GLUT::setPassiveMouseMoveCallback(PassiveMouseMoveCallback);
}
