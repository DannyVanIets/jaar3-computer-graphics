#include "Tree.h"
#include "Hexagon.h"
#include "Pyramid.h"
#include "Object.h"

Tree::Tree(bool pyramidLeaves)
{
	PyramidLeaves = pyramidLeaves;

	AddAllEntities();
}

Tree::Tree(float x, float y, float z, bool pyramidLeaves)
{
	X = x;
	Y = y;
	Z = z;

	PyramidLeaves = pyramidLeaves;

	AddAllEntities();
}

Tree::Tree(float x, float y, float z, float width, float height, float length, bool pyramidLeaves)
{
	X = x;
	Y = y;
	Z = z;

	Height = height;
	Width = width;
	Length = length;

	PyramidLeaves = pyramidLeaves;

	AddAllEntities();
}

void Tree::AddAllEntities()
{
	Entities.clear();

	AddTrunk();
	AddLeaves();
}

void Tree::AddTrunk()
{
	Entities.push_back(new Hexagon(X, Y, Z, Width / 3, Height, Length / 3, false));
}

void Tree::AddLeaves()
{
	if (PyramidLeaves) 
	{
		Y += Height * 1.25f;
		Entities.push_back(new Pyramid(X, Y, Z, Width, Height / 1.25, Length, false));
	}
	else 
	{
		Y += Height;
		// Load in sphere and use it.
		Entities.push_back(new Object("sphere", X, Y, Z, Width, Height, Length));
	}
}