#include "House.h"
#include "Cube.h"

House::House(int amountOfCubes)
{
	AmountOfCubes = amountOfCubes;
	AddCubes();
}

House::House(float x, float y, float z, float height = 1, float width = 1, float length = 1)
{
	X = x;
	Y = y;
	Z = z;
	Height = height;
	Width = width;
	Length = length;
	AddCubes();
}

House::House(int amountOfCubes, float x, float y, float z, float height = 1, float width = 1, float length = 1)
{
	AmountOfCubes = amountOfCubes;
	X = x;
	Y = y;
	Z = z;
	Height = height;
	Width = width;
	Length = length;
	AddCubes();
}

void House::AddCubes()
{
	Shapes.clear();

	// TODO: Make sure the cubes are stacked on top of each other.
	// Maybe add windows and doors too, would be really nice!
	for (int i = 0; i < AmountOfCubes; i++) {
		Cube cube;
		Shapes.push_back(cube);
	}
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