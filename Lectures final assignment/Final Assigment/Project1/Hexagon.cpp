#include "Hexagon.h"

Hexagon::Hexagon(float x, float y, float z)
{
	Setup(Hexagon_Vertices, {}, Hexagon_Elements, {});

    float MiddleLeft = x + Width / 4;

    float MiddleRight = x + Width / 4 * 3;
    float TopMiddleX = x + Width / 2;

    float MiddleZ = z - Length / 2;
    float LengthMinusZ = z - Length;

    GLfloat newVertices[] = {
        // front
        MiddleLeft,  y,          z, // bottom left, 0
        MiddleRight, y,          z, // bottom right, 1
        // right side
        x + Width,   y,          MiddleZ, // bottom middle, 2
        // back
        MiddleRight, y,          LengthMinusZ, // bottom right, 3
        MiddleLeft,  y,          LengthMinusZ, // bottom left, 4
        // left side
        x,           y,          MiddleZ, // bottom middle, 5

        // front
        MiddleLeft,  y + Height, z, // top left, 6
        MiddleRight, y + Height, z, // top right, 7
        // right side
        x + Width,   y + Height, MiddleZ, // top middle, 8
        // back
        MiddleRight, y + Height, LengthMinusZ, // top right, 9
        MiddleLeft,  y + Height, LengthMinusZ, // top left, 10
        // left side
        x,           y + Height, MiddleZ, // top middle, 11

        // bottom middle, 12
        TopMiddleX,  y,          MiddleZ,

        // bottom middle, 13
        TopMiddleX,  y + Height, MiddleZ,
    };

    std::copy_n(newVertices, sizeof(newVertices) / 4, this->Vertices);
}

Hexagon::Hexagon(float x, float y, float z, float width, float height, float length)
{
	Setup(Hexagon_Vertices, {}, Hexagon_Elements, {});

	Height = height;
	Width = width;
	Length = length;

    float MiddleLeft = x + Width / 4;

    float MiddleRight = x + Width / 4 * 3;
    float TopMiddleX = x + Width / 2;

    float MiddleZ = z - Length / 2;
    float LengthMinusZ = z - Length;

    GLfloat newVertices[] = {
        // front
        MiddleLeft,  y,          z, // bottom left, 0
        MiddleRight, y,          z, // bottom right, 1
        // right side
        x + Width,   y,          MiddleZ, // bottom middle, 2
        // back
        MiddleRight, y,          LengthMinusZ, // bottom right, 3
        MiddleLeft,  y,          LengthMinusZ, // bottom left, 4
        // left side
        x,           y,          MiddleZ, // bottom middle, 5

        // front
        MiddleLeft,  y + Height, z, // top left, 6
        MiddleRight, y + Height, z, // top right, 7
        // right side
        x + Width,   y + Height, MiddleZ, // top middle, 8
        // back
        MiddleRight, y + Height, LengthMinusZ, // top right, 9
        MiddleLeft,  y + Height, LengthMinusZ, // top left, 10
        // left side
        x,           y + Height, MiddleZ, // top middle, 11

        // bottom middle, 12
        TopMiddleX,  y,          MiddleZ,

        // bottom middle, 13
        TopMiddleX,  y + Height, MiddleZ,
    };

    std::copy_n(newVertices, sizeof(newVertices) / 4, this->Vertices);
}