#pragma once
#include <vector>
#include "Entity.h"

class World
{
public:
	std::vector<Entity*> WorldEntities = {};
	//std::vector<Model*> WorldModels = {};

	// Constructors
	//World();

	// Methods
	void RenderAll(glm::mat4 projection, glm::mat4 view);
	void InitBufferAll(glm::mat4 projection, glm::mat4 view);
};