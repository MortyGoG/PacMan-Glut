#include "Comida.h"

Comida::Comida(char *filename1)
{
    //ctor
    this->textura1 = filename1;
    this->texturaNum = 1;

    //Dir
    this->dirX = 11.0f;
    this->dirY = 11.0f;

}

void Comida::loadTexture(){
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);

	RgbImage theTexMap( textura1 );

    //generate an OpenGL texture ID for this texture
    glGenTextures(1, &texture[texturaNum]);
    //bind to the new texture ID
    glBindTexture(GL_TEXTURE_2D, texture[texturaNum]);

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, theTexMap.GetNumCols(), theTexMap.GetNumRows(), 0,
                     GL_RGB, GL_UNSIGNED_BYTE, theTexMap.ImageData());
    theTexMap.Reset();
}

void Comida::draw(){

    this->loadTexture();
    glPushMatrix();

    // Calcula las coordenadas del centro del Pac-Man
    float centroX = this->dirX + 2.0f; // La mitad del ancho del Pac-Man
    float centroY = this->dirY + 2.0f; // La mitad de la altura del Pac-Man

    glTranslatef(dirX, dirY, 0.0f); // Translada al centro

    //activa la textura
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[texturaNum]);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex2f(-1.0, 1.0);  // Esquina inferior izquierda

    glTexCoord2f(0.0, 1.0);
    glVertex2f(-1.0, -1.0);  // Esquina superior izquierda

    glTexCoord2f(1.0, 1.0);
    glVertex2f(1.0, -1.0);  // Esquina superior derecha

    glTexCoord2f(1.0, 0.0);
    glVertex2f(1.0, 1.0);  // Esquina inferior derecha

    glEnd();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}
