#include "Fantasma.h"

Fantasma::Fantasma(float mapa[31][28], int CordI, int CordJ,
                   float dirInitX, float dirInitY, char* texturas[8])
{
    //Coordenadas de dibujado
    this->fantasma1X = dirInitX; // Posición inicial en X del cuadrado
    this->fantasma1Y = dirInitY; // Posición inicial en Y del cuadrado

    //Auxiliar para Dibujado
    this->contadorUP = 0;
    this->contadorDOWN = 0;
    this->contadorLEFT = 0;
    this->contadorRIGHT = 0;

    //Coordenadas en Matriz
    this->fantasma1CordI = CordI;
    this->fantasma1CordJ = CordJ;

    //Direccion
    this->dirAutoFantasma="right";

    //Tamaño Matriz
    this->Fila = 31;
    this->Columna = 28;

    // Inicializa la semilla del generador de números aleatorios
    srand(static_cast<unsigned int>(time(nullptr)));

    /* Texturas */
    this->textura1 = texturas[0];
    this->textura2 = texturas[1];
    this->textura3 = texturas[2];
    this->textura4 = texturas[3];
    this->textura5 = texturas[4];
    this->textura6 = texturas[5];
    this->textura7 = texturas[6];
    this->textura8 = texturas[7];

    this->texturaActual = textura1;

    this->texturaNum = 0;

    // Copia la matriz recibida al miembro de la clase
    for (int i = 0; i < Fila; i++) {
        for (int j = 0; j < Columna; j++) {
            this->mapa[i][j] = mapa[i][j];
        }
    }

    // Cargar textura
    for (int i = 0; i < 8; i++) {
        glGenTextures(1, &texture[i]);
        glBindTexture(GL_TEXTURE_2D, texture[i]);
    }
}

Fantasma::~Fantasma() {
    // Liberar recursos relacionados con las texturas si es necesario
    for (int i = 0; i < 8; i++) {
        glDeleteTextures(1, &texture[i]);
    }
}


void Fantasma::fantasmaDecisiones(){
    //Arriba, Abajo e Izquierda
    if(mapa[fantasma1CordI - 1][fantasma1CordJ] == 0 &&
       mapa[fantasma1CordI + 1][fantasma1CordJ] == 0 &&
       mapa[fantasma1CordI][fantasma1CordJ - 1] == 0 &&
       dirAutoFantasma == "right"){
        int numero_aleatorio = rand() % 3 + 1;
        if(numero_aleatorio == 1){
            dirAutoFantasma = "up";
            return;
        }else if(numero_aleatorio == 2){
            dirAutoFantasma = "down";
            return;
        }else {
            dirAutoFantasma = "left";
            return;
        }
    }
    //Arriba, Abajo y derecha
    if(mapa[fantasma1CordI - 1][fantasma1CordJ] == 0 &&
       mapa[fantasma1CordI + 1][fantasma1CordJ] == 0 &&
       mapa[fantasma1CordI][fantasma1CordJ + 1] == 0 &&
       dirAutoFantasma == "left"){
        int numero_aleatorio = rand() % 3 + 1;
        if(numero_aleatorio == 1){
            dirAutoFantasma = "up";
            return;
        }else if(numero_aleatorio == 2){
            dirAutoFantasma = "down";
            return;
        }else {
            dirAutoFantasma = "right";
            return;
        }
    }
    //Arriba, Izquierda y derecha
    if(mapa[fantasma1CordI - 1][fantasma1CordJ] == 0 &&
       mapa[fantasma1CordI][fantasma1CordJ - 1] == 0 &&
       mapa[fantasma1CordI][fantasma1CordJ + 1] == 0 &&
       dirAutoFantasma == "down"){
        int numero_aleatorio = rand() % 3 + 1;
        if(numero_aleatorio == 1){
            dirAutoFantasma = "up";
            return;
        }else if(numero_aleatorio == 2){
            dirAutoFantasma = "left";
            return;
        }else {
            dirAutoFantasma = "right";
            return;
        }
    }
    //Abajo, Izquierda y derecha
    if(mapa[fantasma1CordI + 1][fantasma1CordJ] == 0 &&
       mapa[fantasma1CordI][fantasma1CordJ - 1] == 0 &&
       mapa[fantasma1CordI][fantasma1CordJ + 1] == 0 &&
       dirAutoFantasma == "up"){
        int numero_aleatorio = rand() % 3 + 1;
        if(numero_aleatorio == 1){
            dirAutoFantasma = "down";
            return;
        }else if(numero_aleatorio == 2){
            dirAutoFantasma = "left";
            return;
        }else {
            dirAutoFantasma = "right";
            return;
        }
    }

    //Arriba y abajo
    if(mapa[fantasma1CordI - 1][fantasma1CordJ] == 0 &&
       mapa[fantasma1CordI + 1][fantasma1CordJ] == 0 &&
       (dirAutoFantasma == "left" || dirAutoFantasma == "right")){
        int numero_aleatorio = rand() % 2 + 1;
        if(numero_aleatorio == 1){
            dirAutoFantasma = "left";
            return;
        }else{
            dirAutoFantasma = "right";
            return;
        }
    }
    //Izquierda y Derecha
    if(mapa[fantasma1CordI][fantasma1CordJ - 1] == 0 &&
       mapa[fantasma1CordI][fantasma1CordJ + 1] == 0 &&
       (dirAutoFantasma == "up" || dirAutoFantasma == "down")){
        int numero_aleatorio = rand() % 2 + 1;
        if(numero_aleatorio == 1){
            dirAutoFantasma = "right";
            return;
        }else{
            dirAutoFantasma = "left";
            return;
        }
    }
    //Arriba y Izquierda
    if(mapa[fantasma1CordI - 1][fantasma1CordJ] == 0 &&
       mapa[fantasma1CordI][fantasma1CordJ - 1] == 0 &&
       (dirAutoFantasma == "down" || dirAutoFantasma == "right")){
        int numero_aleatorio = rand() % 2 + 1;
        if(numero_aleatorio == 1){
            dirAutoFantasma = "left";
            return;
        }else{
            dirAutoFantasma = "up";
            return;
        }
    }
    //Arriba y Derecha
    if(mapa[fantasma1CordI - 1][fantasma1CordJ] == 0 &&
       mapa[fantasma1CordI][fantasma1CordJ + 1] == 0 &&
       (dirAutoFantasma == "left" || dirAutoFantasma == "down")){
        int numero_aleatorio = rand() % 2 + 1;
        if(numero_aleatorio == 1){
            dirAutoFantasma = "right";
            return;
        }else{
            dirAutoFantasma = "up";
            return;
        }
    }
    //Abajo y Izquierda
    if(mapa[fantasma1CordI + 1][fantasma1CordJ] == 0 &&
       mapa[fantasma1CordI][fantasma1CordJ - 1] == 0  &&
       (dirAutoFantasma == "up" || dirAutoFantasma == "right")){
        int numero_aleatorio = rand() % 2 + 1;
        if(numero_aleatorio == 1){
            dirAutoFantasma = "down";
            return;
        }else{
            dirAutoFantasma = "left";
            return;
        }
    }
    //Abajo y Derecha
    if(mapa[fantasma1CordI + 1][fantasma1CordJ] == 0 &&
       mapa[fantasma1CordI][fantasma1CordJ + 1] == 0 &&
       (dirAutoFantasma == "left" || dirAutoFantasma == "up")){
        int numero_aleatorio = rand() % 2 + 1;
        if(numero_aleatorio == 1){
            dirAutoFantasma = "right";
            return;
        }else{
            dirAutoFantasma = "down";
            return;
        }
    }
}

void Fantasma::movimientoFantasma(){
    if(contadorUP == 0 && contadorDOWN == 0 && contadorLEFT == 0 && contadorRIGHT == 0){


        //Teletransportar pacman por tunel
        if(mapa[fantasma1CordI][fantasma1CordJ - 1] == 2 && dirAutoFantasma == "left"){
            fantasma1CordI = 14;
            fantasma1CordJ = 27;
            fantasma1X = 219;
            fantasma1Y = 115;
            dirAutoFantasma = "left";
            printf("PacMan Tunel 1");
        }
        if(mapa[fantasma1CordI][fantasma1CordJ + 1] == 2 && dirAutoFantasma == "right"){
            fantasma1CordI = 14;
            fantasma1CordJ = 0;
            fantasma1X = 3;
            fantasma1Y = 115;
            dirAutoFantasma = "right";
            printf("PacMan Tunel 2");
        }

        fantasmaDecisiones();

        //printf("DirX= %d, DirY= %d\n", fantasma1CordJ, fantasma1CordJ);
        if(dirAutoFantasma == "up" && contadorUP == 0){
            if(mapa[fantasma1CordI - 1][fantasma1CordJ] == 0){
                //printf("%d, %d", fantasma1CordI, fantasma1CordJ);
                //Mover Arriba
                dirAutoFantasma = "up";
                fantasma1CordI--;
                contadorUP = 8;
                return;
            }else{
                //printf("Up Direccion no valida\n");
                dirAutoFantasma = "stop";
                return;
            }
            return;
        }else if(dirAutoFantasma == "down" && contadorDOWN == 0){
            if(mapa[fantasma1CordI + 1][fantasma1CordJ] == 0){
                //printf("%d, %d", fantasma1CordI, fantasma1CordJ);
                //Mover Abajo
                dirAutoFantasma = "down";
                fantasma1CordI++;
                contadorDOWN = 8;
                return;
            }else{
                //printf("Down Direccion no valida\n");
                dirAutoFantasma = "stop";
                return;
            }
            return;
        }else if(dirAutoFantasma == "left" && contadorLEFT == 0){
            if(mapa[fantasma1CordI][fantasma1CordJ - 1] == 0){
                //printf("%d, %d", fantasma1CordI, fantasma1CordJ);
                //Mover Izquierda
                dirAutoFantasma = "left";
                fantasma1CordJ--;
                contadorLEFT = 8;
                return;
            }else{
                //printf("Left Direccion no valida\n");
                dirAutoFantasma = "stop";
                return;
            }
            return;
        }else if(dirAutoFantasma == "right" && contadorRIGHT == 0){
            if(mapa[fantasma1CordI][fantasma1CordJ + 1] == 0){
                //printf("%d, %d", fantasma1CordI, fantasma1CordJ);
                //Mover Derecha
                dirAutoFantasma = "right";
                fantasma1CordJ++;
                contadorRIGHT = 8;
                return;
            }else{
                //printf("Right Direccion no valida\n");
                dirAutoFantasma = "stop";
                return;
            }
        }
    }
    //printf("Te mueves a la %s\n", dirAutoFantasma.c_str());
    return;
}

void Fantasma::dibujarMovimientoFantasma(){
    if(dirAutoFantasma == "up" && contadorUP != 0){
        //Dibujado de movimiento UP
        fantasma1Y -= 1.0f;
        contadorUP -= 1;
        if(contadorUP == 8 || contadorUP == 6 || contadorUP == 5 ||
           contadorUP == 3 || contadorUP == 1){
           texturaActual = textura1;
           texturaNum = 0;
        } else {
           texturaActual = textura2;
           texturaNum = 1;
        }
        //printf("Fantasma en movimiento UP\n");
        return;
    }
    //Dibujado de movimiento DOWN
    else if(dirAutoFantasma == "down" && contadorDOWN != 0){
        fantasma1Y += 1.0f;
        contadorDOWN -= 1;
        if (contadorDOWN == 8 || contadorDOWN == 6 || contadorDOWN == 5 ||
            contadorDOWN == 3 || contadorDOWN == 1) {
            texturaActual = textura3;
            texturaNum = 2;
            return;
        } else {
            texturaActual = textura4;
            texturaNum = 3;
            return;
        }
        //printf("Fantasma en movimiento DOWN\n");
        return;
    }
    //Dibujado de movimiento LEFT
    else if(dirAutoFantasma == "left" && contadorLEFT != 0){
        fantasma1X -= 1.0f;
        contadorLEFT -= 1;
        if (contadorLEFT == 8 || contadorLEFT == 6 || contadorLEFT == 5 ||
            contadorLEFT == 3 || contadorLEFT == 1) {
            texturaActual = textura5;
            texturaNum = 4;
            return;
        } else {
            texturaActual = textura6;
            texturaNum = 5;
            return;
        }

        //printf("Fantasma en movimiento LEFT\n");
        return;
    }
    //Dibujado de movimiento RIGHT
    else if(dirAutoFantasma == "right" && contadorRIGHT != 0){
        //printf("Dibujando movimiento");
        fantasma1X += 1.0f;
        contadorRIGHT -= 1;
        if (contadorRIGHT == 8 || contadorRIGHT == 6 || contadorRIGHT == 5 ||
            contadorRIGHT == 3 || contadorRIGHT == 1) {
            texturaActual = textura7;
            texturaNum = 6;
        } else {
            texturaActual = textura8;
            texturaNum = 7;
        }

        //printf("Fantasma en movimiento RIGHT %f\n", fantasma1X);
        return;
    }
}

void Fantasma::loadTexture(){
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);

	RgbImage theTexMap( texturaActual );

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, theTexMap.GetNumCols(), theTexMap.GetNumRows(), 0,
                     GL_RGB, GL_UNSIGNED_BYTE, theTexMap.ImageData());
    theTexMap.Reset();
}

void Fantasma::draw(){

    this->loadTexture();

    glPushMatrix();
    // Calcula las coordenadas del centro del Pac-Man
    float centroFant1X = this->fantasma1X + 2.0f; // La mitad del ancho del Pac-Man
    float centroFant1Y = this->fantasma1Y + 2.0f; // La mitad de la altura del Pac-Man

    glTranslatef(centroFant1X, centroFant1Y, 0.0f); // Translada al centro

    glScalef(3.0f, 3.0f, 0.0f);
    //printf("En X se movio el Pacman %f\n", pacmanX);
    //printf("En Y se movio el Pacman %f\n", pacmanY);

    //activa la textura
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[texturaNum]);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex2f(-2.0, 2.0);  // Esquina inferior izquierda

    glTexCoord2f(0.0, 1.0);
    glVertex2f(-2.0, -2.0);  // Esquina superior izquierda

    glTexCoord2f(1.0, 1.0);
    glVertex2f(2.0, -2.0);  // Esquina superior derecha

    glTexCoord2f(1.0, 0.0);
    glVertex2f(2.0, 2.0);  // Esquina inferior derecha

    glEnd();
    // Ahora, cuando quieras eliminar las texturas, puedes usar glDeleteTextures
    glDeleteTextures(texturaNum, texture);
    // Asegúrate de desvincular cualquier textura activa
    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}
