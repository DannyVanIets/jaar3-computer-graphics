#pragma once
#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>

#include "Shape.h"

class Hexagon : public Shape
{
public:
    std::vector<GLfloat> Hexagon_Vertices = { // X, Y, Z.
        // bottom
        // front
        -0.5, -1.0,  1.0, // bottom left, 0
         0.5, -1.0,  1.0, // bottom right, 1
        // right side
         1.0, -1.0,  0.0, // bottom middle, 2
        // back
         0.5, -1.0, -1.0, // top right, 3
        -0.5, -1.0, -1.0, // top left, 4
        // left side
        -1.0, -1.0,  0.0, // bottom middle, 5

        // top
        // front
        -0.5,  1.0,  1.0, // bottom left, 6
         0.5,  1.0,  1.0, // bottom right, 7
         // right side
         1.0,  1.0,  0.0, // top middle, 8
        // back
         0.5,  1.0, -1.0, // top right, 9
        -0.5,  1.0, -1.0, // top left, 10
        // left side
        -1.0,  1.0,  0.0, // top middle, 11

        // bottom middle, 12
         0.0, -1.0,  0.0,

        // bottom middle, 13
         0.0,  1.0,  0.0,
    };

    std::vector<GLfloat> Hexagon_Colors = {
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

    std::vector<GLushort> Hexagon_Elements = {
        0,1,7,  0,7,6,   // front
        1,2,8,  1,8,7,   // front right
        5,0,6,  5,6,11,  // front left
        3,4,10, 3,10,9,  // back
        2,3,9,  2,9,8,   // back right
        4,5,11, 4,11,10, // back left
        0,1,12, 1,2,12, 2,3,12, 3,4,12,  4,5,12,   5,0,12, // top
        6,7,13, 7,8,13, 8,9,13, 9,10,13, 10,11,13, 11,6,13 // bottom
    };

    // Constructors
    Hexagon() = default;
    Hexagon(float x, float y, float z);
    Hexagon(float x, float y, float z, float width, float height, float length);
};