#include "EventReceiver.h"
#include "BricksModelsManager.h"
#include "Action\Petla.h"
#include "FloorModel.h"

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

	BricksModelsManager *bricksModelsManager3 = new BricksModelsManager(cube3, engine);
	BricksModelsManager *bricksModelsManager2 = new BricksModelsManager(cube2, engine);
	BricksModelsManager *bricksModelsManager4 = new BricksModelsManager(cube4, engine);

	EventReceiver::setEngine(engine);
	EventReceiver::setCube(cube4);
	EventReceiver::setModelsManager(bricksModelsManager4);
	EventReceiver::setCube(cube2);
	EventReceiver::setModelsManager(bricksModelsManager2);
	EventReceiver::setCube(cube3);
	EventReceiver::setModelsManager(bricksModelsManager3);
	engine->GetEvents_Manager()->setKeyDownCallback(EventReceiver::KeyCallback);
	engine->GetEvents_Manager()->setMouseMoveCallback(EventReceiver::MouseMoveCallback);
	engine->GetEvents_Manager()->setPassiveMouseMoveCallback(EventReceiver::PassiveMouseMoveCallback);

	//local shaders
	engine->GetShader_Manager()->CreateProgram("floorShader",
		"Shaders\\Floor_Vertex_Shader.glsl",
		"Shaders\\Cube_Fragment_Shader.glsl");
	FloorModel* floor = new FloorModel();
	floor->SetProgram(engine->GetShader_Manager()->GetShader("floorShader"));
	floor->Create(-2); 
	engine->GetModels_Manager()->SetModel("floor", floor);
	FloorModel* floor2 = new FloorModel();
	floor2->SetProgram(engine->GetShader_Manager()->GetShader("floorShader"));
	floor2->Create(2);
	engine->GetModels_Manager()->SetModel("floor2", floor2);

	engine->Run();

	delete engine;
	delete cube3;
	return 0;
}
