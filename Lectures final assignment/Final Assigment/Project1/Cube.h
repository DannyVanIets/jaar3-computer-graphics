#pragma once
#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>

#include "Shape.h"

class Cube : public Shape
{
public:
    std::vector<GLfloat> Cube_Vertices = {
        // front
        -1.0, -1.0,  1.0, // 0
         1.0, -1.0,  1.0, // 1
         1.0,  1.0,  1.0, // 2

        /* 1.0,  1.0,  1.0, // top right, 2
        -1.0,  1.0,  1.0, // top left, 3
        -1.0, -1.0,  1.0, // bottom left, 0*/

         1.0,  1.0,  1.0, // 2
        -1.0,  1.0,  1.0, // 3
        -1.0, -1.0,  1.0, // 0
        // top
        -1.0,  1.0,  1.0,
         1.0,  1.0,  1.0,
         1.0,  1.0, -1.0,

         1.0,  1.0, -1.0,
        -1.0,  1.0, -1.0,
        -1.0,  1.0,  1.0,
        // back
         1.0, -1.0, -1.0,
        -1.0, -1.0, -1.0,
        -1.0,  1.0, -1.0,

        -1.0,  1.0, -1.0,
         1.0,  1.0, -1.0,
         1.0, -1.0, -1.0,
        // bottom
        -1.0, -1.0, -1.0,
         1.0, -1.0, -1.0,
         1.0, -1.0,  1.0,

         1.0, -1.0,  1.0,
        -1.0, -1.0,  1.0,
        -1.0, -1.0, -1.0,
        // left
        -1.0, -1.0, -1.0,
        -1.0, -1.0,  1.0,
        -1.0,  1.0,  1.0,

        -1.0,  1.0,  1.0,
        -1.0,  1.0, -1.0,
        -1.0, -1.0, -1.0,
        // right
         1.0, -1.0,  1.0,
         1.0, -1.0, -1.0,
         1.0,  1.0, -1.0,

         1.0,  1.0, -1.0,
         1.0,  1.0,  1.0,
         1.0, -1.0,  1.0,
    };

    // Constructors
    Cube() = default;
    Cube(float x, float y, float z, string texture_name);
    Cube(float x, float y, float z, float width, float height, float length, string texture_name);
};