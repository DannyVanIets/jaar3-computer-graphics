#include <iostream>

#include <GL/glew.h>
#include <GL/freeglut.h>

#include "glsl.h"

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace std;

// ID
GLuint program_id;

//--------------------------------------------------------------------------------
// Consts
//--------------------------------------------------------------------------------

const int WIDTH = 800, HEIGHT = 600;
const char* fragshader_name = "fragmentshader.frag";
const char* vertexshader_name = "vertexshader.vert";


//--------------------------------------------------------------------------------
// Keyboard handling
//--------------------------------------------------------------------------------

void keyboardHandler(unsigned char key, int a, int b)
{
    if (key == 27)
        glutExit();
}


//--------------------------------------------------------------------------------
// Rendering
//--------------------------------------------------------------------------------

void Render()
{
    // Define background
    static const GLfloat blue[] = { 0.0, 0.0, 0.4, 1.0 };
    glClearBufferfv(GL_COLOR, 0, blue);
    
    glUseProgram(program_id);

    glPointSize(40.0f);
    glDrawArrays(GL_POINTS, 0, 1);

    // Triangle.
    /*glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 0.0); // V0
    glVertex2f(-0.5, -0.5);
    glColor3f(1.0, 0.0, 0.0); // V1
    glVertex2f(0.5, -0.5);
    glColor3f(0.0, 0.0, 1.0); // V2
    glVertex2f(0, 0.5);
	glEnd();*/

	// Rectangle.
    /*glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.0); // V0
    glVertex2f(-0.5, -0.5);
    glColor3f(1.0, 0.0, 0.0); // V1
    glVertex2f(0.5, -0.5);
    glColor3f(0.0, 0.0, 1.0); // V2
    glVertex2f(0.5, 0.5);
    glColor3f(1.0, 0.0, 0.0); // V3
    glVertex2f(-0.5, 0.5);
    glEnd();*/

    // Swap buffers
    glutSwapBuffers();
}


//------------------------------------------------------------
// void InitGlutGlew(int argc, char **argv)
// Initializes Glut and Glew
//------------------------------------------------------------

void InitGlutGlew(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Hello OpenGL");
    glutDisplayFunc(Render);
    glutKeyboardFunc(keyboardHandler);

    glewInit();
}

void InitShaders()
{
    char* vertexshader = glsl::readFile(vertexshader_name);
    GLuint vsh_id = glsl::makeVertexShader(vertexshader);

    char* fragshader = glsl::readFile(fragshader_name);
    GLuint fsh_id = glsl::makeFragmentShader(fragshader);

    program_id = glsl::makeShaderProgram(vsh_id, fsh_id);
}


int main(int argc, char** argv)
{
    InitGlutGlew(argc, argv);
    InitShaders();

	// Create vector.
    glm::vec4 position = glm::vec4(0.3f, 0.4f, 0.0f, 1.0f); // Change the position.
    glm::vec4 color = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f); // Change the color.

	// Get location of uniform variable (create if new)
    GLuint position_id = glGetUniformLocation(program_id, "position");
    GLuint color_id = glGetUniformLocation(program_id, "color");

	// Attach to program (needed to fill uniform vars)
    glUseProgram(program_id);

	// Specify the value of the uniform variable
	// Args: locaiton, count, value
    glUniform4fv(position_id, 1, glm::value_ptr(position));
    glUniform4fv(color_id, 1, glm::value_ptr(color));

    // Hide console window
    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_HIDE);

    // Main loop
    glutMainLoop();

    return 0;
}
