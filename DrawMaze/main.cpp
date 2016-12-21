#include "EventReceiver.h"
#include "MazeModel\maze.h"
#include "DrawMaze\WallModelsManager.h"
#include "FloorModel.h"
#include "DrawMaze\WallModel.h"
#include "soil\SOIL_ext.h"


using namespace BasicEngine;
using namespace MazeModel;
using namespace DrawMaze;

int main(int argc, char **argv)
{
	Engine *engine = new Engine();
	engine->Init();
	Maze *maze = new Maze();
	engine->GetScene_Manager()->SetCamera((maze->Getplayer()->GetCamera()));

	//local shaders
	engine->GetShader_Manager()->CreateProgram("wallShader",
		"Shaders\\Wall_Textured_Vertex_Shader.glsl",
		"Shaders\\Wall_Textured_Fragment_Shader.glsl");

	WallsModelsManager *wallsModelsManager = new WallsModelsManager(maze, engine);

	EventReceiver::setEngine(engine);
	EventReceiver::setPlayer(maze->Getplayer());
	engine->GetEvents_Manager()->setKeyDownCallback(EventReceiver::KeyCallback);
	engine->GetEvents_Manager()->setMouseMoveCallback(EventReceiver::MouseMoveCallback);
	engine->GetEvents_Manager()->setPassiveMouseMoveCallback(EventReceiver::PassiveMouseMoveCallback);

	//local shaders
	engine->GetShader_Manager()->CreateProgram("floorShader",
		"Shaders\\Floor_Vertex_Shader.glsl",
		"Shaders\\Cube_Fragment_Shader.glsl");
	FloorModel* floor = new FloorModel();
	floor->SetProgram(engine->GetShader_Manager()->GetShader("floorShader"));
	floor->Create(-1);
	engine->GetModels_Manager()->SetModel("floor", floor);
	FloorModel* floor2 = new FloorModel();
	floor2->SetProgram(engine->GetShader_Manager()->GetShader("floorShader"));
	floor2->Create(1);
	engine->GetModels_Manager()->SetModel("floor2", floor2);

	engine->Run();

	delete wallsModelsManager;
	delete engine;
	delete maze;
	return 0;
}
