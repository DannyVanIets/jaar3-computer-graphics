#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>
#include <GL/freeglut_std.h>

void Camera::CalculateView()
{
	view = glm::lookAt(
		glm::vec3(cameraPos),
		glm::vec3(cameraPos + cameraFront),
		glm::vec3(cameraUp)
	);
}

void Camera::CalculateProjection()
{
	// In the comments are the original values, in-case you want to revert it.
	projection = glm::perspective(
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
	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos; // Y starts from bottom to top, so it's reversed.
	lastX = xpos;
	lastY = ypos;

	// Reduce how strong the mouse movement is.
	const float sensitivity = 0.1f;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	yaw += xoffset;
	pitch += yoffset;

	// Make sure that the camera can't go over 89 degrees while looking up or below -89 degrees while looking down.
	// If it goes over 89, it will could cause a flip at the LookAt function.
	if (pitch > 89.0f) {
		pitch = 89.0f;
	}
	if (pitch < -89.0f) {
		pitch = -89.0f;
	}

	glm::vec3 direction;
	direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	direction.y = sin(glm::radians(pitch));
	direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	cameraFront = glm::normalize(direction); // CameraFront is used in the LookAt function.

	glutWarpPointer(400, 300); // Centers the mouse after moving it into a certain direction.
}