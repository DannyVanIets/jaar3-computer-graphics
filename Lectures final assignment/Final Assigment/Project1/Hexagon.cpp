#include "Hexagon.h"

Hexagon::Hexagon(float x, float y, float z)
{
	Setup(Hexagon_Vertices, {}, Hexagon_Elements, {});


}

Hexagon::Hexagon(float x, float y, float z, float height, float width, float length)
{
	Setup(Hexagon_Vertices, {}, Hexagon_Elements, {});

	Height = height;
	Width = width;
	Length = length;

	// TODO: Make it possible to change the x, y and z positions, just like the cube.

}