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

	AddAllShapes();
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

	AddAllShapes();
}

House::House(int amountOfFloors, bool pyramidRoof)
{
	AmountOfFloors = amountOfFloors;

	PyramidRoof = pyramidRoof;

	AddAllShapes();
}

House::House(int amountOfFloors, float x, float y, float z, bool pyramidRoof)
{
	AmountOfFloors = amountOfFloors;

	X = x;
	Y = y;
	Z = z;

	PyramidRoof = pyramidRoof;

	AddAllShapes();
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

	AddAllShapes();
}

void House::AddAllShapes()
{
	Shapes.clear();

	AddGarage();
	AddFloors();
	if (PyramidRoof) {
		AddPyramidRoof();
	}
	else {
		AddTrapezoidRoof();
	}
	AddChimney();
	AddSmoke();
}

void House::AddGarage()
{
	RightRemovedTrapezoidPrism garage = RightRemovedTrapezoidPrism(X - Width, Y, Z);

	Shapes.push_back(garage);

	if (AmountOfFloors > 1) {
		Wedge garageRoof = Wedge(X - Width / 2, Y + Height, Z, Width / 2, Height / 2, Length);
		Shapes.push_back(garageRoof);
	}

	Wedge garageRoad = Wedge(X - Width / 2, Y, Z + Length, Width / 2, Height / 2, Length);
	Shapes.push_back(garageRoad);
}

void House::AddFloors()
{
	for (int i = 0; i < AmountOfFloors; i++) {
		Cube cube = Cube(X, Y, Z, false);

		Shapes.push_back(cube);

		Y += Height;
	}
}

void House::AddPyramidRoof()
{
	TriangularPrism roof = TriangularPrism(X, Y, Z);
	Shapes.push_back(roof);
}

void House::AddTrapezoidRoof()
{
	TrapezoidPrism roof = TrapezoidPrism(X + 0.5, Y, Z, 1.0, 2.0, 2.0);
	Shapes.push_back(roof);
}

void House::AddChimney()
{
	Hexagon chimney = Hexagon(X + 1.0, Y, Z - 0.5, 0.75, 3.0, 0.75);
	Shapes.push_back(chimney);
}

void House::AddSmoke()
{

}

void House::RenderAllShapes(glm::mat4 projection, glm::mat4 view)
{
	for (auto& shape : Shapes) {
		shape.Render(projection, view);
	}
}

void House::BufferAllShapes(Shader shader, glm::mat4 projection, glm::mat4 view)
{
	for (auto& shape : Shapes) {
		shape.InitBuffer(shader, projection, view);
	}
}