#pragma once
#include "../utils/glUtils.h"
#include "../utils/logics.h"
#include "../macros.h"
#include "../Provider/Textures.h"

class Shape {
protected:
    float x, y, z;              // Center position
    float angle;                // Angle of rotation
    float zrot;                 // Z-axis rotation
    float deltaAngle;           // Angle of rotation per frame
    vector<GLuint> textures;    // Textures for mapping
    
protected:
    Shape(float x, float y, float z, int nTexture) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->angle = 0.0f;
        this->zrot = randFloat(0.5f, 0.9f);
        this->deltaAngle = randFloat(0.3f, 0.5f);
        
        int maxTextureId = Textures::getInstance()->getNTexture();
        textures.push_back(randInt(0, maxTextureId - 1));
        for (int i = 1; i < nTexture; i++) {
            int id;
            do {
                id = randInt(0, maxTextureId - 1);
            } while (id == textures[i - 1]);
            textures.push_back(id);
        }        
    }

protected:
    virtual void drawing() = 0;

public:
    virtual void draw() {
        glPushMatrix();
        glTranslatef(x, y, z);
        glRotatef(angle, -1.0f, -1.5f, zrot);

        drawing();

        angle += deltaAngle;
        glPopMatrix();
    }
};
