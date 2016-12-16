#include "EventReceiver.h"
#include "BricksModelsManager.h"
#include "Action\Petla.h"

using namespace BasicEngine;
using namespace RubiksCube;

int main(int argc, char **argv)
{
	Cube *cube = new Cube(4);
	Engine *engine = new Engine();
	engine->Init();

	//local shaders
	engine->GetShader_Manager()->CreateProgram("brickShader",
		"Shaders\\Cube_Vertex_Shader.glsl",
		"Shaders\\Cube_Fragment_Shader.glsl");

	BricksModelsManager *bricksModelsManager = new BricksModelsManager(cube, engine);
	bricksModelsManager->createBricksModels();

	EventReceiver::setCube(cube);
	EventReceiver::setEngine(engine);
	EventReceiver::setModelsManager(bricksModelsManager);
	engine->GetEvents_Manager()->setKeyDownCallback(EventReceiver::KeyCallback);
	engine->GetEvents_Manager()->setMouseMoveCallback(EventReceiver::MouseMoveCallback);
	engine->GetEvents_Manager()->setPassiveMouseMoveCallback(EventReceiver::PassiveMouseMoveCallback);

	//Petla::petlowanie(3, 3, 3, [](int i, int j, int k) {
	//	BrickModel* brickm = new BrickModel();
	//	brickm->SetProgram(engine->GetShader_Manager()->GetShader("brickShader"));
	//	brickm->Create(glm::vec3(i, j, k), cube->get_brick(glm::vec3(i, j, k)));
	//	string nazwa = "cube" + to_string((int)i) + to_string((int)j) + to_string((int)k);
	//	engine->GetModels_Manager()->SetModel(nazwa, brickm);
	//})


	engine->Run();

	delete engine;
	delete cube;
	return 0;
}
