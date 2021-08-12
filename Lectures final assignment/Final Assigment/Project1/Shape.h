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
    GLfloat Vertices[108] = { };

    int VerticesSize = 0;
    
    GLfloat Colors[72] = { // Standard rainbow colors.
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

    GLfloat uvs[72] = { 
        // U, V,
        // front
        0.0f, 0.0f, // bottom left
        1.0f, 0.0f, // bottom right
        1.0f, 1.0f, // top right
        0.0f, 1.0f, // top left
    };

    GLfloat Normals [120] = { };

    float Height = 1.0, Width = 1.0, Length = 1.0;
    bool WithTexture;

    const char* vertexshader_name = "vertexshader.vert";
    const char* fragshader_name = "fragmentshader.frag";

    const char* texture_vertexshader_name = "texturevs.vert";
    const char* texture_fragshader_name = "texturefs.frag";

    const char* shape_vertexshader_name = "shapevs.vert";
    const char* shape_fragshader_name = "shapefs.frag";

    Shader shader;
    Shader textureShader;
    Shader newShader;

    // Constructors/Destructors

    // Methods
    void Setup(std::vector<GLfloat> newVertices, std::vector<GLfloat> newColors, std::vector<GLushort> newElements, std::vector<GLfloat> newUvs);
    void CalculateNormals();

    void Render(glm::mat4 projection, glm::mat4 view) override;

    void InitBuffers(glm::mat4 projection, glm::mat4 view) override;
    void InitBufferWithShading(glm::mat4 projection, glm::mat4 view);
    void InitBufferWithoutTexture();
    void InitBufferWithTexture();
};