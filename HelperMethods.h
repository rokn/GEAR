#ifndef HELPER_METHODS_H
#define HELPER_METHODS_H

#include <string>
#include "GL/glew.h"

namespace HM
{

	std::string GetShaderSource(std::string filename);
	GLuint LoadShader(std::string filename, GLenum shaderType);
	bool ShaderIsCompiled(GLuint shader);
	void PrintShaderInfoLog(GLuint shader);
};

#endif //HELPER_METHODS_H