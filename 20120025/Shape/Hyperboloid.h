#pragma once
#include "./Shape.h"
#include "./MyEllipse.h"

class Hyperboloid : public Shape {
private:
    float a, b, c;  // x^2 / a^2 + y^2 / b^2 - z^2 / c^2 = 1
    float height;   // Height of the hyperboloid
    int stacks;     // Number of stacks (to draw the side)
    int slices;     // Number of slices (to draw the circles)

public:
    Hyperboloid(float x, float y, float z, float a, float b, float c, float height, int stacks = 50, int slices = 360)
        : Shape(x, y, z, 3) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->height = height;
        this->stacks = stacks;
        this->slices = slices;
    }

public:
    void drawing() {
        float tHeight = height / c;

        Textures* texturesControl = Textures::getInstance();
        float radiusA = sqrt(a * a * (tHeight * tHeight / 4.0f + 1));
        float radiusB = sqrt(b * b * (tHeight * tHeight / 4.0f + 1));

        // Bottom ellipse
        glPushMatrix();
        texturesControl->loadGLTextures(textures[0]);
        glTranslatef(0.0f, 0.0f, -height / 2.0f);
        MyEllipse topEllipse(x, y, z, radiusA, radiusB, slices, textures[0], angle, deltaAngle);
        topEllipse.drawing();
        glPopMatrix();

        // Top ellipse
        glPushMatrix();
        glTranslatef(0.0f, 0.0f, height / 2.0f);
        texturesControl->loadGLTextures(textures[1]);
        MyEllipse bottomEllipse(x, y, z, radiusA, radiusB, slices, textures[1], angle, deltaAngle);
        bottomEllipse.drawing();
        glPopMatrix();

        // Side
        texturesControl->loadGLTextures(textures[2]);

        for (int stack = 0; stack <= stacks; stack++) {
            glBegin(GL_QUAD_STRIP);

            float ratio_stack = 1.0f * stack / stacks;
            float v = ratio_stack * tHeight / 2.0f;

            for (int slide = 0; slide <= slices; slide++) {
                float ratio_slice = 1.0f * slide / slices;
                float u = 2.0f * PI * ratio_slice;          
                float cos_u = cos(u);
                float sin_u = sin(u);
                
                float x1 = a * (cos_u - v * sin_u);
                float y1 = b * (sin_u + v * cos_u);
                float z1 = c * v;

                float x2 = a * (cos_u + v * sin_u);
                float y2 = b * (sin_u - v * cos_u);
                float z2 = - c * v;

                glVertex3f(x2, y2, z2);
                glVertex3f(x1, y1, z1);

                glTexCoord2f(ratio_slice, ratio_stack);
            }

            glEnd();
        }
    }
};