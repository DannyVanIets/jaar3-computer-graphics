#pragma once
#include "Animation.h"

class Animate_GoUpAndThenDown : public Animation
{
public:
	bool FirstTime = true;
	bool GoingUp = true;
	float HowMuchHigher;
	float OriginalYValue;
	float Y = 0.01;

	Animate_GoUpAndThenDown() = default;
	Animate_GoUpAndThenDown(float howMuchHigher);

	glm::mat4 DoAnimation(glm::mat4 model) override;
};