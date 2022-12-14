#pragma once
#include "./Shape.h"
#include "Circle.h"

class Cylinder : public Shape {
private:
    float bottomRadius;         // Radius of the bottom circle
    float topRadius;            // Radius of the top circle
    float height;               // Height of the cylinder
    int slices;                 // Number of slices (to draw the circles)

public:
    Cylinder(float x, float y, float z, float radius, float height, int slices = 180) : Shape(x, y, z, 3) {
        this->bottomRadius = radius;
        this->topRadius = radius;
        this->height = height;
        this->slices = slices;
    }

    Cylinder(float x, float y, float z, float bottomRadius, float topRadius, float height, int slices = 180) : Shape(x, y, z, 3) {
        this->bottomRadius = bottomRadius;
        this->topRadius = topRadius;
        this->height = height;
        this->slices = slices;
    }


public:
    void drawing() {
        Textures* texturesControl = Textures::getInstance();
        
        // Bottom circle
        glPushMatrix();
        glTranslatef(0.0f, 0.0f, -height / 2.0f);
        texturesControl->loadGLTextures(textures[0]);
        Circle topCircle(0.0f, 0.0f, 0.0f, bottomRadius, slices, textures[0], angle, deltaAngle);
        topCircle.drawing();
        glPopMatrix();

        // Top circle
        glPushMatrix();
        glTranslatef(0.0f, 0.0f, height / 2.0f);
        texturesControl->loadGLTextures(textures[1]);
        Circle bottomCircle(0.0f, 0.0f, 0.0f, topRadius, slices, textures[1], angle, deltaAngle);
        bottomCircle.drawing();
        glPopMatrix();

        // Side
        texturesControl->loadGLTextures(textures[2]);
        glBegin(GL_QUAD_STRIP);
        float delta = 360.0f / slices;
        for (float deg = 0.0f; deg <= 360.0f; deg += delta) {
           float rad = deg * (PI / 180.0f);
           float ratio = deg / 360.0f;
           glTexCoord2f(ratio, 0.0f);
           glVertex3f((float)cos(rad) * bottomRadius, (float)sin(rad) * bottomRadius, -height / 2.0f);
           glTexCoord2f(ratio, 1.0f);
           glVertex3f((float)cos(rad) * topRadius, (float)sin(rad) * topRadius, height / 2.0f);

        }
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(bottomRadius, 0.0f, -height / 2.0f);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(topRadius, 0.0f, height / 2.0f);
        glEnd();
    }
};