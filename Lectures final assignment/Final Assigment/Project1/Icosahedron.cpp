#include "Icosahedron.h"

Icosahedron::Icosahedron(float x, float y, float z)
{
	Setup(Icosahedron_Vertices, Icosahedron_Colors, Icosahedron_Elements, {});
	DoTranslation(x, y, z);
	BasicShading = true;
}

Icosahedron::Icosahedron(float x, float y, float z, std::vector<Animation*> aniList)
{
	Setup(Icosahedron_Vertices, Icosahedron_Colors, Icosahedron_Elements, {});
	DoTranslation(x, y, z);
	BasicShading = true;
	animations = aniList;
}

Icosahedron::Icosahedron(float x, float y, float z, float width, float height, float length)
{
	Setup(Icosahedron_Vertices, Icosahedron_Colors, Icosahedron_Elements, {});

	Width = width;
	Height = height;
	Length = length;

	DoTranslation(x, y, z);
	DoScaling(Width, Height, Length);
	BasicShading = true;
}

Icosahedron::Icosahedron(float x, float y, float z, float width, float height, float length, std::vector<Animation*> aniList)
{
	Setup(Icosahedron_Vertices, Icosahedron_Colors, Icosahedron_Elements, {});

	Width = width;
	Height = height;
	Length = length;

	DoTranslation(x, y, z);
	DoScaling(Width, Height, Length);
	BasicShading = true;

	animations = aniList;
}
