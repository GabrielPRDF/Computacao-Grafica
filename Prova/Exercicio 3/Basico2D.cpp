#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <GL\gl.h>
#include <GL/glu.h>
#include <GL\glut.h>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <random>
//Sites Visitados

float eixoX, eixoY;
using namespace std;
float numeroRandom (){
    srand(time(NULL));
    static std::default_random_engine x;
    static std::uniform_real_distribution<> aux(1, -1);
    return aux(x);
}
void Timer(int valor)
{
    eixoX = numeroRandom();
    eixoY = numeroRandom();
    glTranslated(eixoX, eixoY, 0.0);
    glutPostRedisplay();
    glutTimerFunc(33,Timer, 1);
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
    glColor3f(0,1,0);
    glLineWidth(3);
    glBegin(GL_POLYGON);
        glVertex2i(0,0);
        glVertex2i(0,2);
        glVertex2i(1,3);
        glVertex2i(2,2);
        glVertex2i(2,0);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2i(4,4);
        glVertex2i(4,6);
        glVertex2i(5,7);
        glVertex2i(6,6);
        glVertex2i(6,4);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2i(-4,-4);
        glVertex2i(-4,-2);
        glVertex2i(-3,-1);
        glVertex2i(-2,-2);
        glVertex2i(-2,-4);
    glEnd();
}
void init(void){
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Fundo de tela preto
}
void display( void )
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    // coloque aqui as chamadas das rotinas que desenha os objetos
    poligono();
    // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
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

    case 'a':
        //
        glutPostRedisplay();
    default:
        break;
    }
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
    case GLUT_KEY_UP:       // When Up Arrow Is Pressed...
        glutFullScreen ( ); // Go Into Full Screen Mode
        break;
    case GLUT_KEY_DOWN:     // When Down Arrow Is Pressed...
        glutInitWindowSize  ( 700, 500 );
        break;
    default:
        break;
    }
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
    Timer(0);
    glutMainLoop ( );
    return 0;
}


