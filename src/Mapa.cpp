#include "Mapa.h"

Mapa::Mapa(char *filename)
{
    /* Textura */
    this->textura1 = filename;
    this->texturaNum = 0;

    //generate an OpenGL texture ID for this texture
    glGenTextures(1, &texture[texturaNum]);
    //bind to the new texture ID
    glBindTexture(GL_TEXTURE_2D, texture[texturaNum]);
}

/* Cargar Texturas */
void Mapa::loadTexture(){
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);

	RgbImage theTexMap( textura1 );

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, theTexMap.GetNumCols(), theTexMap.GetNumRows(), 0,
                     GL_RGB, GL_UNSIGNED_BYTE, theTexMap.ImageData());
    theTexMap.Reset();
}

/* Dibujar texturas */
void Mapa::draw(){
    this->loadTexture();
    //activa la textura
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[texturaNum]);
    glBegin(GL_QUADS);

    glTexCoord2f(0.0, 0.0);
    glVertex2f(0.0, 248.0);  //Esquina inferior izquierda

    glTexCoord2f(0.0, 1.0);
    glVertex2f(0.0, 0.0);   //Esquina superior izquierda

    glTexCoord2f(1.0, 1.0);
    glVertex2f(224.0, 0.0);    //Esquina superior derecha

    glTexCoord2f(1.0, 0.0);
    glVertex2f(224.0, 248.0);   //Esquina inferior izquierda

    glEnd();
    glDisable(GL_TEXTURE_2D);
}
