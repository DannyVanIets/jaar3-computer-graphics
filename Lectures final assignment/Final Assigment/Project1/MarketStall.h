#pragma once
#include "Model.h"

class MarketStall : public Model
{
public:
	// Constructors
	MarketStall() = default;
	MarketStall(float x, float y, float z);
	MarketStall(float x, float y, float z, float width, float height, float length);

	// Methods
	void AddAllEntities();
};