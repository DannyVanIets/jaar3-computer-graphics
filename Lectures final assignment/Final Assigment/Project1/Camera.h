#pragma once
#include <glm/gtc/type_ptr.hpp>
#include "ViewMode.h"

class Camera
{
public:
	bool walkModeEnabled = true;

	ViewMode walkMode;
	ViewMode droneMode = ViewMode(glm::vec3(2.0, 10.0, 7.0), -90, -45);
	ViewMode currentvm = walkMode;

	Camera() = default;

	void CalculateView();
	void CalculateProjection();
	void LookAround(int xpos, int ypos);
};