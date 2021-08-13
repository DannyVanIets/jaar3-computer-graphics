#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <array>
#include <string>

class CustomPlane
{
public:
    GLuint uniform_mvp;
    glm::mat4 mvp;
    glm::mat4 Model;

    GLuint PlaneVAO;
    GLfloat PlaneVertices[12];
    GLfloat PlaneColors[12];
    std::array<GLushort, 6> Plane_elements;
    std::array<GLfloat, 8> Cube_uvs;
    GLuint Program_id;
    bool isTextured = false;
    std::string Texture_name = "./Yellobrk.bmp";
    GLuint Loaded_texture;

    const char* vertexshader_name_Texture = "texturevs.vert";
    const char* fragshader_name_Texture = "texturefs.frag";

    
    CustomPlane() = default;
    CustomPlane(float x, float y, float z, float width, float height, float depth, float angle, std::string texture_name);

    void Render(glm::mat4 projection, glm::mat4 view, GLuint texture_id);
    void InitBuffer(glm::mat4 projection, glm::mat4 view, GLuint texture_id);
    void LoadShader();
    void InitLoadTextures();
};