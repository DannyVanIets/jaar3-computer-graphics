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
	projection = glm::perspective(
		glm::radians(45.0f),
		800.0f / 600.0f,
		0.1f,
		10.0f);
}

void Camera::MouseMovement(int xpos, int ypos) 
{
	float lastX = 400, lastY = 300;

	/*if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}*/

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos;
	lastX = xpos;
	lastY = ypos;

	const float sensitivity = 0.1f;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	yaw += xoffset;
	pitch += yoffset;

	// Make sure that the camera can't go over 90 degrees while looking up or below -90 degrees while looking down.
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
	cameraFront = glm::normalize(direction);

	glutWarpPointer(400, 300); // Centers the mouse after moving it into a certain direction.
}