#pragma once
#include "Model.h"

class House : public Model
{
public:
	// Variabeles
	int AmountOfFloors = 1;

	// Constructors
	House() = default;
	House(float x, float y, float z);
	House(float x, float y, float z, float width, float height, float length);
	House(int amountOfFloors);
	House(int amountOfFloors, float x, float y, float z);
	House(int amountOfFloors, float x, float y, float z, float width, float height, float length);

	// Shapes.
	void AddAllEntities();
	void AddGarage();
	void AddFloors();
	void AddRoof();
	void AddChimney();
	void AddSmoke();
};