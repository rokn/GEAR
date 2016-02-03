#ifndef GLRenderer_H
#define GLRenderer_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
namespace OGI
{
	
	class GLRenderer
	{
	private:
		
		void InitializeGlew();
	public:
		GLRenderer();
		~GLRenderer();
		void Initialize();
		void Clear(glm::vec3 clearColor);
		
	};
}

#endif //GLRenderer_H
