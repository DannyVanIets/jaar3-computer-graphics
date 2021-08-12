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
}