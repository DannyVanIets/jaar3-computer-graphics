#include "Cube.h"

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "glsl.h"

#include <glm/gtc/matrix_transform.hpp>

Cube::Cube(float x, float y, float z, bool withTexture)
{
	WithTexture = withTexture;

	if (WithTexture)
	{
		Setup(Cube_Vertices, Cube_Normals, Cube_Elements, {});
	}
	else 
	{
		Setup(Cube_Vertices, Cube_Normals, Cube_Elements, {});
	}

	DoTranslation(x, y, z);
	ChangeColor(glm::vec3(0.0, 1.0, 0.0));
}

Cube::Cube(float x, float y, float z, float width, float height, float length, bool withTexture)
{
	Width = width;
	Height = height;
	Length = length;

	WithTexture = withTexture;

	if (WithTexture)
	{
		Setup(Cube_Vertices_For_Textures, Cube_Normals, Cube_Elements_for_Textures, {});
	}
	else
	{
		Setup(Cube_Vertices, Cube_Normals, Cube_Elements, {});
	}

	DoTranslation(x, y, z);
	DoScaling(Width, Height, Length);

	/* ------------------------ Why translation first? --------------------------------------
	Remember that matrix multiplication is applied in reverse.This time a translation is thus
	applied first to the container positioning it in the bottom - right corner of the screen.
	After the translation the rotation is applied to the translated container.

	A rotation transformation is also known as a change - of - basis transformation
	for when we dig a bit deeper into linear algebra.Since we're changing the
	basis of the container, the next resulting translations will translate the container
	based on the new basis vectors.Once the vector is slightly rotated, the vertical
	translations would also be slightly translated for example.
	Source: https://learnopengl.com/Getting-started/Transformations.
	*/
}