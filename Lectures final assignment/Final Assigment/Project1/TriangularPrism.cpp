#include "TriangularPrism.h"

TriangularPrism::TriangularPrism(float x, float y, float z, bool withTexture)
{
    WithTexture = withTexture;

    if (WithTexture)
    {
        Setup(TriangularPrism_Vertices2, TriangularPrism_Normals, TriangularPrism_Elements2, TriangularPrism_uvs);
    }
    else
    {
        Setup(TriangularPrism_Vertices2, {}, TriangularPrism_Elements, {});
    }

    DoTranslation(x, y, z);
    VerticesSize = TriangularPrism_Vertices2.size();
    CalculateNormals();
}

TriangularPrism::TriangularPrism(float x, float y, float z, float width, float height, float length, bool withTexture)
{
    Height = height;
    Width = width;
    Length = length;

    WithTexture = withTexture;

    if (WithTexture)
    {
        Setup(TriangularPrism_Vertices2, TriangularPrism_Normals, TriangularPrism_Elements2, TriangularPrism_uvs);
    }
    else
    {
        Setup(TriangularPrism_Vertices, {}, TriangularPrism_Elements, {});
    }

    DoTranslation(x, y, z);
    DoScaling(Width, Height, Length);

    VerticesSize = TriangularPrism_Vertices2.size();
    CalculateNormals();
}