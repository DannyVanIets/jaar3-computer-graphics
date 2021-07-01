#pragma once
#include <glm/gtc/type_ptr.hpp>

class Camera
{
public:
	/*glm::vec3(2.0, 1.0, 7.0), cameraPos
		glm::vec3(-2.0, 1.0, -7.0), cameraPos + cameraFront
		glm::vec3(0.0, 1.0, 0.0) cameraUp
	*/

	// Camera Direction
	glm::vec3 cameraPos = glm::vec3(2.0, 1.0, 7.0);
	glm::vec3 cameraFront = glm::vec3(-4.0, 0.0, -14.0);
	glm::vec3 cameraUp = glm::vec3(0.0, 1.0, 0.0);

	float yaw = -90.0;
	float pitch = 0;

	bool firstMouse = true;

	glm::mat4 view, projection;

	Camera() = default;

	void CalculateView();
	void CalculateProjection();
	void MouseMovement(int xpos, int ypos);
};