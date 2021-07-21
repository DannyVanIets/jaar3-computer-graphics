#pragma once
#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>
#include "Shader.h"
#include <vector>

class Shape
{
public:
    GLfloat Vertices[72] = { };

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

    GLushort Elements[36] = { };

    GLfloat uvs[48] = { };

    float Height = 1.0, Width = 1.0, Length = 1.0;
    //glm::mat4 model, mvp;
    GLuint vao;

    void Setup(std::vector<GLfloat> newVertices, std::vector<GLfloat> newColors, std::vector<GLushort> newElements, std::vector<GLfloat> newUvs);
    
    void Render(GLuint uniform_mvp, glm::mat4 projection, glm::mat4 view, glm::mat4 mvp);
    void InitBuffers(Shader shader, GLuint uniform_mvp, glm::mat4 mvp);
    void InitBuffersTexture(Shader shader, GLuint uniform_mvp, glm::mat4 mvp);
};