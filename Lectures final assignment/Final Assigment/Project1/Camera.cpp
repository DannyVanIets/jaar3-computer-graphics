#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>

// TODO: Currently uses polar coordinates, should use spherical coordinates!

void Camera::CalculateView()
{
	view = glm::lookAt(
		glm::vec3(x, 1.0, z),
		glm::vec3(x + lx, 1.0, z + lz),
		glm::vec3(0.0, 1.0, 0.0)
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

void Camera::ComputePos() // Moving
{
	x += deltaMove * lx * 0.1f;
	z += deltaMove * lz * 0.1f;
}

void Camera::ComputeDir() // Strafing
{
	angle += deltaAngle;
	lx = sin(angle);
	lz = -cos(angle);
}
