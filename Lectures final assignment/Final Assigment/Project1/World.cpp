#include "World.h"
#include "Cube.h"
#include "House.h"
#include "Object.h"
#include "Tree.h"
#include "TriangularPrism.h"
#include "Hexagon.h"
#include "Wedge.h"
#include "MarketStall.h"
#include "Icosahedron.h"
#include "Chair.h"
#include "Animate_MoveLeftAndReset.h"
#include "Plane.h"

World::World(float x, float y, float z)
{
	X = x;
	Y = y;
	Z = z;

	AddModelsAndEntities();
}

void World::AddModelsAndEntities()
{
	Entities.clear();
	Models.clear();

	AddAllShapes();
	AddAllModels();
}

void World::AddAllShapes()
{
	Entities.push_back(new Plane(0.0, -1.0, 0.0, 100.0, 0.0, 100.0, "texture/grass.bmp"));
	std::vector<Animation*> aniList = {};
	aniList.push_back(new Animate_MoveLeftAndReset(-90.0));
	Entities.push_back(new Object("ufosimple", 45.0, 10.0, 0.0, "texture/silver2.bmp", aniList));
}

void World::AddAllModels()
{
	Models.push_back(new MarketStall(5.0f, 0.0f, 0.0f));
	Models.push_back(new House(2, 10.0f, 0.0f, 1.0f));
	Models.push_back(new Tree(-4.0f, 0.0f, 1.0f, true));
	Models.push_back(new Tree(-1.0f, 0.0f, 1.0f, false));
	Models.push_back(new Chair(5.0f, 0.0f, -2.0f));
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