#pragma once
#include "./Shape.h"

class Torus : public Shape {
private:
    float outerRadius;  // outer radius (R) of the torus
    float innerRadius;  // inner radius (r) of the tube
    int slices;         // number of slices for each radial section
    int stacks;         // number of radial sections

public:
    Torus(float x, float y, float z, float outerRadius, float innerRadius, int slices = 100, int stacks = 100)
        : Shape(x, y, z, 1) {
        this->outerRadius = outerRadius;
        this->innerRadius = innerRadius;
        this->slices = slices;
        this->stacks = stacks;
    }

public:
    void drawing() {
        Textures* texturesControl = Textures::getInstance();
        texturesControl->loadGLTextures(textures[0]);

        for (int stack = 0; stack <= stacks; stack++) {
            glBegin(GL_QUAD_STRIP);

            for (int slide = 0; slide <= slices; slide++) {
                float ratio_slice = 1.0f * slide / slices;
                float v = 2.0f * PI * ratio_slice;
                float cos_v = cos(v);
                float sin_v = sin(v);

                for (int i = 0; i < 2; i++) {
                    float ratio_stack = 1.0f * (stack + i) / stacks;
                    float u = 2.0f * PI * ratio_stack;
                    float cos_u = cos(u);
                    float sin_u = sin(u);

                    float x = (outerRadius + innerRadius * cos_v) * cos_u;
                    float y = (outerRadius + innerRadius * cos_v) * sin_u;
                    float z = innerRadius * sin_v;

                    glTexCoord2f(ratio_stack, ratio_slice);
                    glVertex3f(x,  y, z);
                }
            }

            glEnd();
        }
    }
};