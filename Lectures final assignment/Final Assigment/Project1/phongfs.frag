#version 430 core

uniform vec3 mat_ambient;
uniform vec3 mat_diffuse;
uniform vec3 mat_specular;
uniform float mat_power;

uniform bool texture_enabled;
uniform sampler2D myTextureSampler;

in vec2 UV;

in VS_OUT
{
vec3 N;
vec3 L;
vec3 V;
} fs_in;

void main()
{
	// Normalize the incoming N and L vectors
	vec3 N = normalize(fs_in.N);
	vec3 L = normalize(fs_in.L);
	vec3 V = normalize(fs_in.V);

	// Compute the diffuse component for each fragment.
	// Turn the 0.0 higher to make the back of the object not as dark!
	vec3 diffuse;
	if(texture_enabled){
		diffuse = max(dot(N, L), 0.3) * texture(myTextureSampler, UV).rgb;
	} else {
		diffuse = max(dot(N, L), 0.3) * mat_diffuse;
	}

	// Calculate R locally
	vec3 R = reflect(-L, N);

	// Compute the specular component for each fragment
	vec3 specular = pow(max(dot(R, V), 0.0), mat_power) * mat_specular;

	// Write final color to the framebuffer
	gl_FragColor = vec4(mat_ambient + diffuse + specular, 1.0);
}