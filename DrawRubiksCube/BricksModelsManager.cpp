#include "BricksModelsManager.h"
#include "BrickModel.h"
#include <string>

using namespace BasicEngine;
using namespace RubiksCube;

BricksModelsManager::BricksModelsManager()
{
}

BricksModelsManager::~BricksModelsManager()
{
}

BricksModelsManager::BricksModelsManager(Cube *cube, Engine *engine) {
	this->engine = engine;
	this->cube = cube;
}

void BricksModelsManager::updateBricksModels() {
	BrickModel* brickm = new BrickModel();
	for (double i = 0; i < cube->getSize(); i++) {
		for (double j = 0; j < cube->getSize(); j++) {
			for (double k = 0; k < cube->getSize(); k++) {
				if (cube->get_brick(glm::vec3(i, j, k)) != nullptr) {
					string nazwa = "cube" + to_string((int)i) + to_string((int)j) + to_string((int)k);
					brickm = (BrickModel*)engine->GetModels_Manager()->GetModel(nazwa);
					brickm->updateBrick(cube->get_brick(glm::vec3(i, j, k)));
					brickm->updateVertices();
					brickm->setRotation(cube->getRotation());
				}
			}
		}
	}
}

void BricksModelsManager::createBricksModels()
{
	for (double i = 0; i < cube->getSize(); i++) {
		for (double j = 0; j < cube->getSize(); j++) {
			for (double k = 0; k < cube->getSize(); k++) {
				if (cube->get_brick(glm::vec3(i, j, k)) != nullptr) {
					BrickModel* brickm = new BrickModel();
					brickm->SetProgram(engine->GetShader_Manager()->GetShader("brickShader"));
					brickm->Create(glm::vec3(i, j, k), cube->get_brick(glm::vec3(i, j, k)));
					std::string nazwa = "cube" + std::to_string((int)i) + std::to_string((int)j) + std::to_string((int)k);
					engine->GetModels_Manager()->SetModel(nazwa, brickm);
				}
			}
		}
	}
}
