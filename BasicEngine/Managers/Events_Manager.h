#pragma once
#include "../Core/Init/IEventsListener.h"
#include "../Core/Init/Init_GLUT.h"

namespace BasicEngine
{
	namespace Managers
	{
		class Events_Manager : public Core::IEventsListener

		{
		public:
			Events_Manager();
			~Events_Manager();

			virtual void setKeyDownCallback(void (*KeyDownCallback)(unsigned char, int, int));
			virtual void setMouseMoveCallback(void(*MouseMoveCallback)(int, int));
			virtual void setPassiveMouseMoveCallback(void(*PassiveMouseMoveCallback)(int, int));


		private:

		};

	}
}