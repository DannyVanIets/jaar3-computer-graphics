#pragma once
#include "Shape.h"

class Hexagon : public Shape
{
public:

    std::vector<GLfloat> Hexagon_Vertices = { // X, Y, Z.
        // front
        -0.5, -1.0,  1.0, // bottom left
         0.5, -1.0,  1.0, // bottom right
        -0.5,  1.0,  1.0, // top left

        -0.5,  1.0,  1.0, // top left
         0.5, -1.0,  1.0, // bottom right
         0.5,  1.0,  1.0, // top right

        // front-left
        -0.5, -1.0,  1.0, // bottom right
        -0.5,  1.0,  1.0, // top right
        -1.0,  1.0,  0.0, // top left

        -0.5, -1.0,  1.0, // bottom right
        -1.0,  1.0,  0.0, // top left
        -1.0, -1.0,  0.0, // bottom left

        // front-right
         0.5, -1.0,  1.0, // bottom left
         0.5,  1.0,  1.0, // top left
         1.0,  1.0,  0.0, // top right

         0.5, -1.0,  1.0, // bottom left
         1.0,  1.0,  0.0, // top right
         1.0, -1.0,  0.0, // bottom right

        // back
        -0.5, -1.0, -1.0,
         0.5, -1.0, -1.0, 
        -0.5,  1.0, -1.0,

        -0.5,  1.0, -1.0,
         0.5,  1.0, -1.0,
         0.5, -1.0, -1.0,

        // back-left
        -0.5,  1.0, -1.0,
        -1.0,  1.0,  0.0,
        -0.5, -1.0, -1.0,

        -0.5, -1.0, -1.0,
        -1.0,  1.0,  0.0,
        -1.0, -1.0,  0.0,

        // back right
         0.5,  1.0, -1.0,
         0.5, -1.0, -1.0,
         1.0, -1.0,  0.0,

         0.5,  1.0, -1.0,
         1.0, -1.0,  0.0,
         1.0,  1.0,  0.0,
    };

    // Constructors
    Hexagon() = default;
    Hexagon(float x, float y, float z);
    Hexagon(float x, float y, float z, glm::vec3 rgb);
    Hexagon(float x, float y, float z, float width, float height, float length);
    Hexagon(float x, float y, float z, float width, float height, float length, glm::vec3 rgb);
};