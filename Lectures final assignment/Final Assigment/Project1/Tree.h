#pragma once
#include "Model.h"

class Tree : public Model
{
public:
	// Properties.
	//int AmountOfLeaves = 1; // TODO: Maybe implement this later.
	bool PyramidLeaves = true;

	// Constructors
	Tree() = default;
	Tree(bool pyramidLeaves);
	Tree(float x, float y, float z, bool pyramidLeaves);
	Tree(float x, float y, float z, float width, float height, float length, bool pyramidLeaves);

	// Methods
	void AddAllEntities();
	void AddTrunk();
	void AddLeaves();
};