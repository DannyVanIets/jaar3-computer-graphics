#include "Cube.h"

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "glsl.h"

#include <glm/gtc/matrix_transform.hpp>

Cube::Cube(float height = 1.0, float width = 1.0, float length = 1.0, float x = 1.0, float y = 1.0, float z = 1.0)
{
    Setup(Cube_Vertices, {}, Cube_elements, Cube_uvs);

    Height = height;
    Width = width;
    Length = length;

    float LengthMinusZ = z - Length;

    GLfloat newVertices[] = {
        // Front
        x,         y,          z, // Bottom left
        x + Width, y,          z, // Bottom Right
        x + Width, y + Height, z, // Top Right
        x,        y + Height, z, // Top Left
        // Back
        x,         y,          LengthMinusZ, // Bottom left
        x + Width, y,          LengthMinusZ, // Bottom Right
        x + Width, y + Height, LengthMinusZ, // Top Right
        x,         y + Height, LengthMinusZ, // Top Left
    };

    std::copy_n(newVertices, sizeof(newVertices) / 4, this->Vertices);

    //for (int i = 1; i < 6; i++)
        //memcpy(&Cube_uvs[i * 4 * 2], &Cube_uvs[0], 2 * 4 * sizeof(GLfloat));
}