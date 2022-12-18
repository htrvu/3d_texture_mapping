#pragma once
#include "./Shape.h"

class Cube : public Shape {
private:
    float size;     // 1/2 of the cube's side length

public:
    Cube(float x, float y, float z, float size) : Shape(x, y, z, 6) {
        this->size = size;
    }

public:
    void drawing() {
        Textures* texturesControl = Textures::getInstance();

        // Front Face
        texturesControl->loadGLTextures(textures[0]);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f * size, -1.0f * size, 1.0f * size);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f * size, -1.0f * size, 1.0f * size);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f * size, 1.0f * size, 1.0f * size);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f * size, 1.0f * size, 1.0f * size);
        glEnd();

        // Back Face
        texturesControl->loadGLTextures(textures[1]);
        glBegin(GL_QUADS);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f * size, -1.0f * size, -1.0f * size);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f * size, 1.0f * size, -1.0f * size);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f * size, 1.0f * size, -1.0f * size);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f * size, -1.0f * size, -1.0f * size);
        glEnd();

        // Top Face
        texturesControl->loadGLTextures(textures[2]);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f * size, 1.0f * size, -1.0f * size);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f * size, 1.0f * size, 1.0f * size);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f * size, 1.0f * size, 1.0f * size);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f * size, 1.0f * size, -1.0f * size);
        glEnd();

        // Bottom Face
        texturesControl->loadGLTextures(textures[3]);
        glBegin(GL_QUADS);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f * size, -1.0f * size, -1.0f * size);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f * size, -1.0f * size, -1.0f * size);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f * size, -1.0f * size, 1.0f * size);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f * size, -1.0f * size, 1.0f * size);
        glEnd();

        // Right face
        texturesControl->loadGLTextures(textures[4]);
        glBegin(GL_QUADS);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f * size, -1.0f * size, -1.0f * size);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f * size, 1.0f * size, -1.0f * size);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f * size, 1.0f * size, 1.0f * size);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f * size, -1.0f * size, 1.0f * size);
        glEnd();

        // Left Face
        texturesControl->loadGLTextures(5);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f * size, -1.0f * size, -1.0f * size);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f * size, -1.0f * size, 1.0f * size);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f * size, 1.0f * size, 1.0f * size);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f * size, 1.0f * size, -1.0f * size);
        glEnd();
    }
};