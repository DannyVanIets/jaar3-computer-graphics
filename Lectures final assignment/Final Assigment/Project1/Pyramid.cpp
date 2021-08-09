#include "Pyramid.h"

Pyramid::Pyramid(float x, float y, float z, bool withTexture)
{
	WithTexture = withTexture;

	if (WithTexture)
	{
		Setup(Pyramid_Vertices, {}, Pyramid_Elements, Pyramid_uvs);
	}
	else
	{
		Setup(Pyramid_Vertices, {}, Pyramid_Elements, {});
	}

	DoTranslation(x, y, z);
}

Pyramid::Pyramid(float x, float y, float z, float width, float height, float length, bool withTexture)
{
	Width = width;
	Height = height;
	Length = length;

	WithTexture = withTexture;

	if (WithTexture)
	{
		Setup(Pyramid_Vertices, {}, Pyramid_Elements, Pyramid_uvs);
	}
	else
	{
		Setup(Pyramid_Vertices, {}, Pyramid_Elements, {});
	}

	DoTranslation(x, y, z);
	DoScaling(Width, Height, Length);
}