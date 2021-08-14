#pragma once
#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>
#include "Shape.h"

class TriangularPrism : public Shape
{
public:
    std::vector<GLfloat> TriangularPrism_Vertices = {
        // X, Y, Z.
        // front
        -1.0, -1.0,  1.0, // bottom left
         1.0, -1.0,  1.0, // bottom right
         0.0,  1.0,  1.0, // top middle
        // right
         1.0, -1.0,  1.0,
         0.0,  1.0,  1.0,
         0.0,  1.0, -1.0,

         1.0, -1.0,  1.0,
         0.0,  1.0, -1.0,
         1.0, -1.0, -1.0,
        // back
         1.0, -1.0, -1.0, // bottom right
        -1.0, -1.0, -1.0, // bottom left
         0.0,  1.0, -1.0, // top middle
         // left
        -1.0, -1.0, -1.0,
        -1.0, -1.0,  1.0,
         0.0,  1.0,  1.0,

        -1.0, -1.0, -1.0,
         0.0,  1.0,  1.0,
         0.0,  1.0, -1.0,
        // bottom
        -1.0, -1.0, -1.0,
         1.0, -1.0, -1.0,
         1.0, -1.0,  1.0,

        -1.0, -1.0, -1.0,
         1.0, -1.0,  1.0,
        -1.0, -1.0,  1.0,
    };

    std::vector<GLfloat> TriangularPrism_uvs = {
        // U, V,
        // front
        0.0f, 0.0f, // bottom left
        1.0f, 0.0f, // bottom right
        1.0f, 1.0f, // top right
    };

    // Constructors
    TriangularPrism() = default;
    TriangularPrism(float x, float y, float z);
    TriangularPrism(float x, float y, float z, glm::vec3 rgb);
    TriangularPrism(float x, float y, float z, float width, float height, float length);
    TriangularPrism(float x, float y, float z, float width, float height, float length, glm::vec3 rgb);
};