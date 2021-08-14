#pragma once
#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>

#include "Shape.h"

class Pyramid : public Shape
{
public:
    std::vector<GLfloat> Pyramid_Vertices = { // X, Y, Z.
        // front
        -1.0, -1.0,  1.0, // bottom left
         1.0, -1.0,  1.0, // bottom right
         0.0,  1.0,  0.0, // top middle
        // back
        -1.0, -1.0, -1.0, // bottom left
         1.0, -1.0, -1.0, // bottom right
    };

    std::vector<GLfloat> Pyramid_Colors = {
        // front colors
        0.0, 0.7, 0.0,
        0.0, 0.7, 0.0,
        0.0, 0.7, 0.0,
        0.0, 0.7, 0.0,
        // right side colors
        0.0, 0.7, 0.0,
        0.0, 0.7, 0.0,
        0.0, 0.7, 0.0,
        0.0, 0.7, 0.0,
        // left side colors
        0.0, 0.7, 0.0,
        0.0, 0.7, 0.0,
        0.0, 0.7, 0.0,
        0.0, 0.7, 0.0,
        // back colors
        0.0, 0.7, 0.0,
        0.0, 0.7, 0.0,
        0.0, 0.7, 0.0,
        0.0, 0.7, 0.0,
        // top colors
        0.0, 0.7, 0.0,
        0.0, 0.7, 0.0,
        0.0, 0.7, 0.0,
        0.0, 0.7, 0.0,
        // bottom colors
        0.0, 0.7, 0.0,
        0.0, 0.7, 0.0,
        0.0, 0.7, 0.0,
        0.0, 0.7, 0.0,
    };

    std::vector<GLushort> Pyramid_Elements = {
		0,1,2, // front
		1,4,2, // right side
		4,3,2, // back
		3,0,2, // left side
		3,4,1, 3,1,0 // bottom
	};

    std::vector<GLfloat> Pyramid_uvs = {
        // U, V,
        // front
        0.0f, 0.0f, // bottom left
        1.0f, 0.0f, // bottom right
        1.0f, 1.0f, // top right
        0.0f, 1.0f, // top left
    };

	// Constructors
	Pyramid() = default;
	Pyramid(float x, float y, float z);
	Pyramid(float x, float y, float z, float width, float height, float length);
};