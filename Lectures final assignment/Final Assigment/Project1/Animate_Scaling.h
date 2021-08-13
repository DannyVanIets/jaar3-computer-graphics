#pragma once
#include "Animation.h"

class Animate_Scaling : public Animation
{
public:
	float ScaleX = 1.0;
	float ScaleY = 1.0;
	float ScaleZ = 1.0;

	Animate_Scaling() = default;
	Animate_Scaling(float scaleX, float scaleY, float scaleZ);

	glm::mat4 DoAnimation(glm::mat4 model) override;
};