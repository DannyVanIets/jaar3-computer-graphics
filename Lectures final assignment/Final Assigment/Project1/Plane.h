#pragma once
#include "Shape.h"

class Plane : public Shape
{
public:
    std::vector<GLfloat> PlaneVertices = {
        -1.0,  0.0, -1.0, // 0
         1.0,  0.0, -1.0, // 1
         1.0,  0.0,  1.0, // 2

         1.0,  0.0,  1.0, // 2
        -1.0,  0.0,  1.0, // 3
        -1.0,  0.0, -1.0, // 0
    };

    std::vector<GLfloat> PlaneColors = {
        
    };

    std::vector<GLushort> Plane_Elements = {
        0,1,2,
        0,2,3
    };

    std::vector<GLfloat> Plane_Uvs = {
        0.0f, 0.0f, // bottom left
        1.0f, 0.0f, // bottom right
        1.0f, 1.0f, // top right

        1.0f, 1.0f,
        0.0f, 1.0f,
        0.0f, 0.0f,
    };
    
    Plane() = default;
    Plane(float x, float y, float z);
    Plane(float x, float y, float z, string texture_name);
    Plane(float x, float y, float z, float width, float height, float length);
    Plane(float x, float y, float z, float width, float height, float length, string texture_name);
};