#include <iostream>

#include <GL/glew.h>
#include <GL/freeglut.h>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "glsl.h"

#include <glm/gtc/matrix_transform.hpp>

#include "Cube.h"
#include "Camera.h"

//#include "glfw3.h"

using namespace std;

//--------------------------------------------------------------------------------
// Consts
//--------------------------------------------------------------------------------

const int WIDTH = 800, HEIGHT = 600;

const char* fragshader_name = "fragmentshader.frag";
const char* vertexshader_name = "vertexshader.vert";

unsigned const int DELTA_TIME = 10;


//--------------------------------------------------------------------------------
// Variables
//--------------------------------------------------------------------------------


GLuint program_id;

glm::mat4 view, projection;
GLuint uniform_mvp;

glm::mat4 model, mvp; // Not sure if needed.

Cube cube = Cube(2.0, 2.0, 2.0, -1.0, -1.0, 1.0);
Cube cube2 = Cube(2.0, 2.0, 2.0, -4.0, -1.0, 1.0);

Camera camera;


//--------------------------------------------------------------------------------
// Keyboard handling
//--------------------------------------------------------------------------------

void keyboardHandler(unsigned char key, int a, int b)
{
	if (key == 27)
		glutExit();
}

void processSpecialKeys(int key, int xx, int yy)
{
	// FROM: https://www.lighthouse3d.com/tutorials/glut-tutorial/keyboard-example-moving-around-the-world/
	float fraction = 0.1f;

	switch (key)
	{
	case GLUT_KEY_LEFT: // strafe left.
		camera.angle -= 0.01f;
		camera.lx = sin(camera.angle);
		camera.lz = -cos(camera.angle);
		break;

	case GLUT_KEY_RIGHT: // strafe right.
		camera.angle += 0.01;
		camera.lx = sin(camera.angle);
		camera.lz = -cos(camera.angle);
		break;

	case GLUT_KEY_UP: // Move forward.
		camera.x += camera.lx * fraction;
		camera.z += camera.lz * fraction;
		break;

	case GLUT_KEY_DOWN: // Move backwards.
		camera.x -= camera.lx * fraction;
		camera.z -= camera.lz * fraction;
		break;
	}
}

//--------------------------------------------------------------------------------
// Rendering
//--------------------------------------------------------------------------------

void Render()
{
	// Define background
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Attach to program_id
	glUseProgram(program_id);

	/*model = glm::rotate(
		model,
		glm::radians(0.1f),
		glm::vec3(0.0f, 1.0f, 0.0f));*/

	/*--------------------CAMERA START-----------------------*/
	// View.
	view = glm::lookAt(
		glm::vec3(camera.x, 1.0, camera.z),
		glm::vec3(camera.x + camera.lx, 1.0, camera.z + camera.lz),
		glm::vec3(0.0, 1.0, 0.0)
	);

	// Projection.
	projection = glm::perspective(
		glm::radians(45.0f),
		800.0f / 600.0f,
		0.1f,
		10.0f);
	/*--------------------CAMERA END-----------------------*/

	mvp = projection * view * model;

	cube.Render(uniform_mvp, projection, view, mvp);
	cube2.Render(uniform_mvp, projection, view, mvp);

	// Draw the ground.
	/*glColor3f(0.0f, 0.5f, 0.5f);
	glBegin(GL_QUADS);
	glVertex3f(-100.0f, 0.0f, -100.0f);
	glVertex3f(-100.0f, 0.0f, 100.0f);
	glVertex3f(100.0f, 0.0f, 100.0f);
	glVertex3f(100.0f, 0.0f, -100.0f);
	glVertex3f(100.0f, 0.0f, -100.0f);
	glEnd();*/

	// Swap buffers
	glutSwapBuffers();
}


//------------------------------------------------------------
// void Render(int n)
// Render method that is called by the timer function
//------------------------------------------------------------

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
	glutTimerFunc(DELTA_TIME, Render, 0);

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

void InitMatrices()
{
	model = glm::mat4();

	// Scaling
	/*model = glm::scale(
		model,
		glm::vec3(1.0f, 0.5f, 1.0f));

	// Rotation
	model = glm::rotate(
		model,
		glm::radians(10.0f),
		glm::vec3(0.0f, 0.0f, 1.0f));

	// Translation
	model = glm::translate(
		model,
		glm::vec3(1.0f, 2.0f, -1.0f));*/

	// View.
	view = glm::lookAt(
		glm::vec3(x, 1.0, z),
		glm::vec3(x + lx, 1.0, z + lz),
		glm::vec3(0.0, 1.0, 0.0)
	);

	// Projection.
	projection = glm::perspective(
		glm::radians(45.0f),
		800.0f / 600.0f,
		0.1f,
		10.0f);

	// Combine everything.
	mvp = projection * view * model;
}


//-----------------------------------------------------------
// void InitBuffers()
// Allocates and fills buffers
//------------------------------------------------------------

void InitBuffers()
{
	cube.InitBuffers(program_id, uniform_mvp, mvp);
	cube2.InitBuffers(program_id, uniform_mvp, mvp);
}

int main(int argc, char** argv)
{
	InitGlutGlew(argc, argv);
	InitShaders();
	InitMatrices();
	InitBuffers();
	glutSpecialFunc(processSpecialKeys);

	glEnable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);

	// Hide console window
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE); // Set to SW_SHOW to debug

	// Main loop
	glutMainLoop();

	return 0;
}