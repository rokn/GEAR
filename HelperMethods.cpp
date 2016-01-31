#include "HelperMethods.h"
#include <fstream>
#include <iostream>

namespace HM
{
	std::string GetShaderSource(std::string filename)
	{
		std::string shaderSource = "";
		std::string line = "";

		std::ifstream shaderFile;
		shaderFile.open(filename.c_str());
		if (shaderFile.is_open())
		{
			while (getline(shaderFile, line))
			{
				shaderSource.append(line + "\n");
			}

			shaderFile.close();
		}
		else std::cout << "Unable to open shader file : " << filename << std::endl;


		return shaderSource;
	}

	GLuint LoadShader(std::string filename, GLenum shaderType)
	{
		std::string str = GetShaderSource(filename);
		const GLchar * shaderSource = (const GLchar *)str.c_str();

		GLuint shader = glCreateShader(shaderType);
		glShaderSource(shader, 1, &shaderSource, NULL);
		glCompileShader(shader);

		if (!ShaderIsCompiled(shader))
		{
			PrintShaderInfoLog(shader);
			return 0;
		}

		return shader;
	}

	bool ShaderIsCompiled(GLuint shader)
	{
		GLint status;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &status);

		return status == GL_TRUE;
	}

	void PrintShaderInfoLog(GLuint shader)
	{
		const int bufferSize = 1024;
		char buffer[bufferSize];
		glGetShaderInfoLog(shader, bufferSize, NULL, buffer);
		std::cout << buffer << std::endl;
	}
}