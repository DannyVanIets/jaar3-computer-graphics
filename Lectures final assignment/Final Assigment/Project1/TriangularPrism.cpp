#include "TriangularPrism.h"

TriangularPrism::TriangularPrism(float x, float y, float z)
{
    Setup(TriangularPrism_Vertices, {}, TriangularPrism_Elements, {});

    float LengthMinusZ = z - Length;
    float TopMiddle = x + Width / 2;

    GLfloat newVertices[] = {
        // Front
        x,         y,          z, // Bottom left
        x + Width, y,          z, // Bottom Right
        TopMiddle, y + Height, z, // Top Right
        // Back
        x,         y,          LengthMinusZ, // Bottom left
        x + Width, y,          LengthMinusZ, // Bottom Right
        TopMiddle, y + Height, LengthMinusZ, // Top Right
    };

    std::copy_n(newVertices, sizeof(newVertices) / 4, this->Vertices);
}

TriangularPrism::TriangularPrism(float x, float y, float z, float height, float width, float length)
{
    Setup(TriangularPrism_Vertices, {}, TriangularPrism_Elements, {});

    Height = height;
    Width = width;
    Length = length;

    float LengthMinusZ = z - Length;
    float TopMiddle = x + Width / 2;

    GLfloat newVertices[] = {
        // Front
        x,         y,          z, // Bottom left
        x + Width, y,          z, // Bottom Right
        TopMiddle, y + Height, z, // Top Right
        // Back
        x,         y,          LengthMinusZ, // Bottom left
        x + Width, y,          LengthMinusZ, // Bottom Right
        TopMiddle, y + Height, LengthMinusZ, // Top Right
    };

    std::copy_n(newVertices, sizeof(newVertices) / 4, this->Vertices);
}