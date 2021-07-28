#pragma once
#include <vector>
#include "Shape.h"

class House
{
public:
	// Variabeles
	int AmountOfFloors = 1;
	float X = 2.0, Y = -1.0, Z = 2.0;
	float Height = 2.0, Width = 2.0, Length = 2.0;

	std::vector<Shape> Shapes = {};

	// Constructors
	House() = default;
	House(float x, float y, float z);
	House(float x, float y, float z, float width, float height, float length);
	House(int amountOfFloors);
	House(int amountOfFloors, float x, float y, float z);
	House(int amountOfFloors, float x, float y, float z, float width, float height, float length);

	// Shapes.
	// TODO: Maybe add windows and doors too, would be really nice!
	void AddAllShapes();
	void AddGarage();
	void AddFloors();
	void AddRoof();
	void AddChimney();
	void AddSmoke();


	void RenderAllShapes(GLuint uniform_mvp, glm::mat4 projection, glm::mat4 view, glm::mat4 mvp);
	void BufferAllShapes(Shader shader, GLuint uniform_mvp, glm::mat4 mvp);
};