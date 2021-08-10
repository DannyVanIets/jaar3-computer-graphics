#pragma once
#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>

#include "Shape.h"

class Cube : public Shape
{
public:
    std::vector<GLfloat> Cube_Vertices = {
        // front
        -1.0, -1.0,  1.0, // bottom left, 0
         1.0, -1.0,  1.0, // bottom right, 1
         1.0,  1.0,  1.0, // top right, 2
        -1.0,  1.0,  1.0, // top left, 3
        // back
        -1.0, -1.0, -1.0, // bottom left, 4
         1.0, -1.0, -1.0, // bottom right, 5
         1.0,  1.0, -1.0, // top right, 6
        -1.0,  1.0, -1.0, // top left, 7
    };

    std::vector<glm::vec3> Test = {
        glm::vec3(1.0, 1.0, 1.0),
        glm::vec3(-1.0, 1.0, 1.0),
    };

    std::vector<GLfloat> Cube_Normals = {
        // front
         0.0,  0.0,  1.0,
         0.0,  0.0,  1.0,
         0.0,  0.0,  1.0,
         0.0,  0.0,  1.0,
        // top
         0.0,  1.0,  0.0,
         0.0,  1.0,  0.0,
         0.0,  1.0,  0.0,
         0.0,  1.0,  0.0,
        // back
         0.0,  0.0, -1.0,
         0.0,  0.0, -1.0,
         0.0,  0.0, -1.0,
         0.0,  0.0, -1.0,
        // bottom
         0.0, -1.0,  0.0,
         0.0, -1.0,  0.0,
         0.0, -1.0,  0.0,
         0.0, -1.0,  0.0,
        // left
         -1.0,  0.0,  0.0,
         -1.0,  0.0,  0.0,
         -1.0,  0.0,  0.0,
         -1.0,  0.0,  0.0,
        // right
         1.0,  0.0,  0.0,
         1.0,  0.0,  0.0,
         1.0,  0.0,  0.0,
         1.0,  0.0,  0.0,
    };

    std::vector<GLfloat> Cube_Vertices_For_Textures = {
        // front
        -1.0, -1.0,  1.0, // bottom left, 0
         1.0, -1.0,  1.0, // bottom right, 1
         1.0,  1.0,  1.0, // top right, 2
        -1.0,  1.0,  1.0, // top left, 3
        // top
        -1.0,  1.0,  1.0,
         1.0,  1.0,  1.0,
         1.0,  1.0, -1.0,
        -1.0,  1.0, -1.0,
        // back
         1.0, -1.0, -1.0,
        -1.0, -1.0, -1.0,
        -1.0,  1.0, -1.0,
         1.0,  1.0, -1.0,
        // bottom
        -1.0, -1.0, -1.0,
         1.0, -1.0, -1.0,
         1.0, -1.0,  1.0,
        -1.0, -1.0,  1.0,
        // left
        -1.0, -1.0, -1.0,
        -1.0, -1.0,  1.0,
        -1.0,  1.0,  1.0,
        -1.0,  1.0, -1.0,
        // right
         1.0, -1.0,  1.0,
         1.0, -1.0, -1.0,
         1.0,  1.0, -1.0,
         1.0,  1.0,  1.0,
    };

    //------------------------------------------------------------
    // Variables for object
    //
    //           7----------6
    //          /|         /|
    //         / |        / |
    //        /  4-------/--5               y
    //       /  /       /  /                |
    //      3----------2  /                 ----x
    //      | /        | /                 /
    //      |/         |/                  z
    //      0----------1
    //------------------------------------------------------------

    std::vector<GLushort> Cube_Elements = {
        0,1,2, 0,2,3, // front
        1,5,6, 1,6,2, // right side
        4,0,3, 4,3,7, // left side
        5,4,7, 5,7,6, // back
        3,2,6, 3,6,7, // top
        4,5,1, 4,1,0, // bottom
    };

    std::vector<GLushort> Cube_Elements_for_Textures = {
        // front
        0, 1, 2,
        2, 3, 0,
        // top
        4, 5, 6,
        6, 7, 4,
        // back
        8, 9, 10,
        10, 11, 8,
        // bottom
        12, 13, 14,
        14, 15, 12,
        // left
        16, 17, 18,
        18, 19, 16,
        // right
        20, 21, 22,
        22, 23, 20,
    };

    // Constructors
    Cube() = default;
    Cube(float x, float y, float z, bool withTexture);
    Cube(float x, float y, float z, float width, float height, float length, bool withTexture);
};