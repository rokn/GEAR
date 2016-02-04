#ifndef Camera_H
#define Camera_H

#include <GL/glew.h>
#include <SFML/Window.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "direction.h"


namespace OGI
{
	class Camera
	{
	private:
		const static GLfloat DEFAULT_PITCH = 0.0f;
		const static GLfloat DEFAULT_YAW = -90.0f;
		const static GLfloat DEFAULT_MOVE_SPEED = 5.0f;
		const static GLfloat DEFAULT_ZOOM = 45.0f;
		const static GLfloat DEFAULT_NEAR_CLIP = 0.1f;
		const static GLfloat DEFAULT_FAR_CLIP = 100.0f;
		const static GLfloat MIN_ZOOM = 1.0f;
		const static GLfloat MAX_ZOOM = 90.0f;
		const static GLfloat SENSITIVITY = 0.05f;

		glm::vec3 _position;
		glm::vec3 _forward;
		glm::vec3 _up;
		glm::vec3 _right;
		glm::vec3 _worldUpDirection;
		GLfloat _moveSpeed;
		GLfloat _pitch;
		GLfloat _yaw;
		GLfloat _aspectRatio;
		GLfloat _nearClip;
		GLfloat _farClip;
		GLfloat _fov;
		
	public:
		Camera(GLfloat aspectRatio,
				glm::vec3 position = glm::vec3(0.0f,0.0f,0.0f),
				GLfloat moveSpeed = DEFAULT_MOVE_SPEED,
				GLfloat fov = DEFAULT_ZOOM,
				glm::vec3 worldUp = glm::vec3(0.0f,1.0f,0.0f),
				GLfloat pitch = DEFAULT_PITCH,
				GLfloat yaw = DEFAULT_YAW,
				GLfloat nearClip = DEFAULT_NEAR_CLIP,
				GLfloat farClip = DEFAULT_FAR_CLIP);
				
		~Camera();
		
		void Move(Direction direction, GLfloat deltaTime);
		void LookAt(glm::vec3 target);
		void Zoom(GLfloat amount);
		void Turn(GLfloat x, GLfloat y);
		glm::mat4 GetViewMatrix() const;
		glm::mat4 GetProjectionMatrix() const;
		void SetMoveSpeed(GLfloat newMoveSpeed);
		void FreeFlyControl(const sf::Window& window, sf::Time elapsedTime);
		
	private:
		void UpdateDirection();
	};
}
#endif //Camera_H
