#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h> 
#include <stdlib.h>
#include <time.h>

void display(void);
void init(void);
void reshape(int, int);
//letras
void draw9(int,int);
void draw3(int,int);
void drawJ(int,int);
void drawM(int, int);
void drawL(int, int);
void drawA(int, int);
void drawI(int,int);
void drawR(int, int);
void drawD(int, int);
void drawG(int,int);
void drawO(int, int);
void drawE(int, int);
void drawZ(int, int);
void drawN(int, int);
void drawU(int, int);
void drawJaime(int,int);
void drawMargolin(int,int);
void drawMJaime(int,int);
void drawJuan(int,int);
void drawLeon(int,int);
void drawMJuan(int,int);

int main(int argc, char** argv)
{
	//inicio para hacer la ventana con GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("kshe jamor tizdayen otja");
	init();

	//funciones para hacer el display 
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	//que dibuje continuamente 
	glutMainLoop();

	return 0;
}

void drawJaime(int letra,int renglon)
{
	drawJ(0,0);
	letra+=17;
	drawA(letra,renglon);
	letra+=17;
	drawI(letra,renglon);
	letra +=17;
	drawM(letra,renglon);
	letra+=17;
	drawE(letra,renglon);
}

void drawMargolin(int letra,int renglon)
{
	drawM(letra,renglon);
	letra+=17;
	drawA(letra,renglon);
	letra+=17;
	drawR(letra,renglon);
	letra+=17;
	drawG(letra,renglon);
	letra+=17;
	drawO(letra,renglon);
	letra+=17;
	drawL(letra,renglon);
	letra+=17;
	drawI(letra,renglon);
	letra+=17;
	drawN(letra,renglon);
}

void drawMJaime(int letra,int renglon)
{
	drawA(letra,renglon);
	letra+=17;
	drawO(letra,renglon);
	letra+=17;
	drawI(letra,renglon);
	letra+=17;
	drawO(letra,renglon);
	letra+=17;
	drawI(letra,renglon);
	letra+=17;
	draw9(letra,renglon);
	letra+=17;
	draw3(letra,renglon);
	letra+=17;
	draw3(letra,renglon);
	letra+=17;
	drawZ(letra,renglon);
}

void drawJuan(int letra,int renglon)
{
	drawJ(letra,renglon);
	letra+=17;
	drawU(letra,renglon);
	letra+=17;
	drawA(letra,renglon);
	letra+=17;
	drawN(letra,renglon);
}

void drawLeon(int letra,int renglon)
{
	drawL(letra,renglon);
	letra+=17;
	drawE(letra,renglon);
	letra+=17;
	drawO(letra,renglon);
	letra+=17;
	drawN(letra,renglon);
}

void drawMJuan(int letra,int renglon)
{
	drawA(letra,renglon);
	letra+=17;
	drawO(letra,renglon);
	letra+=17;
	drawI(letra,renglon);
	letra+=17;
	drawO(letra,renglon);
	letra+=17;
	drawZ(letra,renglon);
	letra+=17;
	drawO(letra,renglon);
	letra+=17;
	drawZ(letra,renglon);
	letra+=17;
	drawO(letra,renglon);
	letra+=17;
	drawO(letra,renglon);
}

//Desplegar 
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	//iniciamos una semilla para valores aleatorios, esto va pintar cada pixel de las letras con un valor diferente cada uno
	srand((int)time(NULL));
	int renglon = 0, letra = 0;

	drawJaime(0,renglon);
	drawMargolin(0,renglon-=17);
	drawMJaime(0, renglon-=17);
	drawJuan(0, renglon-=40);
	drawLeon(0, renglon-=17);
	drawMJuan(0, renglon-=17);

	glutSwapBuffers();
}

//inicio y color de la pantalla
void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}


//funciones para la vista de la camara
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-100.0, 120.0, -100.0, 100.0, -4.0, 4.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void coloreamela()
{
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
}

//U
void drawU(int x, int y){
	//1,1
	coloreamela();
	glRectf(-50 + x, 50 + y, -47.5 + x, 47.5 + y);
	//1,5
	coloreamela();
	glRectf(-37.5 + x, 50 + y, -35 + x, 47.5 + y);
	//2, 5
	coloreamela();
	glRectf(-37.5 + x, 47.5 + y, -35 + x, 45 + y);
	//3, 5
	coloreamela();
	glRectf(-37.5 + x, 45 + y, -35 + x, 42.5 + y);
	//4, 5
	coloreamela();
	glRectf(-37.5 + x, 42.5 + y, -35 + x, 40 + y);
	//5, 5
	coloreamela();
	glRectf(-37.5 + x, 40 + y, -35 + x, 37.5 + y);
	//6, 4
	coloreamela();
	glRectf(-40 + x, 37.5 + y, -37.5 + x, 35 + y);
	//6, 3
	coloreamela();
	glRectf(-42.5 + x, 37.5 + y, -40 + x, 35 + y);
	//6, 2
	coloreamela();
	glRectf(-45 + x, 37.5 + y, -42.5 + x, 35 + y);
	//2, 0
	coloreamela();
	glRectf(-50 + x, 47.5 + y, -47.5 + x, 45 + y);
	//3, 0
	coloreamela();
	glRectf(-50 + x, 45 + y, -47.5 + x, 42.5 + y);
	//4,0
	coloreamela();
	glRectf(-50 + x, 42.5 + y, -47.5 + x, 40 + y);
	//5, 0
	coloreamela();
	glRectf(-50 + x, 40 + y, -47.5 + x, 37.5 + y);
	//6, 1
	coloreamela();
	glRectf(-47.5 + x, 37.5 + y, -45 + x, 35 + y);
}

//M
void drawM(int x, int y) {
	// 1, 1
	coloreamela();
	glRectf(-50.0 + x, 50.0 + y, -47.5 + x, 47.5 + y);
	//2, 1
	coloreamela();
	glRectf(-47.5 + x, 50.0 + y, -45 + x, 47.5 + y);
	//3, 2
	coloreamela();
	glRectf(-45 + x, 47.5 + y, -42.5 + x, 45 + y);
	//4, 2
	coloreamela();
	glRectf(-42.5 + x, 47.5 + y, -40 + x, 45 + y);
	//5, 1
	coloreamela();
	glRectf(-40 + x, 50 + y, -37.5 + x, 47.5 + y);
	//6, 1
	coloreamela();
	glRectf(-37.5 + x, 50 + y, -35 + x, 47.5 + y);
	//6, 2
	coloreamela();
	glRectf(-37.5 + x, 47.5 + y, -35 + x, 45 + y);
	//6, 3
	coloreamela();
	glRectf(-37.5 + x, 45 + y, -35 + x, 42.5 + y);
	//6, 4
	coloreamela();
	glRectf(-37.5 + x, 42.5 + y, -35 + x, 40 + y);
	//6, 5
	coloreamela();
	glRectf(-37.5 + x, 40 + y, -35 + x, 37.5 + y);
	//6, 6
	coloreamela();
	glRectf(-37.5 + x, 37.5 + y, -35 + x, 35 + y);
	//1, 2
	coloreamela();
	glRectf(-50.0 + x, 47.5 + y, -47.5 + x, 45 + y);
	//1, 3
	coloreamela();
	glRectf(-50.0 + x, 45.0 + y, -47.5 + x, 42.5 + y);
	//1, 4
	coloreamela();
	glRectf(-50.0 + x, 42.5 + y, -47.5 + x, 40 + y);
	//1, 5
	coloreamela();
	glRectf(-50.0 + x, 40 + y, -47.5 + x, 37.5 + y);
	//1, 6
	coloreamela();
	glRectf(-50.0 + x, 37.5 + y, -47.5 + x, 35 + y);
}

// A
void drawA(int x, int y) {
	//1, 1
	coloreamela();
	glRectf(-45.0 + x, 50.0 + y, -42.5 + x, 47.5 + y);
	//0,2
	coloreamela();
	glRectf(-47.5 + x, 47.5 + y, -45 + x, 45 + y);
	//0,3
	coloreamela();
	glRectf(-47.5 + x, 45 + y, -45 + x, 42.5 + y);
	//-1,4
	coloreamela();
	glRectf(-50 + x, 42.5 + y, -47.5 + x, 40 + y);
	//-1,5
	coloreamela();
	glRectf(-50 + x, 40 + y, -47.5 + x, 37.5 + y);
	//-1,6
	coloreamela();
	glRectf(-50 + x, 37.5 + y, -47.5 + x, 35 + y);
	//2,2
	coloreamela();
	glRectf(-42.5 + x, 47.5 + y, -40 + x, 45 + y);
	//2, 3
	coloreamela();
	glRectf(-42.5 + x, 45 + y, -40 + x, 42.5 + y);
	//3, 4
	coloreamela();
	glRectf(-40 + x, 42.5 + y, -37.5 + x, 40 + y);
	//3, 5
	coloreamela();
	glRectf(-40 + x, 40 + y, -37.5 + x, 37.5 + y);
	//3, 6
	coloreamela();
	glRectf(-40 + x, 37.5 + y, -37.5 + x, 35 + y);
	//2, 4
	coloreamela();
	glRectf(-42.5 + x, 42.5 + y, -40 + x, 40 + y);
	//1, 4
	coloreamela();
	glRectf(-45 + x, 42.5 + y, -42.5 + x, 40 + y);
	//0, 4
	coloreamela();
	glRectf(-47.5 + x, 42.5 + y, -45 + x, 40 + y);
}

// J
void drawJ(int x, int y){
	//1,1
	coloreamela();
	glRectf(-50+x,50+y,-47.5+x,47.5+y);
	//1,2
	coloreamela();
	glRectf(-47.5+x,50+y,-45+x,47.5+y);
	//1,3
	coloreamela();
	glRectf(-45+x,50+y,-42.5+x,47.5+y);
	//1,4
	coloreamela();
	glRectf(-42.5+x,50+y,-40+x,47.5+y);
	//1,5
	coloreamela();
	glRectf(-40+x,50+y,-37.5+x,47.5+y);
	//2,3
	coloreamela();
	glRectf(-45+x,47.5+y,-42.5+x,45+y);
	//3,3
	coloreamela();
	glRectf(-45+x,45+y,-42.5+x,42.5+y);
	//4,3
	coloreamela();
	glRectf(-45+x,42.5+y,-42.5+x,40+y);
	//5,3
	coloreamela();
	glRectf(-45+x,40+y,-42.5+x,37.5+y);
	//6,3
	coloreamela();
	glRectf(-45+x,37.5+y,-42.5+x,35+y);
	//6,2
	coloreamela();
	glRectf(-47.5+x,37.5+y,-45+x,35+y);
	//6,1
	coloreamela();
	glRectf(-50+x,37.5+y,-47.5+x,35+y);
}

// R
void drawR(int x, int y) {
	//1,1
	coloreamela();
	glRectf(-50 + x, 50 + y, -47.5 + x, 47.5 + y);
	//2,1
	coloreamela();
	glRectf(-50 + x, 47.5 + y, -47.5 + x, 45 + y);
	//3, 1
	coloreamela();
	glRectf(-50 + x, 45 + y, -47.5 + x, 42.5 + y);
	//4, 1
	coloreamela();
	glRectf(-50 + x, 42.5 + y, -47.5 + x, 40 + y);
	//5, 1
	coloreamela();
	glRectf(-50 + x, 40 + y, -47.5 + x, 37.5 + y);
	//6, 1
	coloreamela();
	glRectf(-50 + x, 37.5 + y, -47.5 + x, 35 + y);
	//1, 2
	coloreamela();
	glRectf(-47.5 + x, 50 + y, -45 + x, 47.5 + y);
	//1, 3
	coloreamela();
	glRectf(-45 + x, 50 + y, -42.5 + x, 47.5 + y);
	//1, 4
	coloreamela();
	glRectf(-42.5 + x, 50 + y, -40 + x, 47.5 + y);
	//2, 5
	coloreamela();
	glRectf(-40 + x, 47.5 + y, -37.5 + x, 45 + y);
	//3, 2
	coloreamela();
	glRectf(-47.5 + x, 45 + y, -45 + x, 42.5 + y);
	//3, 3
	coloreamela();
	glRectf(-45 + x, 45 + y, -42.5 + x, 42.5 + y);
	//3, 4
	coloreamela();
	glRectf(-42.5 + x, 45 + y, -40 + x, 42.5 + y);
	//4, 5
	coloreamela();
	glRectf(-40 + x, 42.5 + y, -37.5 + x, 40 + y);
	//5, 5
	coloreamela();
	glRectf(-40 + x, 40 + y, -37.5 + x, 37.5 + y);
	//6, 5
	coloreamela();
	glRectf(-40 + x, 37.5 + y, -37.5 + x, 35 + y);
}

//G
void drawG(int x, int y)
{
	//1,1
	coloreamela();
	glRectf(-50 + x, 50 + y, -47.5 + x, 47.5 + y);
	//1,2
	coloreamela();
	glRectf(-47.5 + x, 50 + y, -45 + x, 47.5 + y);
	//1,3
	coloreamela();
	glRectf(-45 + x, 50 + y, -42.5 + x, 47.5 + y);
	//1,4
	coloreamela();
	glRectf(-42.5 + x, 50 + y, -40 + x, 47.5 + y);
	//1,5
	coloreamela();
	glRectf(-40 + x, 50 + y, -37.5 + x, 47.5 + y);
	//2,1
	coloreamela();
	glRectf(-50 + x, 47.5 + y, -47.5 + x, 45 + y);
	//3,1
	coloreamela();
	glRectf(-50 + x, 45 + y, -47.5 + x, 42.5 + y);
	//4,1
	coloreamela();
	glRectf(-50 + x, 42.5 + y, -47.5 + x, 40 + y);
	//5,1
	coloreamela();
	glRectf(-50 + x, 40 + y, -47.5 + x, 37.5 + y);
	//6,1
	coloreamela();
	glRectf(-50 + x, 37.5 + y, -47.5 + x, 35 + y);
	//6,2
	coloreamela();
	glRectf(-47.5 + x, 37.5 + y, -45 + x, 35 + y);
	//6,3
	coloreamela();
	glRectf(-45 + x, 37.5 + y, -42.5 + x, 35 + y);
	//6,4
	coloreamela();
	glRectf(-42.5 + x, 37.5 + y, -40 + x, 35 + y);
	//6,5
	coloreamela();
	glRectf(-40 + x, 37.5 + y, -37.5 + x, 35 + y);
	//6,4
	coloreamela();
	glRectf(-40 + x, 40 + y, -37.5 + x, 37.5 + y);
	//6,3
	coloreamela();
	glRectf(-40 + x, 42.5 + y, -37.5 + x, 40 + y);
	//5,3
	coloreamela();
	glRectf(-42.5 + x, 42.5 + y, -40 + x, 40 + y);
}

// O
void drawO(int x, int y) {
	//1, 1
	coloreamela();
	glRectf(-47.5 + x, 50 + y, -45 + x, 47.5 + y);
	//1, 2
	coloreamela();
	glRectf(-45 + x, 50 + y, -42.5 + x, 47.5 + y);
	//1, 3
	coloreamela();
	glRectf(-42.5 + x, 50 + y, -40 + x, 47.5 + y);
	//1, 4
	coloreamela();
	glRectf(-40 + x, 50 + y, -37.5 + x, 47.5 + y);
	//2, 5
	coloreamela();
	glRectf(-37.5 + x, 47.5 + y, -35 + x, 45 + y);
	//3, 5
	coloreamela();
	glRectf(-37.5 + x, 45 + y, -35 + x, 42.5 + y);
	//4, 5
	coloreamela();
	glRectf(-37.5 + x, 42.5 + y, -35 + x, 40 + y);
	//5, 5
	coloreamela();
	glRectf(-37.5 + x, 40 + y, -35 + x, 37.5 + y);
	//6, 4
	coloreamela();
	glRectf(-40 + x, 37.5 + y, -37.5 + x, 35 + y);
	//6, 3
	coloreamela();
	glRectf(-42.5 + x, 37.5 + y, -40 + x, 35 + y);
	//6, 2
	coloreamela();
	glRectf(-45 + x, 37.5 + y, -42.5 + x, 35 + y);
	//2, 0
	coloreamela();
	glRectf(-50 + x, 47.5 + y, -47.5 + x, 45 + y);
	//3, 0
	coloreamela();
	glRectf(-50 + x, 45 + y, -47.5 + x, 42.5 + y);
	//4,0
	coloreamela();
	glRectf(-50 + x, 42.5 + y, -47.5 + x, 40 + y);
	//5, 0
	coloreamela();
	glRectf(-50 + x, 40 + y, -47.5 + x, 37.5 + y);
	//6, 1
	coloreamela();
	glRectf(-47.5 + x, 37.5 + y, -45 + x, 35 + y);
}

// I 
void drawI(int x, int y)
{
	//1,1 
	coloreamela();
	glRectf(-45+x,50+y,-42.5+x,47.5+y);
	//2,3
	coloreamela();
	glRectf(-45+x,47.5+y,-42.5+x,45+y);
	//3,3
	coloreamela();
	glRectf(-45+x,45+y,-42.5+x,42.5+y);
	//4,3
	coloreamela();
	glRectf(-45+x,42.5+y,-42.5+x,40+y);
	//5,3
	coloreamela();
	glRectf(-45+x,40+y,-42.5+x,37.5+y);
	//6,3
	coloreamela();
	glRectf(-45+x,37.5+y,-42.5+x,35+y);
}


//funcion para dibujar L
void drawL(int x, int y) {
	//1,1
	coloreamela();
	glRectf(-50 + x, 50 + y, -47.5 + x, 47.5 + y);
	//2,1
	coloreamela();
	glRectf(-50 + x, 47.5 + y, -47.5 + x, 45 + y);
	//3,1
	coloreamela();
	glRectf(-50 + x, 45 + y, -47.5 + x, 42.5 + y);
	//4,1
	coloreamela();
	glRectf(-50 + x, 42.5 + y, -47.5 + x, 40 + y);
	//5,1
	coloreamela();
	glRectf(-50 + x, 40 + y, -47.5 + x, 37.5 + y);
	//6,1
	coloreamela();
	glRectf(-50 + x, 37.5 + y, -47.5 + x, 35 + y);
	//6,2
	coloreamela();
	glRectf(-47.5 + x, 37.5 + y, -45 + x, 35 + y);
	//6,3
	coloreamela();
	glRectf(-45 + x, 37.5 + y, -42.5 + x, 35 + y);
}

// dibuja 9
void draw9(int x, int y)
{
	//1,1
	coloreamela();
	glRectf(-50 + x, 50 + y, -47.5 + x, 47.5 + y);
	//1,2
	coloreamela();
	glRectf(-47.5 + x, 50 + y, -45 + x, 47.5 + y);
	//1,3
	coloreamela();
	glRectf(-45 + x, 50 + y, -42.5 + x, 47.5 + y);
	//1,4
	coloreamela();
	glRectf(-42.5 + x, 50 + y, -40 + x, 47.5 + y);
	//1,5
	coloreamela();
	glRectf(-40 + x, 50 + y, -37.5 + x, 47.5 + y);
	//2,5
	coloreamela();
	glRectf(-40+x,47.5+y,-37.5+x,45+y);
	//3,5
	coloreamela();
	glRectf(-40+x,45+y,-37.5+x,42.5+y);
	//4,5
	coloreamela();
	glRectf(-40+x,42.5+y,-37.5+x,40+y);
	//5,5
	coloreamela();
	glRectf(-40+x,40+y,-37.5+x,37.5+y);
	//6,5
	coloreamela();
	glRectf(-40+x,37.5+y,-37.5+x,35+y);
	//2,1
	coloreamela();
	glRectf(-50+x,47.5+y,-47.5+x,45+y);
	//3,1
	coloreamela();
	glRectf(-50+x,45+y,-47.5+x,42.5+y);
	//3,2
	coloreamela();
	glRectf(-47.5+x,45+y,-45+x,42.5+y);
	//3,3
	coloreamela();
	glRectf(-45+x,45+y,-42.5+x,42.5+y);
	//3,4
	coloreamela();
	glRectf(-42.5+x,45+y,-40+x,42.5+y);
}


//funcion para dibujar E
void drawE(int x, int y) {
	//1,1
	coloreamela();
	glRectf(-50 + x, 50 + y, -47.5 + x, 47.5 + y);
	//1,2
	coloreamela();
	glRectf(-47.5 + x, 50 + y, -45 + x, 47.5 + y);
	//1,3
	coloreamela();
	glRectf(-45 + x, 50 + y, -42.5 + x, 47.5 + y);
	//1,4
	coloreamela();
	glRectf(-42.5 + x, 50 + y, -40 + x, 47.5 + y);
	//1,5
	coloreamela();
	glRectf(-40 + x, 50 + y, -37.5 + x, 47.5 + y);
	//2,1
	coloreamela();
	glRectf(-50 + x, 47.5 + y, -47.5 + x, 45 + y);
	//3,1
	coloreamela();
	glRectf(-50 + x, 45 + y, -47.5 + x, 42.5 + y);
	//3,2
	coloreamela();
	glRectf(-47.5 + x, 45 + y, -45 + x, 42.5 + y);
	//3,3
	coloreamela();
	glRectf(-45 + x, 45 + y, -42.5 + x, 42.5 + y);
	//3,4
	coloreamela();
	glRectf(-42.5 + x, 45 + y, -40 + x, 42.5 + y);
	//3,5
	coloreamela();
	glRectf(-40 + x, 45 + y, -37.5 + x, 42.5 + y);
	//4,1
	coloreamela();
	glRectf(-50 + x, 42.5 + y, -47.5 + x, 40 + y);
	//5,1
	coloreamela();
	glRectf(-50 + x, 40 + y, -47.5 + x, 37.5 + y);
	//6,1
	coloreamela();
	glRectf(-50 + x, 37.5 + y, -47.5 + x, 35 + y);
	//6,2
	coloreamela();
	glRectf(-47.5 + x, 37.5 + y, -45 + x, 35 + y);
	//6,3
	coloreamela();
	glRectf(-45 + x, 37.5 + y, -42.5 + x, 35 + y);
	//6,4
	coloreamela();
	glRectf(-42.5 + x, 37.5 + y, -40 + x, 35 + y);
	//6,5
	coloreamela();
	glRectf(-40 + x, 37.5 + y, -37.5 + x, 35 + y);
}

//funcion para dibujar Z
void drawZ(int x, int y) {
	//1,1
	coloreamela();
	glRectf(-50 + x, 50 + y, -47.5 + x, 47.5 + y);
	//1,2
	coloreamela();
	glRectf(-47.5 + x, 50 + y, -45 + x, 47.5 + y);
	//1,3
	coloreamela();
	glRectf(-45 + x, 50 + y, -42.5 + x, 47.5 + y);
	//1,4
	coloreamela();
	glRectf(-42.5 + x, 50 + y, -40 + x, 47.5 + y);
	//1,5
	coloreamela();
	glRectf(-40 + x, 50 + y, -37.5 + x, 47.5 + y);
	//2,4
	coloreamela();
	glRectf(-42.5 + x, 47.5 + y, -40 + x, 45 + y);
	//3,3
	coloreamela();
	glRectf(-45 + x, 45 + y, -42.5 + x, 42.5 + y);
	//4,2
	coloreamela();
	glRectf(-47.5 + x, 42.5 + y, -45 + x, 40 + y);
	//5,1
	coloreamela();
	glRectf(-50 + x, 40 + y, -47.5 + x, 37.5 + y);
	//6,1
	coloreamela();
	glRectf(-50 + x, 37.5 + y, -47.5 + x, 35 + y);
	//6,2
	coloreamela();
	glRectf(-47.5 + x, 37.5 + y, -45 + x, 35 + y);
	//6,3
	coloreamela();
	glRectf(-45 + x, 37.5 + y, -42.5 + x, 35 + y);
	//6,4
	coloreamela();
	glRectf(-42.5 + x, 37.5 + y, -40 + x, 35 + y);
	//6,5
	coloreamela();
	glRectf(-40 + x, 37.5 + y, -37.5 + x, 35 + y);
}

//funcion para dibujar N
void drawN(int x, int y) {
	//1,1
	coloreamela();
	glRectf(-50 + x, 50 + y, -47.5 + x, 47.5 + y);
	//2,1
	coloreamela();
	glRectf(-50 + x, 47.5 + y, -47.5 + x, 45 + y);
	//3,1
	coloreamela();
	glRectf(-50 + x, 45 + y, -47.5 + x, 42.5 + y);
	//4,1
	coloreamela();
	glRectf(-50 + x, 42.5 + y, -47.5 + x, 40 + y);
	//5,1
	coloreamela();
	glRectf(-50 + x, 40 + y, -47.5 + x, 37.5 + y);
	//6,1
	coloreamela();
	glRectf(-50 + x, 37.5 + y, -47.5 + x, 35 + y);
	//2,2
	coloreamela();
	glRectf(-47.5 + x, 47.5 + y, -45 + x, 45 + y);
	//3,3
	coloreamela();
	glRectf(-45 + x, 45 + y, -42.5 + x, 42.5 + y);
	//4,4
	coloreamela();
	glRectf(-42.5 + x, 42.5 + y, -40 + x, 40 + y);
	//5,5
	coloreamela();
	glRectf(-40 + x, 40 + y, -37.5 + x, 37.5 + y);
	//1,6
	coloreamela();
	glRectf(-37.5 + x, 50 + y, -35 + x, 47.5 + y);
	//2,6
	coloreamela();
	glRectf(-37.5 + x, 47.5 + y, -35 + x, 45 + y);
	//3,6
	coloreamela();
	glRectf(-37.5 + x, 45 + y, -35 + x, 42.5 + y);
	//4,6
	coloreamela();
	glRectf(-37.5 + x, 42.5 + y, -35 + x, 40 + y);
	//5,6
	coloreamela();
	glRectf(-37.5 + x, 40 + y, -35 + x, 37.5 + y);
	//6,6
	coloreamela();
	glRectf(-37.5 + x, 37.5 + y, -35 + x, 35 + y);
}

//pinta 3 
void draw3(int x, int y)
{
	//1,1
	coloreamela();
	glRectf(-50 + x, 50 + y, -47.5 + x, 47.5 + y);
	//1,2
	coloreamela();
	glRectf(-47.5 + x, 50 + y, -45 + x, 47.5 + y);
	//1,3
	coloreamela();
	glRectf(-45 + x, 50 + y, -42.5 + x, 47.5 + y);
	//1,4
	coloreamela();
	glRectf(-42.5 + x, 50 + y, -40 + x, 47.5 + y);
	//1,5
	coloreamela();
	glRectf(-40 + x, 50 + y, -37.5 + x, 47.5 + y);
	//3,1
	coloreamela();
	glRectf(-50 + x, 45 + y, -47.5 + x, 42.5 + y);
	//3,2
	coloreamela();
	glRectf(-47.5 + x, 45 + y, -45 + x, 42.5 + y);
	//3,3
	coloreamela();
	glRectf(-45 + x, 45 + y, -42.5 + x, 42.5 + y);
	//3,4
	coloreamela();
	glRectf(-42.5 + x, 45 + y, -40 + x, 42.5 + y);
	//3,5
	coloreamela();
	glRectf(-40 + x, 45 + y, -37.5 + x, 42.5 + y);
	//6,1
	coloreamela();
	glRectf(-50 + x, 37.5 + y, -47.5 + x, 35 + y);
	//6,2
	coloreamela();
	glRectf(-47.5 + x, 37.5 + y, -45 + x, 35 + y);
	//6,3
	coloreamela();
	glRectf(-45 + x, 37.5 + y, -42.5 + x, 35 + y);
	//6,4
	coloreamela();
	glRectf(-42.5 + x, 37.5 + y, -40 + x, 35 + y);
	//6,5
	coloreamela();
	glRectf(-40 + x, 37.5 + y, -37.5 + x, 35 + y);
	//2,5
	coloreamela();
	glRectf(-40+x,47.5+y,-37.5+x,45+y);
	//3,5
	coloreamela();
	glRectf(-40+x,45+y,-37.5+x,42.5+y);
	//4,5
	coloreamela();
	glRectf(-40+x,42.5+y,-37.5+x,40+y);
	//5,5
	coloreamela();
	glRectf(-40+x,40+y,-37.5+x,37.5+y);
	//6,5
	coloreamela();
	glRectf(-40+x,37.5+y,-37.5+x,35+y);
}

//funcion para dibujar D no se usa, favor de comentarlo 
void drawD(int x, int y) {
	//1,1
	coloreamela();
	glRectf(-50 + x, 50 + y, -47.5 + x, 47.5 + y);
	//2,1
	coloreamela();
	glRectf(-50 + x, 47.5 + y, -47.5 + x, 45 + y);
	//3,1
	coloreamela();
	glRectf(-50 + x, 45 + y, -47.5 + x, 42.5 + y);
	//4,1
	coloreamela();
	glRectf(-50 + x, 42.5 + y, -47.5 + x, 40 + y);
	//5,1
	coloreamela();
	glRectf(-50 + x, 40 + y, -47.5 + x, 37.5 + y);
	//6,1
	coloreamela();
	glRectf(-50 + x, 37.5 + y, -47.5 + x, 35 + y);
	//1,2
	coloreamela();
	glRectf(-47.5 + x, 50 + y, -45 + x, 47.5 + y);
	//1,3
	coloreamela();
	glRectf(-45 + x, 50 + y, -42.5 + x, 47.5 + y);
	//2,4
	coloreamela();
	glRectf(-42.5 + x, 47.5 + y, -40 + x, 45 + y);
	//3,5
	coloreamela();
	glRectf(-40 + x, 45 + y, -37.5 + x, 42.5 + y);
	//4,5
	coloreamela();
	glRectf(-40 + x, 42.5 + y, -37.5 + x, 40 + y);
	//5,5
	coloreamela();
	glRectf(-40 + x, 40 + y, -37.5 + x, 37.5 + y);
	//6,4
	coloreamela();
	glRectf(-42.5 + x, 37.5 + y, -40 + x, 35 + y);
	//6,3
	coloreamela();
	glRectf(-45 + x, 37.5 + y, -42.5 + x, 35 + y);
	//6,2
	coloreamela();
	glRectf(-47.5 + x, 37.5 + y, -45 + x, 35 + y);
}