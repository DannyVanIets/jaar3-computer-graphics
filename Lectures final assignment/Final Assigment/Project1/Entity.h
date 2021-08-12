#pragma once
//#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>
#include "Shader.h"
#include "Animation.h"
#include "Animate_Scaling.h"

class Entity
{
public:
	// Properties
	glm::mat4 model = glm::mat4(1.0);
	glm::mat4 mvp, mv;
	GLuint vao;
	GLuint uniform_mvp, uniform_mv;

	/* Old values:
	glm::vec3 light_position = glm::vec3(4, 4, 4);
	glm::vec3 ambient_color = glm::vec3(0.2, 0.2, 0.1);
	glm::vec3 diffuse_color = glm::vec3(0.5, 0.5, 0.3);
	glm::vec3 specular = glm::vec3(0.7, 0.7, 0.7);
	float power = 1024;
	*/

	// To see what it all means: https://learnopengl.com/Lighting/Basic-Lighting.
	glm::vec3 light_position = glm::vec3(4, 4, 4);
	glm::vec3 ambient_color = glm::vec3(0.2, 0.2, 0.1);
	glm::vec3 diffuse_color = glm::vec3(0.5, 0.5, 0.3);
	glm::vec3 specular = glm::vec3(0.7, 0.7, 0.7);
	float power = 64;

	bool animationsOn = true;
	/*Animation animations[30] = {

	};*/
	Animate_Scaling animation = Animate_Scaling(false, false, false);

	// Methods
	void DoScaling(float x, float y, float z);
	void DoRotation(float radians, float x, float y, float z);
	void DoTranslation(float x, float y, float z);

	void ChangeColor(glm::vec3 rgb);

	void CalculateMv(glm::mat4 view);
	void CalculateMvp(glm::mat4 projection, glm::mat4 view);

	virtual void Render(glm::mat4 projection, glm::mat4 view) = 0;
	virtual void InitBuffers(glm::mat4 projection, glm::mat4 view) = 0;
};