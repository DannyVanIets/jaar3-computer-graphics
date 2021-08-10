#include "World.h"
#include "Cube.h"
#include "House.h"
#include "Object.h"
#include "Tree.h"

World::World(float x, float y, float z)
{
	X = x;
	Y = y;
	Z = z;

	AddModelsAndEntities();
}

void World::AddModelsAndEntities()
{
	AddAllShapes();
	AddAllModels();
}

void World::AddAllShapes()
{
	Entities.push_back(new Cube(-3.0, 0.0, 1.0, false));
	Entities.push_back(new Object("teapot", 5.0, 0.0, 10.0));
	Entities.push_back(new Object("sphere", 5.0, 0.0, 10.0));
}

void World::AddAllModels()
{
	Models.push_back(new House(2, 5.0f, 0.0f, 1.0f, true));
	Models.push_back(new Tree(-1.0f, 0.0f, 1.0f, false));
}

void World::RenderModels(glm::mat4 projection, glm::mat4 view)
{
	for (auto& model : Models) {
		model->RenderAll(projection, view);
	}
}

void World::InitBufferModels(glm::mat4 projection, glm::mat4 view)
{
	for (auto& model : Models) {
		model->InitBufferAll(projection, view);
	}
}