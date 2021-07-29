#include "Wedge.h"

Wedge::Wedge(float x, float y, float z)
{
    Setup(Wedge_Vertices, {}, Wedge_Elements, {});

    float YHeight = y + Height / 2;
    float LengthMinusZ = z - Length;

    GLfloat newVertices[] = {
        // Front
        x,         y,       z, // Bottom left
        x + Width, y,       z, // Bottom Right
        x + Width, YHeight, z, // Top Right
        // Back
        x,         y,       LengthMinusZ, // Bottom left
        x + Width, y,       LengthMinusZ, // Bottom Right
        x + Width, YHeight, LengthMinusZ, // Top Right
    };

    std::copy_n(newVertices, sizeof(newVertices) / 4, this->Vertices);
}

Wedge::Wedge(float x, float y, float z, float width, float height, float length)
{
    Setup(Wedge_Vertices, {}, Wedge_Elements, {});

    Height = height;
    Width = width;
    Length = length;

    float YHeight = y + Height / 2;
    float LengthMinusZ = z - Length;

    GLfloat newVertices[] = {
        // Front
        x,         y,       z, // Bottom left
        x + Width, y,       z, // Bottom Right
        x + Width, YHeight, z, // Top Right
        // Back
        x,         y,       LengthMinusZ, // Bottom left
        x + Width, y,       LengthMinusZ, // Bottom Right
        x + Width, YHeight, LengthMinusZ, // Top Right
    };

    std::copy_n(newVertices, sizeof(newVertices) / 4, this->Vertices);
}