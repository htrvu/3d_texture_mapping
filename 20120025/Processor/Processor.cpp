#include <GL/glut.h>
#include "Processor.h"
#include "../Shape/index.h"

// Static attributes

Storage Processor::storage = Storage();

////////////////////////////////////////////////////////////////////////////////////

// Functions

void Processor::display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW); // To operate on model-view matrix

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	Processor::storage.draw();

    glutSwapBuffers();
}

void Processor::initShapes() {
    Processor::storage.addShapes({
        new Circle(-2.2f, 2.0f, -5.0f, 0.7f),
        new Cube(0.0f, 1.8f, -5.0f, 0.5f),
        new Torus(2.0f, 2.0f, -5.0f, 0.5f, 0.2f),
        new Cylinder(-2.2f, 0.0f, -5.0f, 0.5f, 1.0f),
        new Sphere(0.0f, 0.0f, -5.0f, 0.7f),
        new Cone(2.0f, 0.0f, -5.0f, 0.8f, 1.0f),
        new Paraboloid(-1.0f, -2.0f, -5.0f, 0.7f, 0.7f, 0.8f),
        new Hyperboloid(1.0f, -2.0f, -5.0f, 0.5f, 0.5f, 0.3f, 0.7f)

        // Demo for each shape:
        //new Cube(0.0f, 0.0f, -5.0f, 1.0f)
        //new MyEllipse(0.0f, 0.0f, -5.0f, 2.0f, 1.0f)
        //new Circle(0.0f, 0.0f, -5.0f, 1.5f)
        //new Cylinder(0.0f, 0.0f, -5.0f, 1.5f, 2.0f, 50)
        //new Cone(0.0f, 0.0f, -5.0f, 1.5f, 2.0f, 50)
        //new Sphere(0.0f, 0.0f, -5.0f, 1.3f)
        //new Torus(0.0f, 0.0f, -5.0f, 1.3f, 0.4f)
        //new Paraboloid(0.0f, 0.0f, -5.0f, 1.0f, 1.0f, 1.8f, 20, 30)
        //new Hyperboloid(0.0f, 0.0f, -5.0f, 0.7f, 0.7f, 0.3f, 1.3f)
        //new Hyperboloid(0.0f, 0.0f, -5.0f, -0.7f, -0.7f, 0.3f, 1.0f)
    });
}

void Processor::reshape(GLsizei width, GLsizei height) {
    if (height == 0)
        height = 1; // To prevent divide by 0

	GLfloat aspect = (GLfloat)width / (GLfloat)height;

	// Set the viewport to cover the new window
	glViewport(0, 0, width, height);

	// Set the aspect ratio of the clipping volume to match the viewport
	glMatrixMode(GL_PROJECTION); // To operate on the Projection matrix
	glLoadIdentity(); // Reset

	// Enable perspective projection with fovy, aspect, zNear and zFar
	gluPerspective(60.0f, aspect, 0.1f, 100.0f);
}


void Processor::timer(int value) {
	glutPostRedisplay();
	glutTimerFunc(REFRESH_DELAY, timer, 0); 
}