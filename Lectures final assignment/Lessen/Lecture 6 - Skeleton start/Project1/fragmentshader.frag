#version 430 core

// Inputs from vertexshader
in vec4 vColor;

void main()
{
    gl_FragColor = vColor;
}
