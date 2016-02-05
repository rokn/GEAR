#ifndef ResourceManager_H
#define ResourceManager_H

#include <GL/glew.h>

namespace OGI
{
	class ResourceManager
	{
	private:
	public:
		ResourceManager();
		~ResourceManager();
		static GLuint LoadTexture(const char *texturePath);
	};
}

#endif //ResourceManager_H
