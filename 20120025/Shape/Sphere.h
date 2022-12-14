#pragma once
#include "./Shape.h"

class Sphere : public Shape {
private:
    float radius;   // radius of the sphere
    int stack;      // number of stacks (or the number of circles)
    int slices;     // number of slices (to draw the circles)

public:
    Sphere(float x, float y, float z, float radius, int stack = 50, int slices = 180) : Shape(x, y, z, 1) {
        this->radius = radius;
        this->stack = stack;
        this->slices = slices;
    }

public:
    void drawing() {
        Textures* texturesControl = Textures::getInstance();
        texturesControl->loadGLTextures(textures[0]);

        GLUquadric* sphere = gluNewQuadric();
        gluQuadricDrawStyle(sphere, GLU_FILL);
        gluQuadricTexture(sphere, GL_TRUE);
        gluQuadricNormals(sphere, GLU_SMOOTH);
        gluSphere(sphere, radius, stack, slices);
    }
};