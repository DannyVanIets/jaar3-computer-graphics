#include "TrapezoidPrism.h"

TrapezoidPrism::TrapezoidPrism(float x, float y, float z)
{
    Setup(Trapezoid_Vertices, {}, Trapezoid_Elements, Trapezoid_uvs);

    DoTranslation(x, y, z);
}

TrapezoidPrism::TrapezoidPrism(float x, float y, float z, float width, float height, float length)
{
    Width = width;
    Height = height;
    Length = length;

    Setup(Trapezoid_Vertices, {}, Trapezoid_Elements, Trapezoid_uvs);

    DoTranslation(x, y, z);
    DoScaling(Width, Height, Length);
}