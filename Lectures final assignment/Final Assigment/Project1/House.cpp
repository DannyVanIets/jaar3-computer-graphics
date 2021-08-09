#include "House.h"
#include "Cube.h"
#include "TriangularPrism.h"
#include "Hexagon.h"
#include "TrapezoidPrism.h"
#include "RightRemovedTrapezoidPrism.h"
#include "Wedge.h"

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

	AddGarage();
	AddFloors();
	AddRoof();
	AddChimney();
	AddSmoke();
}

void House::AddGarage()
{
	float wedgeX = X - Width * 2;
	float wedgeHeight = Height / 4;

	Entities.push_back(new RightRemovedTrapezoidPrism(X - Width * 2, Y, Z, Width, Height, Length, false));

	if (AmountOfFloors > 1) {
		Entities.push_back(new Wedge(wedgeX, Y + Height * 1.25, Z, Width, wedgeHeight, Length, false));
	}

	/*Wedge garageRoad = Wedge(wedgeX, Y - Height, Z + Length * 2, Width, wedgeHeight, Length, false);
	garageRoad.DoRotation(90, 0.0, 1.0, 0.0);
	Shapes.push_back(garageRoad);*/
}

void House::AddFloors()
{
	/*Cube minusOneFloor = Cube(X / 2, Y, Z, Width / 2, Height / 2, Length, false);
	Shapes.push_back(minusOneFloor);
	Y += 0.5;*/

	for (int i = 0; i < AmountOfFloors; i++) {
		Entities.push_back(new Cube(X, Y, Z, Width, Height, Length, false));

		Y += Height * 2;
	}
}

void House::AddRoof()
{
	if (PyramidRoof)
	{
		Entities.push_back(new TriangularPrism(X, Y, Z, Width, Height, Length, false));
	}
	else
	{
		// TODO: Fix this one.
		//Shapes.push_back(new TrapezoidPrism(X + 0.5, Y, Z, 1.0, 2.0, 2.0, false));
	}
}

void House::AddChimney()
{
	Entities.push_back(new Hexagon(X + Height / 4, Y, Z, 0.25, Height * 1.25, 0.25, false));
}

void House::AddSmoke()
{

}