#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include <string>

#include "Object.h"
#include "objloader.h"
#include "Shader.h"

Object::Object(std::string path)
{
    this->path = "objects/" + path + ".obj";
}

Object::Object(std::string path, float x, float y, float z)
{
    this->path = "objects/" + path + ".obj";
    DoTranslation(x, y, z);
}

void Object::LoadObject()
{
    bool result = loadOBJ(path.c_str(), vertices, uvs, normals);
}

void Object::Render(glm::mat4 view)
{
    CalculateMv(view);

    glUniformMatrix4fv(uniform_mv, 1, GL_FALSE, glm::value_ptr(mv));

    // Send vao
    glBindVertexArray(vao);

    glDrawArrays(GL_TRIANGLES, 0, vertices.size());

    glBindVertexArray(0);
}

void Object::InitBuffers(Shader shader, glm::mat4 projection, glm::mat4 view)
{
    CalculateMv(view);

    GLuint position_id;
    GLuint vbo_vertices;
    GLuint normal_id;
    GLuint vbo_normals;

    glGenBuffers(1, &vbo_vertices);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_vertices);
    glBufferData(GL_ARRAY_BUFFER,
        vertices.size() * sizeof(glm::vec3), &vertices[0],
        GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // vbo for normals
    glGenBuffers(1, &vbo_normals);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_normals);
    glBufferData(GL_ARRAY_BUFFER,
        normals.size() * sizeof(glm::vec3),
        &normals[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // Get vertex attributes
    position_id = glGetAttribLocation(shader.ID, "position");
    normal_id = glGetAttribLocation(shader.ID, "normal");

    // No color!

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

    // Stop bind to vao
    glBindVertexArray(0);

    // Make uniform vars
    uniform_mv = glGetUniformLocation(shader.ID, "mv");
    GLuint uniform_proj = glGetUniformLocation(shader.ID, "projection");
    GLuint uniform_light_pos = glGetUniformLocation(shader.ID, "light_pos");
    GLuint uniform_material_ambient = glGetUniformLocation(shader.ID,
        "mat_ambient");
    GLuint uniform_material_diffuse = glGetUniformLocation(shader.ID,
        "mat_diffuse");
    // Specular
    GLuint uniform_specular = glGetUniformLocation(
        shader.ID, "mat_specular");
    GLuint uniform_material_power = glGetUniformLocation(
        shader.ID, "mat_power");

    // Send mv
    glUseProgram(shader.ID);
    glUniformMatrix4fv(uniform_mv, 1, GL_FALSE, glm::value_ptr(mv));
    glUniformMatrix4fv(uniform_proj, 1, GL_FALSE, glm::value_ptr(projection));
    glUniform3fv(uniform_light_pos, 1, glm::value_ptr(light_position));
    glUniform3fv(uniform_material_ambient, 1, glm::value_ptr(ambient_color));
    glUniform3fv(uniform_material_diffuse, 1, glm::value_ptr(diffuse_color));
    glUniform3fv(uniform_specular, 1, glm::value_ptr(specular));
    glUniform1f(uniform_material_power, power);
}