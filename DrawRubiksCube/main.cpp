#include "EventReceiver.h"
#include "BricksModelsManager.h"
#include "Action\Petla.h"

using namespace BasicEngine;
using namespace RubiksCube;

int main(int argc, char **argv)
{
	Cube *cube3 = new Cube(3, glm::vec3(0,0,0));
	Cube *cube2 = new Cube(2, glm::vec3(5, 0, 0));
	Cube *cube4 = new Cube(4, glm::vec3(-5, 0, 0));
	Engine *engine = new Engine();
	engine->Init();

	//local shaders
	engine->GetShader_Manager()->CreateProgram("brickShader",
		"Shaders\\Cube_Vertex_Shader.glsl",
		"Shaders\\Cube_Fragment_Shader.glsl");

	BricksModelsManager *bricksModelsManager = new BricksModelsManager(cube3, engine);
	bricksModelsManager->createBricksModels();
	BricksModelsManager *bricksModelsManager2 = new BricksModelsManager(cube2, engine);
	bricksModelsManager2->createBricksModels();
	BricksModelsManager *bricksModelsManager4 = new BricksModelsManager(cube4, engine);
	bricksModelsManager4->createBricksModels();

	EventReceiver::setCube(cube3);
	EventReceiver::setEngine(engine);
	EventReceiver::setModelsManager(bricksModelsManager);
	engine->GetEvents_Manager()->setKeyDownCallback(EventReceiver::KeyCallback);
	engine->GetEvents_Manager()->setMouseMoveCallback(EventReceiver::MouseMoveCallback);
	engine->GetEvents_Manager()->setPassiveMouseMoveCallback(EventReceiver::PassiveMouseMoveCallback);


	engine->Run();

	delete engine;
	delete cube3;
	return 0;
}
