#pragma once
#include "Model.h"

class House : public Model
{
public:
	// Variabeles
	int AmountOfFloors = 1;
	bool PyramidRoof = true;

	// Constructors
	House() = default;
	House(float x, float y, float z, bool pyramidRoof);
	House(float x, float y, float z, float width, float height, float length, bool pyramidRoof);
	House(int amountOfFloors, bool pyramidRoof);
	House(int amountOfFloors, float x, float y, float z, bool pyramidRoof);
	House(int amountOfFloors, float x, float y, float z, float width, float height, float length, bool pyramidRoof);

	// Shapes.
	void AddAllEntities();
	void AddGarage();
	void AddFloors();
	void AddRoof();
	void AddChimney();
	void AddSmoke();
};