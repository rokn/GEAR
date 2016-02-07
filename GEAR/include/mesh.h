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
#ifndef Mesh_H
#define Mesh_H

#include "shader.h"

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>
#include <vector>

namespace GEAR
{
	struct Vertex
	{
		glm::vec3 Position;
		glm::vec3 Normal;
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
		Mesh(std::vector<GEAR::Vertex> vertices, std::vector<GLuint> indices, std::vector<GEAR::Texture> textures);
		~Mesh();
		void Draw(const Shader& shader);
		static Mesh* MakeCube(float w, float h, float z);
		
	private:
		std::vector<GEAR::Vertex> _vertices;
		std::vector <GLuint> _indices;
		std::vector<GEAR::Texture> _textures;
		GLuint _vao;
		GLuint _vbo;
		GLuint _ebo;
		void Setup();
	};
}

#endif //Mesh_H
