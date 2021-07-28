#include "House.h"
#include "Cube.h"
#include "TriangularPrism.h"
#include "Hexagon.h"
#include "TrapezoidPrism.h"

House::House(float x, float y, float z)
{
	X = x;
	Y = y;
	Z = z;

	AddAllShapes();
}

House::House(float x, float y, float z, float width, float height, float length)
{
	X = x;
	Y = y;
	Z = z;

	Height = height;
	Width = width;
	Length = length;

	AddAllShapes();
}

House::House(int amountOfFloors)
{
	AmountOfFloors = amountOfFloors;

	AddAllShapes();
}

House::House(int amountOfFloors, float x, float y, float z)
{
	AmountOfFloors = amountOfFloors;

	X = x;
	Y = y;
	Z = z;

	AddAllShapes();
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

	AddAllShapes();
}

void House::AddAllShapes()
{
	Shapes.clear();

	AddFloors();
	AddGarage();
	AddRoof();
	AddChimney();
	AddSmoke();
}

void House::AddGarage()
{
	TrapezoidPrism groundFloor = TrapezoidPrism(X, Y, Z);

	Shapes.push_back(groundFloor);
}

void House::AddFloors()
{
	for (int i = 0; i < AmountOfFloors; i++) {
		Cube cube = Cube(X, Y, Z);

		Shapes.push_back(cube);

		Y += Height;
	}
}

void House::AddRoof()
{
	TriangularPrism roof = TriangularPrism(X + 0.5, Y, Z, 1.0, 2.0, 2.0);
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

void House::RenderAllShapes(GLuint uniform_mvp, glm::mat4 projection, glm::mat4 view, glm::mat4 mvp)
{
	for (auto& shape : Shapes) {
		shape.Render(uniform_mvp, projection, view, mvp);
	}
}

void House::BufferAllShapes(Shader shader, GLuint uniform_mvp, glm::mat4 mvp)
{
	for (auto& shape : Shapes) {
		shape.InitBuffers(shader, uniform_mvp, mvp);
	}
}