#pragma once
#include "glsl.h"
#include <string>

/// <summary>
/// Class used to load in vertexshaders and fragmentshaders.
/// </summary>
class Shader
{
public:
	GLuint ID;

	Shader() = default;
	Shader(const char* vertexPath, const char* fragmentPath);

	/// <summary>
	/// Activate the shader ID.
	/// </summary>
	void Use();
};