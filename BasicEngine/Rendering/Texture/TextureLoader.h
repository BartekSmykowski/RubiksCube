//TextureLoader.h
#pragma once
#include <glew\glew.h>
#include <fstream>
#include <iostream>
#include <string>
#include "BMPHeaders.h"//check git for this class

namespace BasicEngine
{
	namespace Rendering
	{
		class TextureLoader
		{
		public:
			TextureLoader();
			~TextureLoader();

			unsigned int LoadTexture(const std::string& filename,
				unsigned int width,
				unsigned int height);

		private:

			void LoadBMPFile(const std::string& filename,
				unsigned int& width,
				unsigned int& height,
				unsigned char*& data);
		};



	}
}