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
		std::string stringFilename = "Textures\\5\\Texture" + std::to_string(i) + ".bmp";
		const char* filename = stringFilename.c_str();
		GLuint texture = SOIL_load_OGL_texture(filename, SOIL_LOAD_AUTO,
				SOIL_CREATE_NEW_ID,
				SOIL_FLAG_MIPMAPS);
		textures["Texture" + std::to_string(i)] = texture;
	}

	std::string stringFloorFilename = "Textures\\5\\Floor.bmp";
	const char* floorFilename = stringFloorFilename.c_str();
	GLuint floorTexture = SOIL_load_OGL_texture(floorFilename, SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS);
	textures["FloorTexture"] = floorTexture;

	std::string stringCeilingFilename = "Textures\\5\\Ceiling.bmp";
	const char* ceilingFilename = stringCeilingFilename.c_str();
	GLuint ceilingTexture = SOIL_load_OGL_texture(ceilingFilename, SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS);
	textures["CeilingTexture"] = ceilingTexture;
}

GLuint DrawMaze::TexturesManager::GetTexture(std::string textureName)
{
	return textures.at(textureName);
}
