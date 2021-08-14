#pragma once
#include "Camera.h"

/// <summary>
/// Class used when you press a button on the keyboard.
/// </summary>
class Movement
{
public:
	const float walkSpeedZ = 0.1f; // Controls how fast you can move forward/backward.
	const float walkSpeedX = 0.1f; // Controls how fast you can move left/right.

	Movement() = default;

	/// <summary>
	/// Used when you press a keyboard key, like 'a'.
	/// </summary>
	/// <param name="camera">The camera that you use to view the world.</param>
	/// <param name="key">The key that you pressed.</param>
	/// <returns>The updated camera.</returns>
	Camera KeyboardKeys(Camera camera, unsigned char key);

	/// <summary>
	/// Used when you press a special keyboard key, like the arrow key up.
	/// </summary>
	/// <param name="camera">The camera that you use to view the world.</param>
	/// <param name="key">The key that you pressed.</param>
	/// <returns>The updated camera.</returns>
	Camera KeyboardKeysSpecial(Camera camera, int key);

	/// <summary>
	/// Function is called when you walk forwards or backwards, so W or S.
	/// Calculates everything so that the camera moves forward/backwards.
	/// </summary>
	/// <param name="camera">The camera that you use to view the world.</param>
	/// <returns>The updated camera.</returns>
	glm::vec3 CalculateForwardOrBackward(Camera camera);

	/// <summary>
	/// Function is called when you walk left or right, so A or D.
	/// Calculates everything so that the camera moves left or right.
	/// </summary>
	/// <param name="camera">The camera that you use to view the world.</param>
	/// <returns>The updated camera.</returns>
	glm::vec3 CalculateRightOrLeft(Camera camera);
};