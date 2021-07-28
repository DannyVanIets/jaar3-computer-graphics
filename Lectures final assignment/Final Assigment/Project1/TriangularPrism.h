#pragma once
#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>

#include "Shape.h"

class TriangularPrism : public Shape
{
public:
    float x, y, z, LengthMinusZ, TopMiddle;

    GLfloat example[36] = {
        // Front
        x,         y,          z, // Bottom left
        x + Width, y,          z, // Bottom Right
        TopMiddle, y + Height, z, // Top Right
        // Back
        x,         y,          LengthMinusZ, // Bottom left
        x + Width, y,          LengthMinusZ, // Bottom Right
        TopMiddle, y + Height, LengthMinusZ, // Top Right
    };

    std::vector<GLfloat> TriangularPrism_Vertices = { 
        // X, Y, Z.
        // front
        -1.0, -1.0,  1.0, // bottom left,  0
         1.0, -1.0,  1.0, // bottom right, 1
         0.0,  1.0,  1.0, // top middle,   2
        // back
        -1.0, -1.0, -1.0, // bottom left,  3
         1.0, -1.0, -1.0, // bottom right, 4
         0.0,  1.0, -1.0, // top middle,   5
    };

    std::vector<GLfloat> TriangularPrism_Colors = {
        // front colors
        1.0, 1.0, 0.0,
        0.0, 1.0, 0.0,
        0.0, 0.0, 1.0,
        1.0, 1.0, 1.0,
        // right side colors
        0.0, 1.0, 1.0,
        1.0, 0.0, 1.0,
        1.0, 0.0, 0.0,
        1.0, 1.0, 0.0,
        // left side colors
        1.0, 1.0, 0.0,
        0.0, 1.0, 0.0,
        0.0, 0.0, 1.0,
        1.0, 1.0, 1.0,
        // back colors
        0.0, 1.0, 1.0,
        1.0, 0.0, 1.0,
        1.0, 0.0, 0.0,
        1.0, 1.0, 0.0,
        // top colors
        1.0, 1.0, 0.0,
        0.0, 1.0, 0.0,
        0.0, 0.0, 1.0,
        1.0, 1.0, 1.0,
        // bottom colors
        0.0, 1.0, 1.0,
        1.0, 0.0, 1.0,
        1.0, 0.0, 0.0,
        1.0, 1.0, 0.0
    };

    std::vector<GLushort> TriangularPrism_Elements = {
        0,1,2,        // front
        1,2,5, 1,4,5, // right side
        4,3,5,        // back
        3,0,2, 3,2,5, // left side
        0,1,3, 1,3,4  // bottom
    };

    // Constructors
    TriangularPrism() = default;
    TriangularPrism(float x, float y, float z);
    TriangularPrism(float x, float y, float z, float width, float height, float length);
};

