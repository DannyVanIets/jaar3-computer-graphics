#pragma once
class Camera
{
public:
	float angle = 0.0; // Angle of rotation for the camera direction.
	float lx = -4.0, lz = -14.0; // Actual vector representing the camera's direction.
	float x = 2.0, z = 7.0; // XZ position of the camera.

	Camera() = default;
};