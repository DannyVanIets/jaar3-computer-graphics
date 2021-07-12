#version 430 core

out vec4 gl_FragColor;

// Inputs from vertexshader
in vec3 TexCoords;

uniform samplerCube skybox;

void main()
{
    gl_FragColor = texture(skybox, TexCoords);
}