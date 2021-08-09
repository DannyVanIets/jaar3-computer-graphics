#include "TriangularPrism.h"

TriangularPrism::TriangularPrism(float x, float y, float z, bool withTexture)
{
    WithTexture = withTexture;

    if (WithTexture)
    {
        Setup(TriangularPrism_Vertices, {}, TriangularPrism_Elements, TriangularPrism_uvs);
    }
    else
    {
        Setup(TriangularPrism_Vertices, {}, TriangularPrism_Elements, {});
    }

    DoTranslation(x, y, z);
}

TriangularPrism::TriangularPrism(float x, float y, float z, float width, float height, float length, bool withTexture)
{
    Height = height;
    Width = width;
    Length = length;

    WithTexture = withTexture;

    if (WithTexture)
    {
        Setup(TriangularPrism_Vertices, {}, TriangularPrism_Elements, TriangularPrism_uvs);
    }
    else
    {
        Setup(TriangularPrism_Vertices, {}, TriangularPrism_Elements, {});
    }

    DoTranslation(x, y, z);
    DoScaling(Width, Height, Length);
}