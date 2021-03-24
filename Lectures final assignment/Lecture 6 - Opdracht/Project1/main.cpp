#include <iostream>

#include <GL/glew.h>
#include <GL/freeglut.h>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "glsl.h"

using namespace std;


//--------------------------------------------------------------------------------
// Consts
//--------------------------------------------------------------------------------

unsigned const int DELTA_TIME = 100;
const int WIDTH = 800, HEIGHT = 600;

const char* fragshader_name = "fragmentshader.frag";
const char* vertexshader_name = "vertexshader.vert";


//--------------------------------------------------------------------------------
// Variables
//--------------------------------------------------------------------------------

// ID's
GLuint program_id;
GLuint vao;

GLuint position_id;
GLuint color_id;

GLuint vbo_vertices;
GLuint vbo_colors; // Unused.

float f = 0.0f;
bool up = true;

const glm::vec4 vertices[] = {
	glm::vec4(0.5, -0.5, 0.0, 1.0),
	glm::vec4(-0.5, -0.5, 0.0, 1.0),
	glm::vec4(0.0, 0.5, 0.0, 1.0)
};

const glm::vec4 colors[] =
{
	glm::vec4(1.0f, 0.0f, 0.0f, 1.0f),
	glm::vec4(0.0f, 1.0f, 0.0f, 1.0f),
	glm::vec4(0.0f, 0.0f, 1.0f, 1.0f)
};

//--------------------------------------------------------------------------------
// Struct VertexFormat
//--------------------------------------------------------------------------------

struct VertexFormat
{
	glm::vec4 position;
	glm::vec4 color;

	VertexFormat(glm::vec4 pos, glm::vec4 col)
	{
		position = pos;
		color = col;
	}
};

VertexFormat triangle[] = {
	VertexFormat(glm::vec4(0.5, -0.5, 0.0, 1.0), // Position
			glm::vec4(1.0f, 0.0f, 0.0f, 1.0f)), // Color
	VertexFormat(glm::vec4(-0.5, -0.5, 0.0, 1.0),
			glm::vec4(0.0f, 1.0f, 0.0f, 1.0f)),
	VertexFormat(glm::vec4(0.0, 0.5, 0.0, 1.0),
			glm::vec4(0.0f, 0.0f, 1.0f, 1.0f))
};

/*VertexFormat triangle2[] = {
	VertexFormat(glm::vec4(0.5, -0.5, 0.0, 1.0), // Position, left
			glm::vec4(1.0f, 0.0f, 0.0f, 1.0f)), // Color
	VertexFormat(glm::vec4(0.5, -0.5, 0.0, 1.0), // Right
			glm::vec4(0.0f, 1.0f, 0.0f, 1.0f)),
	VertexFormat(glm::vec4(0.0, -1.5, 0.0, 1.0), // Top
			glm::vec4(0.0f, 0.0f, 1.0f, 1.0f))
};*/

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
	// Define background.
	const glm::vec4 blue = glm::vec4(0.0f, 0.0f, 0.4f, 1.0f);
	glClearBufferfv(GL_COLOR, 0, glm::value_ptr(blue));

	// Attach to program_id.
	glUseProgram(program_id);

	if (up)
	{
		f += 0.1f;
		if (f >= 1.0)
		{
			up = false;
		}
	}
	else
	{
		f -= 0.1f;
		if (f <= 0.0)
		{
			up = true;
		}
	}

	glm::vec4 v = glm::vec4(0.0, f, 0.0, 1.0);
	
	glBindBuffer(GL_ARRAY_BUFFER, vbo_vertices);
	glBufferSubData(GL_ARRAY_BUFFER, // target
		4 * sizeof(glm::vec4),	     // offset
		sizeof(glm::vec4),			 // size
		&v);						 // data
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0);

	//Just a regular triangle.
	/*
	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(-0.5, -0.5); // Changes left side.
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(0.5, -0.5); // Changes the right side.
	glColor3f(0.0, 1.0, 1.0);
	glVertex2f(0, 0.5);  // Changes the top.
	glEnd();*/

	// Inverted triangle, bottom.
	/*glBegin(GL_TRIANGLES);
	glColor3f(0.0, 1.0, 0.0);
	// X makes it go more to the left or right.
	// Y makes it possible to make it longer or invert it.
	glVertex2f(-0.5, -0.5); // Changes left side.
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(0.5, -0.5); // Changes the right side.
	glColor3f(0.0, 1.0, 1.0);
	glVertex2f(0, -1.5);  // Changes the top.
	glEnd();

	// To the left.
	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(-1.5, 0); // Changes left side.
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(0, -0.5); // Changes the right side.
	glColor3f(0.0, 1.0, 1.0);
	glVertex2f(0, 0.5);  // Changes the top.
	glEnd();

	// To the right.
	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(0, -0.5); // Changes left side.
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(1, 0); // Changes the right side.
	glColor3f(0.0, 1.0, 1.0);
	glVertex2f(0, 0.5);  // Changes the top.
	glEnd();*/

	/*glBegin(GL_LINES); // -10,20 to -20,20
	glVertex2f(0, 0.25);
	glVertex2f(-0.25, 0.25);
	glEnd();

	glBegin(GL_LINES); // -20,20 to -20,10
	glVertex2f(-0.25, 0.25);
	glVertex2f(-0.25, 0);
	glEnd();

	glBegin(GL_LINES); // -20,10 to -40, 0
	glVertex2f(-0.25, 0);
	glVertex2f(-0.50, -0.25);
	glEnd();

	glBegin(GL_LINES); // -40, 0 to -20, -10
	glVertex2f(-0.50, -0.25);
	glVertex2f(-0.25, -0.50);
	glEnd();

	glBegin(GL_LINES); // -20, -10 to -20,-20
	glVertex2f(-0.25, -0.50);
	glVertex2f(-0.25, -0.75);
	glEnd();

	glBegin(GL_LINES); // -20,-20 to -10,-20
	glVertex2f(-0.25, -0.75);
	glVertex2f(0, -0.75);
	glEnd();

	glBegin(GL_LINES); // -10,-20 to 0,-40
	glVertex2f(0, -0.75);
	glVertex2f(0.15, -1);
	glEnd();

	glBegin(GL_LINES); // 0,-40 to 10,-20
	glVertex2f(0.15, -1);
	glVertex2f(0.30, -0.75);
	glEnd();

	glBegin(GL_LINES); // 10,-20 to 20,-20
	glVertex2f(0.30, -0.75);
	glVertex2f(0.55, -0.75);
	glEnd();

	glBegin(GL_LINES); // 20,-20 to 20,-10
	glVertex2f(0.55, -0.75);
	glVertex2f(0.55, -0.50);
	glEnd();

	glBegin(GL_LINES); // 20,-10 to 40,0
	glVertex2f(0.55, -0.50);
	glVertex2f(0.80, -0.25);
	glEnd();

	glBegin(GL_LINES); // 40,0 to 20,10
	glVertex2f(0.80, -0.25);
	glVertex2f(0.55, 0);
	glEnd();

	glBegin(GL_LINES); // 20,10 to 20,20
	glVertex2f(0.55, 0);
	glVertex2f(0.55, 0.25);
	glEnd();

	glBegin(GL_LINES); // 20,20 to 10,20
	glVertex2f(0.55, 0.25);
	glVertex2f(0.30, 0.25);
	glEnd();

	glBegin(GL_LINES); // 10,20 to 0,40
	glVertex2f(0.30, 0.25);
	glVertex2f(0.15, 0.50);
	glEnd();

	glBegin(GL_LINES); // 0,40 to -10,20
	glVertex2f(0.15, 0.50);
	glVertex2f(0, 0.25);
	glEnd();*/

	// Swap buffers.
	glutSwapBuffers();
}

void Render(int n)
{
	Render();
	glutTimerFunc(DELTA_TIME, Render, 0);
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
	glutTimerFunc(DELTA_TIME, Render, 0); // For animation.

	glewInit();
}


//------------------------------------------------------------
// void InitShaders()
// Initializes the fragmentshader and vertexshader
//------------------------------------------------------------

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

	// First
	// - Allocate and fill VBO's
	// - Create attrib attribute

	//int amount = 2;

	// Generate buffer object (in this case 1).
	glGenBuffers(2, &vbo_vertices);
	// Bind named buffer object.
	glBindBuffer(GL_ARRAY_BUFFER, vbo_vertices);
	// Create and initialize buffer object's data store.
	glBufferData(GL_ARRAY_BUFFER, sizeof(triangle), triangle, GL_STATIC_DRAW);
	// Unbind.
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// Attrib.
	position_id = glGetAttribLocation(program_id, "position");
	color_id = glGetAttribLocation(program_id, "color");

	// Vao.
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	// Position.
	glBindBuffer(GL_ARRAY_BUFFER, vbo_vertices);
	glVertexAttribPointer(position_id, 4, GL_FLOAT, GL_FALSE,
		sizeof(VertexFormat), 0);
	glEnableVertexAttribArray(position_id);

	// Colors.
	glVertexAttribPointer(color_id, 4, GL_FLOAT, GL_FALSE,
		sizeof(VertexFormat), (void*)(sizeof(glm::vec4)));
	glEnableVertexAttribArray(color_id);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	// Hide console window
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE);

	// Main loop
	glutMainLoop();

	return 0;
}