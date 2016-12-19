//Shader_Manager.h
//modify from http://in2gpu.com/2014/10/29/shaders-basics/
#pragma once
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
//#include "../Dependencies/include/glew/glew.h"
//#include "../Dependencies/include/freeglut/freeglut.h"
#include <glew/glew.h>
#include <freeglut/freeglut.h>
namespace BasicEngine
{
	namespace Managers
	{

		class Shader_Manager
		{

		public:

			Shader_Manager(void);
			~Shader_Manager(void);

			//modify char* to std::string
			void CreateProgram(const std::string& shaderName,
				const std::string& VertexShaderFilename,
				const std::string& FragmentShaderFilename);

			static const GLuint GetShader(const std::string&);

		private:
			//modify char* to std::string
			std::string ReadShader(const std::string& filename);
			//modify char* to std::string
			GLuint CreateShader(GLenum shaderType,
				const std::string& source,
				const std::string& shaderName);

			static std::map<std::string, GLuint> programs;
		};
	}
}