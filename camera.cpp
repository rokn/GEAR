#include "camera.h"

namespace OGI
{
	Camera::Camera(GLfloat aspectRatio, glm::vec3 position, GLfloat moveSpeed, GLfloat fov, glm::vec3 worldUp, GLfloat pitch, GLfloat yaw, GLfloat nearClip, GLfloat farClip)
	{
		_aspectRatio = aspectRatio;
		_position = position;
		_moveSpeed = moveSpeed;
		_fov = fov;
		_pitch = pitch;
		_yaw = yaw;
		_worldUpDirection = worldUp;
		_nearClip = nearClip;
		_farClip = farClip;
		UpdateDirection();
	}

	Camera::~Camera()
	{
		
	}
	
	void Camera::Move(Direction direction, GLfloat deltaTime)
	{
		GLfloat moveDistance = _moveSpeed * deltaTime;
		
		if(direction & FORWARD)
			_position += _forward * moveDistance;
		if(direction & BACKWARD)
			_position -= _forward * moveDistance;
		if(direction & RIGHT)
			_position += _right * moveDistance;
		if(direction & LEFT)
			_position -= _right * moveDistance;
	}
	
	void Camera::LookAt(glm::vec3 target)
	{
//		_forward = glm::normalize(target - _position);
	}
	
	void Camera::Zoom(GLfloat amount)
	{
		if(_fov >= MIN_ZOOM && _fov <= MAX_ZOOM)
			_fov -= amount;
		if(_fov < MIN_ZOOM)
			_fov = MIN_ZOOM;
		if(_fov > MAX_ZOOM)
			_fov = MAX_ZOOM;
	}
	
	void Camera::Turn(GLfloat xAmount, GLfloat yAmount)
	{
		_yaw += xAmount;
		_pitch += yAmount;
		
		if(_pitch > 89)
		{
			_pitch = 89;
		}
		else if(_pitch < -89)
		{
			_pitch = -89;
		}
		
		UpdateDirection();
	}
	
	glm::mat4 Camera::GetViewMatrix() const
	{
		return glm::lookAt(_position, _position + _forward, _up);
	}
	
	glm::mat4 Camera::GetProjectionMatrix() const
	{
		return glm::perspective(glm::radians(_fov), _aspectRatio, _nearClip, _farClip);	
	}
	
	void Camera::SetMoveSpeed(GLfloat newMoveSpeed)
	{
		_moveSpeed = newMoveSpeed;
	}
	
	glm::vec3 Camera::GetPosition() const
	{
		return _position;
	}
	
	glm::vec3 Camera::GetFrontVec() const
	{
		return _forward;
	}
	
	void Camera::UpdateDirection()
	{
		glm::vec3 newDirection;
		newDirection.x = cos(glm::radians(_pitch)) * cos(glm::radians(_yaw));
		newDirection.y = sin(glm::radians(_pitch));
		newDirection.z = cos(glm::radians(_pitch)) * sin(glm::radians(_yaw));
		_forward = glm::normalize(newDirection);
		_right = glm::normalize(glm::cross(_forward, _worldUpDirection));
		_up = glm::normalize(glm::cross(_right, _forward));
		
	}
	
	void Camera::FreeFlyControl(const sf::Window& window, sf::Time elapsedTime)
	{
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			Move(OGI::LEFT, elapsedTime.asSeconds());
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			Move(OGI::RIGHT, elapsedTime.asSeconds());
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			Move(OGI::BACKWARD, elapsedTime.asSeconds());
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			Move(OGI::FORWARD, elapsedTime.asSeconds());
		}
		
		sf::Vector2u screenSize = window.getSize();
		sf::Vector2i windowCenterPos(screenSize.x/2,screenSize.y/2);
		
		sf::Vector2i mouseOffset = sf::Mouse::getPosition(window) - windowCenterPos;
		
		Turn(mouseOffset.x * SENSITIVITY, -mouseOffset.y * SENSITIVITY);
	}
}