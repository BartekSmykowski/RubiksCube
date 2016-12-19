#include "TexturesManager.h"
#include "../MazeModel/Enums.h"
#include <string>
#include "soil\SOIL_ext.h"

using namespace MazeModel;

DrawMaze::TexturesManager::TexturesManager()
{
}

DrawMaze::TexturesManager::~TexturesManager()
{
}

void DrawMaze::TexturesManager::LoadTextures()
{
	for (int i = 0; i < 7; i++) {
		//std::string stringFilename = "Textures\\Texture3.bmp";
		std::string stringFilename = "Textures\\Texture" + std::to_string(i) + ".bmp";
		const char* filename = stringFilename.c_str();
		GLuint texture = SOIL_load_OGL_texture(filename, SOIL_LOAD_AUTO,
				SOIL_CREATE_NEW_ID,
				SOIL_FLAG_MIPMAPS);
		textures["Texture" + std::to_string(i)] = texture;
	}
}

GLuint DrawMaze::TexturesManager::GetTexture(std::string textureName)
{
	return textures.at(textureName);
}
