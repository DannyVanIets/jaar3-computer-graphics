#pragma once
#include "Shape.h"

class Icosahedron : public Shape
{
public:
    std::vector<GLfloat> Icosahedron_Vertices = { // X, Y, Z.
        -0.5, 0.5, 0.75, // 0
        0.5, 0.5, 0.75, // 1
        0.75, 0.5, -0.25, // 2
        0, 0.5, -0.75, // 3
        -0.75, 0.5, -0.25, // 4

        0, 1.5, 0.75, // 5
        0.66, 1.5, 0.25, // 6
        0.5, 1.5, -0.5, // 7
        -0.33, 1.5, -0.5, // 8
        -0.66, 1.5, 0.25, // 9

        0, -0.25, 0, // 10
        0, 2.25, 0, // 11
    };

    std::vector<GLfloat> Icosahedron_Colors = {
        // front colors
        0.0, 0.0, 0.0,
        0.0, 0.0, 0.0,
        0.0, 0.0, 0.0,
        0.0, 0.0, 0.0,
        // right side colors
        0.0, 0.0, 0.0,
        0.0, 0.0, 0.0,
        0.0, 0.0, 0.0,
        0.0, 0.0, 0.0,
        // left side colors
        0.0, 0.0, 0.0,
        0.0, 0.0, 0.0,
        0.0, 0.0, 0.0,
        0.0, 0.0, 0.0,
        // back colors
        0.0, 0.0, 0.0,
        0.0, 0.0, 0.0,
        0.0, 0.0, 0.0,
        0.0, 0.0, 0.0,
        // top colors
        0.0, 0.0, 0.0,
        0.0, 0.0, 0.0,
        0.0, 0.0, 0.0,
        0.0, 0.0, 0.0,
        // bottom colors
        0.0, 0.0, 0.0,
        0.0, 0.0, 0.0,
        0.0, 0.0, 0.0,
        0.0, 0.0, 0.0,
    };

    std::vector<GLushort> Icosahedron_Elements = {
        // All the middle triangles.
        0,1,5,
        5,6,1,
        1,2,6,
        6,7,2,
        2,3,7,
        7,8,3,
        3,4,8,
        8,9,4,
        4,0,9,
        9,5,0,
        // All the bottom triangles.
        0,1,10,
        1,2,10,
        2,3,10,
        3,4,10,
        4,0,10,
        // All the top triangles.
        5,6,11,
        6,7,11,
        7,8,11,
        8,9,11,
        9,5,11
    };

    // Constructors
    Icosahedron() = default;
    Icosahedron(float x, float y, float z);
    Icosahedron(float x, float y, float z, std::vector<Animation*> aniList);
    Icosahedron(float x, float y, float z, float width, float height, float length);
    Icosahedron(float x, float y, float z, float width, float height, float length, std::vector<Animation*> aniList);
};