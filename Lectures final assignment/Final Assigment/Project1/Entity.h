#pragma once
#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>
#include "Shader.h"

class Entity
{
public:
	// Properties
	glm::mat4 model = glm::mat4(1.0);
	glm::mat4 mvp, mv;
	GLuint vao;
	GLuint uniform_mvp, uniform_mv;

	// Constructors/Destructors

	// Methods
	void DoScaling(float x, float y, float z);
	void DoRotation(float radians, float x, float y, float z);
	void DoTranslation(float x, float y, float z);

	void CalculateMv(glm::mat4 view);
	void CalculateMvp(glm::mat4 projection, glm::mat4 view);

	virtual void Render(glm::mat4 projection, glm::mat4 view) = 0;
	virtual void InitBuffers(glm::mat4 projection, glm::mat4 view) = 0;
};