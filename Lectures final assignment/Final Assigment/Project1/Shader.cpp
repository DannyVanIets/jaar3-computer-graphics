#include "Shader.h"

Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
    char* vertexshader = glsl::readFile(vertexPath);
	GLuint vsh_id = glsl::makeVertexShader(vertexshader);

	char* fragshader = glsl::readFile(fragmentPath);
	GLuint fsh_id = glsl::makeFragmentShader(fragshader);

	ID = glsl::makeShaderProgram(vsh_id, fsh_id);
}

void Shader::Use()
{
	glUseProgram(ID);
}