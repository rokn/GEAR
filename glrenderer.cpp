#include "glrenderer.h"

namespace OGI
{
	
	GLRenderer::GLRenderer(sf::Window& gameWindow)
		:_gameWindow(gameWindow)
	{
		Initialize();
	}

	GLRenderer::~GLRenderer()
	{
	}
	
	void GLRenderer::Initialize()
	{
		InitializeGlew();
		glEnable(GL_DEPTH_TEST);
	}
	
	void GLRenderer::BeginDraw(glm::vec3 clearColor)
	{
		glClearColor(clearColor.r, clearColor.g, clearColor.b, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
	
	void GLRenderer::EndDraw()
	{
		_gameWindow.display();
	}
	
	void GLRenderer::InitializeGlew()
	{
		glewExperimental = true;
		glewInit();
	}
}
