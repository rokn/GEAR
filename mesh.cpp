#include "mesh.h"

namespace OGI
{
	Mesh::Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices, std::vector<Texture> textures)
	{
		_vertices = vertices;
		_indices = indices;
		_textures = textures;
		Setup();
	}

	Mesh::~Mesh()
	{
		glDeleteBuffers(1, &_vbo);
		glDeleteBuffers(1, &_ebo);
		glDeleteBuffers(1, &_vao);
	}

	void Mesh::Draw(const Shader& shader)
	{
		for(unsigned int i = 0; i < _textures.size(); ++i)
		{
			GLuint loc = glGetUniformLocation(shader.GetProgram(), _textures[0].samplerName.c_str());
			
			if(loc >= 0)
			{
				glActiveTexture(GL_TEXTURE0 + i);
				glBindTexture(GL_TEXTURE_2D, _textures[0].Id);
				glUniform1i(loc, i);
			}
		}
		
		glActiveTexture(GL_TEXTURE0);
		
		glBindVertexArray(_vao);
		glDrawElements(GL_TRIANGLES, _indices.size(), GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
	}

	void Mesh::Setup()
	{
		//Generate VAO
		glGenVertexArrays(1,&_vao);
		glBindVertexArray(_vao);	
	
		//Generate EBO
		glGenBuffers(1, &_ebo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, _indices.size() * sizeof(GLuint), &_indices[0], GL_STATIC_DRAW);
		
		//Generate VBO
		glGenBuffers(1, &_vbo);
		glBindBuffer(GL_ARRAY_BUFFER, _vbo);
		glBufferData(GL_ARRAY_BUFFER, _vertices.size() * sizeof(Vertex), &_vertices[0], GL_STATIC_DRAW);
		
		//Position
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)offsetof(Vertex, Position));
		glEnableVertexAttribArray(0);
		
		//Tex coords
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)offsetof(Vertex, TexCoords));
		glEnableVertexAttribArray(1);
		
		glBindVertexArray(0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	
	}
	
}