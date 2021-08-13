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
        -1.0, -1.0,  1.0, // bottom left,  0
         1.0, -1.0,  1.0, // bottom right, 1
         1.0,  1.0,  1.0, // top right,   2
        // back
        -1.0, -1.0, -1.0, // bottom left,  3
         1.0, -1.0, -1.0, // bottom right, 4
         1.0,  1.0, -1.0, // top right,   5
    };

    std::vector<GLfloat> Wedge_Vertices2 = {
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

    std::vector<GLushort> Wedge_Elements = {
        0,1,2,        // front
        1,2,5, 1,4,5, // right side
        4,3,5,        // back
        3,0,2, 3,2,5, // left side
        0,1,3, 1,3,4  // bottom
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
    Wedge(float x, float y, float z, float width, float height, float length);
    Wedge(float x, float y, float z, float width, float height, float length, float rotateRadians, float rotateX, float rotateY, float rotateZ);
};