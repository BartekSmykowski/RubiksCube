#include "WallModelsManager.h"
#include "WallModel.h"
#include <string>
#include "soil\SOIL_ext.h"
#include "TexturesManager.h"
#include "CeilingModel.h"
#include "FloorModel.h"
#include "PlayerModel.h"

using namespace BasicEngine;
using namespace DrawMaze;
using namespace MazeModel;

WallsModelsManager::WallsModelsManager()
{
}

WallsModelsManager::~WallsModelsManager()
{
}

WallsModelsManager::WallsModelsManager(Maze *maze, Engine *engine) {
	this->engine = engine;
	this->maze = maze;
	createBricksModels();
}

void WallsModelsManager::updateBricksModels() {

	PlayerModel *pm = (PlayerModel*)engine->GetModels_Manager()->GetModel("Player");

}

void WallsModelsManager::createBricksModels()
{
	TexturesManager textMnanager = TexturesManager();
	textMnanager.LoadTextures();
	colorT color = GRAY;
	//walls
	for (int i = 0; i < maze->GetDimensions().x; i++) {
		for (int j = 0; j < maze->GetDimensions().y; j++) {
			if (maze->GetTypeOfWall(glm::vec2(i,j)) != ' ') {
				WallModel* wallm = new WallModel();
				wallm->SetProgram(engine->GetShader_Manager()->GetShader("wallShader"));
				color = PrzypiszKolor(maze->GetTypeOfWall(glm::vec2(i, j)));
				wallm->Create(glm::vec3(i, 0, j), color);
				GLuint texture = textMnanager.GetTexture("Texture" + std::to_string((int)color));
				wallm->SetTexture("Crate", texture);
				std::string nazwa = "wall" + std::to_string(i) + std::to_string(j);
				engine->GetModels_Manager()->SetModel(nazwa, wallm);
			}
		}
	}
	//floor and ceiling
	for (int i = 0; i < maze->GetDimensions().x; i++) {
		for (int j = 0; j < maze->GetDimensions().y; j++) {
			CeilingModel* ceilingModel = new CeilingModel();
			ceilingModel->SetProgram(engine->GetShader_Manager()->GetShader("wallShader"));
			ceilingModel->Create(glm::vec3(i, 0, j), color);
			GLuint texturec = textMnanager.GetTexture("CeilingTexture");
			ceilingModel->SetTexture("CeilingTexture", texturec);
			std::string nazwac = "ceilingModel" + std::to_string(i) + "y" + std::to_string(j);
			engine->GetModels_Manager()->SetModel(nazwac, ceilingModel);
			FloorModel* floorModel = new FloorModel();
			floorModel->SetProgram(engine->GetShader_Manager()->GetShader("wallShader"));
			floorModel->Create(glm::vec3(i, 0, j), color);
			GLuint texturef = textMnanager.GetTexture("FloorTexture");
			floorModel->SetTexture("FloorTexture", texturef);
			std::string nazwaf = "floorModel" + std::to_string(i) + "y" + std::to_string(j);
			engine->GetModels_Manager()->SetModel(nazwaf, floorModel);
		}
	}
	PlayerModel *playerm = new PlayerModel();
	playerm->SetProgram(engine->GetShader_Manager()->GetShader("playerShader"));
	playerm->Create(maze->Getplayer());
	GLuint texturep = textMnanager.GetTexture("PlayerTexture");
	playerm->SetTexture("PlayerTexture", texturep);
	engine->GetModels_Manager()->SetModel("Player", playerm);
}

colorT DrawMaze::WallsModelsManager::PrzypiszKolor(char type)
{
	colorT color = GRAY;

	switch (type) {
	case '@': color = YELLOW; break;
	case '#': color = RED; break;
	case '$': color = GREEN; break;
	case '%': color = BLUE; break;
	case '^': color = ORANGE; break;
	case '&': color = WHITE; break;
	case '*': color = GRAY; break;
	case 'B': color = GRAY; break;
	}

	return color;
}
