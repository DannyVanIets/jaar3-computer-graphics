#pragma once
#include "Animation.h"

class Animate_Rotating : public Animation
{
public:
	float Radians = 0.0;
	float RotateX = 1.0;
	float RotateY = 1.0;
	float RotateZ = 1.0;

	Animate_Rotating() = default;
	Animate_Rotating(float radians, float rotateX, float rotateY, float rotateZ);

	glm::mat4 DoAnimation(glm::mat4 model) override;
};