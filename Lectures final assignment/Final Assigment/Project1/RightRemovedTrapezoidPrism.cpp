#include "RightRemovedTrapezoidPrism.h"

RightRemovedTrapezoidPrism::RightRemovedTrapezoidPrism(float x, float y, float z, bool withTexture)
{
    WithTexture = withTexture;

    if (WithTexture)
    {
        Setup(Trapezoid_Vertices, {}, Trapezoid_Elements, Trapezoid_uvs);
    }
    else
    {
        Setup(Trapezoid_Vertices, {}, Trapezoid_Elements, {});
    }

    DoTranslation(x, y, z);
}

RightRemovedTrapezoidPrism::RightRemovedTrapezoidPrism(float x, float y, float z, float width, float height, float length, bool withTexture)
{
    WithTexture = withTexture; 
    
    Width = width;
    Height = height;
    Length = length;

    if (WithTexture)
    {
        Setup(Trapezoid_Vertices, {}, Trapezoid_Elements, Trapezoid_uvs);
    }
    else
    {
        Setup(Trapezoid_Vertices, {}, Trapezoid_Elements, {});
    }

    DoTranslation(x, y, z);
    DoScaling(Width, Height, Length);
}