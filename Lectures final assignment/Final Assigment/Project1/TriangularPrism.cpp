#include "TriangularPrism.h"

TriangularPrism::TriangularPrism(float x, float y, float z)
{
    Setup(TriangularPrism_Vertices, {}, TriangularPrism_Elements, {});


}

TriangularPrism::TriangularPrism(float x, float y, float z, float height, float width, float length)
{
    Setup(TriangularPrism_Vertices, {}, TriangularPrism_Elements, {});

    Height = height;
    Width = width;
    Length = length;

    // TODO: Make it possible to change the x, y and z positions, just like the cube.
}