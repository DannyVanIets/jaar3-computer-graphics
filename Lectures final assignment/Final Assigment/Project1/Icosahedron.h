#pragma once
#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>

class Icosahedron
{
public:
    GLfloat Vertices[36] = { // X, Y, Z.
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

    GLushort Elements[60] = {
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
        // All the bottom triangles. TODO: CHANGE 5 TO 10!
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

    float Height = 1.0, Width = 1.0, Length = 1.0;
    GLuint vao;

    // Constructors
    Icosahedron() = default;
    Icosahedron(float height, float width, float length, float x, float y, float z);

    // Methods
    void Render(GLuint uniform_mvp, glm::mat4 projection, glm::mat4 view, glm::mat4 mvp);
    void InitBuffers(GLuint program_id, GLuint uniform_mvp, glm::mat4 mvp);
};