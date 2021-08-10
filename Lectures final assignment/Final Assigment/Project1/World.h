#pragma once
#include "Model.h"

class World : public Model
{
public:
	// Variabeles
	int amountOfCubes = 2;
	std::vector<Model*> Models = {};

	// Constructors
	World() = default;
	World(float x, float y, float z);

	// Methods
	void AddModelsAndEntities();
	void AddAllShapes();
	void AddAllModels();

	void RenderModels(glm::mat4 projection, glm::mat4 view);
	void InitBufferModels(glm::mat4 projection, glm::mat4 view);
};