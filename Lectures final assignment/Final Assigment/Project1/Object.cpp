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

    LoadObject();
}

Object::Object(std::string path, float x, float y, float z)
{
    this->path = "objects/" + path + ".obj";

    DoTranslation(x, y, z);
    LoadObject();
}

Object::Object(std::string path, float x, float y, float z, string texture_name)
{
    this->path = "objects/" + path + ".obj";

    DoTranslation(x, y, z);
    LoadObject();

    texture_path = texture_name;
}

Object::Object(std::string path, float x, float y, float z, string texture_name, std::vector<Animation*> aniList)
{
    this->path = "objects/" + path + ".obj";

    DoTranslation(x, y, z);
    LoadObject();

    texture_path = texture_name;
    animations = aniList;
}

Object::Object(std::string path, float x, float y, float z, glm::vec3 rgb)
{
    this->path = "objects/" + path + ".obj";

    DoTranslation(x, y, z);
    LoadObject();
    ChangeColor(rgb);
}

Object::Object(std::string path, float x, float y, float z, glm::vec3 rgb, std::vector<Animation*> aniList)
{
    this->path = "objects/" + path + ".obj";

    DoTranslation(x, y, z);
    LoadObject();
    ChangeColor(rgb);
    animations = aniList;
}

Object::Object(std::string path, float x, float y, float z, float width, float height, float length)
{
    this->path = "objects/" + path + ".obj";

    DoTranslation(x, y, z);
    DoScaling(width, height, length);
    LoadObject();
}

Object::Object(std::string path, float x, float y, float z, float width, float height, float length, string texture_name)
{
    this->path = "objects/" + path + ".obj";

    DoTranslation(x, y, z);
    DoScaling(width, height, length);
    LoadObject();

    texture_path = texture_name;
}

Object::Object(std::string path, float x, float y, float z, float width, float height, float length, string texture_name, std::vector<Animation*> aniList)
{
    this->path = "objects/" + path + ".obj";

    DoTranslation(x, y, z);
    DoScaling(width, height, length);
    LoadObject();

    texture_path = texture_name;
    animations = aniList;
}

Object::Object(std::string path, float x, float y, float z, float width, float height, float length, glm::vec3 rgb)
{
    this->path = "objects/" + path + ".obj";

    DoTranslation(x, y, z);
    DoScaling(width, height, length);
    LoadObject();
    ChangeColor(rgb);
}

Object::Object(std::string path, float x, float y, float z, float width, float height, float length, glm::vec3 rgb, std::vector<Animation*> aniList)
{
    this->path = "objects/" + path + ".obj";

    DoTranslation(x, y, z);
    DoScaling(width, height, length);
    LoadObject();
    ChangeColor(rgb);

    animations = aniList;
}

void Object::LoadObject()
{
    bool result = loadOBJ(path.c_str(), vertices, uvs, normals);
}

void Object::Render(glm::mat4 projection, glm::mat4 view)
{
    shader.Use();

    CalculateMv(view);

    if (animations.size() > 0) {
        for (auto& ani : animations) {
            model = ani->DoAnimation(model);
        }
    }

    if (TextureEnabled) {
        glBindTexture(GL_TEXTURE_2D, texture_id);
    }

    glUniformMatrix4fv(uniform_mv, 1, GL_FALSE, glm::value_ptr(mv));

    // Send vao
    glBindVertexArray(vao);

    glDrawArrays(GL_TRIANGLES, 0, vertices.size());

    glBindVertexArray(0);
}

void Object::InitBuffers(glm::mat4 projection, glm::mat4 view)
{
    shader = Shader(phong_vertexshader_name, phong_fragshader_name);

    if (!texture_path.empty()) {
        TextureEnabled = true;
        texture_id = loadBMP(texture_path.c_str());
    }

    CalculateMv(view);

    GLuint position_id;
    GLuint vbo_vertices;

    GLuint normal_id;
    GLuint vbo_normals;

    GLuint vbo_uvs;
    GLuint uv_id;

    // Get vertex attributes
    position_id = glGetAttribLocation(shader.ID, "position");
    normal_id = glGetAttribLocation(shader.ID, "normal");
    uv_id = glGetAttribLocation(shader.ID, "vertexUV");

    glGenBuffers(1, &vbo_vertices);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_vertices);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // vbo for normals
    glGenBuffers(1, &vbo_normals);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_normals);
    glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(glm::vec3), &normals[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // vbo for uvs
    glGenBuffers(1, &vbo_uvs);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_uvs);
    glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), &uvs[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

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

    // Bind textures to vao
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
    glUniformMatrix4fv(uniform_proj, 1, GL_FALSE, glm::value_ptr(projection));
    glUniform1i(uniform_texture_enabled, TextureEnabled);
    glUniform3fv(uniform_light_pos, 1, glm::value_ptr(light_position));
    glUniform3fv(uniform_material_ambient, 1, glm::value_ptr(ambient_color));
    glUniform3fv(uniform_material_diffuse, 1, glm::value_ptr(diffuse_color));
    glUniform3fv(uniform_specular, 1, glm::value_ptr(specular));
    glUniform1f(uniform_material_power, power);
}