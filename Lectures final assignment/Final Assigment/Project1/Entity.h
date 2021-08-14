#pragma once
//#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>
#include "Shader.h"
#include "Animation.h"
#include "Animate_Scaling.h"
#include "Animate_Rotating.h"
#include "Animate_GoUpAndReset.h"
#include "Animate_GoUpAndThenDown.h"
#include <vector>
#include "texture/TextureLoader.h"

class Entity
{
public:
	// Properties
	glm::mat4 model = glm::mat4(1.0);
	glm::mat4 mvp, mv;
	GLuint vao;
	GLuint uniform_mvp, uniform_mv;
	GLuint texture_id;
	string texture_path;
	bool TextureEnabled = false;

	// To see what it all means: https://learnopengl.com/Lighting/Basic-Lighting.
	glm::vec3 light_position = glm::vec3(4, 4, 4);
	glm::vec3 ambient_color = glm::vec3(0.2, 0.2, 0.1);
	glm::vec3 diffuse_color = glm::vec3(0.5, 0.5, 0.3);
	glm::vec3 specular = glm::vec3(0.7, 0.7, 0.7);
	float power = 64; // Old value: float power = 1024;

	std::vector<Animation*> animations = {};

	const char* basic_vertexshader_name = "basicvs.vert";
	const char* basic_fragshader_name = "basicfs.frag";

	const char* basic_texture_vertexshader_name = "basictexturevs.vert";
	const char* basic_texture_fragshader_name = "basictexturefs.frag";

	const char* phong_vertexshader_name = "phongvs.vert";
	const char* phong_fragshader_name = "phongfs.frag";

	bool BasicShading = false;
	Shader shader;

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