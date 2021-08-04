#pragma once
#include <vector>
#include "Shape.h"

class House
{
public:
	// Variabeles
	int AmountOfFloors = 1;
	bool PyramidRoof = true;
	float X = 2.0, Y = -1.0, Z = 2.0;
	float Height = 2.0, Width = 2.0, Length = 2.0;

	std::vector<Shape> Shapes = {};

	// Constructors
	House() = default;
	House(float x, float y, float z, bool pyramidRoof);
	House(float x, float y, float z, float width, float height, float length, bool pyramidRoof);
	House(int amountOfFloors, bool pyramidRoof);
	House(int amountOfFloors, float x, float y, float z, bool pyramidRoof);
	House(int amountOfFloors, float x, float y, float z, float width, float height, float length, bool pyramidRoof);

	// Shapes.
	// TODO: Maybe add windows and doors too, would be really nice!
	void AddAllShapes();
	void AddGarage();
	void AddFloors();
	void AddPyramidRoof();
	void AddTrapezoidRoof();
	void AddChimney();
	void AddSmoke();

	void RenderAllShapes(glm::mat4 projection, glm::mat4 view);
	void BufferAllShapes(Shader shader, glm::mat4 projection, glm::mat4 view);
};