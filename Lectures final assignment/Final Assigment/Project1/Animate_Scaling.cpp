#include "Animate_Scaling.h"

Animate_Scaling::Animate_Scaling(float scaleX, float scaleY, float scaleZ)
{
	ScaleX = scaleX;
	ScaleY = scaleY;
	ScaleZ = scaleZ;
}

glm::mat4 Animate_Scaling::DoAnimation(glm::mat4 model)
{
	return DoScaling(model, ScaleX, ScaleY, ScaleZ);
}