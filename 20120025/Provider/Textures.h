#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <GL/glut.h>
#include "../SOIL/SOIL.h"
using namespace std;

class Textures {
private:
    vector<GLuint> textures; // Storage for textures
    int nTexture = 0; // Number of available texture ids

private:
    Textures() {
    	vector<string> paths = {
             "E:/HCMUS Journey/Semesters/5 - 2022/Computer Graphics/Labs/4 - 3D Object Transformation and Texture Mapping/workspace/Debug/textures/texture0.jpg",
             "E:/HCMUS Journey/Semesters/5 - 2022/Computer Graphics/Labs/4 - 3D Object Transformation and Texture Mapping/workspace/Debug/textures/texture1.jpg",
             "E:/HCMUS Journey/Semesters/5 - 2022/Computer Graphics/Labs/4 - 3D Object Transformation and Texture Mapping/workspace/Debug/textures/texture2.jpg",
             "E:/HCMUS Journey/Semesters/5 - 2022/Computer Graphics/Labs/4 - 3D Object Transformation and Texture Mapping/workspace/Debug/textures/texture3.jpg",
             "E:/HCMUS Journey/Semesters/5 - 2022/Computer Graphics/Labs/4 - 3D Object Transformation and Texture Mapping/workspace/Debug/textures/texture4.jpg",
             "E:/HCMUS Journey/Semesters/5 - 2022/Computer Graphics/Labs/4 - 3D Object Transformation and Texture Mapping/workspace/Debug/textures/texture5.jpg",
             "E:/HCMUS Journey/Semesters/5 - 2022/Computer Graphics/Labs/4 - 3D Object Transformation and Texture Mapping/workspace/Debug/textures/texture6.jpg",
             "E:/HCMUS Journey/Semesters/5 - 2022/Computer Graphics/Labs/4 - 3D Object Transformation and Texture Mapping/workspace/Debug/textures/texture7.jpg",
             "E:/HCMUS Journey/Semesters/5 - 2022/Computer Graphics/Labs/4 - 3D Object Transformation and Texture Mapping/workspace/Debug/textures/texture8.jpg",
             "E:/HCMUS Journey/Semesters/5 - 2022/Computer Graphics/Labs/4 - 3D Object Transformation and Texture Mapping/workspace/Debug/textures/texture9.jpg",
        };

        cout << "Loading textures..." << endl;
        this->readGLTextures(paths);
        cout << "Completed!" << endl;
    }

private:
    // Load image files and convert to textures
    void readGLTextures(vector<string> filenames) {
        for (int i = 0; i < filenames.size(); i++) {
            GLuint id = SOIL_load_OGL_texture(
                filenames[i].c_str(),
                SOIL_LOAD_AUTO,
                SOIL_CREATE_NEW_ID,
                SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT

            );
            if (id == 0)
                continue;
                
            this->textures.push_back(id);
            this->nTexture++;

            glBindTexture(GL_TEXTURE_2D, id);
            glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
            glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        }
    }

public:
    static Textures* getInstance() {
        static Textures instance;
        return &instance;
    }

    Textures(Textures const&) = delete;
    void operator=(Textures const&) = delete;

public:
    int getNTexture() {
        return this->nTexture;
    }

    void loadGLTextures(int idx) {
        glBindTexture(GL_TEXTURE_2D, this->textures[idx]);
    }
};
