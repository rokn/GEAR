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

Engine::Engine()
{	
    CreateWindow(DEFAULT_RESOLUTION_WIDTH, DEFAULT_RESOLUTION_HEIGHT, DEFAULT_FULLSCREEN);
	Initialize();
	_mainWindow.setFramerateLimit(60);
	_exitCode = 0;
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
	sf::Clock updateTimeClock;
	sf::Clock drawTimeClock;
	sf::Clock fpsClock;
	int framesPerSec = 0;
	
	
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

const sf::Time Engine::GetRuntime()
{
	return _runtimeClock.getElapsedTime();
}

void Engine::HandleEvent(sf::Event windowEvent)
{
	switch(windowEvent.type)
	{
		case sf::Event::Closed:
			Exit(0);
			break;
		default:
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

void Engine::Initialize()
{
}

void Engine::Update(const sf::Time elapsedTime)
{
	
}

void Engine::Draw(const sf::Time elapsedTime)
{
}

void Engine::Exit(int code)
{
	_exitCode = code;
	_running = false;
}
