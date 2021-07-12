#version 430 core

// Inputs from vertexshader
in vec3 vColor;

void main()
{
    gl_FragColor = vec4(vColor, 1.0);
}