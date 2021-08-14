#pragma once
#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>

#include "Shape.h"

class Wedge : public Shape
{
public:
    std::vector<GLfloat> Wedge_Vertices = {
        // X, Y, Z.
        // front
        -1.0, -1.0,  1.0, // bottom left
         1.0, -1.0,  1.0, // bottom right
         1.0,  1.0,  1.0, // top right

        // left
         1.0,  1.0, -1.0,
        -1.0, -1.0,  1.0,
        -1.0, -1.0, -1.0,

        -1.0, -1.0,  1.0,
         1.0,  1.0,  1.0,
         1.0,  1.0, -1.0,

        // back
         1.0, -1.0, -1.0, // bottom right
        -1.0, -1.0, -1.0, // bottom left
         1.0,  1.0, -1.0, // top right

        // right
         1.0,  1.0, -1.0,
         1.0,  1.0,  1.0,
         1.0, -1.0,  1.0,

         1.0,  1.0, -1.0,
         1.0, -1.0,  1.0,
         1.0, -1.0, -1.0,

         // bottom
        -1.0, -1.0, -1.0,
         1.0, -1.0, -1.0,
         1.0, -1.0,  1.0,

        -1.0, -1.0, -1.0,
         1.0, -1.0,  1.0,
        -1.0, -1.0,  1.0,
    };

    std::vector<GLfloat> Wedge_uvs = {
        // U, V,
        // front
        0.0f, 0.0f, // bottom left
        1.0f, 0.0f, // bottom right
        1.0f, 1.0f, // top right
        0.0f, 1.0f, // top left
    };

    // Constructors
    Wedge() = default;
    Wedge(float x, float y, float z);
    Wedge(float x, float y, float z, glm::vec3 rgb);
    Wedge(float x, float y, float z, float width, float height, float length);
    Wedge(float x, float y, float z, float width, float height, float length, glm::vec3 rgb);
    Wedge(float x, float y, float z, float width, float height, float length, float rotateRadians, float rotateX, float rotateY, float rotateZ);
    Wedge(float x, float y, float z, float width, float height, float length, float rotateRadians, float rotateX, float rotateY, float rotateZ, glm::vec3 rgb);
};