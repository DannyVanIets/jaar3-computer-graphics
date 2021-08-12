#include "Wedge.h"

Wedge::Wedge(float x, float y, float z, bool withTexture)
{
    WithTexture = withTexture;

    if (WithTexture)
    {
        Setup(Wedge_Vertices2, {}, Wedge_Elements, Wedge_uvs);
    }
    else
    {
        Setup(Wedge_Vertices, {}, Wedge_Elements, {});
    }

    DoTranslation(x, y, z);
    VerticesSize = Wedge_Vertices2.size();
    CalculateNormals();
}

Wedge::Wedge(float x, float y, float z, float width, float height, float length, bool withTexture)
{
    Height = height;
    Width = width;
    Length = length;

    WithTexture = withTexture;

    if (WithTexture)
    {
        Setup(Wedge_Vertices2, {}, Wedge_Elements, Wedge_uvs);
    }
    else
    {
        Setup(Wedge_Vertices, {}, Wedge_Elements, {});
    }

    DoTranslation(x, y, z);
    DoScaling(Width, Height, Length);

    VerticesSize = Wedge_Vertices2.size();
    CalculateNormals();
}

Wedge::Wedge(float x, float y, float z, float width, float height, float length, float rotateRadians, float rotateX, float rotateY, float rotateZ, bool withTexture)
{
    Height = height;
    Width = width;
    Length = length;

    WithTexture = withTexture;

    if (WithTexture)
    {
        Setup(Wedge_Vertices2, {}, Wedge_Elements, Wedge_uvs);
    }
    else
    {
        Setup(Wedge_Vertices, {}, Wedge_Elements, {});
    }

    DoTranslation(x, y, z);
    DoScaling(Width, Height, Length);
    DoRotation(rotateRadians, rotateX, rotateY, rotateZ);

    VerticesSize = Wedge_Vertices2.size();
    CalculateNormals();
}