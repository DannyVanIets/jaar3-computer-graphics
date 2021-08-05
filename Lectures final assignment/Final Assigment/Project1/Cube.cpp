#include "Cube.h"

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "glsl.h"

#include <glm/gtc/matrix_transform.hpp>

Cube::Cube(float x, float y, float z)
{
    Setup(Cube_Vertices, {}, Cube_elements, Cube_uvs);

    float LengthMinusZ = z - Length;

    GLfloat newVertices[] = {
        // Front
        x,         y,          z, // Bottom left
        x + Width, y,          z, // Bottom Right
        x + Width, y + Height, z, // Top Right
        x,         y + Height, z, // Top Left
        // Back
        x,         y,          LengthMinusZ, // Bottom left
        x + Width, y,          LengthMinusZ, // Bottom Right
        x + Width, y + Height, LengthMinusZ, // Top Right
        x,         y + Height, LengthMinusZ, // Top Left
    };

    std::copy_n(newVertices, sizeof(newVertices) / 4, this->Vertices);
}

Cube::Cube(float x, float y, float z, float width, float height, float length)
{
    Setup(Cube_Vertices, {}, Cube_elements, Cube_uvs);

    Height = height;
    Width = width;
    Length = length;

    float LengthMinusZ = z - Length;

    GLfloat newVertices[] = {
        // Front
        x,         y,          z, // Bottom left
        x + Width, y,          z, // Bottom Right
        x + Width, y + Height, z, // Top Right
        x,         y + Height, z, // Top Left
        // Back
        x,         y,          LengthMinusZ, // Bottom left
        x + Width, y,          LengthMinusZ, // Bottom Right
        x + Width, y + Height, LengthMinusZ, // Top Right
        x,         y + Height, LengthMinusZ, // Top Left
    };

    //std::copy_n(newVertices, sizeof(newVertices) / 4, this->Vertices);
}