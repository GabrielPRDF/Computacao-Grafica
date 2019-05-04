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
// Sites visitados
//https://www.inf.pucrs.br/~manssour/OpenGL/Tutorial.html
//https://www.experts-exchange.com/questions/23733731/OpenGL-Timer-Function.html
//http://hohohuhu.blogspot.com/2011/03/opengl-timer-function.html
//https://www.badprog.com/c-opengl-using-glrotatef-to-rotate-around-the-x-y-and-z-axis
int x = 1;
void Timer(int valor)
{
    if(x < 38){
        glRotatef(10, 0.0, 0.0, 1.0);
    }
    if(x > 38 && x < 76){
        glRotatef(10.0, 1.0, 0.0, 0.0);
    }
    if(x > 76 && x < 113){
        glRotatef(10.0, 0.0, 1.0, 0.0);
    }
    x++;
    glutPostRedisplay();
    glutTimerFunc(100,Timer, 1);
}
void init(void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Fundo de tela preto
}
void reshape( int w, int h ){
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
    poligono();
    glutSwapBuffers();
}
void keyboard ( unsigned char key, int x, int y )
{
    switch ( key )
    {
    case 27:        // Termina o programa qdo
        exit ( 0 );   // a tecla ESC for pressionada
        break;
    case 'a':
        glutPostRedisplay();
    default:
        break;
    }
}
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
int main ( int argc, char** argv )
{
    glutInit            ( &argc, argv );
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB );
    glutInitWindowPosition (0,0);
    glutInitWindowSize  ( 600, 600 );
    glutCreateWindow    ( "Exercicio 1 C" );
    init ();
    glutDisplayFunc ( display );
    glutReshapeFunc ( reshape );
    glutKeyboardFunc ( keyboard );
    glutSpecialFunc ( arrow_keys );
    Timer(0);
    glutMainLoop ( );
    return 0;
}


