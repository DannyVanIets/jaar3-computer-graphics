#pragma once
#include <glm/gtc/type_ptr.hpp>

class Camera
{
public:
	// The key states. These variables will be zero when no key is being pressed.
	float deltaAngle = 0.0f;
	float deltaMove = 0;

	float angle = 0.0; // Angle of rotation for the camera direction.
	float lx = -4.0, lz = -14.0; // Actual vector representing the camera's direction.
	float x = 2.0, z = 7.0; // XZ position of the camera.

	glm::mat4 view, projection;

	Camera() = default;

	void CalculateView();
	void CalculateProjection();
	void ComputePos();
	void ComputeDir();
};