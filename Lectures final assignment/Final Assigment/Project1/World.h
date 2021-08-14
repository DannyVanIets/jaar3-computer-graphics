#pragma once
#include "Model.h"

#include "Tree.h"
#include "Chair.h"
#include "House.h"
#include "MarketStall.h"

class World : public Model
{
public:
	// Variabeles

	/// <summary>
	/// List of models we want to show in the world.
	/// </summary>
	std::vector<Model*> Models = {};

	// Constructors
	World() = default;
	World(float x, float y, float z);

	// Methods

	/// <summary>
	/// Add all the models and entities you want in this world, uses AddAllShapes and AddAllModels for it.
	/// </summary>
	void AddModelsAndEntities();
	void AddAllShapes();
	void AddAllModels();

	/// <summary>
	/// Used to render models you want in this world.
	/// </summary>
	/// <param name="projection">The camera projection, used to calculate MVP or MV.</param>
	/// <param name="view">The camera view, used to calculate MVP or MV.</param>
	void RenderModels(glm::mat4 projection, glm::mat4 view);
	void InitBufferModels(glm::mat4 projection, glm::mat4 view);
};