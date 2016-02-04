#include "engine.h"
#include "shader.h"
#include "mesh.h"

#include <math.h>
#include <iostream>
#include <string>
#include <cstdio>

#include <GL/glew.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#define DEFAULT_RESOLUTION_WIDTH 800
#define DEFAULT_RESOLUTION_HEIGHT 600
#define DEFAULT_FULLSCREEN false

sf::Vector2i centerPos;
GLfloat sensitivity = 0.05f;
bool wireframeMode = false;
OGI::Mesh *mesh;
OGI::Shader *shader;

void SwitchWireframeMode()
{
	wireframeMode = !wireframeMode;
	glUniform1i(glGetUniformLocation(shader->GetProgram(),"wireframeMode"), (int)wireframeMode);
}

Engine::Engine()
{	
	_exitCode = 0;
    CreateWindow(DEFAULT_RESOLUTION_WIDTH, DEFAULT_RESOLUTION_HEIGHT, DEFAULT_FULLSCREEN);
	Initialize();
	_mainWindow.setFramerateLimit(60);
	centerPos.x = DEFAULT_RESOLUTION_WIDTH/2;
	centerPos.y = DEFAULT_RESOLUTION_HEIGHT/2;
//	_mainWindow.setFramerateLimit(true);
}

Engine::~Engine()
{
	_mainWindow.close();
	delete mesh;
	delete shader;
}

void Engine::ResetMousePos()
{
	sf::Mouse::setPosition(sf::Vector2i(DEFAULT_RESOLUTION_WIDTH/2,DEFAULT_RESOLUTION_HEIGHT/2), _mainWindow);
}

int Engine::Run()
{
	_running = true;
	_runtimeClock.restart();
	sf::Event currEvent;
	sf::Clock updateTimeClock;
	sf::Clock drawTimeClock;
	sf::Clock fpsClock;
	int framesPerSec = 0;
	_mainWindow.setMouseCursorVisible(false);
	ResetMousePos();
	
	
	while(_running)
	{
		while(_mainWindow.pollEvent(currEvent))
		{
			HandleEvent(currEvent);
		}
		
		Update(updateTimeClock.getElapsedTime());
		updateTimeClock.restart();
		
		Draw(drawTimeClock.getElapsedTime());
		drawTimeClock.restart();
		
		framesPerSec ++;
		if(fpsClock.getElapsedTime().asSeconds() >= 1)
		{
			std::cout << framesPerSec << std::endl;
			framesPerSec = 0;
			fpsClock.restart();
		}
		
	}
	
	return _exitCode;
}

sf::Window& Engine::GetWindow()
{
	return _mainWindow;
}

void Engine::HandleEvent(sf::Event windowEvent)
{
	switch(windowEvent.type)
	{
		case sf::Event::Closed:
			Exit(0);
			break;
		case sf::Event::MouseWheelScrolled:
				_mainCamera->Zoom(windowEvent.mouseWheelScroll.delta);
			break;
		case sf::Event::KeyPressed:
			if(windowEvent.key.code == sf::Keyboard::F2)
				SwitchWireframeMode();
			break;
		default:
			//std::cout << "Event not handled" << windowEvent.type << std::endl;
			break;
	}
	
}

void Engine::CreateWindow(int resolutionWidth, int resolutionHeight, bool fullscreen)
{
	sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 4;
	
	int fullscreenFlag = (fullscreen) ? sf::Style::Fullscreen : sf::Style::None;
	
	_mainWindow.create(sf::VideoMode(resolutionWidth,resolutionHeight),"OpenGL", sf::Style::Close | fullscreenFlag, settings);
}

void InitOpenGL()
{	
	shader = new OGI::Shader("MyVertexShader.vs","MyFragmentShader.fs");
	
	mesh = OGI::Mesh::MakeCube(1,1,1);
	
	glUseProgram(shader->GetProgram());
}

void Engine::Initialize()
{
	_renderer.Initialize();
	_mainCamera = new OGI::Camera((GLfloat)DEFAULT_RESOLUTION_WIDTH/DEFAULT_RESOLUTION_HEIGHT,glm::vec3(0.0f,0.0f,3.0f));
	InitOpenGL();
}

void Engine::Update(const sf::Time elapsedTime)
{
	if(_mainWindow.hasFocus())
	{
		_mainCamera->FreeFlyControl(_mainWindow,centerPos,elapsedTime);
		ResetMousePos();
	}
}

void Engine::Draw(const sf::Time elapsedTime)
{
	glUniformMatrix4fv(glGetUniformLocation(shader->GetProgram(),"view"), 1, GL_FALSE, glm::value_ptr(_mainCamera->GetViewMatrix()));
	glUniformMatrix4fv(glGetUniformLocation(shader->GetProgram(),"projection"), 1, GL_FALSE, glm::value_ptr(_mainCamera->GetProjectionMatrix()));
	
	_renderer.Clear(glm::vec3(0.0f,0.0f,0.0f));
	
	mesh->Draw(*shader);
	
	_mainWindow.display();
}

void Engine::Exit(int code)
{
	_exitCode = code;
	_running = false;
}


//	glGenTextures(1, &texture1);
//    glBindTexture(GL_TEXTURE_2D, texture1); // All upcoming GL_TEXTURE_2D operations now have effect on our texture object
//    // Set our texture parameters
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// Set texture wrapping to GL_REPEAT
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//    // Set texture filtering
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//    // Load, create texture and generate mipmaps
//    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.getSize().x, image.getSize().y, 0, GL_RGBA, GL_UNSIGNED_BYTE, image.getPixelsPtr());
//    glGenerateMipmap(GL_TEXTURE_2D);
//    glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.
//	