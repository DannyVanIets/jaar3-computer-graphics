#pragma once
#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>
#include "Shader.h"
#include "Animation.h"
#include "Animate_Scaling.h"
#include "Animate_Rotating.h"
#include "Animate_GoUpAndReset.h"
#include "Animate_GoUpAndThenDown.h"
#include <vector>
#include "texture/TextureLoader.h"

/// <summary>
/// This class is used by every object and shape.
/// </summary>
class Entity
{
public:
	// Properties
	glm::mat4 model = glm::mat4(1.0);
	glm::mat4 mvp, mv;
	GLuint vao;
	GLuint uniform_mvp, uniform_mv;

	// Texture properties.
	GLuint texture_id;
	string texture_path;
	bool TextureEnabled = false;

	// To see what it all means: https://learnopengl.com/Lighting/Basic-Lighting.
	glm::vec3 light_position = glm::vec3(4, 4, 4);
	glm::vec3 ambient_color = glm::vec3(0.2, 0.2, 0.1);
	glm::vec3 diffuse_color = glm::vec3(0.5, 0.5, 0.3);
	glm::vec3 specular = glm::vec3(0.7, 0.7, 0.7);
	float power = 64; // Old value: float power = 1024;

	/// <summary>
	/// List of animations that will be used during the rendering of the entity.
	/// </summary>
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
	
	/// <summary>
	/// Used if you want to scale the entity.
	/// </summary>
	/// <param name="x">X axis, for left or right.</param>
	/// <param name="y">Y axis, for up or down.</param>
	/// <param name="z">Y axis, for forward or backwards.</param>
	void DoScaling(float x, float y, float z);

	/// <summary>
	/// Used if you want to rotate the entity.
	/// </summary>
	/// <param name="radians">The radians of how much you want to turn it.</param>
	/// <param name="x">X axis, for left or right.</param>
	/// <param name="y">Y axis, for up or down.</param>
	/// <param name="z">Y axis, for forward or backwards.</param>
	void DoRotation(float radians, float x, float y, float z);

	/// <summary>
	/// Used if you want to translate the entity, very useful to move it somewhere else.
	/// </summary>
	/// <param name="x">X axis, for left or right.</param>
	/// <param name="y">Y axis, for up or down.</param>
	/// <param name="z">Y axis, for forward or backwards.</param>
	void DoTranslation(float x, float y, float z);

	/// <summary>
	///  Change the color of the entity. Only possible if you don't use the basic shading!
	/// </summary>
	/// <param name="rgb">vec3 where the first value is Red, second is Green and third is blue.</param>
	void ChangeColor(glm::vec3 rgb);

	/// <summary>
	/// Calculate the MV based on the view from the camera.
	/// </summary>
	/// <param name="view">Will be multiplied by the model.</param>
	void CalculateMv(glm::mat4 view);

	/// <summary>
	/// Calculate the MVP based on the view and projection from the camera.
	/// </summary>
	/// <param name="projection">Will be multiplied by the model and view.</param>
	/// <param name="view">Will be multiplied by the model and projection.</param>
	void CalculateMvp(glm::mat4 projection, glm::mat4 view);

	/// <summary>
	/// Render the entity with the projection and the view from camera to recalculate the MV or MVP.
	/// </summary>
	virtual void Render(glm::mat4 projection, glm::mat4 view) = 0;
	virtual void InitBuffers(glm::mat4 projection, glm::mat4 view) = 0;
};