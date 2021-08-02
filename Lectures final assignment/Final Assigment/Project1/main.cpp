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

GLuint uniform_mvp;

glm::mat4 model, mvp, mv;

Camera camera;
Movement movement;

TriangularPrism tripri = TriangularPrism(-1.0, -1.0, 1.0);
Icosahedron ico = Icosahedron(-1.0, -1.0, 1.0);
Hexagon hexagon = Hexagon(7.0, -1.0, 15.0);
Pyramid pyramid = Pyramid(-1.0, -1.0, 1.0);
TrapezoidPrism trapezoid = TrapezoidPrism(-1.0, -1.0, 1.0, 4.0, 2.0, 2.0);
RightRemovedTrapezoidPrism trapezoidNoRight = RightRemovedTrapezoidPrism(10.0, -1.0, 1.0);
Wedge wedge = Wedge(-1.0, -1.0, 1.0);

//Cube cube = Cube(-1.0, -1.0, 1.0);
Cube cube2 = Cube(-10.0, -1.0, -3.0);

House house = House(2, 5.0f, -1.0f, 1.0f, true);

//Object object;
Object object = Object("teapot");

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
	// Look around with the moused.
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

	// Rotate the models continiously.
	/*model = glm::rotate(
		model,
		glm::radians(0.1f),
		glm::vec3(0.0f, 1.0f, 0.0f));*/

	// Calculate the view of the camera.
	// Will update the view after a button has been pressed for the movement.
	camera.CalculateView();

	mvp = model * camera.view * camera.projection;
	
	house.RenderAllShapes(camera.projection, camera.view, mvp);

	//texturedShader.Use(); // Textures: http://www.opengl-tutorial.org/beginners-tutorials/tutorial-5-a-textured-cube/.
	cube2.Render(camera.projection, camera.view, mvp);
	//wedge.Render(camera.projection, camera.view, mvp);
	//trapezoid.Render(camera.projection, camera.view, mvp);
	//trapezoidNoRight.Render(camera.projection, camera.view, mvp);
	//pyramid.Render(camera.projection, camera.view, mvp);
	//hexagon.Render(camera.projection, camera.view, mvp);
	//ico.Render(camera.projection, camera.view, mvp);
	//tripri.Render(camera.projection, camera.view, mvp);

	// Objects
	objectShader.Use();

	object.Render(mv);

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
	//texturedShader = Shader(texture_vertexshader_name, texture_fragshader_name);
	objectShader = Shader(object_vertexshader_name, object_fragshader_name);
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

	// Translation, base values are
	model = glm::translate(
		model,
		glm::vec3(1.0f, 2.0f, -1.0f));*/

	// Calculate the camera projection.
	camera.CalculateProjection();

	// Combine everything.
	mvp = model * camera.view * camera.projection;

	/*model = glm::translate(
		model,
		glm::vec3(-1.0f, -1.0f, 1.0f));;*/

	mv = model * camera.view;
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
	house.BufferAllShapes(shader, mvp);
	object.InitBuffers(objectShader, mv, camera.projection);

	cube2.InitBuffers(shader, mvp);
	//cube2.InitBuffersTexture(texturedShader, mvp);
	//wedge.InitBuffers(shader, mvp);
	//trapezoid.InitBuffers(shader, mvp);
	//trapezoidNoRight.InitBuffers(shader, mvp);
	//pyramid.InitBuffers(shader, mvp);
	//hexagon.InitBuffers(shader, mvp);
	//ico.InitBuffers(shader, mvp);
	//tripri.InitBuffers(shader, mvp);
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