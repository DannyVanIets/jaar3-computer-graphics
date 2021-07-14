#include "Skybox.h"
#include "glsl.h"
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <string>

#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <iostream>

// For the skybox: https://learnopengl.com/Advanced-OpenGL/Cubemaps

unsigned int Skybox::loadCubemap(vector<std::string> faces)
{
	unsigned int textureID;

	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);

	int width, height, nrChannels;

	// for stbi_load: https://learnopengl.com/getting-started/textures
	for (unsigned int i = 0; i < faces.size(); i++) {

		unsigned char *data = stbi_load(faces[i].c_str(), &width, &height, &nrChannels, 0);

		if (data) {
			glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			stbi_image_free(data);
		}
		else {
			std::cout << "Cubemap tex failed to load at path: " << faces[i] << std::endl;
			stbi_image_free(data);
		}
	}

	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	return textureID;
}

void Skybox::RenderCubemap(GLuint shader_id, GLuint uniform_mvp, glm::mat4 projection, glm::mat4 view, glm::mat4 mvp)
{
	glUniformMatrix4fv(uniform_mvp, 1, GL_FALSE, glm::value_ptr(mvp));
	
	// Skybox.
	glDepthMask(GL_LEQUAL);
	glUseProgram(shader_id);
	glBindVertexArray(vao);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture);
	glDrawArrays(GL_TRIANGLES, 0, 36);

	//glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, 0);

	glBindVertexArray(0);
	glDepthMask(GL_LESS);
}

void Skybox::InitBuffers(GLuint shader_id, GLuint uniform_mvp, glm::mat4 mvp)
{
	GLuint position_id;

	// Get vertex attributes
	position_id = glGetAttribLocation(shader_id, "skybox");

	GLuint vbo_vertices;

	// vbo for vertices.
	glGenBuffers(1, &vbo_vertices);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_vertices);
	glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// Allocate memory for vao.
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	// Bind vertices to vao.
	glBindBuffer(GL_ARRAY_BUFFER, vbo_vertices);
	glVertexAttribPointer(position_id, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(position_id);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// Stop bind to vao
	glBindVertexArray(0);

	glUniform1i(position_id, 0);

	// Make uniform vars
	/*uniform_mvp = glGetUniformLocation(shader_id, "mvp");

	// Send mvp
	glUseProgram(shader_id);
	glUniformMatrix4fv(uniform_mvp, 1, GL_FALSE, glm::value_ptr(mvp));*/
}

void Skybox::InitBuffers2(GLuint shader_id)
{
	unsigned int skyboxVBO;

	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &skyboxVBO);
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, skyboxVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
}