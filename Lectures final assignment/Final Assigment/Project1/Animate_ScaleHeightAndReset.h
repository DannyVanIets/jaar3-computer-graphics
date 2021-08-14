#pragma once
#include "Animation.h"

class Animate_ScaleHeightAndReset : public Animation
{
public:
	float HowMuchSmaller = 5.0;
	float OriginalHeightValue = 1.0;
	float ScaleHowMuch = 1.0;
	bool FirstTime = true;

	Animate_ScaleHeightAndReset() = default;
	Animate_ScaleHeightAndReset(float howMuchSmaller, float scaleHowMuch);

	glm::mat4 DoAnimation(glm::mat4 model) override;
};