#include "Pyramid.h"

Pyramid::Pyramid(float x, float y, float z)
{
	Setup(Pyramid_Vertices, Pyramid_Colors, Pyramid_Elements, Pyramid_uvs);

	DoTranslation(x, y, z);
	BasicShading = true;
}

Pyramid::Pyramid(float x, float y, float z, float width, float height, float length)
{
	Width = width;
	Height = height;
	Length = length;

	Setup(Pyramid_Vertices, Pyramid_Colors, Pyramid_Elements, Pyramid_uvs);

	DoTranslation(x, y, z);
	DoScaling(Width, Height, Length);
	BasicShading = true;
}