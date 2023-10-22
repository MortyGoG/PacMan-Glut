/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

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

#include "Escenario.h"

using namespace std;

/* Identifador de ventana*/
int mainWindow;

/* Escena */
Escenario Escena;

/* Teclas */
void key(int key, int x, int y) {
    Escena.key(key, x, y);
}

/* Ventana tamaño */
void resizeWindow(int w, int h){
    glClearColor(0.0, 0.0, 0.0, 0.0);

	float viewWidth = 224.0;
	float viewHeight = 248.0;


	// Asegura que la altura y la anchura no sean cero
    h = (h == 0) ? 1 : h;
    w = (w == 0) ? 1 : w;
	printf("w=%d h=%d\n",w,h);

    glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// Codigo de redimensionamiento profe ejemplo
	printf("w=%f h=%f\n",viewWidth,viewHeight);
    glOrtho(0, viewWidth, viewHeight, 0, 0.0, 1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


/* Mostrar en pantalla */
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    Escena.escenaPrincipal();
    glutPostRedisplay();
    glutSwapBuffers();
}


/* Main */
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(672,744);
	glutInitWindowPosition(600,200);
    mainWindow = glutCreateWindow("Pac-Man");
    glutReshapeFunc(resizeWindow);
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutSpecialFunc(key);
	glutMainLoop();
	return 0;
}
