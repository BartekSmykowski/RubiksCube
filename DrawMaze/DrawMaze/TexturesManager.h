#pragma once
#include <map>
#include <glew/glew.h>

namespace DrawMaze {

	class TexturesManager {
	public:
		TexturesManager();
		~TexturesManager();
		void LoadTextures();
		GLuint GetTexture(std::string textureName);

	private:
		std::map<std::string, GLuint> textures;

	};


}