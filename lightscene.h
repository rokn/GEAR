#ifndef LightScene_H
#define LightScene_H

#include "engine.h"
#include "mesh.h"
#include "shader.h"
#include "glrenderer.h"

namespace OGI
{
	class LightScene : public Engine
	{
	private:
		bool wireframeMode;
		OGI::Mesh *mesh;
		OGI::Shader *shader;
		OGI::Camera *_mainCamera;
		OGI::GLRenderer *_renderer;
		
	public:
		LightScene();
		~LightScene();
	protected:
		void Initialize();
		void HandleEvent(sf::Event windowEvent);
		void Update(const sf::Time elapsedTime);
		void Draw(const sf::Time elapsedTime);
	private:
		void SwitchWireframeMode();
		void ResetMousePos();
	};
}

#endif //LightScene_H
