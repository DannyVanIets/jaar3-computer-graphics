#pragma once

#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include <string>

#include "Shader.h"

class Object
{
public:
	// Properties
	GLuint vao;
	GLuint uniform_mv;
	std::string path = "objects/teapot.obj";
	
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals;

	glm::vec3 light_position = glm::vec3(4, 4, 4);
	glm::vec3 ambient_color = glm::vec3(0.2, 0.2, 0.1);
	glm::vec3 diffuse_color = glm::vec3(0.5, 0.5, 0.3);
	glm::vec3 specular = glm::vec3(0.7, 0.7, 0.7);
	float power = 1024;
	
	// Constructors
	Object() = default;
	Object(std::string path);

	// Methods
	void LoadObject();
	void Render(glm::mat4 mvp);
	void InitBuffers(Shader shader, glm::mat4 mvp, glm::mat4 projection);
};