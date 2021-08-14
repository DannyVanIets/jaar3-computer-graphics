#include "Hexagon.h"

Hexagon::Hexagon(float x, float y, float z)
{
    Setup(Hexagon_Vertices, {}, {}, {});

    DoTranslation(x, y, z);
    VerticesSize = Hexagon_Vertices.size();
    CalculateNormals();
}

Hexagon::Hexagon(float x, float y, float z, glm::vec3 rgb)
{
    Setup(Hexagon_Vertices, {}, {}, {});

    DoTranslation(x, y, z);
    VerticesSize = Hexagon_Vertices.size();
    CalculateNormals();
    ChangeColor(rgb);
}

Hexagon::Hexagon(float x, float y, float z, float width, float height, float length)
{
	Height = height;
	Width = width;
	Length = length;

    Setup(Hexagon_Vertices, {}, {}, {});

    DoTranslation(x, y, z);
    DoScaling(Width, Height, Length);
    VerticesSize = Hexagon_Vertices.size();
    CalculateNormals();
}

Hexagon::Hexagon(float x, float y, float z, float width, float height, float length, glm::vec3 rgb)
{
    Height = height;
    Width = width;
    Length = length;

    Setup(Hexagon_Vertices, {}, {}, {});

    DoTranslation(x, y, z);
    DoScaling(Width, Height, Length);
    VerticesSize = Hexagon_Vertices.size();
    CalculateNormals();

    ChangeColor(rgb);
}
