#include "Shape.h"

void Shape::Setup(std::vector<GLfloat> newVertices, std::vector<GLfloat> newColors, std::vector<GLushort> newElements, std::vector<GLfloat> newUvs = {})
{
	std::copy(newVertices.begin(), newVertices.end(), Vertices);

	if (newColors.size() > 0) {
		std::copy(newColors.begin(), newColors.end(), Colors);
	}

	if (newElements.size() > 0) {
		std::copy(newElements.begin(), newElements.end(), Elements);
	}

	if (newUvs.size() > 0) {
		std::copy(newUvs.begin(), newUvs.end(), uvs);

		// TODO: THIS DOES NOT WORK YET! FIX THIS GARBAGE.
		for (int i = 1; i < 6; i++) {
			memcpy(&uvs[i * 4 * 2], &uvs[0], 2 * 4 * sizeof(GLfloat));
		}
	}
}

void Shape::Render(glm::mat4 projection, glm::mat4 view)
{
	CalculateMvp(projection, view);

	glUniformMatrix4fv(uniform_mvp, 1, GL_FALSE, glm::value_ptr(mvp));

	// Send vao
	glBindVertexArray(vao);

	glDrawElements(
		GL_TRIANGLES,
		sizeof(Elements) / sizeof(GLushort),
		GL_UNSIGNED_SHORT,
		0);

	glBindVertexArray(0);
}

void Shape::InitBuffer(Shader shader, glm::mat4 projection, glm::mat4 view)
{
	CalculateMvp(projection, view);

	if (WithTexture) {
		InitBufferWithTexture(shader);
	}
	else {
		InitBufferWithoutTexture(shader);
	}
}

void Shape::InitBufferWithoutTexture(Shader shader)
{
	GLuint position_id;
	GLuint color_id;

	// Get vertex attributes
	position_id = glGetAttribLocation(shader.ID, "position");
	color_id = glGetAttribLocation(shader.ID, "color");

	GLuint ibo_elements;
	GLuint vbo_vertices;
	GLuint vbo_colors;

	// vbo for vertices
	glGenBuffers(1, &vbo_vertices);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_vertices);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// vbo for colors
	glGenBuffers(1, &vbo_colors);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_colors);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Colors), Colors, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// vbo for cube elements
	glGenBuffers(1, &ibo_elements);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo_elements);
	glBufferData(
		GL_ELEMENT_ARRAY_BUFFER, sizeof(Elements),
		Elements, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	// Allocate memory for vao
	glGenVertexArrays(1, &vao);

	// Bind to vao
	glBindVertexArray(vao);

	// Bind vertices to vao
	glBindBuffer(GL_ARRAY_BUFFER, vbo_vertices);
	glVertexAttribPointer(position_id, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(position_id);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// Bind colors to vao
	glBindBuffer(GL_ARRAY_BUFFER, vbo_colors);
	glVertexAttribPointer(color_id, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(color_id);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// Bind cube elements.
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo_elements);

	// Stop bind to vao
	glBindVertexArray(0);

	// Make uniform vars
	uniform_mvp = glGetUniformLocation(shader.ID, "mvp");

	// Send mvp
	shader.Use();
	glUniformMatrix4fv(uniform_mvp, 1, GL_FALSE, glm::value_ptr(mvp));
}

void Shape::InitBufferWithTexture(Shader shader)
{
	GLuint position_id;
	GLuint uv_id;

	// Get vertex attributes
	position_id = glGetAttribLocation(shader.ID, "vertexPosition");
	uv_id = glGetAttribLocation(shader.ID, "vertexUV");

	GLuint ibo_elements;
	GLuint vbo_vertices;
	GLuint vbo_uvs;

	// vbo for vertices
	glGenBuffers(1, &vbo_vertices);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_vertices);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// vbo for uvs
	glGenBuffers(1, &vbo_uvs);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_uvs);
	glBufferData(GL_ARRAY_BUFFER, sizeof(uvs), uvs, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// vbo for cube elements
	glGenBuffers(1, &ibo_elements);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo_elements);
	glBufferData(
		GL_ELEMENT_ARRAY_BUFFER, sizeof(Elements),
		Elements, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	// Allocate memory for vao
	glGenVertexArrays(1, &vao);

	// Bind to vao
	glBindVertexArray(vao);

	// Bind vertices to vao
	glBindBuffer(GL_ARRAY_BUFFER, vbo_vertices);
	glVertexAttribPointer(position_id, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(position_id);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// Bind uvs to vao
	glBindBuffer(GL_ARRAY_BUFFER, vbo_uvs);
	glVertexAttribPointer(uv_id, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(uv_id);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// Bind cube elements.
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo_elements);

	// Stop bind to vao
	glBindVertexArray(0);

	// Make uniform vars
	uniform_mvp = glGetUniformLocation(shader.ID, "mvp");

	// Send mvp
	shader.Use();
	glUniformMatrix4fv(uniform_mvp, 1, GL_FALSE, glm::value_ptr(mvp));
}