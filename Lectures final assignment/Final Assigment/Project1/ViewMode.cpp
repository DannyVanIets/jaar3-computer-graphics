#include "ViewMode.h"

ViewMode::ViewMode(glm::vec3 position, float yaw, float pitch)
{
	cameraPos = position;
	this->yaw = yaw;
	this->pitch = pitch;
}