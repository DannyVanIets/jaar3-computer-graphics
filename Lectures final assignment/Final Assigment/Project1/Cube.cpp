#include "Cube.h"

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "glsl.h"

#include <glm/gtc/matrix_transform.hpp>

Cube::Cube(float height = 1.0, float width = 1.0, float length = 1.0, float x = 1.0, float y = 1.0, float z = 1.0)
{
    Height = height;
    Width = width;
    Length = length;

    float LengthMinusZ = z - Length;

    GLfloat newVertices[] = {
        // Front
        x,         y,          z, // Bottom left
        x + Width, y,          z, // Bottom Right
        x + Width, y + Height, z, // Top Right
        x,        y + Height, z, // Top Left
        // Back
        x,         y,          LengthMinusZ, // Bottom left
        x + Width, y,          LengthMinusZ, // Bottom Right
        x + Width, y + Height, LengthMinusZ, // Top Right
        x,         y + Height, LengthMinusZ, // Top Left
    };

    std::copy_n(newVertices, sizeof(newVertices) / 4, this->Vertices);
}

void Cube::Render(GLuint uniform_mvp, glm::mat4 projection, glm::mat4 view, glm::mat4 mvp)
{
    glUniformMatrix4fv(uniform_mvp, 1, GL_FALSE, glm::value_ptr(mvp));

    // Send vao
    glBindVertexArray(vao);

    glDrawElements(
        GL_TRIANGLES,
        sizeof(Cube_elements) / sizeof(GLushort),
        GL_UNSIGNED_SHORT,
        0);

    glBindVertexArray(0);
}

void Cube::InitBuffers(Shader shader, GLuint uniform_mvp, glm::mat4 mvp)
{
    GLuint position_id;
    GLuint color_id;

    // Get vertex attributes
    position_id = glGetAttribLocation(shader.ID, "position");
    color_id = glGetAttribLocation(shader.ID, "color");

    GLuint ibo_cube_elements;
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
    glGenBuffers(1, &ibo_cube_elements);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo_cube_elements);
    glBufferData(
        GL_ELEMENT_ARRAY_BUFFER, sizeof(Cube_elements),
        Cube_elements, GL_STATIC_DRAW);
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
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo_cube_elements);

    // Stop bind to vao
    glBindVertexArray(0);

    // Make uniform vars
    uniform_mvp = glGetUniformLocation(shader.ID, "mvp");

    // Send mvp
    shader.Use();
    glUniformMatrix4fv(uniform_mvp, 1, GL_FALSE, glm::value_ptr(mvp));
}

void Cube::InitBuffersTexture(Shader shader, GLuint uniform_mvp, glm::mat4 mvp)
{
    GLuint position_id;
    GLuint uv_id;

    // Get vertex attributes
    position_id = glGetAttribLocation(shader.ID, "vertexPosition");
    uv_id = glGetAttribLocation(shader.ID, "vertexUV");

    GLuint ibo_cube_elements;
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
    glGenBuffers(1, &ibo_cube_elements);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo_cube_elements);
    glBufferData(
        GL_ELEMENT_ARRAY_BUFFER, sizeof(Cube_elements),
        Cube_elements, GL_STATIC_DRAW);
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
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo_cube_elements);

    // Stop bind to vao
    glBindVertexArray(0);

    // Make uniform vars
    uniform_mvp = glGetUniformLocation(shader.ID, "mvp");

    // Send mvp
    shader.Use();
    glUniformMatrix4fv(uniform_mvp, 1, GL_FALSE, glm::value_ptr(mvp));
}