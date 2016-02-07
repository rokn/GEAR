//////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                      //
//                                                                                                      //
//   Copyright (C) 2016 Antonio Mindov, All Rights Reserved.                                            //
//                                                                                                      //
//   NOTICE:  All information contained herein is, and remains the property of Antonio Mindov.          //
//   Grants of right:                                                                                   //
//     1. You are allowed to reproduce the software AS-IS.                                              //
//     2. You are allowed to use the software for personal use.                                         //
//                                                                                                      //
//   Conditions and limitations :                                                                       //
//     1. No Trademark License- This license does not grant you rights to use any                       //
//        contributors' name, logo, or trademarks.                                                      //
//                                                                                                      //
//     2. The copyright holder does not hold any responsibility for damage done by                      //
//        the software or by a modified version of the software. Use at your own risk.                  //
//                                                                                                      //
//     3. You are not allowed to use the software for commercial use.                                   //
//                                                                                                      //
//     4. If you distribute any portion of the software, you must retain all copyright,                 //
//        patent, trademark, and attribution notices that are present in the software.                  //
//                                                                                                      //
//     5. If you distribute any portion of the software in source code form, you may do so              //
//        only under this license by including a complete copy of this license with your                //
//        distribution. If you distribute any portion of the software in compiled or                    //
//        object code form, you may only do so under a license that complies with this license.         //
//                                                                                                      //
//                                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "shader.h"

namespace GEAR
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