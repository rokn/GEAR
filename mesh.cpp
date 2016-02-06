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
#include "mesh.h"
#include <iostream>

namespace OGI
{
	Mesh::Mesh(GLfloat* vertices,int vc, GLuint* indices, int ic)
	{
		for(unsigned int i = 0;i<vc;i+=3)
		{
			OGI::Vertex v;
			v.Position.x = vertices[i];
			v.Position.y = vertices[i+1];
			v.Position.z = vertices[i+2];
			_vertices.push_back(v);
		}
		
		for(unsigned int i = 0;i<ic;i++)
		{
			_indices.push_back(indices[i]);
		}
		
		Setup();
	}
	
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
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)offsetof(Vertex, Position));
		glEnableVertexAttribArray(0);
		
		//Tex coords
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)offsetof(Vertex, Normal));
		glEnableVertexAttribArray(1);
		
		//Tex coords
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)offsetof(Vertex, TexCoords));
		glEnableVertexAttribArray(2);
		
		glBindVertexArray(0);
	}
	
	Mesh* Mesh::MakeCube(float w, float h, float z)
	{
		w /= 2;
		h /= 2;
		z /= 2;
		GLfloat verts[] = {
			 w,-h,-z,
			 w,-h, z,
			-w,-h, z,
			-w,-h,-z,
			 w, h,-z,
			 w, h, z,
			-w, h, z,
			-w, h,-z,
		};
			
		GLuint inds[] = {
			1,2,3,
			7,6,5,
			4,5,1,
			5,6,2,
			2,6,7,
			0,3,7,
			0,1,3,
			4,7,5,
			0,4,1,
			1,5,2,
			3,2,7,
			4,0,7,
		};
		
		return new OGI::Mesh(verts, 24, inds, 36);
	}
}