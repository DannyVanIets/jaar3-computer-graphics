#include "Model.h"

void Model::RenderAll(glm::mat4 projection, glm::mat4 view)
{
	for (auto& entity : Entities) {
		entity->Render(projection, view);
	}
}

void Model::InitBufferAll(glm::mat4 projection, glm::mat4 view)
{
	for (auto& entity : Entities) {
		entity->InitBuffers(projection, view);
	}

	/* TODO: Remove this later.
	for (int i = 0; i < Entities.size(); i++) {
		Entities[i]->InitBuffers(shader, projection, view);
	}*/
}