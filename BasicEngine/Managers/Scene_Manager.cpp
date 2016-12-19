#include "Scene_Manager.h"

using namespace BasicEngine;
using namespace Managers;


Scene_Manager::Scene_Manager()
{
	camera = Camera::CameraFPSEuler();
	glEnable(GL_DEPTH_TEST);
	
	view_matrix = camera.GetViewMatrix();
	//view_matrix = glm::mat4(1.0f, 0.0f, 0.0f, 0.0f,
	//						0.0f, 1.0f, 0.0f, 0.0f,
	//						0.0f, 0.0f, -1.0f, 0.0f,
	//						0.0f, 0.0f, 5.0f, 1.0f);
}

Scene_Manager::~Scene_Manager()
{

}

void Scene_Manager::NotifyBeginFrame()
{
	models_manager->Update();
}

void Scene_Manager::NotifyDisplayFrame()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);

	models_manager->Draw();
	models_manager->Draw(projection_matrix, camera.GetViewMatrix());
}

void Scene_Manager::NotifyEndFrame()
{

}

void Scene_Manager::NotifyReshape(int width, int height,
	int previos_width, int previous_height)
{
	float ar = (float)glutGet(GLUT_WINDOW_WIDTH) / (float)glutGet(GLUT_WINDOW_HEIGHT);
	float angle = 45.0f, near1 = 0.1f, far1 = 2000.0f;

	projection_matrix[0][0] = 1.0f / (ar * tan(angle / 2.0f));
	projection_matrix[1][1] = 1.0f / tan(angle / 2.0f);
	projection_matrix[2][2] = (-near1 - far1) / (near1 - far1);
	projection_matrix[2][3] = 1.0f;
	projection_matrix[3][2] = 2.0f * near1 * far1 / (near1 - far1);
}

void Scene_Manager::notifyKeyDown(unsigned char key, int x, int y) {
	camera.KeyPressed(key);
}

void Scene_Manager::notifyMouseMove(int x, int y) {
	camera.MousePressed(x, y);
}

void BasicEngine::Managers::Scene_Manager::notifyPassiveMouseMove(int x, int y)
{
	camera.MouseMove(x, y);
}

Managers::Models_Manager* Scene_Manager::GetModels_Manager()
{
	return models_manager;
}

void Scene_Manager::SetModelsManager(Managers::Models_Manager*& models_m)
{
	models_manager = models_m;
}

Camera::CameraFPSEuler BasicEngine::Managers::Scene_Manager::GetCamera()
{
	return camera;
}

void BasicEngine::Managers::Scene_Manager::SetCamera(Camera::CameraFPSEuler camera)
{
	this->camera = camera;
}
