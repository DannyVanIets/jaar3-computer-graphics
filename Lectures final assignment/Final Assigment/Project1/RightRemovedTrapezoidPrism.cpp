#include "RightRemovedTrapezoidPrism.h"

RightRemovedTrapezoidPrism::RightRemovedTrapezoidPrism(float x, float y, float z)
{
    Setup(Trapezoid_Vertices, {}, Trapezoid_Elements, {});

    float TopLeft = x + Width / 2;

    float LengthMinusZ = z - Length;

    GLfloat newVertices[] = {
        // Front
        x,         y,          z, // Bottom left
        x + Width, y,          z, // Bottom Right
        x + Width, y + Height, z, // Top Right
        TopLeft,   y + Height, z, // Top Left
        // Back
        x,         y,          LengthMinusZ, // Bottom left
        x + Width, y,          LengthMinusZ, // Bottom Right
        x + Width, y + Height, LengthMinusZ, // Top Right
        TopLeft,   y + Height, LengthMinusZ, // Top Left
    };

    std::copy_n(newVertices, sizeof(newVertices) / 4, this->Vertices);
}

RightRemovedTrapezoidPrism::RightRemovedTrapezoidPrism(float x, float y, float z, float width, float height, float length)
{
    Setup(Trapezoid_Vertices, {}, Trapezoid_Elements, {});

    Width = width;
    Height = height;
    Length = length;

    float TopLeft = x + Width / 4;

    float LengthMinusZ = z - Length;

    GLfloat newVertices[] = {
        // Front
        x,         y,          z, // Bottom left
        x + Width, y,          z, // Bottom Right
        x + Width, y + Height, z, // Top Right
        TopLeft,   y + Height, z, // Top Left
        // Back
        x,         y,          LengthMinusZ, // Bottom left
        x + Width, y,          LengthMinusZ, // Bottom Right
        x + Width, y + Height, LengthMinusZ, // Top Right
        TopLeft,   y + Height, LengthMinusZ, // Top Left
    };

    std::copy_n(newVertices, sizeof(newVertices) / 4, this->Vertices);
}