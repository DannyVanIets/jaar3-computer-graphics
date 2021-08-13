#include "Icosahedron.h"

Icosahedron::Icosahedron(float x, float y, float z)
{
	Setup(Icosahedron_Vertices, {}, Icosahedron_Elements, {});
	DoTranslation(x, y, z);
	BasicShading = true;
}

Icosahedron::Icosahedron(float x, float y, float z, float width, float height, float length)
{
	Setup(Icosahedron_Vertices, {}, Icosahedron_Elements, {});

	Width = width;
	Height = height;
	Length = length;

	DoTranslation(x, y, z);
	DoScaling(Width, Height, Length);
	BasicShading = true;
}