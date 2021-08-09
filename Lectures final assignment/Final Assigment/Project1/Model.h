#pragma once
#include <vector>
#include "Entity.h"

class Model
{
public:
	// Properties
	float X = 0.0, Y = 0.0, Z = 0.0;
	float Width = 1.0, Height = 1.0, Length = 1.0;

	std::vector<Entity*> Entities = {};

	// Methods
	void RenderAll(glm::mat4 projection, glm::mat4 view);
	void InitBufferAll(glm::mat4 projection, glm::mat4 view);
};