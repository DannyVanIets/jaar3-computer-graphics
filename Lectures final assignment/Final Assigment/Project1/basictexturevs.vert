#version 430 core

// Per-vertex inputs, different for all executions of this shader.
layout(location = 0) in vec3 vertexPosition;
layout(location = 1) in vec2 vertexUV;

// Outputs
out vec2 UV;

// Values that stay constant for the whole mesh.
uniform mat4 mvp;

void main()
{
    // Output position of the vertex, in clip space : MVP * vertexPosition
    gl_Position = mvp * vec4(vertexPosition, 1);

    UV = vertexUV;
}