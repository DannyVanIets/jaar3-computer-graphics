#include "Pyramid.h"

Pyramid::Pyramid(float x, float y, float z)
{
    Setup(Pyramid_Vertices, {}, Pyramid_Elements, {});


}

Pyramid::Pyramid(float x, float y, float z, float width, float height, float length)
{
    Setup(Pyramid_Vertices, {}, Pyramid_Elements, {});

	Height = height;
	Width = width;
	Length = length;

    // TODO: Make it possible to change the x, y and z positions, just like the cube.
}