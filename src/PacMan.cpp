#include "PacMan.h"

PacMan::PacMan(float mapa[31][28], char *filename1, char *filename2, char *filename3){
    //Coordenadas de dibujado
    this->pacmanX = 11.0f; // Posición inicial en X del cuadrado
    this->pacmanY = 11.0f; // Posición inicial en Y del cuadrado

    //Auxiliar para Dibujado
    this->contadorUP = 0;
    this->contadorDOWN = 0;
    this->contadorLEFT = 0;
    this->contadorRIGHT = 0;

    //Coordenadas en Matriz
    this->pacmanCordI = 1;
    this->pacmanCordJ = 1;

    //Direccion de movimiento inicial PacMan
    this->dirPacMan = "right";
    this->bufferDirPacMan = "right";

    //Tamaño Matriz
    this->Fila = 31;
    this->Columna = 28;

    //Textura
    this->textura1 = filename1;
    this->textura2 = filename2;
    this->textura3 = filename3;
    this->texturaActual = filename2;
    this->texturaNum = 2;

    // Copia la matriz recibida al miembro de la clase
    for (int i = 0; i < Fila; i++) {
        for (int j = 0; j < Columna; j++) {
            this->mapa[i][j] = mapa[i][j];
        }
    }

    // Cargar textura
    for (int i = 0; i < 3; i++) {
        glGenTextures(1, &texture[i]);
        glBindTexture(GL_TEXTURE_2D, texture[i]);
    }
}

void PacMan::movimientoPacMan(){
    if(contadorUP == 0 && contadorDOWN == 0 && contadorLEFT == 0 && contadorRIGHT == 0){

        //printf("DirX= %d, DirY= %d\n", pacmanCordI, pacmanCordJ);

        //Teletransportar pacman por tunel
        if(mapa[pacmanCordI][pacmanCordJ - 1] == 2 && dirPacMan == "left"){
            pacmanCordI = 14;
            pacmanCordJ = 27;
            pacmanX = 219;
            pacmanY = 115;
            dirPacMan = "left";
            printf("PacMan Tunel 1");
        }
        if(mapa[pacmanCordI][pacmanCordJ + 1] == 2 && dirPacMan == "right"){
            pacmanCordI = 14;
            pacmanCordJ = 0;
            pacmanX = 3;
            pacmanY = 115;
            dirPacMan = "right";
            printf("PacMan Tunel 2");
        }

        //Control de Direccion de PacMan
        dirPacMan = bufferDirPacMan;

        if(dirPacMan == "up" && contadorUP == 0){
            if(mapa[pacmanCordI - 1][pacmanCordJ] == 0){
                //Mover Arriba
                dirPacMan = "up";
                pacmanCordI--;
                contadorUP = 8;
                return;
            }else{
                //printf("Up Direccion no valida\n");
                dirPacMan = "stop";
                return;
            }
            return;
        }else if(dirPacMan == "down" && contadorDOWN == 0){
            if(mapa[pacmanCordI + 1][pacmanCordJ] == 0){
                //printf("%d, %d", pacmanCordI, pacmanCordJ);
                //Mover Abajo
                dirPacMan = "down";
                pacmanCordI++;
                contadorDOWN = 8;
                return;
            }else{
                //printf("Down Direccion no valida\n");
                dirPacMan = "stop";
                return;
            }
            return;
        }else if(dirPacMan == "left" && contadorLEFT == 0){
            if(mapa[pacmanCordI][pacmanCordJ - 1] == 0){
                //printf("%d, %d", pacmanCordI, pacmanCordJ);
                //Mover Izquierda
                dirPacMan = "left";
                pacmanCordJ--;
                contadorLEFT = 8;
                return;
            }else{
                //printf("Left Direccion no valida\n");
                dirPacMan = "stop";
                return;
            }
            return;
        }else if(dirPacMan == "right" && contadorRIGHT == 0){
            if(mapa[pacmanCordI][pacmanCordJ + 1] == 0){
                //printf("%d, %d", pacmanCordI, pacmanCordJ);
                //Mover Derecha
                dirPacMan = "right";
                pacmanCordJ++;
                contadorRIGHT = 8;
                return;
            }else{
                //printf("Right Direccion no valida\n");
                dirPacMan = "stop";
                return;
            }
            return;
        }
    }
    //printf("Te mueves a la %s\n", dirPacMan.c_str());
}

void PacMan::dibujarMovimientoPacMan(){

    if(dirPacMan == "up" && contadorUP != 0){
        //Dibujado de movimiento UP
        pacmanY -= 1.0f;
        contadorUP -= 1;
        //Animacion
        if (contadorUP == 8 || contadorUP == 7 || contadorUP == 3 || contadorUP == 2) {
            texturaActual = textura1;
            texturaNum = 1;
        } else if (contadorUP == 6 || contadorUP == 1 || contadorUP == 0) {
            texturaActual = textura2;
            texturaNum = 2;
        } else {
            texturaActual = textura3;
            texturaNum = 3;
        }

        //printf("PacMan en movimiento UP\n");
        return;
    }
    //Dibujado de movimiento DOWN
    else if(dirPacMan == "down" && contadorDOWN != 0){
        pacmanY += 1.0f;
        contadorDOWN -= 1;
        //Animacion
        if (contadorDOWN == 8 || contadorDOWN == 7 || contadorDOWN == 3 || contadorDOWN == 2) {
            texturaActual = textura1;
            texturaNum = 1;
        } else if (contadorDOWN == 6 || contadorDOWN == 1 || contadorDOWN == 0) {
            texturaActual = textura2;
            texturaNum = 2;
        } else {
            texturaActual = textura3;
            texturaNum = 3;
        }
        //printf("PacMan en movimiento DOWN\n");
        return;
    }
    //Dibujado de movimiento LEFT
    else if(dirPacMan == "left" && contadorLEFT != 0){
        pacmanX -= 1.0f;
        contadorLEFT -= 1;
        //Animacion
        if (contadorLEFT == 8 || contadorLEFT == 7 || contadorLEFT == 3 || contadorLEFT == 2) {
            texturaActual = textura1;
            texturaNum = 1;
        } else if (contadorLEFT == 6 || contadorLEFT == 1 || contadorLEFT == 0) {
            texturaActual = textura2;
            texturaNum = 2;
        } else {
            texturaActual = textura3;
            texturaNum = 3;
        }
        //printf("PacMan en movimiento LEFT\n");
        return;
    }
    //Dibujado de movimiento RIGHT
    else if(dirPacMan == "right" && contadorRIGHT != 0){
        pacmanX += 1.0f;
        contadorRIGHT -= 1;
        //Animacion
        if (contadorRIGHT == 8 || contadorRIGHT == 7 || contadorRIGHT == 3 || contadorRIGHT == 2) {
            texturaActual = textura1;
            texturaNum = 1;
            return;
        } else if ( contadorRIGHT == 6 || contadorRIGHT == 1 || contadorRIGHT == 0) {
            texturaActual = textura2;
            texturaNum = 2;
            return;
        } else {
            texturaActual = textura3;
            texturaNum = 3;
            return;
        }

        //printf("PacMan en movimiento RIGHT %f\n", pacmanX);
        return;
    }
}

void PacMan::key(int key){
    switch (key) {
        case GLUT_KEY_UP:
            if(contadorLEFT < 6 && contadorRIGHT < 6 && mapa[pacmanCordI - 1][pacmanCordJ] == 0){
                bufferDirPacMan = "up"; // Mueve el cuadrado hacia arriba
                angulo = 270.0f;
                printf("Tecla UP\n");
            }
            break;
        case GLUT_KEY_DOWN:
            if(contadorLEFT < 6 && contadorRIGHT < 6 && mapa[pacmanCordI + 1][pacmanCordJ] == 0){
                bufferDirPacMan = "down"; // Mueve el cuadrado hacia arriba
                angulo = 90.0f;
                printf("Tecla DOWN\n");
            }
            break;
        case GLUT_KEY_LEFT:
            if(contadorUP < 6 && contadorDOWN < 6 && mapa[pacmanCordI][pacmanCordJ - 1] == 0){
                bufferDirPacMan = "left"; // Mueve el cuadrado hacia arriba
                angulo = 180.0f;
                printf("Tecla LEFT\n");
            }
            break;
        case GLUT_KEY_RIGHT:
            if(contadorUP < 6 && contadorDOWN < 6 && mapa[pacmanCordI][pacmanCordJ + 1] == 0){
                bufferDirPacMan = "right"; // Mueve el cuadrado hacia la derecha
                angulo = 0.0f;
                printf("Tecla RIGHT\n");
            }
            break;
    }
    glutPostRedisplay(); // Solicita una actualización de la ventana
}

void PacMan::loadTexture(){
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

/* Dibujar texturas */
void PacMan::draw(){
    this->loadTexture();
    glPushMatrix();

    // Calcula las coordenadas del centro del Pac-Man
    float centroX = this->pacmanX + 2.0f; // La mitad del ancho del Pac-Man
    float centroY = this->pacmanY + 2.0f; // La mitad de la altura del Pac-Man

    glTranslatef(centroX, centroY, 0.0f); // Translada al centro

    glScalef(3.0f, 3.0f, 0.0f);
    glRotatef(angulo, 0.0f, 0.0f, 1.0f); // Rotación en el eje Z
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
