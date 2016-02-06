#ifndef LightScene_H
#define LightScene_H

#include "engine.h"
#include "mesh.h"
#include "shader.h"
#include "glrenderer.h"
#include "cube.h"

namespace OGI
{
	class LightScene : public Engine
	{
	private:
		bool wireframeMode;
		OGI::Cube *_mesh;
		OGI::Mesh *_lamp;
		OGI::Shader *_objectShader;
		OGI::Shader *_lampShader;
		OGI::Camera *_mainCamera;
		OGI::GLRenderer *_renderer;
		GLuint _objectShaderModelUniLoc;
		GLuint _objectShaderViewUniLoc;
		GLuint _objectShaderProjUniLoc;
		GLuint _lampShaderModelUniLoc;
		GLuint _lampShaderViewUniLoc;
		GLuint _lampShaderProjUniLoc;
		glm::mat4 _objectModelMat;
		glm::vec3 _lampPos;
		
		
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
