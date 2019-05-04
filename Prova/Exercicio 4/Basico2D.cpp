// **********************************************************************
// COMPUTAÇÃO GRÁFICA
//
// **********************************************************************
//
// Basico2D.cpp
//
// Programa mínimo em OpenGL
//
//		- para compilar no Visual C ou Visual Studio acrescente as seguintes
//        bibliotecas:
//                   project/options/linker/general/adicionar diretorio...
//					 opengl32.lib glu32.lib glaux.lib glut32.lib
//
//      - Code Blocks
//          project/build options.../linker settings/linker lib/add...
//          opengl32 glu32 glaux glut32
//
//		- para compilar no DEVCPP (ou no g++) acrescente as seguintes
//        bibliotecas:
//		      -lopengl32 -lglut32 -lglu32 -lglaux
//
// **********************************************************************
#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <GL\gl.h>
#include <GL/glu.h>
#include <GL\glut.h>
#include <ctime>
#include <cstdlib>
#include <iostream>
// **********************************************************************
//  void init(void)
//		Inicializa os parâmetros globais de OpenGL
//
// **********************************************************************
void init(void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Fundo de tela preto
}

// **********************************************************************
//  void reshape( int w, int h )
//		trata o redimensionamento da janela OpenGL
//
// **********************************************************************
void reshape( int w, int h )
{

    // Reset the coordinate system before modifying
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);
    gluOrtho2D(-10,10,-10,10);
    // Set the clipping volume
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClearColor(0,0,0,1); // fundo tela preto
}
// **********************************************************************

void poligono(){
    //glTranslatef(3,1,1);
    glColor3f(0,1,0);
    glLineWidth(3);
    glBegin(GL_POLYGON);
        glVertex2i(0,0);
        glVertex2i(0,2);
        glVertex2i(1,3);
        glVertex2i(2,2);
        glVertex2i(2,0);
    glEnd();
}

void display( void )
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    // coloque aqui as chamadas das rotinas que desenha os objetos
    poligono();
    glutSwapBuffers();
}
//http://www.opengl.org/sdk/docs/man2/xhtml/glBegin.xml//
// **********************************************************************
//  void keyboard ( unsigned char key, int x, int y )
// **********************************************************************
void keyboard ( unsigned char key, int x, int y )
{
    switch ( key )
    {
        case 27:        // Termina o programa qdo
            exit ( 0 );   // a tecla ESC for pressionada
            break;

        case 'z':
            glScaled(1.1, 1.1, 0);
            break;
        case 'x':
            glScaled(0.9, 0.9, 0);
            break;
        case 'q':
            glRotated(1.1, 0.0, 1.0, 0.0);
            break;
        case 'w':
            glRotated(-1.1, 0.0, 1.0, 0.0);
            break;
    }
    glutPostRedisplay();
}

// **********************************************************************
//  void arrow_keys ( int a_keys, int x, int y )
//
//
// **********************************************************************
void arrow_keys ( int a_keys, int x, int y )
{
    switch ( a_keys )
    {
		case GLUT_KEY_DOWN:
            glTranslated(0.0, -0.1, 0.0);
            break;
        case GLUT_KEY_UP:
            glTranslated(0.0, 0.1, 0.0);
            break;
        case GLUT_KEY_RIGHT:
            glTranslated(0.1, 0.0, 0.0);
            break;
        case GLUT_KEY_LEFT:
            glTranslated(-0.1, 0.0, 0.0);
            break;
    }
    glutPostRedisplay();
}

// **********************************************************************
//  void main ( int argc, char** argv )
//
//
// **********************************************************************
int main ( int argc, char** argv )
{
    glutInit            ( &argc, argv );
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB );
    glutInitWindowPosition (0,0);
    glutInitWindowSize  ( 600, 600 );
    glutCreateWindow    ( "Exemplo Básico de OpenGL" );
    init ();
    glutDisplayFunc ( display );
    glutReshapeFunc ( reshape );
    glutKeyboardFunc ( keyboard );
    glutSpecialFunc ( arrow_keys );
    glutMainLoop ( );
    return 0;
}
