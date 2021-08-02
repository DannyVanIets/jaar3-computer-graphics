#pragma once
#include "Camera.h"

class Movement
{
public:
	const float walkSpeedZ = 0.1f; // Controls how fast you can move forward/backward.
	const float walkSpeedX = 0.1f; // Controls how fast you can move left/right.

	Movement() = default;

	Camera KeyboardKeys(Camera camera, unsigned char key);
	Camera KeyboardKeysSpecial(Camera camera, int key);
};