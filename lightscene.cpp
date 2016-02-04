#include "lightscene.h"

#define RESOLUTION_WIDTH 800
#define RESOLUTION_HEIGHT 600
#define FULLSCREEN false

namespace OGI
{
	LightScene::LightScene()
	{
		wireframeMode = false;
		GetWindow().setSize(sf::Vector2u(RESOLUTION_WIDTH,RESOLUTION_HEIGHT));
		Initialize();
	}

	LightScene::~LightScene()
	{
		delete mesh;
		delete shader;
		delete _renderer;
	}

	void LightScene::Initialize()
	{
		_renderer = new OGI::GLRenderer(GetWindow());
		_mainCamera = new OGI::Camera((GLfloat)RESOLUTION_WIDTH / RESOLUTION_HEIGHT, glm::vec3(0.0f,0.0f,3.0f));
		
		shader = new OGI::Shader("MyVertexShader.vs","MyFragmentShader.fs");
		mesh = OGI::Mesh::MakeCube(1,1,1);		
		glUseProgram(shader->GetProgram());
		
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
		glUniformMatrix4fv(glGetUniformLocation(shader->GetProgram(),"view"), 1, GL_FALSE, glm::value_ptr(_mainCamera->GetViewMatrix()));
		glUniformMatrix4fv(glGetUniformLocation(shader->GetProgram(),"projection"), 1, GL_FALSE, glm::value_ptr(_mainCamera->GetProjectionMatrix()));
		
		_renderer->BeginDraw(glm::vec3(0.0f,0.0f,0.0f));
		
		mesh->Draw(*shader);
		
		_renderer->EndDraw();
	}
	
	void LightScene::SwitchWireframeMode()
	{
		wireframeMode = !wireframeMode;
		glUniform1i(glGetUniformLocation(shader->GetProgram(),"wireframeMode"), (int)wireframeMode);
	}
	
	void LightScene::ResetMousePos()
	{
		sf::Mouse::setPosition(sf::Vector2i(RESOLUTION_WIDTH / 2, RESOLUTION_HEIGHT / 2), GetWindow());
	}
}
