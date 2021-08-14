#pragma once
#include <vector>

#include "Entity.h"

#include "Cube.h"
#include "Hexagon.h"
#include "Wedge.h"
#include "Object.h"
#include "Animate_Scaling.h"
#include "TriangularPrism.h"
#include "Icosahedron.h"
#include "Pyramid.h"
#include "Plane.h"

#include "Animate_ScaleHeightAndReset.h"
#include "Animate_MoveLeftAndReset.h"

/// <summary>
/// Used as a base class for if you want to make a model.
/// Don't need to override anything!
/// </summary>
class Model
{
public:
	// Properties

	/// <summary>
	/// X,Y and Z are used to calculate the translation place for the entities.
	/// Width, Height, Length are used in-case for scaling.
	/// </summary>
	float X = 0.0, Y = 0.0, Z = 0.0;
	float Width = 1.0, Height = 1.0, Length = 1.0;

	/// <summary>
	/// The list of entities attached to this model.
	/// Will be used in RenderAll and InitBufferAll to render and buffer them all.
	/// </summary>
	std::vector<Entity*> Entities = {};

	// Methods

	/// <summary>
	/// Used to render all the entities in this model.
	/// </summary>
	/// <param name="projection">The camera projection, used to calculate the MVP or MV.</param>
	/// <param name="view">The camera view, used to calculate the MVP or MV.</param>
	void RenderAll(glm::mat4 projection, glm::mat4 view);

	/// <summary>
	/// Used to init buffer all the entities in this model.
	/// </summary>
	/// <param name="projection">The camera projection, used to calculate the MVP or MV.</param>
	/// <param name="view">The camera view, used to calculate the MVP or MV.</param>
	void InitBufferAll(glm::mat4 projection, glm::mat4 view);
};