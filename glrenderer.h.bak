#ifndef GLRenderer_H
#define GLRenderer_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <SFML/Window.hpp>

namespace OGI
{
	
	class GLRenderer
	{
	private:
		sf::Window& _gameWindow;
		void InitializeGlew();
		void Initialize();
	public:
		GLRenderer(sf::Window& gameWindow);
		~GLRenderer();
		void BeginDraw(glm::vec3 clearColor);
		void EndDraw();
		
	};
}

#endif //GLRenderer_H
