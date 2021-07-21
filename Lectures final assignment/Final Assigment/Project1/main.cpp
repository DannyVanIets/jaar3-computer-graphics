#include <iostream>

#include <GL/glew.h>
#include <GL/freeglut.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "glsl.h"

#include "Cube.h"
#include "Camera.h"
#include "Pyramid.h"
#include "Hexagon.h"
#include "Icosahedron.h"
#include "TriangularPrism.h"
#include "Shader.h"
#include "texture/texture.h"

using namespace std;

//--------------------------------------------------------------------------------
// Consts
//--------------------------------------------------------------------------------

const int WIDTH = 800, HEIGHT = 600;

const char* vertexshader_name = "vertexshader.vert";
const char* fragshader_name = "fragmentshader.frag";

const char* texture_vertexshader_name = "texturevs.vert";
const char* texture_fragshader_name = "texturefs.frag";

const char* skybox_vertexshader_name = "skyboxvs.vert";
const char* skybox_fragshader_name = "skyboxfs.frag";

//const char* texture_name = "texture/uvtemplate.bmp";
const char* texture_name = "texture/Yellobrk.bmp";

unsigned const int DELTA_TIME = 10;

//--------------------------------------------------------------------------------
// Variables
//--------------------------------------------------------------------------------
GLuint texture_id;

Shader shader;
Shader texturedShader;

GLuint uniform_mvp;

Camera camera;

glm::mat4 model, mvp;

// ideas for forms:
// hemisphere

TriangularPrism tripri;
Icosahedron ico;
Hexagon hexagon;
Pyramid pyramid;

Cube cube = Cube(2.0, 2.0, 2.0, -1.0, -1.0, 1.0);
Cube cube2 = Cube(2.0, 2.0, 2.0, -4.0, -1.0, 1.0);

Cube cubes[1] = { cube2 };

//--------------------------------------------------------------------------------
// Control handling, with keyboard and mouse
//--------------------------------------------------------------------------------

void keyboardHandler(unsigned char key, int a, int b)
{
	// TODO: Implement movement speed from here: https://learnopengl.com/Getting-started/Camera.
	// Helpful: https://github.com/mattearly/TheOnlyEscapeIsESC/blob/master/code/game_callbacks.cpp, ctrl + f on deltatime.
	// All code: https://github.com/mattearly/TheOnlyEscapeIsESC/tree/master/code.

	if (key == 27) // 27 is ESC, closes the tab.
		glutExit();

	/*---------------------------MOVEMENT---------------------------------*/

	const float cameraSpeedZ = 0.1f; // Controls how fast you can move forward/backward.
	const float cameraSpeedX = 0.1f; // Controls how fast you can move left/right.

	if (key == 87 || key == 119) { // 87 is W and 119 is w, moving forwards.
		// First line of code is for the drone mode, second is for just walking around.
		//camera.cameraPos += cameraSpeedZ * camera.cameraFront;
		camera.cameraPos += cameraSpeedZ * glm::normalize(glm::cross(camera.WorldUp, camera.Right));
	}

	if (key == 83 || key == 115) { // 83 is S and 115 is s, moving backwards.
		// First line of code is for the drone mode, second is for just walking around.
		//camera.cameraPos -= cameraSpeedZ * camera.cameraFront;
		camera.cameraPos -= cameraSpeedZ * glm::normalize(glm::cross(camera.WorldUp, camera.Right));
	}

	if (key == 65 || key == 97) { // 65 is A and 97 is a, moving left.
		//camera.cameraPos -= glm::normalize(glm::cross(camera.cameraFront, camera.cameraUp)) * cameraSpeedX;
		camera.cameraPos -= camera.Right * cameraSpeedX;
	}

	if (key == 68 || key == 100) { // 68 is D and 100 is d, moving right.
		//camera.cameraPos += glm::normalize(glm::cross(camera.cameraFront, camera.cameraUp)) * cameraSpeedX;
		camera.cameraPos += camera.Right * cameraSpeedX;
	}

	// TODO: REMOVE THIS BEFORE UPLOADING IT!
	if (key == 'q') {
		camera.cameraPos.y += 1.0f;
	}

	if (key == 'e') {
		camera.cameraPos.y -= 1.0f;
	}

	//camera.cameraPos.y = 1.0f; // Keeps you at ground level, so you cannot fly.

	/*---------------------------STRAFING---------------------------------*/

	if (key == 106) { // 65 is J, strafing to the left.

	}

	if (key == 108) { // 108 is L, strafing to the right.

	}

	if (key == 105) { // 105 is I, strafing up.

	}

	if (key == 107) { // 107 is K, strafing down.

	}
}

void pressKeySpecial(int key, int a, int b)
{
	const float cameraSpeedZ = 0.1f; // Controls how fast you can move forward/backward.
	const float cameraSpeedX = 0.1f; // Controls how fast you can move left/right.

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
	camera.LookAround(x, y);
}

//--------------------------------------------------------------------------------
// Rendering
//--------------------------------------------------------------------------------

void Render()
{
	// Define background
	glClearColor(0.0, 0.5, 0.5, 0.5);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Attach to program_id
	shader.Use();
	//texturedShader.Use();

	// Rotate the models continiously.
	/*model = glm::rotate(
		model,
		glm::radians(0.1f),
		glm::vec3(0.0f, 1.0f, 0.0f));*/

	// Calculate the view of the camera.
	// Will update the view after a button has been pressed for the movement.
	camera.CalculateView();

	mvp = camera.projection * camera.view * model;

	// Textures: http://www.opengl-tutorial.org/beginners-tutorials/tutorial-5-a-textured-cube/.
	for (Cube& c : cubes) {
		c.Render(uniform_mvp, camera.projection, camera.view, mvp);
	}

	//pyramid.Render(uniform_mvp, camera.projection, camera.view, mvp);
	//hexagon.Render(uniform_mvp, camera.projection, camera.view, mvp);
	//ico.Render(uniform_mvp, camera.projection, camera.view, mvp);
	//tripri.Render(uniform_mvp, camera.projection, camera.view, mvp);

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

	// For the movement with WASD.
	glutKeyboardFunc(keyboardHandler);

	// For the movement with arrow keys.
	glutSpecialFunc(pressKeySpecial);

	// For the mouse.
	glutSetCursor(GLUT_CURSOR_NONE); // Hides the mouse.
	glutPassiveMotionFunc(MouseCallback);

	glutTimerFunc(DELTA_TIME, Render, 0);
	glewInit();
}

//------------------------------------------------------------
// void InitShaders()
// Initializes the fragmentshader and vertexshader
//------------------------------------------------------------

void InitShaders()
{
	shader = Shader(vertexshader_name, fragshader_name);
	texturedShader = Shader(texture_vertexshader_name, texture_fragshader_name);
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

void InitLoadTextures() {
	texture_id = loadBMP(texture_name);
}

//-----------------------------------------------------------
// void InitBuffers()
// Allocates and fills buffers
//------------------------------------------------------------

void InitBuffers()
{
	for (Cube& c : cubes) {
		c.InitBuffers(shader, uniform_mvp, mvp);
		//c.InitBuffersTexture(texturedShader, uniform_mvp, mvp);
	}

	//pyramid.InitBuffers(shader.ID, uniform_mvp, mvp);
	//hexagon.InitBuffers(shader.ID, uniform_mvp, mvp);
	//ico.InitBuffers(shader.ID, uniform_mvp, mvp);
	//tripri.InitBuffers(shader.ID, uniform_mvp, mvp);
}

int main(int argc, char** argv)
{
	InitGlutGlew(argc, argv);
	InitShaders();
	InitMatrices();
	InitLoadTextures();
	InitBuffers();

	glEnable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);

	// Hide console window
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE); // Set to SW_SHOW to debug

	// Main loop
	glutMainLoop();

	return 0;
}