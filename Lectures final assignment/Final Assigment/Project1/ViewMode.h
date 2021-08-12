#pragma once
#include <glm/gtc/type_ptr.hpp>

class ViewMode
{
public:
	// Vec3's used for the view.
	// Will be used in the LookAt function.
	glm::vec3 cameraPos = glm::vec3(2.0, 1.0, 7.0);
	glm::vec3 cameraFront = glm::vec3(-4.0, 0.0, -14.0);
	glm::vec3 cameraUp = glm::vec3(0.0, 1.0, 0.0);

	float yaw = -90.0; // The magnitude we're looking to the left or to the right.
	float pitch = 0; // Is the angle that depicts how much we're looking up or down.

	bool firstMouse = true;

	glm::vec3 Right;
	glm::vec3 WorldUp = cameraUp;

	glm::mat4 view, projection;

	ViewMode() = default;
	ViewMode(glm::vec3 position, float yaw, float pitch);
};