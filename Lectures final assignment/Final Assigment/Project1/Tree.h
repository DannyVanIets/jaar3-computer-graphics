#pragma once
#include "Model.h"

class Tree : public Model
{
public:
	// Properties.
	
	/// <summary>
	/// Used to have two different kind of trees, one consisting of objects and the other of metrices.
	/// </summary>
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