#ifndef Cube_H
#define Cube_H

#include "shader.h"

namespace OGI
{
	class Cube
	{
	private:
		GLuint _vao;
		GLuint _vbo;
		void Setup();
	public:
		Cube();
		~Cube();
		void Draw(const Shader& shader);
	};
}

#endif //Cube_H
