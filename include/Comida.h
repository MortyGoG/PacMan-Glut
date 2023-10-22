#ifndef COMIDA_H
#define COMIDA_H

#include <string>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "RgbImage.h"
#include <stdlib.h>
#include <iostream>

#define NTextures 1

using namespace std;

class Comida
{
    public:
        // Constru
        Comida(char *filename1);

        // Textura
        GLuint	texture[NTextures];
        char* textura1;
        int texturaNum;

        // Vars
        float dirX;
        float dirY;

        // Metodos
        void loadTexture();
        void draw();
};

#endif // COMIDA_H
