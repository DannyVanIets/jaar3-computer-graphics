#include "Hexagon.h"

Hexagon::Hexagon(float x, float y, float z)
{
    Setup(Hexagon_Vertices2, {}, Hexagon_Elements, {});

    DoTranslation(x, y, z);
    VerticesSize = Hexagon_Vertices2.size();
    CalculateNormals();
}

Hexagon::Hexagon(float x, float y, float z, float width, float height, float length)
{
	Height = height;
	Width = width;
	Length = length;

    Setup(Hexagon_Vertices2, {}, Hexagon_Elements, {});

    DoTranslation(x, y, z);
    DoScaling(Width, Height, Length);
    VerticesSize = Hexagon_Vertices2.size();
    CalculateNormals();
}