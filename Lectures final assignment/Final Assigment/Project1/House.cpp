#include "House.h"
#include "Cube.h"
#include "TriangularPrism.h"
#include "Hexagon.h"

House::House(int amountOfCubes)
{
	AmountOfCubes = amountOfCubes;

	AddCubes();
	AddRoof();
	AddChimney();
}

House::House(float x, float y, float z, float height, float width, float length)
{
	X = x;
	Y = y;
	Z = z;

	Height = height;
	Width = width;
	Length = length;
}

House::House(int amountOfCubes, float x, float y, float z, float height, float width, float length)
{
	AmountOfCubes = amountOfCubes;
	X = x;
	Y = y;
	Z = z;

	Height = height;
	Width = width;
	Length = length;
}

void House::AddCubes()
{
	Shapes.clear();

	// TODO: Maybe add windows and doors too, would be really nice!
	for (int i = 0; i < AmountOfCubes; i++) {
		Cube cube = Cube(X, Y, Z);

		Shapes.push_back(cube);

		Y += Height;
	}
}

void House::AddRoof()
{
	TriangularPrism roof = TriangularPrism(X, Y, Z);
	Shapes.push_back(roof);
}

void House::AddChimney()
{
	Hexagon chimney = Hexagon(X + 1.0, Y, Z - 0.5, 3.0, 0.75, 0.75);
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