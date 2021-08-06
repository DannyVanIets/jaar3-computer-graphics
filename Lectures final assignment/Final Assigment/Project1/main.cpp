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
#include "texture/TextureLoader.h"
#include "House.h"
#include "TrapezoidPrism.h"
#include "RightRemovedTrapezoidPrism.h"
#include "Wedge.h"
#include "Object.h"
#include "Movement.h"

using namespace std;

//--------------------------------------------------------------------------------
// Consts
//--------------------------------------------------------------------------------

const int WIDTH = 800, HEIGHT = 600;

const char* vertexshader_name = "vertexshader.vert";
const char* fragshader_name = "fragmentshader.frag";

const char* texture_vertexshader_name = "texturevs.vert";
const char* texture_fragshader_name = "texturefs.frag";

const char* object_vertexshader_name = "objectvs.vert";
const char* object_fragshader_name = "objectfs.frag";

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
Shader objectShader;

Camera camera;
Movement movement;

TriangularPrism tripri = TriangularPrism(-1.0, -1.0, 1.0);
Icosahedron ico = Icosahedron(-1.0, -1.0, 1.0);
Hexagon hexagon = Hexagon(7.0, -1.0, 15.0);
Pyramid pyramid = Pyramid(-1.0, -1.0, 1.0);
TrapezoidPrism trapezoid = TrapezoidPrism(-1.0, -1.0, 1.0, 4.0, 2.0, 2.0);
RightRemovedTrapezoidPrism trapezoidNoRight = RightRemovedTrapezoidPrism(10.0, -1.0, 1.0);
Wedge wedge = Wedge(-1.0, -1.0, 1.0);

Cube cube = Cube(-2.0, 0.0, 1.0, 2.0, 2.0, 2.0, false);
Cube cube2 = Cube(-2.0, 0.0, 1.0, true);

House house = House(2, 5.0f, -1.0f, 1.0f, true);

//Object object;
//Object object = Object("ufo"); // Takes a few seconds to load
Object object = Object("teapot", -1.0f, -1.0f, 10.0f);

//--------------------------------------------------------------------------------
// Control handling, with keyboard and mouse
//--------------------------------------------------------------------------------

void keyboardHandler(unsigned char key, int a, int b)
{
	// Move around with WASD.
	camera = movement.KeyboardKeys(camera, key);
}

void pressKeySpecial(int key, int a, int b)
{
	// Move around with the arrow keys.
	camera = movement.KeyboardKeysSpecial(camera, key);
}

void MouseCallback(int x, int y) 
{
	// Look around with the mouse.
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

	// For anti-aliasing
	glEnable(GL_MULTISAMPLE);

	// Draw the ground.
	//glColor3f(0.039f, 0.341f, 0.078f);
	/*glNormal3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
		glVertex3f(-100.0f, -1.0f, -100.0f);
		glVertex3f(-100.0f, -1.0f, 100.0f);
		glVertex3f(100.0f, -1.0f, 100.0f);
		glVertex3f(100.0f, -1.0f, -100.0f);
	glEnd();*/

	// Attach to program_id
	shader.Use();
	//glBindTexture(GL_TEXTURE_2D, texture_id);
	glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, texture_id);

	// Calculate the view of the camera.
	// Will update the view after a button has been pressed for the movement.
	camera.CalculateView();

	cube.Render(camera.projection, camera.view);
	house.RenderAllShapes(camera.projection, camera.view);

	// TODO: Create texture class.
	texturedShader.Use(); // Textures: http://www.opengl-tutorial.org/beginners-tutorials/tutorial-5-a-textured-cube/.
	cube2.Render(camera.projection, camera.view);

	// Objects
	objectShader.Use();
	object.Render(camera.view);

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
	glutSetOption(GLUT_MULTISAMPLE, 8);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_MULTISAMPLE);
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
	objectShader = Shader(object_vertexshader_name, object_fragshader_name);
}

void InitMatrices()
{
	// Calculating the MV and MVP is done in the InitBuffers and Render Function.
	// Calculate the camera projection.
	camera.CalculateProjection();
}

void InitLoadObjects() 
{
	object.LoadObject();
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
	house.BufferAllShapes(shader, camera.projection, camera.view);
	object.InitBuffers(objectShader, camera.projection, camera.view);

	cube.InitBuffer(shader, camera.projection, camera.view);
	cube2.InitBuffer(texturedShader, camera.projection, camera.view);
}

int main(int argc, char** argv)
{
	InitGlutGlew(argc, argv);
	InitShaders();
	InitMatrices();
	InitLoadObjects();
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