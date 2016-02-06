#include "shader.h"

namespace OGI
{
	Shader::Shader(std::string vertexPath, std::string fragmentPath)
	{
		GLuint vertexShader = LoadShader(vertexPath, GL_VERTEX_SHADER);
		GLuint fragmentShader = LoadShader(fragmentPath, GL_FRAGMENT_SHADER);
		
		_program = glCreateProgram();
		glAttachShader(_program,vertexShader);
		glAttachShader(_program,fragmentShader);
		
		glLinkProgram(_program);
		
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
		
		CheckForLinkErrors();
	}

	Shader::~Shader()
	{
		glDeleteProgram(_program);
	}

	GLuint Shader::GetProgram() const
	{
		return _program;
	}
	
	GLuint Shader::GetUniLoc(const char * name) const
	{
		return glGetUniformLocation(GetProgram(),name);
	}
	
	void Shader::Use()
	{
		glUseProgram(_program);
	}
	
	GLuint Shader::LoadShader(std::string filename, GLenum shaderType)
	{
		std::string str = ReadShaderSource(filename);
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
	
	std::string Shader::ReadShaderSource(std::string filename)
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

	bool Shader::ShaderIsCompiled(GLuint shader)
	{
		GLint status;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &status);

		return status == GL_TRUE;
	}

	void Shader::PrintShaderInfoLog(GLuint shader)
	{
		const int bufferSize = 1024;
		char buffer[bufferSize];
		glGetShaderInfoLog(shader, bufferSize, NULL, buffer);
		std::cout << buffer << std::endl;
	}
	
	void Shader::CheckForLinkErrors()
	{
		GLint success;
		glGetProgramiv(_program, GL_LINK_STATUS, &success);
		
		if(!success)
		{
			char infoLog[512];
			glGetProgramInfoLog(_program, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		}
	}
}