#include "Movement.h"

#include <GL/freeglut.h>

Camera Movement::KeyboardKeys(Camera camera, unsigned char key)
{
	// TODO: Implement deltatime from here: https://learnopengl.com/Getting-started/Camera.
	// Helpful: https://github.com/mattearly/TheOnlyEscapeIsESC/blob/master/code/game_callbacks.cpp, ctrl + f on deltatime.
	// All code: https://github.com/mattearly/TheOnlyEscapeIsESC/tree/master/code.

	if (key == 27) // 27 is ESC, closes the tab.
	{
		glutExit();
	}

	key = tolower(key); // Always make the key lowercase, incase you have enabled caps lock.

	/*---------------------------MOVEMENT---------------------------------*/

	if (key == 'w') { // Walk forward.
		// First line of code is for the drone mode, second is for just walking around.
		//camera.cameraPos += cameraSpeedZ * camera.cameraFront;
		camera.cameraPos += walkSpeedZ * glm::normalize(glm::cross(camera.WorldUp, camera.Right));
	}

	if (key == 's') { // Walk backwards.
		// First line of code is for the drone mode, second is for just walking around.
		//camera.cameraPos -= cameraSpeedZ * camera.cameraFront;
		camera.cameraPos -= walkSpeedZ * glm::normalize(glm::cross(camera.WorldUp, camera.Right));
	}

	if (key == 'a') { // Walk left.
		//camera.cameraPos -= glm::normalize(glm::cross(camera.cameraFront, camera.cameraUp)) * cameraSpeedX;
		camera.cameraPos -= camera.Right * walkSpeedX;
	}

	if (key == 'd') { // Walk right
		//camera.cameraPos += glm::normalize(glm::cross(camera.cameraFront, camera.cameraUp)) * cameraSpeedX;
		camera.cameraPos += camera.Right * walkSpeedX;
	}

	// TODO: TURN THIS INTO DRONE MODE!
	if (key == 'q') {
		camera.cameraPos.y += 1.0f;
	}

	if (key == 'e') {
		camera.cameraPos.y -= 1.0f;
	}

	//camera.cameraPos.y = 1.0f; // Keeps you at ground level, so you cannot fly.

	/*---------------------------STRAFING---------------------------------*/

	if (key == 'j') { // Strafing to the left.
		camera.yaw -= 1.0f;
	}

	if (key == 'l') { // Strafing to the right.
		camera.yaw += 1.0f;
	}

	if (key == 'i') { // Strafing up.
		camera.pitch += 1.0f;
	}

	if (key == 'k') { // Strafing down.
		camera.pitch -= 1.0f;
	}

	return camera;
}

Camera Movement::KeyboardKeysSpecial(Camera camera, int key)
{
	// Move around with the arrow keys.
	switch (key)
	{
	case GLUT_KEY_UP: // Move forward.
		// First line of code is for the drone mode, second is for just walking around.
		//camera.cameraPos += cameraSpeedZ * camera.cameraFront;
		camera.cameraPos += walkSpeedZ * glm::normalize(glm::cross(camera.WorldUp, camera.Right));
		break;

	case GLUT_KEY_DOWN: // Move backward.
		// First line of code is for the drone mode, second is for just walking around.
		//camera.cameraPos -= cameraSpeedZ * camera.cameraFront;
		camera.cameraPos -= walkSpeedZ * glm::normalize(glm::cross(camera.WorldUp, camera.Right));
		break;

	case GLUT_KEY_LEFT: // Move left.
		//camera.cameraPos -= glm::normalize(glm::cross(camera.cameraFront, camera.cameraUp)) * cameraSpeedX;
		camera.cameraPos -= camera.Right * walkSpeedX;
		break;

	case GLUT_KEY_RIGHT: // strafe right.
		//camera.cameraPos += glm::normalize(glm::cross(camera.cameraFront, camera.cameraUp)) * cameraSpeedX;
		camera.cameraPos += camera.Right * walkSpeedX;
		break;
	}

	return camera;
}
