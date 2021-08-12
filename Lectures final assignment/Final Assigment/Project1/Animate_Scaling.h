#pragma once
#include "Animation.h"

class Animate_Scaling : public Animation
{
public:
	bool ScaleXUp = false;
	bool ScaleYUp = false;
	bool ScaleZUp = false;

	float x = 0.999, y = 0.999, z = 0.999;

	Animate_Scaling() = default;
	Animate_Scaling(bool scaleXUp, bool scaleYUp, bool scaleZUp);

	glm::mat4 DoAnimation(glm::mat4 model) override;
};