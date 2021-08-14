#pragma once
#include "Animation.h"

class Animate_GoUpAndReset : public Animation
{
public:
	float HowMuchHigher = 10.0;
	float OriginalYValue = 0.0;

	Animate_GoUpAndReset() = default;
	Animate_GoUpAndReset(float howMuchHigher);

	glm::mat4 DoAnimation(glm::mat4 model) override;
};