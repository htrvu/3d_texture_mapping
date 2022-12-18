#pragma once
#include "./Shape.h"

class Sphere : public Shape {
private:
    float radius;   // radius of the sphere
    int stacks;     // number of stacks (or the number of circles)
    int slices;     // number of slices (to draw the circles)

public:
    Sphere(float x, float y, float z, float radius, int stacks = 100, int slices = 180) : Shape(x, y, z, 1) {
        this->radius = radius;
        this->stacks = stacks;
        this->slices = slices;
    }

public:
    void drawing() {
        Textures* texturesControl = Textures::getInstance();
        texturesControl->loadGLTextures(textures[0]);

        for (int stack = 0; stack <= stacks; stack++) {
            glBegin(GL_QUAD_STRIP);

            for (int slice = 0; slice <= slices; slice++) {
                float ratio_slice = 1.0f * slice / slices;
                float v = 2.0f * PI * ratio_slice;
                float cos_v = cos(v);
                float sin_v = sin(v);

                for (int i = 0; i < 2; i++) {
                    float ratio_stack = (float)(stack + i) / stacks;
                    float u = PI * ratio_stack;

                    float cos_u = cos(u);
                    float sin_u = sin(u);

                    float x = radius * sin_u * cos_v;
                    float y = radius * sin_u * sin_v;
                    float z = radius * cos_u;

                    glTexCoord2f(ratio_slice, ratio_stack);
                    glVertex3f(x, y, z);
                }

            }

            glEnd();
        }
    }
};