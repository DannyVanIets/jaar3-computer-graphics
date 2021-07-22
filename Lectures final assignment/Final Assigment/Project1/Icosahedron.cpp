#include "Icosahedron.h"

Icosahedron::Icosahedron(float x, float y, float z)
{
	Setup(Icosahedron_Vertices, {}, Icosahedron_Elements, {});


}

Icosahedron::Icosahedron(float x, float y, float z, float height, float width, float length)
{
	Setup(Icosahedron_Vertices, {}, Icosahedron_Elements, {});

	Height = height;
	Width = width;
	Length = length;

	// TODO: Make it possible to change the x, y and z positions, just like the cube.

}