#pragma once
#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>

class Cube
{
public:
    GLfloat Vertices[24] = {
        // front
        -1.0, -1.0, 1.0, // bottom left, 0
        1.0, -1.0, 1.0, // bottom right, 1
        1.0, 1.0, 1.0, // top right, 2
        -1.0, 1.0, 1.0, // top left, 3
        // back
        -1.0, -1.0, -1.0, // bottom left, 4
        1.0, -1.0, -1.0, // bottom right, 5
        1.0, 1.0, -1.0, // top right, 6
        -1.0, 1.0, -1.0 // top left, 7
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
        1.0, 1.0, 0.0
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

    GLushort Cube_elements[36] = {
        0,1,2, 0,2,3, // front
        1,5,6, 1,6,2, // right side
        4,0,3, 4,3,7, // left side
        5,4,7, 5,7,6, // back
        3,2,6, 3,6,7, // top
        4,5,1, 4,1,0, // bottom
    };

    float Height = 1.0, Width = 1.0, Length = 1.0;
    //glm::mat4 model, mvp;
    GLuint vao;

    // Constructors
    Cube() = default;
    Cube(float height, float width, float length, float x, float y, float z);

    // Methods
    void Render(GLuint uniform_mvp, glm::mat4 projection, glm::mat4 view, glm::mat4 mvp);
    void InitBuffers(GLuint program_id, GLuint uniform_mvp, glm::mat4 mvp);
};