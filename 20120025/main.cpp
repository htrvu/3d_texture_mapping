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
    // system("mode con COLS=700");
    // ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
    // SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);

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

// ///////////////////////////////////////////////////////////////////////////////
// // A hyperboloid1sheet.cpp
// //
// // A hyperboloid of one sheet is approximated with a triangular mesh. It is
// // parametrized by the equations x = sec v cos u, y = sec v sin u, z = tan v.
// //
// // Interaction:
// // Press left/right arrow keys to increase/decrease the number of grid columns.
// // Press up/down arrow keys to increase/decrease the number of grid rows.
// // Press x, X, y, Y, z, Z to turn the surface.
// //
// // Sumanta Guha.
// ///////////////////////////////////////////////////////////////////////////////

// #include <cmath>
// #include <iostream>
// #include <GL/glut.h>

// #define PI 3.14159265358979324

// using namespace std;

// // Globals.
// static int p = 8;                                         // Number of grid columns.
// static int q = 8;                                         // Number of grid rows
// static float *vertices = NULL;                            // Vertex array of the mapped sample on the surface.
// static float Xangle = 330.0, Yangle = 0.0, Zangle = 0.0;  // Angles to rotate the surface.

// // Fuctions to map the grid vertex (u_i,v_j) to the mesh vertex (f(u_i,v_j), g(u_i,v_j), h(u_i,v_j)) on the patch.
// float f(int i, int j) { return (cos((-1 + 2.0 * (float)i / p) * PI) / cos((-0.4 + 0.8 * (float)j / q) * PI)); }

// float g(int i, int j) { return (sin((-1 + 2.0 * (float)i / p) * PI) / cos((-0.4 + 0.8 * (float)j / q) * PI)); }

// float h(int i, int j) { return (tan((-0.4 + 0.8 * (float)j / q) * PI)); }

// // Routine to fill the vertex array with co-ordinates of the mapped sample points.
// void fillVertexArray(void) {
//     int i, j, k;

//     k = 0;
//     for (j = 0; j <= q; j++)
//         for (i = 0; i <= p; i++) {
//             vertices[k++] = f(i, j);
//             vertices[k++] = g(i, j);
//             vertices[k++] = h(i, j);
//         }
// }

// // Initialization routine.
// void setup(void) {
//     glEnableClientState(GL_VERTEX_ARRAY);

//     glClearColor(1.0, 1.0, 1.0, 0.0);
// }

// // Drawing routine.
// void drawScene(void) {
//     int i, j;
//     vertices = new float[3 * (p + 1) * (q + 1)];  // Dynamic array allocation with new value of p and q.

//     glVertexPointer(3, GL_FLOAT, 0, vertices);
//     glClear(GL_COLOR_BUFFER_BIT);

//     glLoadIdentity();
//     gluLookAt(0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

//     glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

//     glColor3f(0.0, 0.0, 0.0);

//     // Rotate scene.
//     glRotatef(Zangle, 0.0, 0.0, 1.0);
//     glRotatef(Yangle, 0.0, 1.0, 0.0);
//     glRotatef(Xangle, 1.0, 0.0, 0.0);

//     // Fill the vertex array.
//     fillVertexArray();

//     // Make the approximating triangular mesh.
//     for (j = 0; j < q; j++) {
//         glBegin(GL_TRIANGLE_STRIP);
//         for (i = 0; i <= p; i++) {
//             glArrayElement((j + 1) * (p + 1) + i);
//             glArrayElement(j * (p + 1) + i);
//         }
//         glEnd();
//     }

//     glutSwapBuffers();
// }

// // OpenGL window reshape routine.
// void resize(int w, int h) {
//     glViewport(0, 0, (GLsizei)w, (GLsizei)h);
//     glMatrixMode(GL_PROJECTION);
//     glLoadIdentity();
//     gluPerspective(60.0, (float)w / (float)h, 1.0, 50.0);
//     glMatrixMode(GL_MODELVIEW);
// }

// // Keyboard input processing routine.
// void keyInput(unsigned char key, int x, int y) {
//     switch (key) {
//         case 27:
//             exit(0);
//             break;
//         case 'x':
//             Xangle += 5.0;
//             if (Xangle > 360.0)
//                 Xangle -= 360.0;
//             glutPostRedisplay();
//             break;
//         case 'X':
//             Xangle -= 5.0;
//             if (Xangle < 0.0)
//                 Xangle += 360.0;
//             glutPostRedisplay();
//             break;
//         case 'y':
//             Yangle += 5.0;
//             if (Yangle > 360.0)
//                 Yangle -= 360.0;
//             glutPostRedisplay();
//             break;
//         case 'Y':
//             Yangle -= 5.0;
//             if (Yangle < 0.0)
//                 Yangle += 360.0;
//             glutPostRedisplay();
//             break;
//         case 'z':
//             Zangle += 5.0;
//             if (Zangle > 360.0)
//                 Zangle -= 360.0;
//             glutPostRedisplay();
//             break;
//         case 'Z':
//             Zangle -= 5.0;
//             if (Zangle < 0.0)
//                 Zangle += 360.0;
//             glutPostRedisplay();
//             break;
//         default:
//             break;
//     }
// }

// // Callback routine for non-ASCII key entry.
// void specialKeyInput(int key, int x, int y) {
//     if (key == GLUT_KEY_LEFT)
//         if (p > 3)
//             p -= 1;
//     if (key == GLUT_KEY_RIGHT)
//         p += 1;
//     if (key == GLUT_KEY_DOWN)
//         if (q > 3)
//             q -= 1;
//     if (key == GLUT_KEY_UP)
//         q += 1;

//     glutPostRedisplay();
// }

// // Routine to output interaction instructions to the C++ window.
// void printInteraction(void) {
//     cout << "Interaction:" << endl;
//     cout << "Press left/right arrow keys to increase/decrease the number of grid columns." << endl
//          << "Press up/down arrow keys to increase/decrease the number of grid rows." << endl
//          << "Press x, X, y, Y, z, Z to turn the surface." << endl;
// }

// // Main routine.
// int main(int argc, char **argv) {
//     printInteraction();
//     glutInit(&argc, argv);
//     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//     glutInitWindowSize(500, 500);
//     glutInitWindowPosition(100, 100);
//     glutCreateWindow("hyperboloid1sheet.cpp");
//     setup();
//     glutDisplayFunc(drawScene);
//     glutReshapeFunc(resize);
//     glutKeyboardFunc(keyInput);
//     glutSpecialFunc(specialKeyInput);
//     glutMainLoop();

//     return 0;
// }
