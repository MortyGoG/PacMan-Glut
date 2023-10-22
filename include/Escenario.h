#ifndef ESCENARIO_H
#define ESCENARIO_H

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

#include "PacMan.h"
#include "Fantasma.h"
#include "Mapa.h"
#include "Comida.h"

using namespace std;

class Escenario
{
    public:
        // Constr
        Escenario();
        ~Escenario(); // Declaración del destructor

        // Intro
        bool introActivada = false;

        // Sonidos
        char* sonidoInicio = "pacmanIntro.wav";
        char* sonidoFinal = "pacman-dies.wav";

        // Texturas
        char* texturaMapa = "sprites\\mapaPuntos.bmp";

        char* texturaPacMan1 = "sprites\\Pacman1.bmp";
        char* texturaPacMan2 = "sprites\\Pacman2.bmp";
        char* texturaPacMan3 = "sprites\\Pacman3.bmp";

        char* texturaIntro = "sprites\\IntroFondo.bmp";
        char* texturaGameOver = "sprites\\gameover.bmp";
        char* texturaComida = "sprites\\comida.bmp";

        // Objetos
        PacMan* PacManP1;
        Fantasma* FantasmaRojo;
        Fantasma* FantasmaRosa;
        Fantasma* FantasmaCyan;
        Fantasma* FantasmaNaranja;
        Mapa* Mapa1;
        Comida* ComidaPoints;

        // Metodos
        void intro();
        void escenaPrincipal();
        void gameOver();
        void key(int key, int x, int y);
        void loadTextureMap();
        void drawMapa();

    private:
        //Texturas
        char* texturasFantasmaRojo[8] = {
            "sprites\\FantasmaRojoU1.bmp",
            "sprites\\FantasmaRojoU2.bmp",
            "sprites\\FantasmaRojoD1.bmp",
            "sprites\\FantasmaRojoD2.bmp",
            "sprites\\FantasmaRojoL1.bmp",
            "sprites\\FantasmaRojoL2.bmp",
            "sprites\\FantasmaRojoR1.bmp",
            "sprites\\FantasmaRojoR2.bmp"};

        char* texturasFantasmaRosa[8] = {
            "sprites\\FantasmaRosaU1.bmp",
            "sprites\\FantasmaRosaU2.bmp",
            "sprites\\FantasmaRosaD1.bmp",
            "sprites\\FantasmaRosaD2.bmp",
            "sprites\\FantasmaRosaL1.bmp",
            "sprites\\FantasmaRosaL2.bmp",
            "sprites\\FantasmaRosaR1.bmp",
            "sprites\\FantasmaRosaR2.bmp"};

        char* texturasFantasmaCyan[8] = {
            "sprites\\FantasmaCU1.bmp",
            "sprites\\FantasmaCU2.bmp",
            "sprites\\FantasmaCD1.bmp",
            "sprites\\FantasmaCD2.bmp",
            "sprites\\FantasmaCL1.bmp",
            "sprites\\FantasmaCL2.bmp",
            "sprites\\FantasmaCR1.bmp",
            "sprites\\FantasmaCR2.bmp"};

        char* texturasFantasmaNaranja[8] = {
            "sprites\\FantasmaNU1.bmp",
            "sprites\\FantasmaNU2.bmp",
            "sprites\\FantasmaND1.bmp",
            "sprites\\FantasmaND2.bmp",
            "sprites\\FantasmaNL1.bmp",
            "sprites\\FantasmaNL2.bmp",
            "sprites\\FantasmaNR1.bmp",
            "sprites\\FantasmaNR2.bmp"};
};

#endif // ESCENARIO_H
