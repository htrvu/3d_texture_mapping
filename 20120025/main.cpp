#define _CRT_SECURE_NO_WARNINGS
#define GL_GLEXT_PROTOTYPES

#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <vector>
#include <string>
#include "Processor/Processor.h"
#include "Provider/Textures.h"
using namespace std;

int main(int argc, char** argv) {
    cout << "Hoang Trong Vu - 20120025 - CNTN20" << endl;
    cout << "Computer graphics - Lab 4: 3D Transformations and Texture Mapping" << endl;
    cout << "-----------------------------------------------------------------" << endl << endl;

	srand(time(NULL));

    // Init window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
	glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
	glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
	glutCreateWindow("Hoang Trong Vu - 20120025 - CNTN20");

	glutDisplayFunc(Processor::display);
	glutReshapeFunc(Processor::reshape);
	glutTimerFunc(0, Processor::timer, 0);

    // Init textures
    Textures::getInstance();

    // Init shapes
    Processor::initShapes();

	initGL();
	glutMainLoop(); // Enter the infinite event-processing loop

	return 0;
}