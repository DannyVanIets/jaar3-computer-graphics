#include "Animation.h"
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

glm::mat4 Animation::DoScaling(glm::mat4 model, float x, float y, float z)
{
    return glm::scale(
        model,
        glm::vec3(x, y, z));
}

glm::mat4 Animation::DoRotation(glm::mat4 model, float radians, float x, float y, float z)
{
    return glm::rotate(
        model,
        radians,
        glm::vec3(x, y, z));
}

glm::mat4 Animation::DoTranslation(glm::mat4 model, float x, float y, float z)
{
    return glm::translate(
        model,
        glm::vec3(x, y, z));;
}