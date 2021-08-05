#pragma once
#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>
#include "Entity.h"
#include "Shader.h"
#include <vector>

class Shape : public Entity
{
public:
    // Properties
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

    GLushort Elements[72] = { };

    GLfloat uvs[72] = { };

    float Height = 2.0, Width = 2.0, Length = 2.0;

    // Methods
    void Setup(std::vector<GLfloat> newVertices, std::vector<GLfloat> newColors, std::vector<GLushort> newElements, std::vector<GLfloat> newUvs);

    void Render(glm::mat4 projection, glm::mat4 view);
    void RenderWithTexture(glm::mat4 projection, glm::mat4 view, GLuint texture_id);

    void InitBuffers(Shader shader, glm::mat4 projection, glm::mat4 view);
    void InitBuffersTexture(Shader shader, glm::mat4 projection, glm::mat4 view);
};