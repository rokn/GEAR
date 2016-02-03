#include "glrenderer.h"

namespace OGI
{
	
	GLRenderer::GLRenderer()
	{
	}

	GLRenderer::~GLRenderer()
	{
	}
	
	void GLRenderer::Initialize()
	{
		InitializeGlew();
		
		glEnable(GL_DEPTH_TEST);
	}
	
	void GLRenderer::Clear(glm::vec3 clearColor)
	{
		glClearColor(clearColor.r, clearColor.g, clearColor.b, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
	
	void GLRenderer::InitializeGlew()
	{
		glewExperimental = true;
		glewInit();
	}
}
