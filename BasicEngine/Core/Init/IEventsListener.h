#pragma once
namespace BasicEngine {
	namespace Core
	{

		class IEventsListener
		{
		public:

			virtual ~IEventsListener() = 0;
			
			//drawing functions
			virtual void setKeyDownCallback(void(*KeyDownCallback)(unsigned char, int, int)) = 0;
			virtual void setMouseMoveCallback(void(*MouseMoveCallback)(int, int)) = 0;
		};

		inline IEventsListener::~IEventsListener()
		{
			//implementation of pure virtual destructor
		}
	}
}