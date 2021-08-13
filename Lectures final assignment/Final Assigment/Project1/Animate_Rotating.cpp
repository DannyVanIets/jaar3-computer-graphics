#include "Animate_Rotating.h"

Animate_Rotating::Animate_Rotating(float radians, float rotateX, float rotateY, float rotateZ)
{
	Radians = radians;
	RotateX = rotateX;
	RotateY = rotateY;
	RotateZ = rotateZ;
}

glm::mat4 Animate_Rotating::DoAnimation(glm::mat4 model)
{
	return DoRotation(model, Radians, RotateX, RotateY, RotateZ);
}
