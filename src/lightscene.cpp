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


#include "lightscene.h"
#include "resourcemanager.h"

#include "string"

#include <SFML/Graphics.hpp>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#define RESOLUTION_WIDTH 800
#define RESOLUTION_HEIGHT 600
#define FULLSCREEN false

namespace AGE
{
	LightScene::LightScene()
	{
//		aiScene *scene;
//		aiNode *node = scene->mRootNode;
		wireframeMode = false;
		GetWindow().setSize(sf::Vector2u(RESOLUTION_WIDTH,RESOLUTION_HEIGHT));
		Initialize();
	}

	LightScene::~LightScene()
	{
		delete _mesh;
		delete _objectShader;
		delete _renderer;
	}

	void LightScene::Initialize()
	{
		_renderer = new AGE::GLRenderer(GetWindow());
		_mainCamera = new AGE::Camera((GLfloat)RESOLUTION_WIDTH / RESOLUTION_HEIGHT, glm::vec3(0.0f,0.0f,3.0f));
		
		_objectShader = new AGE::Shader("Content\\Shaders\\LightVertexShader.vs","Content\\Shaders\\LightFragmentShader.fs");
		_lampShader = new AGE::Shader("Content\\Shaders\\LightVertexShader.vs","Content\\Shaders\\LampFragmentShader.fs");
		_mesh = new AGE::Cube();
		_lamp = AGE::Mesh::MakeCube(0.2f, 0.2f, 0.2f);
		
		_objectShaderModelUniLoc = _objectShader->GetUniLoc("model");
		_objectShaderViewUniLoc = _objectShader->GetUniLoc("view");
		_objectShaderProjUniLoc = _objectShader->GetUniLoc("projection");
		_lampShaderModelUniLoc = _objectShader->GetUniLoc("model");
		_lampShaderViewUniLoc = _objectShader->GetUniLoc("view");
		_lampShaderProjUniLoc = _objectShader->GetUniLoc("projection");
		
		
		
		_objectModelMat = glm::translate(_objectModelMat, glm::vec3(0.0f, 0.0f, 0.0f));
		_objectModelMat = glm::scale(_objectModelMat, glm::vec3(0.5f,0.5f,0.5f));
		
		_objectShader->Use();
		glUniform3f(_objectShader->GetUniLoc("lightColor"), 1.0f, 1.0f, 1.0f);
		glUniform3f(_objectShader->GetUniLoc("material.ambient"), 1.0f, 0.5f, 0.31f);
		glUniform3f(_objectShader->GetUniLoc("material.diffuse"), 1.0f, 0.5f, 0.31f);
		glUniform3f(_objectShader->GetUniLoc("material.specular"), 0.5f, 0.5f, 0.5f);
		glUniform1f(_objectShader->GetUniLoc("material.shininess"), 32.0f);
		
		
		GLuint diffuseTexture = ResourceManager::LoadTexture("Content\\Images\\containerDiffuse.png");
		GLuint specularTexture = ResourceManager::LoadTexture("Content\\Images\\containerSpecular.png");
		GLuint emmisionTexture = ResourceManager::LoadTexture("Content\\Images\\matrix.jpg");
		
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, diffuseTexture);
		
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, specularTexture);
		
		glActiveTexture(GL_TEXTURE2);
		glBindTexture(GL_TEXTURE_2D, emmisionTexture);
		
		glUniform1i(_objectShader->GetUniLoc("material.diffuse"), 0);
		glUniform1i(_objectShader->GetUniLoc("material.specular"), 1);
		glUniform1i(_objectShader->GetUniLoc("material.emmision"), 2);
		
		
		
		
		glUniform3f(_objectShader->GetUniLoc("light.specular"), 1.0f, 1.0f, 1.0f);
		
		this->GetWindow().setMouseCursorVisible(false);
		ResetMousePos();
	}

	void LightScene::HandleEvent(sf::Event windowEvent)
	{
		Engine::HandleEvent(windowEvent);
		
		switch(windowEvent.type)
		{
			case sf::Event::MouseWheelScrolled:
				_mainCamera->Zoom(windowEvent.mouseWheelScroll.delta);
			break;
			
			case sf::Event::KeyPressed:
				if(windowEvent.key.code == sf::Keyboard::F2)
					SwitchWireframeMode();
			break;
			
			default:
				//Warning Disabler
				break;
		}
	}

	void LightScene::Update(const sf::Time elapsedTime)
	{
		if(GetWindow().hasFocus())
		{
			_mainCamera->FreeFlyControl(GetWindow(),elapsedTime);
			ResetMousePos();
		}
	}

	void LightScene::Draw(const sf::Time elapsedTime)
	{

		glm::vec3 cubePositions[] = {
			glm::vec3( 0.0f,  0.0f,  0.0f),
			glm::vec3( 2.0f,  5.0f, -15.0f),
			glm::vec3(-1.5f, -2.2f, -2.5f),
			glm::vec3(-3.8f, -2.0f, -12.3f),
			glm::vec3( 2.4f, -0.4f, -3.5f),
			glm::vec3(-1.7f,  3.0f, -7.5f),
			glm::vec3( 1.3f, -2.0f, -2.5f),
			glm::vec3( 1.5f,  2.0f, -2.5f),
			glm::vec3( 1.5f,  0.2f, -1.5f),
			glm::vec3(-1.3f,  1.0f, -1.5f)
		};
		
		_renderer->BeginDraw(glm::vec3(0.0f,0.0f,0.0f));
		
		//-----------Cube-----------
		
		_objectShader->Use();
		
		glUniformMatrix4fv(_objectShaderViewUniLoc, 1, GL_FALSE, glm::value_ptr(_mainCamera->GetViewMatrix()));
		glUniformMatrix4fv(_objectShaderProjUniLoc, 1, GL_FALSE, glm::value_ptr(_mainCamera->GetProjectionMatrix()));
		
//		glm::vec3 lightColor;
//		lightColor.r = sin(GetRuntime().asSeconds() * 2.0f);
//		lightColor.g = sin(GetRuntime().asSeconds() * 0.7f);
//		lightColor.b = sin(GetRuntime().asSeconds() * 1.3f);
		
		glm::vec3 ambient = glm::vec3(0.25f);
		glm::vec3 diffuse = glm::vec3(0.5f);

		glUniform3f(_objectShader->GetUniLoc("light.ambient"), ambient.r, ambient.g, ambient.b);
		glUniform3f(_objectShader->GetUniLoc("light.diffuse"), diffuse.r, diffuse.g, diffuse.b);
		
		
		glm::vec3 cameraPos =  _mainCamera->GetPosition();
		glm::vec3 cameraFront =  _mainCamera->GetFrontVec();
		glUniform3f(_objectShader->GetUniLoc("light.position"), cameraPos.x, cameraPos.y, cameraPos.z);
		glUniform3f(_objectShader->GetUniLoc("light.direction"), cameraFront.x, cameraFront.y, cameraFront.z);
		glUniform1f(_objectShader->GetUniLoc("light.innerCutOff"), cos(glm::radians(12.5f)));
		glUniform1f(_objectShader->GetUniLoc("light.outerCutOff"), cos(glm::radians(17.5f)));
		
		
		for(int i = 0; i<10; i++)
		{
			glm::mat4 model = glm::mat4();
			model = glm::translate(model, cubePositions[i]);
			float angle = i * 20.0f;
			model = glm::rotate(model, angle, glm::vec3(1.0f, 0.3f, 0.5f));
			glUniformMatrix4fv(_objectShaderModelUniLoc, 1, GL_FALSE, glm::value_ptr(model));
			_mesh->Draw(*_objectShader);
		}
			
		
		//-----------Lamp-----------
		
//		float radius = 3.0f;
//		_lampPos.x = 1.2f;
//		_lampPos.y = 1.0f;
//		_lampPos.z = 2.0f;
		
//		glUniform3f(_objectShader->GetUniLoc("light.position"), _lampPos.x, _lampPos.y, _lampPos.z);
		glUniform3f(_objectShader->GetUniLoc("viewPos"), cameraPos.x, cameraPos.y, cameraPos.z);
		glUniform1f(_objectShader->GetUniLoc("light.constant"), 1.0f);
		glUniform1f(_objectShader->GetUniLoc("light.linear"), 0.09f);
		glUniform1f(_objectShader->GetUniLoc("light.quadratic"), 0.032f);

		glm::mat4 lampModelMat;
		lampModelMat = glm::translate(lampModelMat,  _lampPos);
		
		//_objectShader must be used in the moment for this ^
		
		_lampShader->Use();
		glUniformMatrix4fv(_lampShaderModelUniLoc, 1, GL_FALSE, glm::value_ptr(lampModelMat));
		glUniformMatrix4fv(_lampShaderViewUniLoc, 1, GL_FALSE, glm::value_ptr(_mainCamera->GetViewMatrix()));
		glUniformMatrix4fv(_lampShaderProjUniLoc, 1, GL_FALSE, glm::value_ptr(_mainCamera->GetProjectionMatrix()));
		
		_lamp->Draw(*_lampShader);
		
		_renderer->EndDraw();
	}
	
	void LightScene::SwitchWireframeMode()
	{
		char *cStr = new char[3];
		itoa(42, cStr, 10);
		std::string str = cStr;
		std::cout << str << std::endl;
		wireframeMode = !wireframeMode;
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glUniform1i(glGetUniformLocation(_objectShader->GetProgram(),"wireframeMode"), (int)wireframeMode);
	}
	
	void LightScene::ResetMousePos()
	{
		sf::Mouse::setPosition(sf::Vector2i(RESOLUTION_WIDTH / 2, RESOLUTION_HEIGHT / 2), GetWindow());
	}
}
