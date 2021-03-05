#version 430 core
uniform vec4 position;

uniform vec4 color;
out vec4 vColor;

void main()
{
    gl_Position = position;
    vColor = color;

}