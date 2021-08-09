#pragma once

#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include <string>

#include "Entity.h"
#include "Shader.h"

class Object : public Entity
{
public:
	// Properties
	std::string path = "objects/teapot.obj";
	
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals;

	glm::vec3 light_position = glm::vec3(4, 4, 4);
	glm::vec3 ambient_color = glm::vec3(0.2, 0.2, 0.1);
	glm::vec3 diffuse_color = glm::vec3(0.5, 0.5, 0.3);
	glm::vec3 specular = glm::vec3(0.7, 0.7, 0.7);
	float power = 1024;

	const char* object_vertexshader_name = "objectvs.vert"; // TODO: Move this to a better place, kill it.
	const char* object_fragshader_name = "objectfs.frag";

	Shader shader;
	
	// Constructors
	Object() = default;
	Object(std::string path);
	Object(std::string path, float x, float y, float z);
	Object(std::string path, float x, float y, float z, float width, float height, float length);

	// Methods
	void LoadObject();

	void Render(glm::mat4 projection, glm::mat4 view) override;
	void InitBuffers(glm::mat4 projection, glm::mat4 view) override;
};