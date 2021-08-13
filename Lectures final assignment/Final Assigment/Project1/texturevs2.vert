#version 430 core

uniform mat4 mv;
uniform mat4 model;
uniform vec3 light_pos;
uniform mat4 projection;

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec2 vertexUV;

out vec2 UV;

out VS_OUT
{
vec3 N;
vec3 L;
vec3 V;
} vs_out;

void main()
{
	// Calculate view-space coordinate
	vec4 P = mv * vec4(position, 1.0);

	// Calculate normal in view-space, model is used instead of mv to make sure the lightning doesn't move with you.
	vs_out.N = mat3(model) * normal;

	// Calculate light vector
	vs_out.L = light_pos - P.xyz;

	// Calculate view vector
	vs_out.V = -P.xyz;

	// Calculate the clip-space position of each vertex
	gl_Position = projection * P;

    UV = vertexUV;
}