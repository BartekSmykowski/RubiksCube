#include <BasicEngine\Engine.h>
#include "RCube.h"

using namespace BasicEngine;
int main(int argc, char **argv)
{
	Engine* engine = new Engine();
	engine->Init();

	//local shaders
	engine->GetShader_Manager()->CreateProgram("rcubeShader",
		"Shaders\\Cube_Vertex_Shader.glsl",
		"Shaders\\Cube_Fragment_Shader.glsl");

	RCube* rcube = new RCube();
	rcube->SetProgram(engine->GetShader_Manager()->GetShader("rcubeShader"));
	rcube->Create();

	engine->GetModels_Manager()->SetModel("rcube", rcube);

	engine->Run();

	delete engine;
	return 0;
}