#pragma once
#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>

#include "Shape.h"

class Trapezoid3D : public Shape
{
    std::vector<GLfloat> Trapezoid_Vertices = {
        
    };

    std::vector<GLushort> Trapezoid_elements = {
        
    };

    // Constructors
    Trapezoid3D() = default;
    Trapezoid3D(float x, float y, float z);
    Trapezoid3D(float x, float y, float z, float height, float width, float length);
};