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
#ifndef Camera_H
#define Camera_H

#include <GL/glew.h>
#include <SFML/Window.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "direction.h"


namespace GEAR
{
	class Camera
	{
	private:
		constexpr static GLfloat DEFAULT_PITCH = 0.0f;
		constexpr static GLfloat DEFAULT_YAW = -90.0f;
		constexpr static GLfloat DEFAULT_MOVE_SPEED = 5.0f;
		constexpr static GLfloat DEFAULT_ZOOM = 45.0f;
		constexpr static GLfloat DEFAULT_NEAR_CLIP = 0.1f;
		constexpr static GLfloat DEFAULT_FAR_CLIP = 100.0f;
		constexpr static GLfloat MIN_ZOOM = 1.0f;
		constexpr static GLfloat MAX_ZOOM = 90.0f;
		constexpr static GLfloat SENSITIVITY = 0.05f;

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
		glm::vec3 GetPosition() const;
		glm::vec3 GetFrontVec() const;
		
	private:
		void UpdateDirection();
	};
}
#endif //Camera_H
