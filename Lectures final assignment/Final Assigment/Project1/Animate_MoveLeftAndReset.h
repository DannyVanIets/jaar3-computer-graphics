#pragma once
#include "Animation.h"

class Animate_MoveLeftAndReset : public Animation
{
public:
	float HowMuchToTheLeft = 10.0;
	float OriginalXValue = 0.0;

	Animate_MoveLeftAndReset() = default;
	Animate_MoveLeftAndReset(float howMuchToTheLeft);

	glm::mat4 DoAnimation(glm::mat4 model) override;
};