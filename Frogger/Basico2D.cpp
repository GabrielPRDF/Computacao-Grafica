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
//Variaveis Globais
int moverSapoX = 0, moverSapoY = 0;
int tempo = 0;
int mCarroW = 0, mCarroB = 0, mCarroG = 0, mCarroR = 0;
int fase = -2, v = 3;
int chave = 0, chave2 = 0;
void init(void){
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
void inicio (){
    {
        glColor3f(0,1,0);
        glRasterPos2f(-8.0, 5);
        char* p = (char*) "FROGGER!!!";
        while (*p != '\0'){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *p++);
            }
    }
    {
        glColor3f(1,0,1);
        glRasterPos2f(-8.0, 3);
        char* p = (char*) "Autor: Gabriel P. R. da Fonseca";
        while (*p != '\0'){
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p++);
        }
    }
    {
        glColor3f(0,0,1);
        glRasterPos2f(-8.0, 1);
        char* p = (char*) "Comandos: Utilize as setas direcionais para movimentar o Sapo!!!";
        while (*p != '\0'){
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p++);
        }
    }
    {
        glColor3f(1,0,0);
        glRasterPos2f(-8.0, -1);
        char* p = (char*) "Pressione ESC para sair!!!.";
        while (*p != '\0'){
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p++);
        }
    }
    {
        glColor3f(0.13,0.55,0.13);
        glRasterPos2f(-8.0, -3);
        char* p = (char*) "Pressione Enter para comecar!!!.";
        while (*p != '\0'){
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p++);
        }
    }
    {
        glColor3f(0.13,0.55,0.13);
        glRasterPos2f(-8.0, -5);
        char* p = (char*) "Boa Sorte!!!.";
        while (*p != '\0'){
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p++);
        }
    }
}
void fim(){
    glColor3f(0,1,0);
    glRasterPos2f(-6.0, 0.0);
    char* p = (char*) "Parabens voce GANHOU!!!";
    while (*p != '\0'){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *p++);
    }
}
void vidas(){
    if(v == 3){
        glColor3f(1,1,0);
        glRasterPos2f(-10.0,9.0);
        char* p = (char*) "3 vidas";
        while (*p != '\0'){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *p++);
        }
    }
    if(v == 2){
        glColor3f(1,1,0);
        glRasterPos2f(-10.0,9.0);
        char* p = (char*) "2 vidas";
        while (*p != '\0'){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *p++);
        }
    }
    if(v == 1){
        glColor3f(1,1,0);
        glRasterPos2f(-10.0,9.0);
        char* p = (char*) "1 vidas";
        while (*p != '\0'){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *p++);
        }
    }
}
void gameover(){
    glColor3f(1,0,0);
    glRasterPos2f(-2.0,0.0);
    char* p = (char*) "GAME OVER!!!";
    while (*p != '\0'){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *p++);
    }
}
void rua(){
    glColor3f(0.83,0.83,0.83);
    glBegin(GL_POLYGON);
        glVertex2f(-10,-8);
        glVertex2f(-10,8);
        glVertex2f(10,8);
        glVertex2f(10,-8);
    glEnd();
    glColor3f(1,1,1);
        glLineWidth(3);
    	glBegin(GL_LINES);
		glVertex2i(-10,-8);
		glVertex2i(10,-8);
		glVertex2i(-10,8);
		glVertex2i(10,8);
    glEnd();
    glColor3f(1,1,0);
    //glLineWidth(3);
    glBegin(GL_LINES);
        //glLineStipple(1, 0x00FF);
        //glEnable(GL_LINE_STIPPLE);
		glVertex2i(-10,-4);
		glVertex2i(10,-4);
		glVertex2i(-10,4);
		glVertex2i(10,4);
		glVertex2i(-10,0);
		glVertex2i(10,0);
    glEnd();
}
void calcada(){
    glColor3f(0.44,0.5,0.56);
    glBegin(GL_POLYGON);
        glVertex2f(-10,-8);
        glVertex2f(-10,-10);
        glVertex2f(10,-10);
        glVertex2f(10,-8);
    glEnd();
    glColor3f(0.44,0.5,0.56);
    glBegin(GL_POLYGON);
        glVertex2f(-10,8);
        glVertex2f(-10,10);
        glVertex2f(10,10);
        glVertex2f(10,8);
    glEnd();
}
void carros(){
    //Carro Vermelho---------------------------------------
    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
        glVertex2f(mCarroR + 1,1);
        glVertex2f(mCarroR + 1,3);
        glVertex2f(mCarroR + 4,3);
        glVertex2f(mCarroR + 4,1);
    glEnd();
    //Farois
    glColor3f(1,1,0);
    glPointSize(6.0);
    glBegin(GL_POINTS);
	    glVertex2f (mCarroR + 4, 1.7);
        glVertex2f (mCarroR + 4, 2.3);
	glEnd();
    //Roda Cima Esquerda
    glBegin(GL_POLYGON);
    glColor3f(0.18,0.31,0.31);
        glVertex2f(mCarroR + 1,2.5);
        glVertex2f(mCarroR + 1,3);
        glVertex2f(mCarroR + 2,3);
        glVertex2f(mCarroR + 2,2.5);
    glEnd();
    //Roda Esquerda Baixo
    glBegin(GL_POLYGON);
    glColor3f(0.18,0.31,0.31);
        glVertex2f(mCarroR + 1,1);
        glVertex2f(mCarroR + 1,1.5);
        glVertex2f(mCarroR + 2,1.5);
        glVertex2f(mCarroR + 2,1);
    glEnd();
    //Roda Direita Baixo
    glBegin(GL_POLYGON);
    glColor3f(0.18,0.31,0.31);
        glVertex2f(mCarroR + 3,1);
        glVertex2f(mCarroR + 3,1.5);
        glVertex2f(mCarroR + 4,1.5);
        glVertex2f(mCarroR + 4,1);
    glEnd();
    //Roda Cima Direita
    glBegin(GL_POLYGON);
    glColor3f(0.18,0.31,0.31);
        glVertex2f(mCarroR + 3,2.5);
        glVertex2f(mCarroR + 3,3);
        glVertex2f(mCarroR + 4,3);
        glVertex2f(mCarroR + 4,2.5);
    glEnd();

    //Carro Verde--------------------------------------
    glColor3f(0,1,0);
    glBegin(GL_POLYGON);
        glVertex2f(mCarroG + 1,-1);
        glVertex2f(mCarroG + 1,-3);
        glVertex2f(mCarroG + 4,-3);
        glVertex2f(mCarroG + 4,-1);
     glEnd();
    //Farois
    glColor3f(1,1,0);
    glPointSize(6.0);
    glBegin(GL_POINTS);
	    glVertex2f (mCarroG + 1, -1.7);
        glVertex2f (mCarroG + 1, -2.3);
	glEnd();
    //Roda Cima Esquerda
    glBegin(GL_POLYGON);
    glColor3f(0.18,0.31,0.31);
        glVertex2f(mCarroG + 1,-2.5);
        glVertex2f(mCarroG + 1,-3);
        glVertex2f(mCarroG + 2,-3);
        glVertex2f(mCarroG + 2,-2.5);
    glEnd();
    //Roda Esquerda Baixo
    glBegin(GL_POLYGON);
    glColor3f(0.18,0.31,0.31);
        glVertex2f(mCarroG + 1,-1);
        glVertex2f(mCarroG + 1,-1.5);
        glVertex2f(mCarroG + 2,-1.5);
        glVertex2f(mCarroG + 2,-1);
    glEnd();
    //Roda Direita Baixo
    glBegin(GL_POLYGON);
    glColor3f(0.18,0.31,0.31);
        glVertex2f(mCarroG + 3,-1);
        glVertex2f(mCarroG + 3,-1.5);
        glVertex2f(mCarroG + 4,-1.5);
        glVertex2f(mCarroG + 4,-1);
    glEnd();
    //Roda Cima Direita
    glBegin(GL_POLYGON);
    glColor3f(0.18,0.31,0.31);
        glVertex2f(mCarroG + 3,-2.5);
        glVertex2f(mCarroG + 3,-3);
        glVertex2f(mCarroG + 4,-3);
        glVertex2f(mCarroG + 4,-2.5);
    glEnd();

    //Carro Azul-------------------------
    glColor3f(0,0,1);
    glBegin(GL_POLYGON);
        glVertex2f(mCarroB + 1,-5);
        glVertex2f(mCarroB + 1,-7);
        glVertex2f(mCarroB + 4,-7);
        glVertex2f(mCarroB + 4,-5);
     glEnd();
    //Farois
    glColor3f(1,1,0);
    glPointSize(6.0);
    glBegin(GL_POINTS);
	    glVertex2f (mCarroB + 4, -5.7);
        glVertex2f (mCarroB + 4, -6.3);
	glEnd();
    //Roda baixo Esquerda
    glBegin(GL_POLYGON);
    glColor3f(0.18,0.31,0.31);
        glVertex2f(mCarroB + 1,-6.5);
        glVertex2f(mCarroB + 1,-7);
        glVertex2f(mCarroB + 2,-7);
        glVertex2f(mCarroB + 2,-6.5);
    glEnd();
    //Roda Esquerda cima
    glBegin(GL_POLYGON);
    glColor3f(0.18,0.31,0.31);
        glVertex2f(mCarroB + 1,-5);
        glVertex2f(mCarroB + 1,-5.5);
        glVertex2f(mCarroB + 2,-5.5);
        glVertex2f(mCarroB + 2,-5);
    glEnd();
    //Roda Direita Baixo
    glBegin(GL_POLYGON);
    glColor3f(0.18,0.31,0.31);
        glVertex2f(mCarroB + 3,-7);
        glVertex2f(mCarroB + 3,-6.5);
        glVertex2f(mCarroB + 4,-6.5);
        glVertex2f(mCarroB + 4,-7);
    glEnd();
    //Roda Cima Direita
    glBegin(GL_POLYGON);
    glColor3f(0.18,0.31,0.31);
        glVertex2f(mCarroB + 3,-5.5);
        glVertex2f(mCarroB + 3,-5);
        glVertex2f(mCarroB + 4,-5);
        glVertex2f(mCarroB + 4,-5.5);
    glEnd();

    //Carro Branco-----------------------------
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
        glVertex2f(mCarroW + 1,5);
        glVertex2f(mCarroW + 1,7);
        glVertex2f(mCarroW + 4,7);
        glVertex2f(mCarroW + 4,5);
    glEnd();
    //Farois
    glColor3f(1,1,0);
    glPointSize(6.0);
    glBegin(GL_POINTS);
	    glVertex2f (mCarroW + 1, 5.7);
        glVertex2f (mCarroW + 1, 6.3);
	glEnd();
    //Roda Cima Esquerda
    glBegin(GL_POLYGON);
    glColor3f(0.18,0.31,0.31);
        glVertex2f(mCarroW + 1,6.5);
        glVertex2f(mCarroW + 1,7);
        glVertex2f(mCarroW + 2,7);
        glVertex2f(mCarroW + 2,6.5);
    glEnd();
    //Roda Esquerda Baixo
    glBegin(GL_POLYGON);
    glColor3f(0.18,0.31,0.31);
        glVertex2f(mCarroW + 1,5);
        glVertex2f(mCarroW + 1,5.5);
        glVertex2f(mCarroW + 2,5.5);
        glVertex2f(mCarroW + 2,5);
    glEnd();
    //Roda Direita Baixo
    glBegin(GL_POLYGON);
    glColor3f(0.18,0.31,0.31);
        glVertex2f(mCarroW + 3,7);
        glVertex2f(mCarroW + 3,6.5);
        glVertex2f(mCarroW + 4,6.5);
        glVertex2f(mCarroW + 4,7);
    glEnd();
    //Roda Cima Direita
    glBegin(GL_POLYGON);
    glColor3f(0.18,0.31,0.31);
        glVertex2f(mCarroW + 3,5.5);
        glVertex2f(mCarroW + 3,5);
        glVertex2f(mCarroW + 4,5);
        glVertex2f(mCarroW + 4,5.5);
    glEnd();
}
void sapo(){
    glColor3f(0,1,0);
    glPointSize(20.0);
    glBegin(GL_POINTS);
	    glVertex2f (moverSapoX,moverSapoY - 9);
	glEnd();
    glColor3f(1,1,0);
    glPointSize(3.0);
    glBegin(GL_POINTS);
	    glVertex2f (moverSapoX -0.2,moverSapoY - 8.8);  //Olho esquerdo
	    glVertex2f (moverSapoX + 0.2,moverSapoY - 8.8);  //Olho direito
	glEnd();
    //Desenha as pernas
    glColor3f(0,1,0);
    glLineWidth(2);
    glBegin(GL_LINES);
    	glVertex2f(moverSapoX - 0.7,moverSapoY - 8.7);
		glVertex2f(moverSapoX - 0.2,moverSapoY - 8.9);
    	glVertex2f(moverSapoX + 0.7,moverSapoY - 8.7);
		glVertex2f(moverSapoX + 0.2,moverSapoY - 8.9);
    	glVertex2f(moverSapoX - 0.2,moverSapoY - 9.1);
		glVertex2f(moverSapoX - 0.7,moverSapoY - 9.3);
    	glVertex2f(moverSapoX + 0.7,moverSapoY - 9.3);
		glVertex2f(moverSapoX + 0.2,moverSapoY - 9.1);
    glEnd();
    //Ponto das maos
    glColor3f(0,1,0);
    glPointSize(1.0);
    glBegin(GL_POINTS);
	    glVertex2f (moverSapoX - 0.7,moverSapoY - 8.85);
	    glVertex2f (moverSapoX + 0.7,moverSapoY - 8.85);
	    glVertex2f (moverSapoX - 0.8,moverSapoY - 8.7);
	    glVertex2f (moverSapoX + 0.8,moverSapoY - 8.7);
	    glVertex2f (moverSapoX - 0.6,moverSapoY - 8.6);
	    glVertex2f (moverSapoX + 0.6,moverSapoY - 8.6);
	glEnd();
}
void moviCarro(int passo){
    mCarroB += 1;
    mCarroR += 1;
    if(mCarroB == 8){
        mCarroB = -13;
        mCarroR = -13;
    }
    glutPostRedisplay();
    glutTimerFunc(100-tempo,moviCarro, 1);
}
void moviCarro2(int passo){
    mCarroW -= 1;
    mCarroG -= 1;
    if(mCarroW == -13){
        mCarroW = 7;
        mCarroG = 7;
    }
    glutPostRedisplay();
    glutTimerFunc(100-tempo,moviCarro2, 1);
}
void colisao(){
    if ((mCarroB -3 == moverSapoX-7) && (moverSapoY >= 2 && moverSapoY <= 4)){
        moverSapoY = 0;
        v -= 1;
        if(v == 0){
            fase = 10;
            v = 3;
        }else{
            fase = 0;
        }
        tempo = 0;

    }
    if ((mCarroB -3 == moverSapoX-6) && (moverSapoY >= 2 && moverSapoY <= 4)){
        moverSapoY = 0;
        v -= 1;
        if(v == 0){
            fase = 10;
            v = 3;
        }else{
            fase = 0;
        }
        tempo = 0;
    }
    if ((mCarroB -3 == moverSapoX-5) && (moverSapoY >= 2 && moverSapoY <= 4)){
        moverSapoY = 0;
        v -= 1;
        if(v == 0){
            fase = 10;
            v = 3;
        }else{
            fase = 0;
        }
        tempo = 0;
    }
    if ((mCarroG == moverSapoX-3) && (moverSapoY >= 6 && moverSapoY <= 8)){
        moverSapoY = 0;
        v -= 1;
        if(v == 0){
            fase = 10;
            v = 3;
        }else{
            fase = 0;
        }
        tempo = 0;
    }
    if ((mCarroG == moverSapoX-2) && (moverSapoY >= 6 && moverSapoY <= 8)){
        moverSapoY = 0;
        v -= 1;
        if(v == 0){
            fase = 10;
            v = 3;
        }else{
            fase = 0;
        }
        tempo = 0;
    }
    if ((mCarroG == moverSapoX-1) && (moverSapoY >= 6 && moverSapoY <= 8)){
        moverSapoY = 0;
        v -= 1;
        if(v == 0){
            fase = 10;
            v = 3;
        }else{
            fase = 0;
        }
        tempo = 0;
    }
    if ((mCarroR +4 == moverSapoX+1) && (moverSapoY >= 10 && moverSapoY <= 11)){
        moverSapoY = 0;
        v -= 1;
        if(v == 0){
            fase = 10;
            v = 3;
        }else{
            fase = 0;
        }
        tempo = 0;
    }
    if ((mCarroR +4 == moverSapoX+2) && (moverSapoY >= 10 && moverSapoY <= 11)){
        moverSapoY = 0;
        v -= 1;
        if(v == 0){
            fase = 10;
            v = 3;
        }else{
            fase = 0;
        }
        tempo = 0;
    }
    if ((mCarroR +4 == moverSapoX+3) && (moverSapoY >= 10 && moverSapoY <= 11)){
        moverSapoY = 0;
        v -= 1;
        if(v == 0){
            fase = 10;
            v = 3;
        }else{
            fase = 0;
        }
        tempo = 0;
    }
    if ((mCarroW +8 == moverSapoX+5) && (moverSapoY >= 14 && moverSapoY <= 16)){
        moverSapoY = 0;
        v -= 1;
        if(v == 0){
            fase = 10;
            v = 3;
        }else{
            fase = 0;
        }
        tempo = 0;
    }
    if ((mCarroW +8 == moverSapoX+6) && (moverSapoY >= 14 && moverSapoY <= 16)){
        moverSapoY = 0;
        v -= 1;
        if(v == 0){
            fase = 10;
            v = 3;
        }else{
            fase = 0;
        }
        tempo = 0;
    }
    if ((mCarroW +8 == moverSapoX+7) && (moverSapoY >= 14 && moverSapoY <= 16)){
        moverSapoY = 0;
        v -= 1;
        if(v == 0){
            fase = 10;
            v = 3;
        }else{
            fase = 0;
        }
        tempo = 0;
    }
    glutPostRedisplay();
}
void testeFase(){
    if (moverSapoY == 18 && fase == 0)  fase = 1;
    if (moverSapoY == 0 && fase == 2)  fase = 3;
}
void transicao1(){
    glColor3f(0,1,0);
    glRasterPos2f(-6.0, 0.0);
    char* p = (char*) "FASE 1 !!!";
    while (*p != '\0'){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *p++);
    }
}
void transicao2(){
    glColor3f(0,1,0);
    glRasterPos2f(-6.0, 0.0);
    char* p = (char*) "FASE 2 !!!";
    while (*p != '\0'){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *p++);
    }
}
void display( void ){
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    if(fase == -2){
        inicio();
    }
    if(fase == -1){
        transicao1();
        if(chave == 1){
            fase += 1;
            Sleep(1000);
            chave = 1;
        }
        chave = 1;
    }
    if(fase == 0){
        tempo = 10;
        rua();
        colisao();
        calcada();
        sapo();
        carros();
        vidas();
    }
    if(fase == 1){
        transicao2();
        if(chave == 3){
            fase += 1;
            Sleep(1000);
        }
        chave += 1;
    }
    if(fase == 2){
        tempo = 50;
        rua();
        colisao();
        calcada();
        sapo();
        carros();
    }
    if(fase == 3){
        fim();
    }
    if(fase == 10){
        gameover();
        if(chave2 == 3){
            fase = -1;
            Sleep(1000);
            chave2 = 0;
            chave = 0;
        }
        chave2 += 1;
    }
    glutSwapBuffers();
    testeFase();
}
void keyboard ( unsigned char key, int x, int y ){
    switch ( key )
    {
    case 27:        // Termina o programa qdo
        exit ( 0 );   // a tecla ESC for pressionada
        break;
    case 13:
        fase = -1;
        glutPostRedisplay();
    default:
        break;
    }
}
void arrow_keys ( int a_keys, int x, int y ){
    switch ( a_keys ){
		case GLUT_KEY_DOWN:
            moverSapoY -= 1;
            break;
        case GLUT_KEY_UP:
            moverSapoY += 1;
            break;
        case GLUT_KEY_RIGHT:
            moverSapoX += 1;
            break;
        case GLUT_KEY_LEFT:
            moverSapoX -= 1;
            break;
    }
    glutPostRedisplay();
}
int main ( int argc, char** argv ){
    glutInit            ( &argc, argv );
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB );
    glutInitWindowPosition (0,0);
    glutInitWindowSize  ( 600, 600 );
    glutCreateWindow    ( "Jogo" );
    init ();
    glutTimerFunc(10,moviCarro,1);
    glutTimerFunc(10,moviCarro2,1);
    glutDisplayFunc ( display );
    glutReshapeFunc ( reshape );
    glutKeyboardFunc ( keyboard );
    glutSpecialFunc ( arrow_keys );
    glutMainLoop ( );
    return 0;
}
