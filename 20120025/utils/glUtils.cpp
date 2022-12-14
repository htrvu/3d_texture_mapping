#include "./glUtils.h"
#include "../macros.h"

void initGL() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClearDepth(1.0f); // Set background depth to farthest

	glEnable(GL_DEPTH_TEST); // Enable depth testing for z-culling
	glDepthFunc(GL_LEQUAL); // Set the type of depth-test

	glShadeModel(GL_SMOOTH); // Enable smooth shading

	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Nice perspective corrections
	glEnable(GL_TEXTURE_2D); // Enable Texture Mapping
}