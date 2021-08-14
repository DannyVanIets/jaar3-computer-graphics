#include "World.h"

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
	aniList.push_back(new Animate_GoUpAndThenDown(10.0));
	Entities.push_back(new Object("ufosimple", 45.0, 10.0, 0.0, "texture/silver2.bmp", aniList));
}

void World::AddAllModels()
{
	Models.push_back(new Chair(5.0f, 0.0f, -2.0f));
	Models.push_back(new MarketStall(5.0f, 0.0f, 0.0f));

	Models.push_back(new Chair(-5.0f, 0.0f, -2.0f));
	Models.push_back(new MarketStall(-5.0f, 0.0f, 0.0f));

	Models.push_back(new Chair(-10.0f, 0.0f, -2.0f));
	Models.push_back(new MarketStall(-10.0f, 0.0f, 0.0f));

	Models.push_back(new Chair(-15.0f, 0.0f, -2.0f));
	Models.push_back(new MarketStall(-15.0f, 0.0f, 0.0f));

	Models.push_back(new Chair(-20.0f, 0.0f, -2.0f));
	Models.push_back(new MarketStall(-20.0f, 0.0f, 0.0f));

	Models.push_back(new House(2, 15.0f, 0.0f, -10.0f));
	Models.push_back(new House(3, 25.0f, 0.0f, -10.0f));
	Models.push_back(new House(5, 35.0f, 0.0f, -10.0f, 3.0, 2.0, 3.0f));
	Models.push_back(new House(1, 45.0f, 0.0f, -10.0f, 3.0, 2.0, 3.0f));
	Models.push_back(new House(7, 55.0f, 0.0f, -10.0f, 3.0, 2.0, 3.0f));

	// Add a lot of trees
	for (int i = 25; i > -25; i -= 10.0) {
		for (int j = 15; j < 90; j += 15.0) {
			if (j % 30 == 0) {
				Models.push_back(new Tree(i, 0.0f, j, false));
			}
			else {
				Models.push_back(new Tree(i, 0.0f, j, true));
			}
		}
	}
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