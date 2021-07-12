#version 430 core

uniform mat4 mvp;

// Per-vertex inputs
// in vec3 position;
in vec3 color;

layout (location = 0) in vec3 position;

// Outputs
out vec3 vColor;

out vec3 TexCoords;

void main()
{
    TexCoords = position;
    gl_Position = mvp * vec4(position, 1.0);

    vColor = color;
}