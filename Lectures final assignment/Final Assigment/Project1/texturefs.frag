#version 430 core

// Inputs from vertexshader
in vec2 UV;

// Output
out vec3 FragColor;

// Values that stay constant for the whole mesh.
uniform sampler2D myTextureSampler;

void main()
{
    // Output FragColor = color of the texture at the specified UV
    FragColor = texture2D(myTextureSampler, UV).rgb;
}