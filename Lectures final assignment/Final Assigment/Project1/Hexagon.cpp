#include "Hexagon.h"

Hexagon::Hexagon(float x, float y, float z, bool withTexture)
{
    WithTexture = withTexture;

    if (WithTexture)
    {
        Setup(Hexagon_Vertices, {}, Hexagon_Elements, {});
    }
    else
    {
        Setup(Hexagon_Vertices, {}, Hexagon_Elements, {});
    }

    DoTranslation(x, y, z);
}

Hexagon::Hexagon(float x, float y, float z, float width, float height, float length, bool withTexture)
{
	Height = height;
	Width = width;
	Length = length;

    WithTexture = withTexture;

    if (WithTexture)
    {
        Setup(Hexagon_Vertices, {}, Hexagon_Elements, {});
    }
    else
    {
        Setup(Hexagon_Vertices, {}, Hexagon_Elements, {});
    }

    DoTranslation(x, y, z);
    DoScaling(Width, Height, Length);
}