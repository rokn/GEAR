#include "Engine.h"
#include "GL/glew.h"
#include "SFML/Window.hpp"
#include "HelperMethods.h"
#include <math.h>
#include <iostream>
#include <string>
#include <cstdio>

#define DEFAULT_RESOLUTION_WIDTH 800
#define DEFAULT_RESOLUTION_HEIGHT 600
#define DEFAULT_FULLSCREEN false

Engine::Engine()
{
	_exitCode = 0;
    CreateWindow(DEFAULT_RESOLUTION_WIDTH, DEFAULT_RESOLUTION_HEIGHT, DEFAULT_FULLSCREEN);
	Initialize();
}

Engine::~Engine()
{
	_mainWindow.close();
}

int Engine::Run()
{
	_running = true;
	_runtimeClock.restart();
	sf::Event currEvent;
	
	while(_running)
	{
		while(_mainWindow.pollEvent(currEvent))
		{
			HandleEvent(currEvent);
		}
		
		Update(sf::Time());
		Draw(sf::Time());
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

void Engine::InitializeGlew()
{
	glewExperimental = true;
	glewInit();
}

GLint uniColor;

void InitOpenGL()
{
	GLuint vao;
	glGenVertexArrays(1,&vao);
	
	glBindVertexArray(vao);
	
	//Mesh Data
	float vertices[] = {
		0.0f, 0.5f,
		0.5f, -0.5f,
		-0.5f, -0.5f
	};
	
	//Loading mesh into graphics card
	
	//Mesh object reference
	GLuint vbo;
	glGenBuffers(1, &vbo);
	
	//Set object as active
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	
	
	//Load mesh
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	//GL_STATIC_DRAW - buffer won't change 
	//GL_DYNAMIC_DRAW - buffer will change from time to time
	//GL_STREAM_DRAW - use for GUI many changes slower drawing

	//LoadShaders
	GLuint vertexShader = HM::LoadShader("MyVertexShader.vertexshader", GL_VERTEX_SHADER);
	GLuint fragmentShader = HM::LoadShader("MyFragmentShader.fragmentshader", GL_FRAGMENT_SHADER);
	
	//Create shaderProgram 
	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	
	//Attach the fragment shader to the first buffer
	glBindFragDataLocation(shaderProgram, 0, "outColor");
	
	//Link the shaders together into a program
	glLinkProgram(shaderProgram);
	
	//Start using the shader program
	glUseProgram(shaderProgram);

	//Get the position input from the shader
	GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
	
	//Specify how the current VBO is read into the input
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);
	
	//Enable the input ?
	glEnableVertexAttribArray(posAttrib);
	
	uniColor = glGetUniformLocation(shaderProgram, "triangleColor");
}

void Engine::Initialize()
{
	InitializeGlew();
	InitOpenGL();
}
void Engine::Update(sf::Time gameTime)
{
	glUniform3f(uniColor, (sin(_runtimeClock.getElapsedTime().asSeconds() * 4.0f) + 1.0f )/2.0f, 0.0f,0.0f);
}

void Engine::Draw(sf::Time gameTime)
{
	
	
	glClearColor(0.0f,0.0f,0.0f,1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glDrawArrays(GL_TRIANGLES, 0, 3);
	
	_mainWindow.display();
}

void Engine::Exit(int code)
{
	_exitCode = code;
	_running = false;
}