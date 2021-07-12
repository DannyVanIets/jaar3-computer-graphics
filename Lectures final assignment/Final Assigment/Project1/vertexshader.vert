#version 430 core

uniform mat4 mvp;

// Per-vertex inputs
in vec3 position;
in vec3 color;

// Outputs
out vec3 vColor;

out vec3 TexCoords;

void main()
{
    TexCoords = position;
    gl_Position = mvp * vec4(position, 1.0);

    vColor = color;
}