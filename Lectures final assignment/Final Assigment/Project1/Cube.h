#pragma once
#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>
#include "Shader.h"

class Cube
{
public:
    GLfloat Vertices2[72] = {
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

    GLfloat Vertices[72] = {
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

    GLfloat Colors[72] = {
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
        1.0, 1.0, 0.0,
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

    GLushort Cube_elements2[36] = {
        0,1,2, 0,2,3, // front
        1,5,6, 1,6,2, // right side
        4,0,3, 4,3,7, // left side
        5,4,7, 5,7,6, // back
        3,2,6, 3,6,7, // top
        4,5,1, 4,1,0, // bottom
    };

    GLushort Cube_elements[36] = {
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
    GLfloat uvs[48] = {
        // U, V,
        // front
        0.0f, 0.0f, // bottom left
        1.0f, 0.0f, // bottom right
        1.0f, 1.0f, // top right
        0.0f, 1.0f, // top left
    };

    GLfloat uvs2[24] = {
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

    GLfloat uvs3[72] = {
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

    float Height = 1.0, Width = 1.0, Length = 1.0;
    //glm::mat4 model, mvp;
    GLuint vao;

    // Constructors
    Cube() = default;
    Cube(float height, float width, float length, float x, float y, float z);

    // Methods
    void Render(GLuint uniform_mvp, glm::mat4 projection, glm::mat4 view, glm::mat4 mvp);
    void InitBuffers(Shader shader, GLuint uniform_mvp, glm::mat4 mvp);
    void InitBuffersTexture(Shader shader, GLuint uniform_mvp, glm::mat4 mvp);
};