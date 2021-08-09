#pragma once
#include "World.h"
#include "Cube.h"
#include "Object.h"

//World::World()
//{
//	
//}

void World::RenderAll(glm::mat4 projection, glm::mat4 view)
{
	/*for (auto& entity : WorldEntities) {
		entity->Render(projection, view);
	}*/

	for (int i = 0; i < WorldEntities.size(); ++i)
	{
		WorldEntities[i]->Render(projection, view);
	}

	/*for (auto& model : WorldModels) {
		model->RenderAll(projection, view);
	}*/
}

void World::InitBufferAll(glm::mat4 projection, glm::mat4 view)
{
	/*for (auto& entity : WorldEntities) {
		entity->InitBuffers(projection, view);
	}*/

	for (int i = 0; i < WorldEntities.size(); ++i)
	{
		WorldEntities[i]->InitBuffers(projection, view);
	}

	/*for (auto& model : WorldModels) {
		model->InitBufferAll(projection, view);
	}*/
}