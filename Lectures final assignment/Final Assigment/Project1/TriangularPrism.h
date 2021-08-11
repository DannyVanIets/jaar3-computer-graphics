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
        -1.0, -1.0,  1.0, // bottom left,  0
         1.0, -1.0,  1.0, // bottom right, 1
         0.0,  1.0,  1.0, // top middle,   2
        // back
        -1.0, -1.0, -1.0, // bottom left,  3
         1.0, -1.0, -1.0, // bottom right, 4
         0.0,  1.0, -1.0, // top middle,   5
    };

    std::vector<GLfloat> TriangularPrism_Vertices2 = {
        // X, Y, Z.
        // front
        -1.0, -1.0,  1.0, // bottom left,  0
         1.0, -1.0,  1.0, // bottom right, 1
         0.0,  1.0,  1.0, // top middle,   2
        // right
         1.0, -1.0,  1.0,
         0.0,  1.0,  1.0,
         1.0, -1.0, -1.0,
         0.0,  1.0, -1.0,
        // back
        -1.0, -1.0, -1.0, // bottom left,  3
         1.0, -1.0, -1.0, // bottom right, 4
         0.0,  1.0, -1.0, // top middle,   5
         // left
        -1.0, -1.0, -1.0,
        -1.0, -1.0,  1.0,
         0.0,  1.0,  1.0,
        -1.0, -1.0, -1.0,
        // bottom
        -1.0, -1.0, -1.0,
         1.0, -1.0, -1.0,
         1.0, -1.0,  1.0,
        -1.0, -1.0,  1.0,
    };

    std::vector<GLushort> TriangularPrism_Elements2 = {
        0,1,2,        // front
        3,4,5, 5,6,2, // right side
        7,8,9,        // back
        10,11,12, 12,9,13, // left side
        14,15,16, 14,17,16  // bottom
    };

    std::vector<GLfloat> TriangularPrism_Normals = {
        // front
         0.0,  0.0,  1.0,
         0.0,  0.0,  1.0,
         0.0,  0.0,  1.0,
         // right
         0.0,  1.0,  0.0,
         0.0,  1.0,  0.0,
         0.0,  1.0,  0.0,
         0.0,  1.0,  0.0,
         // back
         0.0,  0.0, -1.0,
         0.0,  0.0, -1.0,
         0.0,  0.0, -1.0,
        // left
         0.0, -1.0,  0.0,
         0.0, -1.0,  0.0,
         0.0, -1.0,  0.0,
         0.0, -1.0,  0.0,
        // bottom
         1.0,  0.0,  0.0,
         1.0,  0.0,  0.0,
         1.0,  0.0,  0.0,
    };

    std::vector<GLushort> TriangularPrism_Elements = {
        0,1,2,        // front
        1,2,5, 1,4,5, // right side
        4,3,5,        // back
        3,0,2, 3,2,5, // left side
        0,1,3, 1,3,4  // bottom
    };

    std::vector<GLfloat> TriangularPrism_uvs = {
        // U, V,
        // front
        0.0f, 0.0f, // bottom left
        1.0f, 0.0f, // bottom right
        1.0f, 1.0f, // top right
        0.0f, 1.0f, // top left
    };

    // Constructors
    TriangularPrism() = default;
    TriangularPrism(float x, float y, float z, bool withTexture);
    TriangularPrism(float x, float y, float z, float width, float height, float length, bool withTexture);
};