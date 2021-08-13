#include "TriangularPrism.h"

TriangularPrism::TriangularPrism(float x, float y, float z)
{
    Setup(TriangularPrism_Vertices2, TriangularPrism_Normals, TriangularPrism_Elements2, TriangularPrism_uvs);

    DoTranslation(x, y, z);
    VerticesSize = TriangularPrism_Vertices2.size();
    CalculateNormals();
}

TriangularPrism::TriangularPrism(float x, float y, float z, float width, float height, float length)
{
    Height = height;
    Width = width;
    Length = length;
    
    Setup(TriangularPrism_Vertices2, TriangularPrism_Normals, TriangularPrism_Elements2, TriangularPrism_uvs);

    DoTranslation(x, y, z);
    DoScaling(Width, Height, Length);

    VerticesSize = TriangularPrism_Vertices2.size();
    CalculateNormals();
}