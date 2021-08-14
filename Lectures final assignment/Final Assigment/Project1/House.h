#pragma once
#include "Model.h"

class House : public Model
{
public:
	// Variabeles

	/// <summary>
	/// Used if you want more blocks in your house.
	/// </summary>
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
	void AddFloors();
	void AddRoof();
	void AddChimney();
	void AddSmoke();
};