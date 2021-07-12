#version 430 core

// Inputs from vertexshader
in vec3 vColor;

out vec4 FragColor;

in vec3 TexCoords;

uniform samplerCube skybox;

void main()
{
    gl_FragColor = vec4(vColor, 1.0);
}