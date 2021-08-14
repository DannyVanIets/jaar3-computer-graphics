#pragma once
#include "Model.h"

class Chair : public Model
{
public:
	// Constructors
	Chair() = default;
	Chair(float x, float y, float z);
	Chair(float x, float y, float z, float width, float height, float length);

	// Methods
	void AddAllEntities();
};