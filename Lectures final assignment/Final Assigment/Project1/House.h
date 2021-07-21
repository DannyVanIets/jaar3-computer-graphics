#pragma once
#include <vector>
#include "Shape.h"

class House
{
public:
	// Variabeles
	int AmountOfCubes = 1;
	float X, Y, Z = 0;
	float Height, Width, Length = 1;
	std::vector<Shape> Shapes = {};

	// Constructors
	House() = default;
	House(int amountOfCubes);
	House(float x, float y, float z, float height, float width, float length);
	House(int amountOfCubes, float x, float y, float z, float height, float width, float length);

	void AddCubes();
	void RenderAllShapes(GLuint uniform_mvp, glm::mat4 projection, glm::mat4 view, glm::mat4 mvp);
	void BufferAllShapes(Shader shader, GLuint uniform_mvp, glm::mat4 mvp);
};