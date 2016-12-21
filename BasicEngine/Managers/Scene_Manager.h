#pragma once
#include "Shader_Manager.h"
#include "Models_Manager.h"
#include "../Core/Init/IListener.h"
#include "../Camera/CameraFPSEuler.h"
namespace BasicEngine
{
	namespace Managers
	{
		class Scene_Manager : public Core::IListener

		{
		public:
			Scene_Manager();
			~Scene_Manager();

			virtual void NotifyBeginFrame();
			virtual void NotifyDisplayFrame();
			virtual void NotifyEndFrame();
			virtual void NotifyReshape(int width, int height, int previos_width, int previous_height);
			virtual void notifyKeyDown(unsigned char key, int x, int y);
			virtual void notifyMouseMove(int x, int y);
			virtual void notifyPassiveMouseMove(int x, int y);
			void SetModelsManager(Managers::Models_Manager*& models_manager);
			Camera::CameraFPSEuler *GetCamera();
			void SetCamera(Camera::CameraFPSEuler *camera);

			Managers::Models_Manager* GetModels_Manager();

		private:
			Managers::Models_Manager* models_manager;
			glm::mat4 projection_matrix;
			glm::mat4 view_matrix;
			Camera::CameraFPSEuler *camera;
		};

	}
}