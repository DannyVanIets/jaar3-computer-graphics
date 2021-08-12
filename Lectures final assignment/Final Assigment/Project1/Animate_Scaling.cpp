#include "Animate_Scaling.h"

Animate_Scaling::Animate_Scaling(bool scaleXUp, bool scaleYUp, bool scaleZUp)
{
	ScaleXUp = scaleXUp;
	ScaleYUp = scaleYUp;
	ScaleZUp = scaleZUp;

	if (ScaleXUp) {
		x = 1.001;
	}
	if (ScaleYUp) {
		y = 1.001;
	}
	if (ScaleZUp) {
		z = 1.001;
	}
}

glm::mat4 Animate_Scaling::DoAnimation(glm::mat4 model)
{
	return DoScaling(model, x, y, z);
}