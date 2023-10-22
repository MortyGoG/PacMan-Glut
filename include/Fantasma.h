#ifndef FANTASMA_H
#define FANTASMA_H

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "RgbImage.h"
#include <stdlib.h>
#include <iostream>

#include <windows.h>
#include <mmsystem.h>

#include <cstdlib>
#include <ctime>

#define NTextures 8

using namespace std;

class Fantasma
{
    public:
        // Cons
        Fantasma(float mapa[31][28], int CordI, int CordJ, float dirInitX, float dirInitY, char* texturas[9]);
        ~Fantasma();

        // Coordenadas de dibujado
        float fantasma1X; // Posición inicial en X del cuadrado
        float fantasma1Y; // Posición inicial en Y del cuadrado

        //Auxiliar para Dibujado
        float contadorUP;
        float contadorDOWN;
        float contadorLEFT;
        float contadorRIGHT;

        //Coordenadas en Matriz
        int fantasma1CordI;
        int fantasma1CordJ;

        // Direccion
        string dirAutoFantasma;

        // Textura
        GLuint	texture[NTextures];
        char* textura1;
        char* textura2;
        char* textura3;
        char* textura4;
        char* textura5;
        char* textura6;
        char* textura7;
        char* textura8;
        char* texturaActual;
        int texturaNum;

        // Metodos
        void fantasmaDecisiones();
        void movimientoFantasma();
        void dibujarMovimientoFantasma();
        void loadTexture();
        void draw();

    private:
        //Mapa
        //Tamaño Matriz
        int Fila;
        int Columna;
        float mapa[31][28];
};

#endif // FANTASMA_H
