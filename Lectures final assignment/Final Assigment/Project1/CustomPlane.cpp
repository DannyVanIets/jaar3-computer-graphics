#include "CustomPlane.h"
#include "glsl.h"
#include <glm/gtc/type_ptr.hpp>
#include "texture/TextureLoader.h"

CustomPlane::CustomPlane(float x, float y, float z, float width, float height, float depth, float angle, std::string texture_name)
{
    Texture_name = texture_name;
    isTextured = true;

    float YZero = y - height / 2;
    float YOne = y - height / 2;
    float YTwo = y + height / 2;
    float YThree = y + height / 2;

    if (angle == 90.0f) {
        YThree = y - height / 2;
        YOne = y + height / 2;
    }
    else if (angle == 180.0f) {
        YZero = y + height / 2;
        YOne = y + height / 2;
        YTwo = y - height / 2;
        YThree = y - height / 2;
    }
    else if (angle == 270.0f) {
        YZero = y + height / 2;
        YTwo = y - height / 2;
    }

    GLfloat planeVertices[] = {
        x - width / 2, YZero, z + depth / 2,    // FrontLeft
        x + width / 2, YOne, z + depth / 2,     // FrontRight
        x + width / 2, YTwo, z - depth / 2,     // BackRight 
        x - width / 2, YThree, z - depth / 2     // BackLeft
    };
    std::copy_n(planeVertices, sizeof(planeVertices) / sizeof(GLfloat), this->PlaneVertices);

    Cube_uvs = {
        // U, V,
        // front
        0.0f, 0.0f, // bottom left
        1.0f, 0.0f, // bottom right
        1.0f, 1.0f, // top right
        0.0f, 1.0f // top left
    };

    Plane_elements = {
        0,1,2,0,2,3
    };
}

void CustomPlane::Render(glm::mat4 projection, glm::mat4 view, GLuint texture_id)
{
    mvp = projection * view * Model;

    if (isTextured) {
        glBindTexture(GL_TEXTURE_2D, Loaded_texture);
        // Should become glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, texture_id);
    }
    glUseProgram(Program_id);

    // Send mvp
    glUniformMatrix4fv(uniform_mvp, 1, GL_FALSE, glm::value_ptr(mvp));

    // Send vao
    glBindVertexArray(PlaneVAO);
    glDrawElements(GL_TRIANGLES, sizeof(this->Plane_elements) / sizeof(GLushort),
        GL_UNSIGNED_SHORT, 0);
    glBindVertexArray(0);
}

void CustomPlane::InitBuffer(glm::mat4 projection, glm::mat4 view, GLuint texture_id)
{
    GLuint position_id;
    GLuint uv_id;

    // Get vertex attributes
    position_id = glGetAttribLocation(Program_id, "vertexPosition");
    uv_id = glGetAttribLocation(Program_id, "vertexUV");

    GLuint ibo_elements;
    GLuint vbo_vertices;
    GLuint vbo_uvs;

    // vbo for vertices
    glGenBuffers(1, &vbo_vertices);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_vertices);
    glBufferData(GL_ARRAY_BUFFER, sizeof(PlaneVertices), PlaneVertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // vbo for uvs
    glGenBuffers(1, &vbo_uvs);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_uvs);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Cube_uvs), Cube_uvs.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // vbo for cube elements
    glGenBuffers(1, &ibo_elements);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo_elements);
    glBufferData(
        GL_ELEMENT_ARRAY_BUFFER, sizeof(Plane_elements),
        Plane_elements.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    // Allocate memory for vao
    glGenVertexArrays(1, &PlaneVAO);

    // Bind to vao
    glBindVertexArray(PlaneVAO);

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
    uniform_mvp = glGetUniformLocation(Program_id, "mvp");

    // Send mvp
    glUseProgram(Program_id);
    glUniformMatrix4fv(uniform_mvp, 1, GL_FALSE, glm::value_ptr(mvp));
}

void CustomPlane::LoadShader()
{
    char* vertexshader; //var to put the vextexshader in
    char* fragshader; //var to put the fragshader in

    //If-statement to determine whether the cube has a texure or not.
    if (isTextured) {
        //Reads the texure shader files, as defined in primitiveShapes.
        vertexshader = glsl::readFile(vertexshader_name_Texture);
        fragshader = glsl::readFile(fragshader_name_Texture);
    }
    else {
        //Reads the color shader files, as defined in primitiveShapes.
        vertexshader = glsl::readFile(vertexshader_name_Texture);
        fragshader = glsl::readFile(fragshader_name_Texture);
    }
    //makes the vertexshader
    GLuint vsh_id = glsl::makeVertexShader(vertexshader);
    //makes the fragshader
    GLuint fsh_id = glsl::makeFragmentShader(fragshader);
    //Creates a new version of the program_id.
    Program_id = glsl::makeShaderProgram(vsh_id, fsh_id);
}

void CustomPlane::InitLoadTextures()
{
    Loaded_texture = loadBMP(Texture_name.c_str());
}