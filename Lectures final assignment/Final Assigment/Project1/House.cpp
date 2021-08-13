#include "House.h"
#include "Cube.h"
#include "TriangularPrism.h"
#include "Hexagon.h"
#include "TrapezoidPrism.h"
#include "RightRemovedTrapezoidPrism.h"
#include "Wedge.h"
#include "Icosahedron.h"

House::House(float x, float y, float z, bool pyramidRoof)
{
	X = x;
	Y = y;
	Z = z;

	PyramidRoof = pyramidRoof;

	AddAllEntities();
}

House::House(float x, float y, float z, float width, float height, float length, bool pyramidRoof)
{
	X = x;
	Y = y;
	Z = z;

	Height = height;
	Width = width;
	Length = length;

	PyramidRoof = pyramidRoof;

	AddAllEntities();
}

House::House(int amountOfFloors, bool pyramidRoof)
{
	AmountOfFloors = amountOfFloors;

	PyramidRoof = pyramidRoof;

	AddAllEntities();
}

House::House(int amountOfFloors, float x, float y, float z, bool pyramidRoof)
{
	AmountOfFloors = amountOfFloors;

	X = x;
	Y = y;
	Z = z;

	PyramidRoof = pyramidRoof;

	AddAllEntities();
}

House::House(int amountOfFloors, float x, float y, float z, float width, float height, float length, bool pyramidRoof)
{
	AmountOfFloors = amountOfFloors;

	X = x;
	Y = y;
	Z = z;

	Height = height;
	Width = width;
	Length = length;

	PyramidRoof = pyramidRoof;

	AddAllEntities();
}

void House::AddAllEntities()
{
	Entities.clear();

	//AddGarage();
	AddFloors();
	AddRoof();
	AddChimney();
	AddSmoke();
}

void House::AddGarage()
{
	float wedgeX = X - Width * 2;
	float wedgeHeight = Height / 4;

	Entities.push_back(new RightRemovedTrapezoidPrism(X - Width * 2, Y, Z, Width, Height, Length));

	if (AmountOfFloors > 1) {
		Entities.push_back(new Wedge(wedgeX, Y + Height * 1.25f, Z, Width, wedgeHeight, Length));
	}
}

void House::AddFloors()
{
	for (int i = 0; i < AmountOfFloors; i++) {
		Entities.push_back(new Cube(X, Y, Z, Width, Height, Length, "texture/Yellobrk.bmp"));

		Y += Height * 2;
	}
}

void House::AddRoof()
{
	if (PyramidRoof)
	{
		Entities.push_back(new TriangularPrism(X, Y, Z, Width, Height, Length));
	}
	else
	{
		// TODO: Fix this one.
		//Shapes.push_back(new TrapezoidPrism(X + 0.5, Y, Z, 1.0, 2.0, 2.0, false));
	}
}

void House::AddChimney()
{
	Entities.push_back(new Hexagon(X + Width / 4, Y, Z, 0.25, Height * 1.25, 0.25));
	Y += Height;
}

void House::AddSmoke()
{
	std::vector<Animation*> aniList = {};
	aniList.push_back(new Animate_Rotating(1, 0.0, 1.0, 0.0));
	aniList.push_back(new Animate_GoUpAndReset(5.0));

	Entities.push_back(new Icosahedron(X + 0.25, Y, Z, 0.25, Height, 0.25, aniList));
}