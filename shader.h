#ifndef Shader_H
#define Shader_H

#include <string>
#include <fstream>
#include <iostream>
#include <GL/glew.h>

namespace OGI
{
	class Shader
	{
		private:
			GLuint _program;

			std::string ReadShaderSource(std::string filename);
			GLuint LoadShader(std::string filename, GLenum shaderType);
			bool ShaderIsCompiled(GLuint shader);
			void PrintShaderInfoLog(GLuint shader);
			void CheckForLinkErrors();
			
		public:
			Shader(std::string vertexPath, std::string fragmentPath);
			~Shader();
			GLuint GetProgram();
			void Use();
	};
}

#endif //Shader_H
