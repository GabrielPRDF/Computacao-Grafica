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
//https://www.inf.pucrs.br/~manssour/OpenGL/Tutorial.html
//http://www.cplusplus.com/reference/cstdlib/rand/
//https://pt.stackoverflow.com/questions/159517/gera%C3%A7%C3%A3o-n%C3%BAmeros-aleat%C3%B3rios-c
using namespace std;
//********************* C O R **************************
int corRandom (){
    srand(time(NULL));
    static std::default_random_engine x;
    static std::uniform_real_distribution<> aux(0, 255);
    return aux(x);
}
//*******************************************************
//**********************C O R D E N A D A S**************
float cordenadasA, cordenadasB, cordenadasC;
float cordenadasRandom (){
    srand(time(NULL));
    static std::default_random_engine x;
    static std::uniform_real_distribution<> aux(10, -10);
    return aux(x);
}
//*******************************************************
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

void triangulo(){
    int x = 1;
    while(x < 10){
        cordenadasA = cordenadasRandom();
        cordenadasB = cordenadasRandom();
        cordenadasC = cordenadasRandom();
        glLineWidth(3);
        glBegin(GL_TRIANGLES);
                glColor3ub(corRandom(), corRandom(), corRandom());
                glVertex2f(cordenadasA, cordenadasA);
                glVertex2f(cordenadasB, cordenadasB);
                glVertex2f(cordenadasC, cordenadasB);
        glEnd();
        x++;
    }
}
void init(void){
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Fundo de tela preto
}

void display( void ){
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    triangulo();
    glutSwapBuffers();
}
void keyboard ( unsigned char key, int x, int y ){
    switch ( key ){
    case 27:        // Termina o programa qdo
        exit ( 0 );   // a tecla ESC for pressionada
        break;
    case 'a':
        glutPostRedisplay();
    default:
        break;
    }
}
void arrow_keys ( int a_keys, int x, int y ){
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
int main ( int argc, char** argv ){
    glutInit            ( &argc, argv );
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB );
    glutInitWindowPosition (0,0);
    glutInitWindowSize  ( 600, 600 );
    glutCreateWindow    ( "Exercicio 2" );
    init ();
    glutDisplayFunc ( display );
    glutReshapeFunc ( reshape );
    glutKeyboardFunc ( keyboard );
    glutSpecialFunc ( arrow_keys );
    glutMainLoop ( );
    return 0;
}


