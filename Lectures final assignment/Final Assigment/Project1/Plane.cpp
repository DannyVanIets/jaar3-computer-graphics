#include "Plane.h"

Plane::Plane(float x, float y, float z)
{
    Setup(PlaneVertices, {}, Plane_Elements, Plane_Uvs);
    DoTranslation(x, y, z);
}

Plane::Plane(float x, float y, float z, string texture_name)
{
    Setup(PlaneVertices, {}, Plane_Elements, Plane_Uvs);
    DoTranslation(x, y, z);
    texture_path = texture_name;
}

Plane::Plane(float x, float y, float z, float width, float height, float length)
{
    Width = width;
    Height = height;
    Length = length;

    Setup(PlaneVertices, {}, Plane_Elements, Plane_Uvs);
    DoTranslation(x, y, z);
    DoScaling(Width, Height, Length);
}

Plane::Plane(float x, float y, float z, float width, float height, float length, string texture_name)
{
    Width = width;
    Height = height;
    Length = length;

    Setup(PlaneVertices, {}, Plane_Elements, Plane_Uvs);
    DoTranslation(x, y, z);
    DoScaling(Width, Height, Length);

    texture_path = texture_name;
}