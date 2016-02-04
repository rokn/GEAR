#ifndef Mesh_H
#define Mesh_H

#include "shader.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>
#include <vector>

namespace OGI
{
	struct Vertex
	{
		glm::vec3 Position;
		glm::vec2 TexCoords;
	};
	
	struct Texture
	{
		GLuint Id;
		std::string samplerName;
	};
	
	class Mesh
	{
	public:
		Mesh(GLfloat* vertices,int vc, GLuint* indices, int ic);
		Mesh(std::vector<OGI::Vertex> vertices, std::vector<GLuint> indices, std::vector<OGI::Texture> textures);
		~Mesh();
		void Draw(const Shader& shader);
		static Mesh* MakeCube(float w, float h, float z);
		
	private:
		std::vector<OGI::Vertex> _vertices;
		std::vector <GLuint> _indices;
		std::vector<OGI::Texture> _textures;
		GLuint _vao;
		GLuint _vbo;
		GLuint _ebo;
		void Setup();
	};
}

#endif //Mesh_H
