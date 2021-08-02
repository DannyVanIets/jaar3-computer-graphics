#include "Movement.h"

#include <GL/freeglut.h>

Camera Movement::KeyboardKeys(Camera camera, unsigned char key)
{
	// Move around with WASD.
	// TODO: Implement deltatime from here: https://learnopengl.com/Getting-started/Camera.
	// Helpful: https://github.com/mattearly/TheOnlyEscapeIsESC/blob/master/code/game_callbacks.cpp, ctrl + f on deltatime.
	// All code: https://github.com/mattearly/TheOnlyEscapeIsESC/tree/master/code.

	if (key == 27) // 27 is ESC, closes the tab.
	{
		glutExit();
	}

	key = tolower(key); // Always make the key lowercase, incase you have enabled caps lock.

	/*---------------------------MOVEMENT---------------------------------*/

	if (key == 87 || key == 119) { // 87 is W and 119 is w, moving forwards.
		// First line of code is for the drone mode, second is for just walking around.
		//camera.cameraPos += cameraSpeedZ * camera.cameraFront;
		camera.cameraPos += walkSpeedZ * glm::normalize(glm::cross(camera.WorldUp, camera.Right));
	}

	if (key == 83 || key == 115) { // 83 is S and 115 is s, moving backwards.
		// First line of code is for the drone mode, second is for just walking around.
		//camera.cameraPos -= cameraSpeedZ * camera.cameraFront;
		camera.cameraPos -= walkSpeedZ * glm::normalize(glm::cross(camera.WorldUp, camera.Right));
	}

	if (key == 65 || key == 97) { // 65 is A and 97 is a, moving left.
		//camera.cameraPos -= glm::normalize(glm::cross(camera.cameraFront, camera.cameraUp)) * cameraSpeedX;
		camera.cameraPos -= camera.Right * walkSpeedX;
	}

	if (key == 68 || key == 100) { // 68 is D and 100 is d, moving right.
		//camera.cameraPos += glm::normalize(glm::cross(camera.cameraFront, camera.cameraUp)) * cameraSpeedX;
		camera.cameraPos += camera.Right * walkSpeedX;
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

	return camera;
}

Camera Movement::KeyboardKeysSpecial(Camera camera, int key)
{
	// Move around with the arrow keys.
	switch (key)
	{
	case GLUT_KEY_UP: // Move forward.
		camera.cameraPos += walkSpeedZ * camera.cameraFront;
		break;

	case GLUT_KEY_DOWN: // Move backward.
		camera.cameraPos -= walkSpeedZ * camera.cameraFront;
		break;

	case GLUT_KEY_LEFT: // Move left
		camera.cameraPos -= glm::normalize(glm::cross(camera.cameraFront, camera.cameraUp)) * walkSpeedX;
		break;

	case GLUT_KEY_RIGHT: // strafe right.
		camera.cameraPos += glm::normalize(glm::cross(camera.cameraFront, camera.cameraUp)) * walkSpeedX;
		break;
	}

	return camera;
}
