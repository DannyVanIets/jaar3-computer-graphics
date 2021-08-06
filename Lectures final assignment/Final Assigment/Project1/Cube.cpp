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
		Setup(Cube_Vertices_For_Textures, {}, Cube_Elements_for_Textures, Cube_uvs);

		DoTranslation(x, y, z); // TODO: Make it all use translation!
	}
	else 
	{
		Setup(Cube_Vertices, {}, Cube_Elements, {});

		float LengthMinusZ = z - Length;

		GLfloat newVertices[] = {
			// Front
			x,         y,          z, // Bottom left
			x + Width, y,          z, // Bottom Right
			x + Width, y + Height, z, // Top Right
			x,         y + Height, z, // Top Left
			// Back
			x,         y,          LengthMinusZ, // Bottom left
			x + Width, y,          LengthMinusZ, // Bottom Right
			x + Width, y + Height, LengthMinusZ, // Top Right
			x,         y + Height, LengthMinusZ, // Top Left
		};

		std::copy_n(newVertices, sizeof(newVertices) / 4, this->Vertices);
	}
}

Cube::Cube(float x, float y, float z, float width, float height, float length, bool withTexture)
{
	Width = width;
	Height = height;
	Length = length;

	WithTexture = withTexture;

	if (WithTexture)
	{
		Setup(Cube_Vertices_For_Textures, {}, Cube_Elements_for_Textures, Cube_uvs);

		DoScaling(Width, Height, Length);
		DoTranslation(x, y, z);
	}
	else
	{
		Setup(Cube_Vertices, {}, Cube_Elements, {});

		float LengthMinusZ = z - Length;

		GLfloat newVertices[] = {
			// Front
			x,         y,          z, // Bottom left
			x + Width, y,          z, // Bottom Right
			x + Width, y + Height, z, // Top Right
			x,         y + Height, z, // Top Left
			// Back
			x,         y,          LengthMinusZ, // Bottom left
			x + Width, y,          LengthMinusZ, // Bottom Right
			x + Width, y + Height, LengthMinusZ, // Top Right
			x,         y + Height, LengthMinusZ, // Top Left
		};

		std::copy_n(newVertices, sizeof(newVertices) / 4, this->Vertices);
	}
}