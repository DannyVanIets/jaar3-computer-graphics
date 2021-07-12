#pragma once
#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>

class TriangularPrism
{
public:
    GLfloat Vertices[18] = { // X, Y, Z.
        // front
        -1.0, -1.0, 1.0, // 0
        1.0, -1.0, 1.0, // 1
        0, 1, 1.0, // 2
        // back
        -1.0, -1.0, -1.0, // 3
        1.0, -1.0, -1.0, // 4
        0, 1.0, -1.0, // 5
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

    GLushort Elements[24] = {
        0,1,2, // front
        1,2,5, 1,4,5, // right side
        4,3,5, // back
        3,0,2, 3,2,5, // left side
        0,1,3, 1,3,4 // bottom
    };

    float Height = 1.0, Width = 1.0, Length = 1.0;
    GLuint vao;

    // Constructors
    TriangularPrism() = default;
    TriangularPrism(float height, float width, float length, float x, float y, float z);

    // Methods
    void Render(GLuint uniform_mvp, glm::mat4 projection, glm::mat4 view, glm::mat4 mvp);
    void InitBuffers(GLuint program_id, GLuint uniform_mvp, glm::mat4 mvp);
};

