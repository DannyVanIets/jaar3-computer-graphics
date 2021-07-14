#pragma once
#include <string>
#include "glsl.h"
#include <glm/detail/type_mat.hpp>

class Shader
{
public:
	GLuint ID;

	Shader() = default;
	Shader(const char* vertexPath, const char* fragmentPath);

	void Use(); // Activate the shader.
	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, bool value) const;
	void setFloat(const std::string& name, bool value) const;
	void setMat4(const std::string& name, const glm::mat4& mat) const;
};