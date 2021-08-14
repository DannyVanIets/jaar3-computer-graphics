#include "Chair.h"

Chair::Chair(float x, float y, float z)
{
	X = x;
	Y = y;
	Z = z;

	AddAllEntities();
}

Chair::Chair(float x, float y, float z, float width, float height, float length)
{
	X = x;
	Y = y;
	Z = z;

	Height = height;
	Width = width;
	Length = length;

	AddAllEntities();
}

void Chair::AddAllEntities()
{
	// Pillars
	float pilarHeight = Height / 3;
	float pillarDivider = 20;
	float pillarX = Width * 1.1 / 3;
	float pillarZ = Length * 0.9 / 3;

	glm::vec3 brown = glm::vec3(0.8, 0.2, 0.2);
	Entities.push_back(new Hexagon(X - pillarX, Y - 0.66, Z + pillarZ, Width / pillarDivider, pilarHeight, Length / pillarDivider, brown)); // Bottom left
	Entities.push_back(new Hexagon(X - pillarX, Y - 0.66, Z - pillarZ, Width / pillarDivider, pilarHeight, Length / pillarDivider, brown)); // Top left

	Entities.push_back(new Hexagon(X + pillarX, Y - 0.66, Z + pillarZ, Width / pillarDivider, pilarHeight, Length / pillarDivider, brown)); // Bottom Right
	Entities.push_back(new Hexagon(X + pillarX, Y - 0.66, Z - pillarZ, Width / pillarDivider, pilarHeight, Length / pillarDivider, brown)); // Top Right

	// Sitting place
	Y += pilarHeight - 0.66;
	Entities.push_back(new Cube(X, Y, Z, Width / 2, Height / 15, Length / 2));

	// Backrest
	Entities.push_back(new Hexagon(X - pillarX, Y + 0.25, Z - pillarZ, Width / pillarDivider, pilarHeight / 2, Length / pillarDivider, brown)); // Top left
	Entities.push_back(new Hexagon(X + pillarX, Y + 0.25, Z - pillarZ, Width / pillarDivider, pilarHeight / 2, Length / pillarDivider, brown)); // Top Right

	Entities.push_back(new Cube(X, Y + 0.75, Z - 0.30, Width / 2, Height / 3, Length / 15));
}