#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>
#include <GL/freeglut_std.h>

void Camera::CalculateView()
{
	currentvm.view = glm::lookAt(
		glm::vec3(currentvm.cameraPos),
		glm::vec3(currentvm.cameraPos + currentvm.cameraFront),
		glm::vec3(currentvm.cameraUp)
	);
}

void Camera::CalculateProjection()
{
	// In the comments are the original values, in-case you want to revert it.
	currentvm.projection = glm::perspective(
		glm::radians(45.0f), // 45
		800.0f / 600.0f, // 800 / 600
		0.1f, // 0.1
		100.0f); // 10
}

/// <summary>
/// Function used to rotate the camera with the mouse.
/// Created with this tutorial: https://learnopengl.com/Getting-started/Camera.
/// </summary>
/// <param name="xpos">The current x position of the mouse.</param>
/// <param name="ypos">The current y position of the mouse.</param>
void Camera::LookAround(int xpos, int ypos)
{
	// lastX and lastY are half of the window size,
	// this is the center of the Window.
	float lastX = 400;
	float lastY = 300;

	// This if statement is for when you click into the Window for the first time,
	// it makes sure it doesn't jump too suddenly.
	if (currentvm.firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		currentvm.firstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos; // Y starts from bottom to top, so it's reversed.
	lastX = xpos;
	lastY = ypos;

	// Reduce how strong the mouse movement is.
	const float sensitivity = 0.1f;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	currentvm.yaw += xoffset;
	currentvm.pitch += yoffset;

	// Make sure that the camera can't go over 89 degrees while looking up or below -89 degrees while looking down.
	// If it goes over 89, it will could cause a flip at the LookAt function.
	if (currentvm.pitch > 89.0f) {
		currentvm.pitch = 89.0f;
	}
	if (currentvm.pitch < -89.0f) {
		currentvm.pitch = -89.0f;
	}

	glm::vec3 direction;
	direction.x = cos(glm::radians(currentvm.yaw)) * cos(glm::radians(currentvm.pitch));
	direction.y = sin(glm::radians(currentvm.pitch));
	direction.z = sin(glm::radians(currentvm.yaw)) * cos(glm::radians(currentvm.pitch));
	currentvm.cameraFront = glm::normalize(direction); // CameraFront is used in the LookAt function.

	// Normalize and cross are used, so that you are not slowed down if you look down or up.
	currentvm.Right = glm::normalize(glm::cross(currentvm.cameraFront, currentvm.WorldUp));
	currentvm.cameraUp = glm::normalize(glm::cross(currentvm.Right, currentvm.cameraFront));

	glutWarpPointer(400, 300); // Centers the mouse after moving it into a certain direction.
}