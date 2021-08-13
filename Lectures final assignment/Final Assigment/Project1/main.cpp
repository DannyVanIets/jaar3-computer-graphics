#include <iostream>

#include <GL/glew.h>
#include <GL/freeglut.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "glsl.h"

#include "Camera.h"
#include "Movement.h"

#include "texture/TextureLoader.h"

#include "World.h"
#include "Cube.h"
#include "CustomPlane.h"

using namespace std;

//--------------------------------------------------------------------------------
// Consts
//--------------------------------------------------------------------------------

const int WIDTH = 800, HEIGHT = 600;

const char* skybox_vertexshader_name = "skyboxvs.vert";
const char* skybox_fragshader_name = "skyboxfs.frag";

const char* texture_vertexshader_name = "texturevs.vert";
const char* texture_fragshader_name = "texturefs.frag";

//const char* texture_name = "texture/uvtemplate.bmp";
const char* texture_name = "texture/Yellobrk.bmp";

unsigned const int DELTA_TIME = 10;

//--------------------------------------------------------------------------------
// Variables
//--------------------------------------------------------------------------------
GLuint texture_id;
Shader textureShader;

Camera camera;
Movement movement;

World world = World(3.0f, 0.0f, 1.0f);
Cube cube2 = Cube(0.0, 0.0, 0.0, "./Yellobrk.bmp");
CustomPlane customplane = CustomPlane(5.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0, "texture/Yellobrk.bmp");

//--------------------------------------------------------------------------------
// Rendering
//--------------------------------------------------------------------------------

void Render()
{
	// Define background
	glClearColor(0.0, 0.5, 0.5, 0.5);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// For anti-aliasing
	//glEnable(GL_MULTISAMPLE);

	// Calculate the view of the camera.
	// Will update the view after a button has been pressed for the movement.
	camera.CalculateView();

	world.RenderAll(camera.currentvm.projection, camera.currentvm.view);
	//world.RenderModels(camera.currentvm.projection, camera.currentvm.view);

	//glBindTexture(GL_TEXTURE_2D, texture_id);
	customplane.Render(camera.currentvm.projection, camera.currentvm.view, texture_id);

	cube2.shader.Use();
	cube2.CalculateMvp(camera.currentvm.projection, camera.currentvm.view);
	textureShader.Use(); // Textures: http://www.opengl-tutorial.org/beginners-tutorials/tutorial-5-a-textured-cube/.
	cube2.Render(camera.currentvm.projection, camera.currentvm.view);

	// Swap buffers
	glutSwapBuffers();
}

//-----------------------------------------------------------
// void InitBuffers()
// Allocates and fills buffers
//------------------------------------------------------------

void InitBuffers()
{
	world.InitBufferAll(camera.currentvm.projection, camera.currentvm.view);
	//world.InitBufferModels(camera.currentvm.projection, camera.currentvm.view);

	customplane.InitBuffer(camera.currentvm.projection, camera.currentvm.view, texture_id);

	cube2.CalculateMvp(camera.currentvm.projection, camera.currentvm.view);
	cube2.shader = textureShader;
	cube2.texture_id = 1;
	cube2.InitBufferWithShadingAndTexture(camera.currentvm.projection);
}

//------------------------------------------------------------
// void InitShaders()
// Initializes the fragmentshader and vertexshader
//------------------------------------------------------------

void InitLoadShaders() {
	customplane.LoadShader();
}

void InitLoadTextures() {
	customplane.InitLoadTextures();
	textureShader = Shader(texture_vertexshader_name, texture_fragshader_name);
	texture_id = loadBMP(texture_name);
}

//--------------------------------------------------------------------------------
// Control handling, with keyboard and mouse
//--------------------------------------------------------------------------------

void keyboardHandler(unsigned char key, int a, int b)
{
	// Move around with WASD and/or look around with IJKL.
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
	//glutSetOption(GLUT_MULTISAMPLE, 8);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	//glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_MULTISAMPLE);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Hello there");
	glutDisplayFunc(Render);

	// For the movement with WASD.
	glutKeyboardFunc(keyboardHandler);

	// For the movement with arrow keys.
	glutSpecialFunc(pressKeySpecial);

	// For the mouse.
	glutSetCursor(GLUT_CURSOR_NONE); // Hides the mouse.
	glutPassiveMotionFunc(MouseCallback);

	glutTimerFunc(DELTA_TIME, Render, 0);

	glewExperimental = GL_TRUE;

	glewInit();
}

int main(int argc, char** argv)
{
	InitGlutGlew(argc, argv); 
	InitLoadShaders();
	camera.CalculateProjection(); // TODO: Move this somewhere else.
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