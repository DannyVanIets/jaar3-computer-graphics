#include "Entity.h"
#include <glm/gtc/matrix_transform.hpp>

void Entity::DoScaling(float x, float y, float z)
{
    model = glm::scale(
        model,
        glm::vec3(x, y, z));
}

void Entity::DoRotation(float radians, float x, float y, float z)
{
    model = glm::rotate(
        model,
        glm::radians(radians),
        glm::vec3(x, y, z));
}

void Entity::DoTranslation(float x, float y, float z)
{
    model = glm::translate(
        model,
        glm::vec3(x, y, z));;
}

void Entity::ChangeColor(glm::vec3 rgb)
{
    diffuse_color = rgb;
}

void Entity::CalculateMv(glm::mat4 view)
{
    mv = view * model;
}

void Entity::CalculateMvp(glm::mat4 projection, glm::mat4 view)
{
    mvp = projection * view * model;
}