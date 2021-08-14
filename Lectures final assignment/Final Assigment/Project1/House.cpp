#include "House.h"
#include "Cube.h"
#include "TriangularPrism.h"
#include "Hexagon.h"
#include "Wedge.h"
#include "Icosahedron.h"
#include "Animate_ScaleHeightAndReset.h"

House::House(float x, float y, float z)
{
	X = x;
	Y = y;
	Z = z;

	AddAllEntities();
}

House::House(float x, float y, float z, float width, float height, float length)
{
	X = x;
	Y = y;
	Z = z;

	Height = height;
	Width = width;
	Length = length;

	AddAllEntities();
}

House::House(int amountOfFloors)
{
	AmountOfFloors = amountOfFloors;

	AddAllEntities();
}

House::House(int amountOfFloors, float x, float y, float z)
{
	AmountOfFloors = amountOfFloors;

	X = x;
	Y = y;
	Z = z;

	AddAllEntities();
}

House::House(int amountOfFloors, float x, float y, float z, float width, float height, float length)
{
	AmountOfFloors = amountOfFloors;

	X = x;
	Y = y;
	Z = z;

	Height = height;
	Width = width;
	Length = length;

	AddAllEntities();
}

void House::AddAllEntities()
{
	Entities.clear();

	AddFloors();
	AddRoof();
	AddChimney();
	AddSmoke();
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
	Entities.push_back(new TriangularPrism(X, Y, Z, Width, Height, Length, glm::vec3(1.0, 0.8, 0.5)));
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