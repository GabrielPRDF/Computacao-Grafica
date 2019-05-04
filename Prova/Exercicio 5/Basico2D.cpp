#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h

//sites
//http://www.ntu.edu.sg/home/ehchua/programming/opengl/CG_examples.html
//https://pt.wikihow.com/Criar-um-Cubo-em-OpenGL
//https://www.opengl.org/discussion_boards/showthread.php/163699-rotate-cube-with-mouse-opengl

/* Global variables */
char title[] = "Exercicio 5";
bool fullscreen = false;
bool mouseDown = false;

float rotatex = 0.0f;
float rotatey = 0.0f;

float xd = 0.0f;
float yd = 0.0f;

void cubo(){
    glBegin(GL_QUADS);
        // Frente verde
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(-0.5f, -0.5f, 0.5f);
        glVertex3f( 0.5f, -0.5f, 0.5f);
        glVertex3f( 0.5f, 0.5f, 0.5f);
        glVertex3f(-0.5f, 0.5f, 0.5f);
        // Atras Branco
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-0.5f, -0.5f, -0.5f);
        glVertex3f(-0.5f, 0.5f, -0.5f);
        glVertex3f( 0.5f, 0.5f, -0.5f);
        glVertex3f( 0.5f, -0.5f, -0.5f);
        // Esquerda Vermelho
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(-0.5f, -0.5f, 0.5f);
        glVertex3f(-0.5f, 0.5f, 0.5f);
        glVertex3f(-0.5f, 0.5f, -0.5f);
        glVertex3f(-0.5f, -0.5f, -0.5f);
        // Direita Azul
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f( 0.5f, -0.5f, -0.5f);
        glVertex3f( 0.5f, 0.5f, -0.5f);
        glVertex3f( 0.5f, 0.5f, 0.5f);
        glVertex3f( 0.5f, -0.5f, 0.5f);
        // Cima Verde musgo
        glColor3f(0.5f, 0.5f, 0.0f);
        glVertex3f(-0.5f, 0.5f, 0.5f);
        glVertex3f( 0.5f, 0.5f, 0.5f);
        glVertex3f( 0.5f, 0.5f, -0.5f);
        glVertex3f(-0.5f, 0.5f, -0.5f);
        // Baixo Roxo
        glColor3f(0.5f, 0.0f, 0.5f);
        glVertex3f(-0.5f, -0.5f, 0.5f);
        glVertex3f(-0.5f, -0.5f, -0.5f);
        glVertex3f( 0.5f, -0.5f, -0.5f);
        glVertex3f( 0.5f, -0.5f, 0.5f);
    glEnd();
}
bool init(){
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glClearDepth(1.0f);
    return true;
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 3.0f,
              0.0f, 0.0f, 0.0f,
              0.0f, 1.0f, 0.0f);
    glRotatef(rotatex, 1.0f, 0.0f, 0.0f);
    glRotatef(rotatey, 0.0f, 1.0f, 0.0f);
    cubo();
    glFlush();
    glutSwapBuffers();
}
void reshape(int w, int h){
    // Reset the coordinate system before modifying
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);
    //Estabelece a perspectiva
    gluPerspective(45.0f, 1.0f * w / h, 1.0f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClearColor(0,0,0,1); // fundo tela preto
}
void idle(){
    if (!mouseDown){
        rotatex += 0.3f;
        rotatey += 0.4f;
    }
    glutPostRedisplay();
}
void keyboard ( unsigned char key, int x, int y ){
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
void specialKeyboard( int a_keys, int x, int y){
    if (a_keys == GLUT_KEY_F1){
        fullscreen = !fullscreen;
        if (fullscreen){
            glutFullScreen();
        }else{
            glutReshapeWindow(500, 500);
            glutPositionWindow(50, 50);
        }
    }
}
void mouse(int button, int state, int x, int y){
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        mouseDown = true;
        xd = x - rotatey;
        yd = -y + rotatex;
    }else{
        mouseDown = false;
    }
}
void mouseMotion(int x, int y){
    if (mouseDown){
        rotatey = x - xd;
        rotatex = y + yd;
        glutPostRedisplay();
    }
}
int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(500, 500);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutCreateWindow("Exercicio 5");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutReshapeFunc(reshape);
    if (!init()){
        return 1;
    }
    glutMainLoop();
    return 0;
}
