#pragma once
#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>
#include "Entity.h"
#include "Shader.h"
#include <vector>

/// <summary>
/// Used by every shape, like the Cube.
/// </summary>
class Shape : public Entity
{
public:
    // Properties

    /// <summary>
    /// Used to draw the lines between elements.
    /// </summary>
    GLfloat Vertices[120] = { };

    /// <summary>
    /// The size of the vertices, used to calculate the normals.
    /// </summary>
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

    /// <summary>
    /// The elements used to draw the shape, in-case you use BasicShading.
    /// </summary>
    GLushort Elements[72] = { };

    /// <summary>
    /// Used to place the textures right.
    /// </summary>
    GLfloat uvs[72] = { };

    /// <summary>
    /// Used for cool lightning effects.
    /// Calculated automatically!
    /// </summary>
    GLfloat Normals [120] = { };

    float Height = 1.0, Width = 1.0, Length = 1.0;

    // Constructors/Destructors

    // Methods

    /// <summary>
    /// Used to fill in every array you can see in this class.
    /// Properties speaks for itself.
    /// </summary>
    void Setup(std::vector<GLfloat> newVertices, std::vector<GLfloat> newColors, std::vector<GLushort> newElements, std::vector<GLfloat> newUvs);
    
    /// <summary>
    /// Used to calculate the normals based on the vertices.
    /// Not possible with basic shading shapes!
    /// </summary>
    void CalculateNormals();

    void Render(glm::mat4 projection, glm::mat4 view) override;
    void RenderBasic(glm::mat4 projection, glm::mat4 view);
    void RenderWithShading(glm::mat4 projection, glm::mat4 view);

    void InitBuffers(glm::mat4 projection, glm::mat4 view) override;
    void InitBufferBasic(glm::mat4 projection, glm::mat4 view);
    void InitBufferBasicTexture(glm::mat4 projection, glm::mat4 view);
    void InitBufferWithShading(glm::mat4 projection, glm::mat4 view);
};