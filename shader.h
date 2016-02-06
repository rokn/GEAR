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
			GLuint GetProgram() const;
			GLuint GetUniLoc(const char* name) const;
			void Use();
	};
}

#endif //Shader_H
