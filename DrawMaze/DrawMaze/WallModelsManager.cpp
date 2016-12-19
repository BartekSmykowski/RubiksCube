#include "WallModelsManager.h"
#include "WallModel.h"
#include <string>
#include "soil\SOIL_ext.h"
#include "TexturesManager.h"

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
	WallModel* brickm = new WallModel();
	for (double i = 0; i < maze->GetDimensions().x; i++) {
		for (double j = 0; j < maze->GetDimensions().y; j++) {
			if (maze->GetTypeOfWall(glm::vec2(i, j)) != ' ') {
				std::string nazwa = "wall" + std::to_string((int)i) + std::to_string((int)j);
				brickm = (WallModel*)engine->GetModels_Manager()->GetModel(nazwa);
			}
		}
	}
}

void WallsModelsManager::createBricksModels()
{
	TexturesManager textMnanager = TexturesManager();
	textMnanager.LoadTextures();
	colorT color;
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
