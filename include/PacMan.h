#ifndef PACMAN_H
#define PACMAN_H

#include <string>
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

#include "Mapa.h"

#define NTextures 8

using namespace std;

class PacMan
{
    public:
        // Cons
        PacMan(float mapa[31][28], char *filename1, char *filename2, char *filename3);

        // Coordenadas de dibujado
        float pacmanX; // Posición inicial en X del cuadrado
        float pacmanY; // Posición inicial en Y del cuadrado

        //Auxiliar para Dibujado
        int contadorUP;
        int contadorDOWN;
        int contadorLEFT;
        int contadorRIGHT;

        //Coordenadas en Matriz
        int pacmanCordI;
        int pacmanCordJ;

        // Textura
        GLuint	texture[NTextures];
        char* textura1;
        char* textura2;
        char* textura3;
        char* texturaActual;
        int texturaNum;

        //Direccion de movimiento inicial PacMan
        string dirPacMan;
        string bufferDirPacMan;
        float angulo = 0.0f;

        // Metodos
        void key(int key);
        void movimientoPacMan();
        void dibujarMovimientoPacMan();
        void loadTexture();
        void draw();

    private:
        //Mapa
        //Tamaño Matriz
        int Fila;
        int Columna;
        float mapa[31][28];
};

#endif // PACMAN_H
