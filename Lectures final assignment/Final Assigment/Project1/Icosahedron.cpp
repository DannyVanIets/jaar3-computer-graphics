#include "Icosahedron.h"

Icosahedron::Icosahedron(float x, float y, float z, bool withTexture)
{
	WithTexture = withTexture;

	if (WithTexture)
	{
		Setup(Icosahedron_Vertices, {}, Icosahedron_Elements, {});
	}
	else
	{
		Setup(Icosahedron_Vertices, {}, Icosahedron_Elements, {});
	}

	DoTranslation(x, y, z);
}

Icosahedron::Icosahedron(float x, float y, float z, float width, float height, float length, bool withTexture)
{
	Setup(Icosahedron_Vertices, {}, Icosahedron_Elements, {});

	Width = width;
	Height = height;
	Length = length;

	WithTexture = withTexture;

	if (WithTexture)
	{
		Setup(Icosahedron_Vertices, {}, Icosahedron_Elements, {});
	}	
	else
	{
		Setup(Icosahedron_Vertices, {}, Icosahedron_Elements, {});
	}

	DoTranslation(x, y, z);
	DoScaling(Width, Height, Length);
}