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

	if (key == 'v') {
		if (camera.walkModeEnabled) {
			camera.walkModeEnabled = false;
			camera.walkMode = camera.currentvm; // Make sure that the camera changes are in walk mode, so that you can switch back to it!
			camera.currentvm = camera.droneMode;
		}
		else {
			camera.walkModeEnabled = true;
			camera.droneMode = camera.currentvm;
			camera.currentvm = camera.walkMode;
		}
	}

	/*---------------------------MOVEMENT---------------------------------*/

	if (key == 'w') { // Walk forward.
		camera.currentvm.cameraPos += CalculateForwardOrBackward(camera);
	}

	if (key == 's') { // Walk backwards.
		camera.currentvm.cameraPos -= CalculateForwardOrBackward(camera);
	}

	if (key == 'a') { // Walk left.
		camera.currentvm.cameraPos -= CalculateRightOrLeft(camera);
	}

	if (key == 'd') { // Walk right
		camera.currentvm.cameraPos += CalculateRightOrLeft(camera);
	}

	if (camera.walkModeEnabled) {
		// Keeps you at ground level, so you cannot fly while in walk mode.
		camera.currentvm.cameraPos.y = 1.0f;
	}
	else {
		if (key == 'q') {
			camera.currentvm.cameraPos.y += 1.0f;
		}

		if (key == 'e') {
			camera.currentvm.cameraPos.y -= 1.0f;
		}
	}

	/*---------------------------STRAFING---------------------------------*/

	if (key == 'i') { // Strafe up.
		camera.currentvm.pitch += 1.0f;
	}

	if (key == 'k') { // Strafe down.
		camera.currentvm.pitch -= 1.0f;
	}

	if (key == 'j') { // Strafe to the left.
		camera.currentvm.yaw -= 1.0f;
	}

	if (key == 'l') { // Strafe to the right.
		camera.currentvm.yaw += 1.0f;
	}

	return camera;
}

Camera Movement::KeyboardKeysSpecial(Camera camera, int key)
{
	// Move around with the arrow keys.
	switch (key)
	{
	case GLUT_KEY_UP: // Move forward.
		camera.currentvm.cameraPos += CalculateForwardOrBackward(camera);
		break;

	case GLUT_KEY_DOWN: // Move backward.
		camera.currentvm.cameraPos -= CalculateForwardOrBackward(camera);
		break;

	case GLUT_KEY_LEFT: // Move left.
		camera.currentvm.cameraPos -= CalculateRightOrLeft(camera);
		break;

	case GLUT_KEY_RIGHT: // Move right.
		camera.currentvm.cameraPos += CalculateRightOrLeft(camera);
		break;
	}
	return camera;
}

glm::vec3 Movement::CalculateForwardOrBackward(Camera camera)
{
	glm::vec3 movement;
	if (camera.walkModeEnabled) {
		// Calculates the movement while in walk mode. Makes sure that you do not slow down if you look down or up.
		movement = walkSpeedZ * glm::normalize(glm::cross(camera.currentvm.WorldUp, camera.currentvm.Right));
	}
	else {
		// Calculates the movement while in drone mode, you also move down or up while in this mode.
		movement = walkSpeedZ * camera.currentvm.cameraFront;
	}
	return movement;
}

glm::vec3 Movement::CalculateRightOrLeft(Camera camera)
{
	glm::vec3 movement;
	if (camera.walkModeEnabled) {
		// Calculates the movement for left/right while in walk mode.
		movement = glm::normalize(glm::cross(camera.currentvm.cameraFront, camera.currentvm.cameraUp)) * walkSpeedX;
	}
	else {
		// Calculates the movement for left/right while in drone mode.
		movement = camera.currentvm.Right * walkSpeedX;
	}
	return movement;
}
