#pragma once
#include "./Shape.h"

class MyEllipse : public Shape {
private:
    float a, b;
    int slices;

public:
    MyEllipse(float x, float y, float z, float a, float b, int slices = 180) : Shape(x, y, z, 1) {
        this->a = a;
        this->b = b;
        this->slices = slices;
    }

    MyEllipse(float x, float y, float z, float a, float b, int slices, int texture, float angle, float deltaAngle) : Shape(x, y, z, 1) {
        this->a = a;
        this->b = b;
        this->slices = slices;
        this->textures[0] = texture;
        this->angle = angle;
        this->deltaAngle = deltaAngle;
    }

public:
    void drawing() {
        if (a == 0.0f || b == 0.0f)
            return;
            
        Textures* texturesControl = Textures::getInstance();
        texturesControl->loadGLTextures(textures[0]);

        glBegin(GL_POLYGON);

        float tarX, tarY;
        float curX, curY;

        glTexCoord2f(0.5f, 0.5f);

        float delta = 360.0f / slices;
        for (float deg = 0.0f; deg <= 360.0f; deg += delta) {
            float rad = deg * (PI / 180.0f);

            curX = (float)cos(rad) * a;
            curY = (float)sin(rad) * b;
            glVertex3f(curX, curY, 0.0f);

            tarX = 0.5f * ((float)cos(rad) + 1);
            tarY = 0.5f * ((float)sin(rad) + 1);
            glTexCoord2f(tarX, tarY);
        }

        tarX = (1.0f + 1.0f) * 0.5f;
        tarY = (0.0f + 1.0f) * 0.5f;
        glTexCoord2f(tarX, tarY);

        glVertex3f(1.0f * a, 0.0f, 0.0f);

        glEnd();
    }
};