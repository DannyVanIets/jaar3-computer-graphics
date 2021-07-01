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
float deltaTime = 0;
float lastFrame = 0;

//--------------------------------------------------------------------------------
// Variables
//--------------------------------------------------------------------------------
GLuint program_id;

GLuint uniform_mvp;

glm::mat4 model, mvp;

Cube cube = Cube(2.0, 2.0, 2.0, -1.0, -1.0, 1.0);
Cube cube2 = Cube(2.0, 2.0, 2.0, -4.0, -1.0, 1.0);

Cube cubes[2] = { cube, cube2 };

Camera camera;

//--------------------------------------------------------------------------------
// Keyboard handling
//--------------------------------------------------------------------------------

void keyboardHandler(unsigned char key, int a, int b)
{
	const float cameraSpeedX = 0.01f * deltaTime;
	const float cameraSpeedZ = 0.005f * deltaTime;

	if (key == 27) // 27 is ESC, closes the tab.
		glutExit();

	/*---------------------------MOVEMENT---------------------------------*/

	if (key == 87 || key == 119) { // 87 is W and 119 is w, moving forwards.
		camera.cameraPos += cameraSpeedZ * camera.cameraFront;
	}

	if (key == 83 || key == 115) { // 83 is S and 115 is s, moving backwards.
		camera.cameraPos -= cameraSpeedZ * camera.cameraFront;
	}

	if (key == 65 || key == 97) { // 65 is A and 97 is a, moving left.
		camera.cameraPos -= glm::normalize(glm::cross(camera.cameraFront, camera.cameraUp)) * cameraSpeedX;
	}

	if (key == 68 || key == 100) { // 68 is D and 100 is d, moving right.
		camera.cameraPos += glm::normalize(glm::cross(camera.cameraFront, camera.cameraUp)) * cameraSpeedX;
	}

	/*---------------------------STRAFING---------------------------------*/

	if (key == 106) { // 65 is J, strafing to the left.
		
	}

	if (key == 108) { // 108 is L, strafing to the right.
		
	}

	if (key == 105) { // 105 is I, strafing up.

	}

	if (key == 107) { // 107 is K, strafing down.

	}
	camera.cameraPos.y = 1.0f; // Keeps you at ground level, so you cannot fly.
}

void pressKeySpecial(int key, int a, int b)
{
	const float cameraSpeedX = 0.01f * deltaTime;
	const float cameraSpeedZ = 0.005f * deltaTime;

	// Move around with the arrow keys.
	switch (key)
	{
	case GLUT_KEY_UP: // Move forward.
		camera.cameraPos += cameraSpeedZ * camera.cameraFront;
		break;

	case GLUT_KEY_DOWN: // Move backward.
		camera.cameraPos -= cameraSpeedZ * camera.cameraFront;
		break;

	case GLUT_KEY_LEFT: // Move left
		camera.cameraPos -= glm::normalize(glm::cross(camera.cameraFront, camera.cameraUp)) * cameraSpeedX;
		break;

	case GLUT_KEY_RIGHT: // strafe right.
		camera.cameraPos += glm::normalize(glm::cross(camera.cameraFront, camera.cameraUp)) * cameraSpeedX;
		break;
	}
}

void MouseCallback(int x, int y) {
	camera.MouseMovement(x, y);
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

	// Rotate the models.
	/*model = glm::rotate(
		model,
		glm::radians(0.1f),
		glm::vec3(0.0f, 1.0f, 0.0f));*/

	// Calculate the view of the camera.
	// Will update the view after a button has been pressed for the movement.
	camera.CalculateView();

	mvp = camera.projection * camera.view * model;

	cube.Render(uniform_mvp, camera.projection, camera.view, mvp);
	cube2.Render(uniform_mvp, camera.projection, camera.view, mvp);

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
	//glutKeyboardFunc(keyboardHandler);
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

	// Calculate the camera projection.
	camera.CalculateProjection();

	// Combine everything.
	mvp = camera.projection * camera.view * model;
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
	float currentFrame = DELTA_TIME;
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;

	InitGlutGlew(argc, argv);
	InitShaders();
	InitMatrices();
	InitBuffers();

	// For the movement with arrow keys.
	//glutSpecialFunc(pressKeySpecial);

	// For the movement/strafing with WASD/IJKL.
	glutKeyboardFunc(keyboardHandler);

	// For the mouse.
	glutSetCursor(GLUT_CURSOR_NONE); // Hides the mouse.
	glutPassiveMotionFunc(MouseCallback);

	glEnable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);

	// Hide console window
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE); // Set to SW_SHOW to debug

	// Main loop
	glutMainLoop();

	return 0;
}