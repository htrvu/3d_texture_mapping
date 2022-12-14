#pragma once
#include "./Shape.h"
#include "Circle.h"

class Paraboloid : public Shape {
private:
    float a, b;     // y = x^2 / a + z ^ 2 / b, a and b are positive
    float height;   // height of paraboloid
    int stacks;     // number of stacks (to draw the side)
    int slices;     // number of slices (to draw the circles)

public:
    Paraboloid(float x, float y, float z, float a, float b, float height, int stacks = 50, int slices = 180)
        : Shape(x, y, z, 1) {
        this->a = abs(a);
        this->b = abs(b);
        this->height = abs(height);
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
                float ratio_slice = (float)slice / slices;
                float rad = 2.0f * PI * ratio_slice;

                for (int i = 0; i < 2; i++) {
                    float ratio_stack = (float)(stack + i) / stacks;
                    float z = (1.0f - ratio_stack) * height;

                    float radiusX = sqrt(z * a);
                    float radiusZ = sqrt(z * b);

                    float x = radiusX * cos(rad);
                    float y = radiusZ * sin(rad);

                    glTexCoord2f(ratio_slice, ratio_stack);
                    glVertex3f(x, y, z - height / 2);
                }
            }

            glEnd();
        }
    }
};