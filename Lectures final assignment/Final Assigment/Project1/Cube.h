#pragma once
#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>
#include "Shader.h"
#include "Shape.h"

class Cube : public Shape
{
public:

    std::vector<GLfloat> Cube_Vertices = {
        // front
        -1.0, -1.0, 1.0, // bottom left, 0
         1.0, -1.0, 1.0, // bottom right, 1
         1.0, 1.0, 1.0, // top right, 2
        -1.0, 1.0, 1.0, // top left, 3
        // back
        -1.0, -1.0, -1.0, // bottom left, 4
         1.0, -1.0, -1.0, // bottom right, 5
         1.0, 1.0, -1.0, // top right, 6
        -1.0, 1.0, -1.0, // top left, 7
    };

    std::vector<GLfloat> Cube_Vertices2 = {
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

    std::vector<GLushort> Cube_elements = {
        0,1,2, 0,2,3, // front
        1,5,6, 1,6,2, // right side
        4,0,3, 4,3,7, // left side
        5,4,7, 5,7,6, // back
        3,2,6, 3,6,7, // top
        4,5,1, 4,1,0, // bottom
    };

    std::vector<GLushort> Cube_elements2 = {
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

    // Two UV coordinates for each vertex.
    std::vector<GLfloat> Cube_uvs = {
        // U, V,
        // front
        0.0f, 0.0f, // bottom left
        1.0f, 0.0f, // bottom right
        1.0f, 1.0f, // top right
        0.0f, 1.0f, // top left
    };

    std::vector<GLfloat> uvs2 = {
        // U, V,
        // front
        0.0f, 0.0f, // bottom left
        1.0f, 0.0f, // bottom right
        1.0f, 1.0f, // top right
        0.0f, 1.0f, // top left

        // behind
        1.0f, 1.0f, // bottom right
        0.0f, 1.0f, // top right
        0.0f, 0.0f, // top left
        1.0f, 0.0f, // bottom left
    };

    std::vector<GLfloat> uvs3 = {
        0.000059f, 1.0f - 0.000004f,
        0.000103f, 1.0f - 0.336048f,
        0.335973f, 1.0f - 0.335903f,
        1.000023f, 1.0f - 0.000013f,
        0.667979f, 1.0f - 0.335851f,
        0.999958f, 1.0f - 0.336064f,
        0.667979f, 1.0f - 0.335851f,
        0.336024f, 1.0f - 0.671877f,
        0.667969f, 1.0f - 0.671889f,
        1.000023f, 1.0f - 0.000013f,
        0.668104f, 1.0f - 0.000013f,
        0.667979f, 1.0f - 0.335851f,
        0.000059f, 1.0f - 0.000004f,
        0.335973f, 1.0f - 0.335903f,
        0.336098f, 1.0f - 0.000071f,
        0.667979f, 1.0f - 0.335851f,
        0.335973f, 1.0f - 0.335903f,
        0.336024f, 1.0f - 0.671877f,
        1.000004f, 1.0f - 0.671847f,
        0.999958f, 1.0f - 0.336064f,
        0.667979f, 1.0f - 0.335851f,
        0.668104f, 1.0f - 0.000013f,
        0.335973f, 1.0f - 0.335903f,
        0.667979f, 1.0f - 0.335851f,
        0.335973f, 1.0f - 0.335903f,
        0.668104f, 1.0f - 0.000013f,
        0.336098f, 1.0f - 0.000071f,
        0.000103f, 1.0f - 0.336048f,
        0.000004f, 1.0f - 0.671870f,
        0.336024f, 1.0f - 0.671877f,
        0.000103f, 1.0f - 0.336048f,
        0.336024f, 1.0f - 0.671877f,
        0.335973f, 1.0f - 0.335903f,
        0.667969f, 1.0f - 0.671889f,
        1.000004f, 1.0f - 0.671847f,
        0.667979f, 1.0f - 0.335851f
    };

    // Constructors
    Cube() = default;
    Cube(float height, float width, float length, float x, float y, float z);
};