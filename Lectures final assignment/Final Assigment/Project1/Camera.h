#pragma once
#include <glm/gtc/type_ptr.hpp>
#include "ViewMode.h"

/// <summary>
/// This class is used to check the current viewmode, to calculate the view/projection and to look around.
/// </summary>
class Camera
{
public:
	// Used to switch between view does.
	bool walkModeEnabled = true;

	ViewMode walkMode;
	ViewMode droneMode = ViewMode(glm::vec3(2.0, 50.0, 7.0), -90, -45);
	ViewMode currentvm = walkMode;

	Camera() = default;

	/// <summary>
	/// Calculates the view based on the paramters cameraPos, which stands for the camera position,
	/// camera front and camera up.
	/// </summary>
	void CalculateView();


	/// <summary>
	/// Calculates the projection part of the camera, like how far you can look.
	/// </summary>
	void CalculateProjection();

	/// <summary>
	/// Function used to rotate the camera with the mouse.
	/// Created with this tutorial: https://learnopengl.com/Getting-started/Camera.
	/// </summary>
	/// <param name="xpos">The current x position of the mouse.</param>
	/// <param name="ypos">The current y position of the mouse.</param>
	void LookAround(int xpos, int ypos);
};