#include "MarketStall.h"
#include "Cube.h"
#include "Hexagon.h"
#include "Wedge.h"
#include "Object.h"
#include "Animate_Scaling.h"

MarketStall::MarketStall(float x, float y, float z)
{
	X = x;
	Y = y;
	Z = z;

	AddAllEntities();
}

MarketStall::MarketStall(float x, float y, float z, float width, float height, float length)
{
	X = x;
	Y = y;
	Z = z;

	Height = height;
	Width = width;
	Length = length;

	AddAllEntities();
}

void MarketStall::AddAllEntities()
{
	// Table
	Entities.push_back(new Cube(X, Y - Height / 2, Z, Width * 1.5, Height / 2, Length, true));

	// Pillars
	float pillarDivider = 10;

	float pillarY = Y + Height;
	float pillarX = Width * 1.4;
	float pillarZ = Length * 0.8;

	Entities.push_back(new Hexagon(X - pillarX, pillarY, Z + pillarZ, Width / pillarDivider, Height, Length / pillarDivider, true)); // Bottom left
	Entities.push_back(new Hexagon(X - pillarX, pillarY, Z - pillarZ, Width / pillarDivider, Height, Length / pillarDivider, true)); // Top left
	
	Entities.push_back(new Hexagon(X + pillarX, pillarY, Z + pillarZ, Width / pillarDivider, Height, Length / pillarDivider, true)); // Bottom Right
	Entities.push_back(new Hexagon(X + pillarX, pillarY, Z - pillarZ, Width / pillarDivider, Height, Length / pillarDivider, true)); // Top Right

	// Roof;
	Entities.push_back(new Wedge(X, Y + Height * 2.5, Z, Width * 1.5, Height / 2, Length, 90, 0.0, 1.0, 0.0, true));

	// Items for sale on the table.
	Entities.push_back(new Object("teapot", X - 1.0, Y, Z, Width / 4, Height / 4, Length / 4, glm::vec3(0.0, 0.0, 1.0)));
	Entities.push_back(new Object("torus", X, Y + 0.075, Z, Width / 4, Height / 4, Length / 4, glm::vec3(0.4, 0.2, 0.2))); // Supposed to be a donut.
	//Entities.push_back(new Object("ufo", X, Y + 0.5, Z, Width / 4, Height / 4, Length / 4, glm::vec3(0.4, 0.2, 0.2))); // TODO: Implement the ufo.
}