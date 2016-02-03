#include "Engine.h"
#include "shader.h"
#include "camera.h"

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

GLuint vao;
GLuint program;
GLuint texture1;
GLuint texture2;
sf::Vector2i centerPos;
GLfloat sensitivity = 0.05f;
OGI::Camera camera((GLfloat)DEFAULT_RESOLUTION_WIDTH/DEFAULT_RESOLUTION_HEIGHT);
bool wireframeMode = false;


void SwitchWireframeMode()
{
	wireframeMode = !wireframeMode;
	glUniform1i(glGetUniformLocation(program,"wireframeMode"), (int)wireframeMode);
}

void AddBlendValue(float value)
{
	static float currValue = 0;
	currValue += value;
	
	if(currValue < 0)
		currValue = 0;
	else if (currValue > 1)
		currValue = 1;
		
	glUniform1f(glGetUniformLocation(program, "blendValue"), currValue);
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
	glDeleteVertexArrays(1, &vao);
	glDeleteProgram(program);
	glDeleteTextures(1, &texture1);
	glDeleteTextures(1, &texture2);
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
				camera.Zoom(windowEvent.mouseWheelScroll.delta);
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

void Engine::InitializeGlew()
{
	glewExperimental = true;
	glewInit();
}

void InitOpenGL()
{
	glEnable(GL_DEPTH_TEST);
	
	OGI::Shader shader("MyVertexShader.vs","MyFragmentShader.fs");
	program = shader.GetProgram();
	
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINES);
	
	glGenVertexArrays(1,&vao);
	
	glBindVertexArray(vao);
	
	sf::Image image;
	image.loadFromFile("Images\\image.png");
	
	

	
	glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1); // All upcoming GL_TEXTURE_2D operations now have effect on our texture object
    // Set our texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// Set texture wrapping to GL_REPEAT
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // Set texture filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // Load, create texture and generate mipmaps
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.getSize().x, image.getSize().y, 0, GL_RGBA, GL_UNSIGNED_BYTE, image.getPixelsPtr());
    glGenerateMipmap(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.
	
    // ===================
    // Texture 2
    // ===================
    glGenTextures(1, &texture2);
    glBindTexture(GL_TEXTURE_2D, texture2);
    // Set our texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // Set texture filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // Load, create texture and generate mipmaps
    image.loadFromFile("Images\\Flowey.png");
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.getSize().x, image.getSize().y, 0, GL_RGBA, GL_UNSIGNED_BYTE, image.getPixelsPtr());
    glGenerateMipmap(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);
	
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture1);
	glUniform1i(glGetUniformLocation(program, "hsTexture"), 0);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texture2);
	glUniform1i(glGetUniformLocation(program, "floweyTex"), 1); 
	
//	glBindTexture(GL_TEXTURE_2D, 0);
	
	//Mesh Data
	GLfloat vertices[] = {
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
	};
	
	//EBO
//	GLuint indices[] = {
//		0, 1, 3,
//		1, 2, 3
//	};
	
	//Generate EBO
//	GLuint ebo;
//	glGenBuffers(1, &ebo);
	
	//Set ebo as active
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	
	//Load ebo into memory
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	
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

	//Get the position input from the shader
//	GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
//	GLint colorAttrib = glGetAttribLocation(shaderProgram, "color");
	
	//Specify how the current VBO is read into the input     sizeof vertex   , offset
	
	//Position
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), 0);
	glEnableVertexAttribArray(0);

	//Color
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
//	glEnableVertexAttribArray(1);
	
	//Tex coords
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);
	
	glBindVertexArray(0);
	
	glUseProgram(program);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture1);
	glUniform1i(glGetUniformLocation(program, "hsTexture"), 0);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texture2);
	glUniform1i(glGetUniformLocation(program, "floweyTex"), 1);
	
	AddBlendValue(0.0f);
}

void Engine::Initialize()
{
	InitializeGlew();
	InitOpenGL();
}

void Engine::Update(const sf::Time elapsedTime)
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		AddBlendValue(-0.01);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		AddBlendValue(0.01);
	}

	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		camera.Move(OGI::LEFT, elapsedTime.asSeconds());
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		camera.Move(OGI::RIGHT, elapsedTime.asSeconds());
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		camera.Move(OGI::BACKWARD, elapsedTime.asSeconds());
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		camera.Move(OGI::FORWARD, elapsedTime.asSeconds());
	}
	
	sf::Vector2i mouseOffset = sf::Mouse::getPosition(_mainWindow) - centerPos;
	
	mouseOffset.y *= -1;
	
	camera.Turn(mouseOffset.x * sensitivity, mouseOffset.y * sensitivity);
	
	ResetMousePos();
}

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



void Engine::Draw(const sf::Time elapsedTime)
{
//	glUniform1f(glGetUniformLocation(program,"offset"), sin(_runtimeClock.getElapsedTime().asSeconds())/2.0f);
	
	glm::mat4 view;
	
	view = camera.GetViewMatrix();
	
	glm::mat4 projection;
	projection = camera.GetProjectionMatrix();
	
	glUniformMatrix4fv(glGetUniformLocation(program,"view"), 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(glGetUniformLocation(program,"projection"), 1, GL_FALSE, glm::value_ptr(projection));
	
//	glm::mat4 trans1;
//	trans1 = glm::translate(trans1, glm::vec3(0.5f,-0.5f, 0.0f));
//	trans1 = glm::rotate(trans1, glm::radians(90.0f) * _runtimeClock.getElapsedTime().asSeconds() / 6.0f, glm::vec3(0.0f,0.0f,1.0f));
//	
//	glm::mat4 trans2;
//	float scaleFactor = sin(_runtimeClock.getElapsedTime().asSeconds()) + 1.0f;
//	trans2 = glm::translate(trans2, glm::vec3(-0.5f,0.5f, 0.0f));
//	trans2 = glm::scale(trans2, glm::vec3(scaleFactor,scaleFactor, 1.0f));
	
	
	glClearColor(0.0f,0.0f,0.0f,1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glBindVertexArray(vao);
	
	for(int i = 0; i < 10; i++)
	{
		glm::mat4 model;
		model = glm::translate(model, cubePositions[i]);
		GLfloat angle;
		
		if(i%3 != 0)
			angle = 20 * i;
		else
			angle = _runtimeClock.getElapsedTime().asSeconds() * (i+1) / 5.0f;
			
		model = glm::rotate(model, angle, glm::vec3(1.0f,0.3f,0.5f));
		glUniformMatrix4fv(glGetUniformLocation(program,"model"), 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays((wireframeMode) ? GL_LINES : GL_TRIANGLES, 0, 36);
	}
	
	_mainWindow.display();
}

void Engine::Exit(int code)
{
	_exitCode = code;
	_running = false;
}