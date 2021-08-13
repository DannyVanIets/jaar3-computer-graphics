#pragma once
#include <glm/gtc/type_ptr.hpp>

class Animation
{
public:
	virtual glm::mat4 DoAnimation(glm::mat4 model) = 0;
protected:
	glm::mat4 DoScaling(glm::mat4 model, float x, float y, float z);
	glm::mat4 DoRotation(glm::mat4 model, float radians, float x, float y, float z);
	glm::mat4 DoTranslation(glm::mat4 model, float x, float y, float z);
};