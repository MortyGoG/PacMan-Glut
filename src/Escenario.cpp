#include "Escenario.h"

Escenario::Escenario()
{
    Mapa1 = new Mapa(texturaMapa);
    /* Objetos */
    //Objeto PacMan
    PacManP1 = new PacMan(Mapa1->mapa, texturaPacMan1, texturaPacMan2, texturaPacMan3);

    //Objeto Fantasma1
    FantasmaRojo = new Fantasma(Mapa1->mapa, 11, 12, 99.0f, 91.0f, texturasFantasmaRojo);

    //Objeto Fantasma2
    FantasmaRosa = new Fantasma(Mapa1->mapa, 11, 14, 115.0f, 91.0f, texturasFantasmaRosa);

    //Ojeto Fantasma3
    FantasmaCyan = new Fantasma(Mapa1->mapa, 11, 16, 131.0f, 91.0f, texturasFantasmaCyan);

    //Objeto Fantsma4
    FantasmaNaranja = new Fantasma(Mapa1->mapa, 11, 18, 147.0f, 91.0f, texturasFantasmaNaranja);

    //Comida
    ComidaPoints = new Comida( texturaComida );
}

Escenario::~Escenario() {
    delete Mapa1;
    delete PacManP1;
    delete FantasmaRojo;
    delete FantasmaRosa;
    delete FantasmaCyan;
    delete FantasmaNaranja;
    delete ComidaPoints;
}


void Escenario::escenaPrincipal()
{
    //printf("Textura: %d\n", *texturaMapa);

    //Juego
    PacManP1->draw();
    FantasmaRojo->draw();
    FantasmaRosa->draw();
    FantasmaCyan->draw();
    FantasmaNaranja->draw();
    // Fix Bugs Texture
    //ComidaPoints->draw();
    Mapa1->draw();


    //PacMan
    PacManP1->movimientoPacMan();
    PacManP1->dibujarMovimientoPacMan();

    //Fantasma1
    FantasmaRojo->movimientoFantasma();
    FantasmaRojo->dibujarMovimientoFantasma();

    //Fantasma2
    FantasmaRosa->movimientoFantasma();
    FantasmaRosa->dibujarMovimientoFantasma();

    //Fantasma3
    FantasmaCyan->movimientoFantasma();
    FantasmaCyan->dibujarMovimientoFantasma();

    //Fantasma3
    FantasmaNaranja->movimientoFantasma();
    FantasmaNaranja->dibujarMovimientoFantasma();

    Sleep(5);
	glFlush();
}


void Escenario::intro()
{

}


void Escenario::gameOver()
{

}

void Escenario::key(int key, int x, int y) {
    // Movimiento con Teclas
    PacManP1->key(key);
}
