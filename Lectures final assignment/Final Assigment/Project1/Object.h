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
	std::vector<glm::vec3> normals;
	std::vector<glm::vec2> uvs;
	
	// Constructors
	Object() = default;
	Object(std::string path);
	Object(std::string path, float x, float y, float z);
	Object(std::string path, float x, float y, float z, string texture_name);
	Object(std::string path, float x, float y, float z, glm::vec3 rgb);
	Object(std::string path, float x, float y, float z, float width, float height, float length);
	Object(std::string path, float x, float y, float z, float width, float height, float length, string texture_name);
	Object(std::string path, float x, float y, float z, float width, float height, float length, glm::vec3 rgb);

	// Methods
	void LoadObject();

	void Render(glm::mat4 projection, glm::mat4 view) override;
	void InitBuffers(glm::mat4 projection, glm::mat4 view) override;
};