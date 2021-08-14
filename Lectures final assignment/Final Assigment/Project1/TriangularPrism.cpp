#include "TriangularPrism.h"

TriangularPrism::TriangularPrism(float x, float y, float z)
{
    Setup(TriangularPrism_Vertices, {}, {}, TriangularPrism_uvs);

    DoTranslation(x, y, z);
    VerticesSize = TriangularPrism_Vertices.size();
    CalculateNormals();
}

TriangularPrism::TriangularPrism(float x, float y, float z, glm::vec3 rgb)
{
    Setup(TriangularPrism_Vertices, {}, {}, TriangularPrism_uvs);

    DoTranslation(x, y, z);
    VerticesSize = TriangularPrism_Vertices.size();
    CalculateNormals();
    ChangeColor(rgb);
}

TriangularPrism::TriangularPrism(float x, float y, float z, float width, float height, float length)
{
    Height = height;
    Width = width;
    Length = length;

    Setup(TriangularPrism_Vertices, {}, {}, TriangularPrism_uvs);

    DoTranslation(x, y, z);
    DoScaling(Width, Height, Length);

    VerticesSize = TriangularPrism_Vertices.size();
    CalculateNormals();
}

TriangularPrism::TriangularPrism(float x, float y, float z, float width, float height, float length, glm::vec3 rgb)
{
    Height = height;
    Width = width;
    Length = length;

    Setup(TriangularPrism_Vertices, {}, {}, TriangularPrism_uvs);

    DoTranslation(x, y, z);
    DoScaling(Width, Height, Length);

    VerticesSize = TriangularPrism_Vertices.size();
    CalculateNormals();
    ChangeColor(rgb);
}
