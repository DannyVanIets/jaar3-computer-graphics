#pragma once
#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>

#include "Shape.h"

class TrapezoidPrism : public Shape
{
public:
    std::vector<GLfloat> Trapezoid_Vertices = {
        // front
        -2.0, -1.0,  1.0, // bottom left, 0
         2.0, -1.0,  1.0, // bottom right, 1
         1.0,  1.0,  1.0, // top right, 2
         1.0,  1.0,  1.0, // top left, 3
        // back
        -2.0, -1.0, -1.0, // bottom left, 4
         2.0, -1.0, -1.0, // bottom right, 5
         1.0,  1.0, -1.0, // top right, 6
         1.0,  1.0, -1.0, // top left, 7
    };

    std::vector<GLushort> Trapezoid_Elements = {
        0,1,2, 0,2,3, // front
        1,5,6, 1,6,2, // right side
        4,0,3, 4,3,7, // left side
        5,4,7, 5,7,6, // back
        3,2,6, 3,6,7, // top
        4,5,1, 4,1,0, // bottom
    };

    // Constructors
    TrapezoidPrism() = default;
    TrapezoidPrism(float x, float y, float z);
    TrapezoidPrism(float x, float y, float z, float width, float height, float length);
};