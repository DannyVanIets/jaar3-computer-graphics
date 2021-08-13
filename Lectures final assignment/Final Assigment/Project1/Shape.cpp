#include "Shape.h"

void Shape::Setup(std::vector<GLfloat> newVertices, std::vector<GLfloat> newNormals, std::vector<GLushort> newElements, std::vector<GLfloat> newUvs = {})
{
	std::copy(newVertices.begin(), newVertices.end(), Vertices);

	if (newNormals.size() > 0) {
		std::copy(newNormals.begin(), newNormals.end(), Normals);
	}

	if (newElements.size() > 0) {
		std::copy(newElements.begin(), newElements.end(), Elements);
	}

	if (newUvs.size() > 0) {
		//td::copy(newUvs.begin(), newUvs.end(), uvs);
	}

	for (int i = 1; i < 12; i++) {
		//memcpy(&uvs[i * 3 * 2], &uvs[0], 2 * 3 * sizeof(GLfloat));
	}
}

void Shape::CalculateNormals()
{
	glm::vec3 a, b, n;
	std::vector<GLfloat> newNormals;

	for (int i = 0; i < VerticesSize; i += 9) {
		glm::vec3 p1, p2, p3;

		int j = i;
		p1 = glm::vec3(Vertices[j], Vertices[j + 1], Vertices[j + 2]);
		j += 3;
		p2 = glm::vec3(Vertices[j], Vertices[j + 1], Vertices[j + 2]);
		j += 3;
		p3 = glm::vec3(Vertices[j], Vertices[j + 1], Vertices[j + 2]);

		a.x = p2.x - p1.x;
		a.y = p2.y - p1.y;
		a.z = p2.z - p1.z;

		b.x = p3.x - p1.x;
		b.y = p3.y - p1.y;
		b.z = p3.z - p1.z;

		n.x = (a.y * b.z) - (a.z * b.y);
		n.y = (a.z * b.x) - (a.x * b.z);
		n.z = (a.x * b.y) - (a.y * b.x);

		// Normalize (divide by root of dot product)
		float o = sqrt(n.x * n.x + n.y * n.y + n.z * n.z);
		n.x /= o;
		n.y /= o;
		n.z /= o;

		int l = 3;

		for (int p = 0; p < l; p++) {
			newNormals.push_back(n.x);
			newNormals.push_back(n.y);
			newNormals.push_back(n.z);
		}
	}

	std::copy(newNormals.begin(), newNormals.end(), Normals);
}

void Shape::Render(glm::mat4 projection, glm::mat4 view)
{
	RenderWithShading(projection, view);
}

void Shape::RenderBasic(glm::mat4 projection, glm::mat4 view)
{
	CalculateMvp(projection, view);

	if (TextureEnabled) {
		glBindTexture(GL_TEXTURE_2D, texture_id);
	}
	shader.Use();

	// Send mvp
	glUniformMatrix4fv(uniform_mvp, 1, GL_FALSE, glm::value_ptr(mvp));

	// Send vao
	glBindVertexArray(vao);

	glDrawElements(GL_TRIANGLES, sizeof(Elements) / sizeof(GLushort), GL_UNSIGNED_SHORT, 0);

	glBindVertexArray(0);
}

void Shape::RenderWithShading(glm::mat4 projection, glm::mat4 view)
{
	shader.Use();

	CalculateMv(view);

	if (animations.size() > 0) {
		for (auto& ani : animations) {
			model = ani->DoAnimation(model);
		}
	}

	if (texture_id != 0) {
		glBindTexture(GL_TEXTURE_2D, texture_id);
	}

	glUniformMatrix4fv(uniform_mv, 1, GL_FALSE, glm::value_ptr(mv));

	// Send vao
	glBindVertexArray(vao);

	glDrawArrays(GL_TRIANGLES, 0, sizeof(Vertices));

	glBindVertexArray(0);
}

void Shape::InitBuffers(glm::mat4 projection, glm::mat4 view)
{
	if (!texture_path.empty())
	{
		TextureEnabled = true;
		texture_id = loadBMP(texture_path.c_str());
	}
	
	shader = Shader(phong_vertexshader_name, phong_fragshader_name);
	InitBufferWithShading(projection, view);
}

void Shape::InitBufferBasic(glm::mat4 projection, glm::mat4 view)
{
	CalculateMvp(projection, view);

	GLuint position_id;
	GLuint uv_id;

	// Get vertex attributes
	position_id = glGetAttribLocation(shader.ID, "position");
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
		GL_ELEMENT_ARRAY_BUFFER, sizeof(Elements), Elements, GL_STATIC_DRAW);
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

void Shape::InitBufferWithShading(glm::mat4 projection, glm::mat4 view)
{
	CalculateMv(view);

	GLuint position_id;
	GLuint vbo_vertices;

	GLuint normal_id;
	GLuint vbo_normals;

	GLuint uv_id;
	GLuint vbo_uvs;

	// vbo for vertices
	glGenBuffers(1, &vbo_vertices);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_vertices);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// vbo for normals
	glGenBuffers(1, &vbo_normals);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_normals);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Normals), Normals, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// vbo for uvs
	glGenBuffers(1, &vbo_uvs);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_uvs);
	glBufferData(GL_ARRAY_BUFFER, sizeof(uvs), uvs, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// Get vertex attributes
	position_id = glGetAttribLocation(shader.ID, "position");
	normal_id = glGetAttribLocation(shader.ID, "normal");
	uv_id = glGetAttribLocation(shader.ID, "vertexUV");

	// Allocate memory for vao
	glGenVertexArrays(1, &vao);

	// Bind to vao
	glBindVertexArray(vao);

	// Bind vertices to vao
	glBindBuffer(GL_ARRAY_BUFFER, vbo_vertices);
	glVertexAttribPointer(position_id, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(position_id);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// Bind normals to vao
	glBindBuffer(GL_ARRAY_BUFFER, vbo_normals);
	glVertexAttribPointer(normal_id, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(normal_id);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// Bind uvs to vao
	glBindBuffer(GL_ARRAY_BUFFER, vbo_uvs);
	glVertexAttribPointer(uv_id, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(uv_id);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// Stop bind to vao
	glBindVertexArray(0);

	// Make uniform vars
	uniform_mv = glGetUniformLocation(shader.ID, "mv");
	GLuint uniform_model = glGetUniformLocation(shader.ID, "model");
	GLuint uniform_proj = glGetUniformLocation(shader.ID, "projection");
	GLuint uniform_texture_enabled = glGetUniformLocation(shader.ID, "texture_enabled");
	GLuint uniform_light_pos = glGetUniformLocation(shader.ID, "light_pos");
	GLuint uniform_material_ambient = glGetUniformLocation(shader.ID,
		"mat_ambient");
	GLuint uniform_material_diffuse = glGetUniformLocation(shader.ID,
		"mat_diffuse");
	GLuint uniform_specular = glGetUniformLocation(
		shader.ID, "mat_specular");
	GLuint uniform_material_power = glGetUniformLocation(
		shader.ID, "mat_power");

	// Send mv
	shader.Use();
	glUniformMatrix4fv(uniform_mv, 1, GL_FALSE, glm::value_ptr(mv));
	glUniformMatrix4fv(uniform_model, 1, GL_FALSE, glm::value_ptr(model));
	glUniform1i(uniform_texture_enabled, TextureEnabled);
	glUniformMatrix4fv(uniform_proj, 1, GL_FALSE, glm::value_ptr(projection));
	glUniform3fv(uniform_light_pos, 1, glm::value_ptr(light_position));
	glUniform3fv(uniform_material_ambient, 1, glm::value_ptr(ambient_color));
	glUniform3fv(uniform_material_diffuse, 1, glm::value_ptr(diffuse_color));
	glUniform3fv(uniform_specular, 1, glm::value_ptr(specular));
	glUniform1f(uniform_material_power, power);
}