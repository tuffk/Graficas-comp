#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h> 
#include <stdlib.h>
#include <time.h>



void display(void);
void init(void);
void reshape(int, int);

//letras
void drawM(int, int);
void drawA(int, int);
void drawR(int, int);
void drawC(int, int);
void drawO(int, int);
void drawS(int, int);
void drawL(int, int);
void drawP(int, int);
void drawE(int, int);
void drawZ(int, int);
void drawN(int, int);
void drawD(int, int);

int main(int argc, char** argv)
{
	//inicio para hacer la ventana con GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("tarea 2");
	init();

	//funciones para hacer el display 
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	//que dibuje continuamente 
	glutMainLoop();

	return 0;
}

//Desplegar 
void display(void)
{

	glClear(GL_COLOR_BUFFER_BIT);

	//iniciamos una semilla para valores aleatorios, esto va pintar cada pixel de las letras con un valor diferente cada uno
	srand((int)time(NULL));

	//1,1 6,6
	drawM(0, 0);
	//8,1 12, 1
	drawA(17.5, 0);
	//14,1 18, 6 
	drawR(32.5, 0);
	//20, 1
	drawC(47.5, 0);
	//26, 1
	drawO(62.5, 0);
	//33, 1
	drawS(80, 0);
	//1, 8
	drawL(0, -17.5);
	//5, 8
	drawO(10, -17.5);
	//11, 8
	drawP(27.5, -17.5);
	//17, 8
	drawE(42.5, -17.5);
	//23, 8
	drawZ(57.5, -17.5);
	//0, 15
	drawM(0, -35);
	//8, 15
	drawE(17.5, -35);
	//14, 15
	drawN(32.5, -35);
	//20, 15
	drawD(50, -35);
	//26,15
	drawO(65, -35);
	//32,15
	drawZ(82.5, -35);
	//38, 15
	drawA(97.5, -35);

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
	glOrtho(-50.0, 60.0, -50.0, 50.0, -2.0, 2.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

//M
void drawM(int x, int y) {

	// 1, 1
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50.0 + x, 50.0 + y, -47.5 + x, 47.5 + y);

	//2, 1
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-47.5 + x, 50.0 + y, -45 + x, 47.5 + y);

	//3, 2
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-45 + x, 47.5 + y, -42.5 + x, 45 + y);

	//4, 2
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-42.5 + x, 47.5 + y, -40 + x, 45 + y);

	//5, 1
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-40 + x, 50 + y, -37.5 + x, 47.5 + y);

	//6, 1
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-37.5 + x, 50 + y, -35 + x, 47.5 + y);

	//6, 2
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-37.5 + x, 47.5 + y, -35 + x, 45 + y);

	//6, 3
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-37.5 + x, 45 + y, -35 + x, 42.5 + y);

	//6, 4
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-37.5 + x, 42.5 + y, -35 + x, 40 + y);

	//6, 5
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-37.5 + x, 40 + y, -35 + x, 37.5 + y);

	//6, 6
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-37.5 + x, 37.5 + y, -35 + x, 35 + y);

	//1, 2
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50.0 + x, 47.5 + y, -47.5 + x, 45 + y);

	//1, 3
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50.0 + x, 45.0 + y, -47.5 + x, 42.5 + y);

	//1, 4
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50.0 + x, 42.5 + y, -47.5 + x, 40 + y);

	//1, 5
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50.0 + x, 40 + y, -47.5 + x, 37.5 + y);

	//1, 6
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50.0 + x, 37.5 + y, -47.5 + x, 35 + y);

}

// A
void drawA(int x, int y) {

	//1, 1
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-45.0 + x, 50.0 + y, -42.5 + x, 47.5 + y);

	//0,2
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-47.5 + x, 47.5 + y, -45 + x, 45 + y);

	//0,3
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-47.5 + x, 45 + y, -45 + x, 42.5 + y);

	//-1,4
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50 + x, 42.5 + y, -47.5 + x, 40 + y);

	//-1,5
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50 + x, 40 + y, -47.5 + x, 37.5 + y);

	//-1,6
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50 + x, 37.5 + y, -47.5 + x, 35 + y);

	//2,2
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-42.5 + x, 47.5 + y, -40 + x, 45 + y);

	//2, 3
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-42.5 + x, 45 + y, -40 + x, 42.5 + y);

	//3, 4
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-40 + x, 42.5 + y, -37.5 + x, 40 + y);

	//3, 5
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-40 + x, 40 + y, -37.5 + x, 37.5 + y);

	//3, 6
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-40 + x, 37.5 + y, -37.5 + x, 35 + y);

	//2, 4
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-42.5 + x, 42.5 + y, -40 + x, 40 + y);

	//1, 4
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-45 + x, 42.5 + y, -42.5 + x, 40 + y);

	//0, 4
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-47.5 + x, 42.5 + y, -45 + x, 40 + y);
}

// R
void drawR(int x, int y) {

	//1,1
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50 + x, 50 + y, -47.5 + x, 47.5 + y);

	//2,1
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50 + x, 47.5 + y, -47.5 + x, 45 + y);

	//3, 1
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50 + x, 45 + y, -47.5 + x, 42.5 + y);

	//4, 1
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50 + x, 42.5 + y, -47.5 + x, 40 + y);

	//5, 1
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50 + x, 40 + y, -47.5 + x, 37.5 + y);

	//6, 1
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50 + x, 37.5 + y, -47.5 + x, 35 + y);

	//1, 2
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-47.5 + x, 50 + y, -45 + x, 47.5 + y);

	//1, 3
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-45 + x, 50 + y, -42.5 + x, 47.5 + y);

	//1, 4
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-42.5 + x, 50 + y, -40 + x, 47.5 + y);

	//2, 5
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-40 + x, 47.5 + y, -37.5 + x, 45 + y);

	//3, 2
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-47.5 + x, 45 + y, -45 + x, 42.5 + y);

	//3, 3
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-45 + x, 45 + y, -42.5 + x, 42.5 + y);

	//3, 4
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-42.5 + x, 45 + y, -40 + x, 42.5 + y);

	//4, 5
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-40 + x, 42.5 + y, -37.5 + x, 40 + y);

	//5, 5
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-40 + x, 40 + y, -37.5 + x, 37.5 + y);

	//6, 5
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-40 + x, 37.5 + y, -37.5 + x, 35 + y);
}

//G


// O
void drawO(int x, int y) {

	//1, 1
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-47.5 + x, 50 + y, -45 + x, 47.5 + y);

	//1, 2
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-45 + x, 50 + y, -42.5 + x, 47.5 + y);

	//1, 3
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-42.5 + x, 50 + y, -40 + x, 47.5 + y);

	//1, 4
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-40 + x, 50 + y, -37.5 + x, 47.5 + y);

	//2, 5
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-37.5 + x, 47.5 + y, -35 + x, 45 + y);

	//3, 5
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-37.5 + x, 45 + y, -35 + x, 42.5 + y);

	//4, 5
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-37.5 + x, 42.5 + y, -35 + x, 40 + y);

	//5, 5
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-37.5 + x, 40 + y, -35 + x, 37.5 + y);

	//6, 4
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-40 + x, 37.5 + y, -37.5 + x, 35 + y);

	//6, 3
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-42.5 + x, 37.5 + y, -40 + x, 35 + y);

	//6, 2
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-45 + x, 37.5 + y, -42.5 + x, 35 + y);

	//2, 0
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50 + x, 47.5 + y, -47.5 + x, 45 + y);

	//3, 0
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50 + x, 45 + y, -47.5 + x, 42.5 + y);

	//4,0
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50 + x, 42.5 + y, -47.5 + x, 40 + y);

	//5, 0
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50 + x, 40 + y, -47.5 + x, 37.5 + y);

	//6, 1
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-47.5 + x, 37.5 + y, -45 + x, 35 + y);

}

//C
void drawC(int x, int y) {

	//1,1 
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50 + x, 45 + y, -47.5 + x, 42.5 + y);

	//0,2
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-47.5 + x, 47.5 + y, -45 + x, 45 + y);

	//-1,3
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-45 + x, 50 + y, -42.5 + x, 47.5 + y);

	//-1,4
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-42.5 + x, 50 + y, -40 + x, 47.5 + y);
	
	//-1,5
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-40 + x, 50 + y, -37.5 + x, 47.5 + y);
	
	//2,1
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50 + x, 42.5 + y, -47.5 + x, 40 + y);

	//3,2
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-47.5 + x, 40 + y, -45 + x, 37.5 + y);

	//4,3
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-45 + x, 37.5 + y, -42.5 + x, 35 + y);

	//4,4
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-42.5 + x, 37.5 + y, -40 + x, 35 + y);

	//4,5
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-40 + x, 37.5 + y, -37.5 + x, 35 + y);
}



//Funci�n para dibujar S
void drawS(int x, int y) {

	//1,1
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50 + x, 50 + y, -47.5 + x, 47.5 + y);

	//1,2
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-47.5 + x, 50 + y, -45 + x, 47.5 + y);

	//1,3
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-45 + x, 50 + y, -42.5 + x, 47.5 + y);

	//1,4
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-42.5 + x, 50 + y, -40 + x, 47.5 + y);

	//1,5
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-40 + x, 50 + y, -37.5 + x, 47.5 + y);

	//2,1
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50 + x, 47.5 + y, -47.5 + x, 45 + y);

	//3,2
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-47.5 + x, 45 + y, -45 + x, 42.5 + y);

	//3,3
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-45 + x, 45 + y, -42.5 + x, 42.5 + y);

	//3,4
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-42.5 + x, 45 + y, -40 + x, 42.5 + y);

	//4,5
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-40 + x, 42.5 + y, -37.5 + x, 40 + y);

	//5,5
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-40 + x, 40 + y, -37.5 + x, 37.5 + y);

	//6,4
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-42.5 + x, 37.5 + y, -40 + x, 35 + y);

	//6,3
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-45 + x, 37.5 + y, -42.5 + x, 35 + y);

	//6,2
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-47.5 + x, 37.5 + y, -45 + x, 35 + y);

	//6,1
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50 + x, 37.5 + y, -47.5 + x, 35 + y);
}

//Funci�n para dibujar L
void drawL(int x, int y) {

	//1,1
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50 + x, 50 + y, -47.5 + x, 47.5 + y);

	//2,1
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50 + x, 47.5 + y, -47.5 + x, 45 + y);

	//3,1
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50 + x, 45 + y, -47.5 + x, 42.5 + y);

	//4,1
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50 + x, 42.5 + y, -47.5 + x, 40 + y);

	//5,1
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50 + x, 40 + y, -47.5 + x, 37.5 + y);

	//6,1
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50 + x, 37.5 + y, -47.5 + x, 35 + y);

	//6,2
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-47.5 + x, 37.5 + y, -45 + x, 35 + y);

	//6,3
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-45 + x, 37.5 + y, -42.5 + x, 35 + y);


}

//Funci�n para dibujar P
void drawP(int x, int y) {

	//1,1
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50 + x, 50 + y, -47.5 + x, 47.5 + y);

	//2,1
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50 + x, 47.5 + y, -47.5 + x, 45 + y);

	//3, 1
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50 + x, 45 + y, -47.5 + x, 42.5 + y);

	//4, 1
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50 + x, 42.5 + y, -47.5 + x, 40 + y);

	//5, 1
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50 + x, 40 + y, -47.5 + x, 37.5 + y);

	//6, 1
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50 + x, 37.5 + y, -47.5 + x, 35 + y);

	//1, 2
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-47.5 + x, 50 + y, -45 + x, 47.5 + y);

	//1, 3
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-45 + x, 50 + y, -42.5 + x, 47.5 + y);

	//1, 4
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-42.5 + x, 50 + y, -40 + x, 47.5 + y);

	//2, 5
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-40 + x, 47.5 + y, -37.5 + x, 45 + y);

	//3, 2
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-47.5 + x, 45 + y, -45 + x, 42.5 + y);

	//3, 3
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-45 + x, 45 + y, -42.5 + x, 42.5 + y);

	//3, 4
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-42.5 + x, 45 + y, -40 + x, 42.5 + y);

}

//Funci�n para dibujar E
void drawE(int x, int y) {

	//1,1
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50 + x, 50 + y, -47.5 + x, 47.5 + y);

	//1,2
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-47.5 + x, 50 + y, -45 + x, 47.5 + y);

	//1,3
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-45 + x, 50 + y, -42.5 + x, 47.5 + y);

	//1,4
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-42.5 + x, 50 + y, -40 + x, 47.5 + y);

	//1,5
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-40 + x, 50 + y, -37.5 + x, 47.5 + y);

	//2,1
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50 + x, 47.5 + y, -47.5 + x, 45 + y);

	//3,1
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50 + x, 45 + y, -47.5 + x, 42.5 + y);

	//3,2
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-47.5 + x, 45 + y, -45 + x, 42.5 + y);

	//3,3
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-45 + x, 45 + y, -42.5 + x, 42.5 + y);

	//3,4
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-42.5 + x, 45 + y, -40 + x, 42.5 + y);

	//3,5
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-40 + x, 45 + y, -37.5 + x, 42.5 + y);

	//4,1
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50 + x, 42.5 + y, -47.5 + x, 40 + y);

	//5,1
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50 + x, 40 + y, -47.5 + x, 37.5 + y);

	//6,1
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50 + x, 37.5 + y, -47.5 + x, 35 + y);

	//6,2
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-47.5 + x, 37.5 + y, -45 + x, 35 + y);

	//6,3
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-45 + x, 37.5 + y, -42.5 + x, 35 + y);

	//6,4
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-42.5 + x, 37.5 + y, -40 + x, 35 + y);

	//6,5
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-40 + x, 37.5 + y, -37.5 + x, 35 + y);

}

//Funci�n para dibujar Z
void drawZ(int x, int y) {

	//1,1
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50 + x, 50 + y, -47.5 + x, 47.5 + y);

	//1,2
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-47.5 + x, 50 + y, -45 + x, 47.5 + y);

	//1,3
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-45 + x, 50 + y, -42.5 + x, 47.5 + y);

	//1,4
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-42.5 + x, 50 + y, -40 + x, 47.5 + y);

	//1,5
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-40 + x, 50 + y, -37.5 + x, 47.5 + y);

	//2,4
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-42.5 + x, 47.5 + y, -40 + x, 45 + y);

	//3,3
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-45 + x, 45 + y, -42.5 + x, 42.5 + y);

	//4,2
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-47.5 + x, 42.5 + y, -45 + x, 40 + y);

	//5,1
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50 + x, 40 + y, -47.5 + x, 37.5 + y);

	//6,1
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50 + x, 37.5 + y, -47.5 + x, 35 + y);

	//6,2
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-47.5 + x, 37.5 + y, -45 + x, 35 + y);

	//6,3
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-45 + x, 37.5 + y, -42.5 + x, 35 + y);

	//6,4
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-42.5 + x, 37.5 + y, -40 + x, 35 + y);

	//6,5
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-40 + x, 37.5 + y, -37.5 + x, 35 + y);
}

//Funci�n para dibujar N
void drawN(int x, int y) {

	//1,1
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50 + x, 50 + y, -47.5 + x, 47.5 + y);

	//2,1
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50 + x, 47.5 + y, -47.5 + x, 45 + y);

	//3,1
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50 + x, 45 + y, -47.5 + x, 42.5 + y);

	//4,1
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50 + x, 42.5 + y, -47.5 + x, 40 + y);

	//5,1
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50 + x, 40 + y, -47.5 + x, 37.5 + y);

	//6,1
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50 + x, 37.5 + y, -47.5 + x, 35 + y);

	//2,2
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-47.5 + x, 47.5 + y, -45 + x, 45 + y);

	//3,3
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-45 + x, 45 + y, -42.5 + x, 42.5 + y);

	//4,4
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-42.5 + x, 42.5 + y, -40 + x, 40 + y);

	//5,5
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-40 + x, 40 + y, -37.5 + x, 37.5 + y);

	//1,6
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-37.5 + x, 50 + y, -35 + x, 47.5 + y);

	//2,6
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-37.5 + x, 47.5 + y, -35 + x, 45 + y);

	//3,6
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-37.5 + x, 45 + y, -35 + x, 42.5 + y);

	//4,6
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-37.5 + x, 42.5 + y, -35 + x, 40 + y);

	//5,6
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-37.5 + x, 40 + y, -35 + x, 37.5 + y);

	//6,6
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-37.5 + x, 37.5 + y, -35 + x, 35 + y);

}

//Funci�n para dibujar D
void drawD(int x, int y) {

	//1,1
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50 + x, 50 + y, -47.5 + x, 47.5 + y);

	//2,1
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50 + x, 47.5 + y, -47.5 + x, 45 + y);

	//3,1
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50 + x, 45 + y, -47.5 + x, 42.5 + y);

	//4,1
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50 + x, 42.5 + y, -47.5 + x, 40 + y);

	//5,1
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50 + x, 40 + y, -47.5 + x, 37.5 + y);

	//6,1
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-50 + x, 37.5 + y, -47.5 + x, 35 + y);

	//1,2
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-47.5 + x, 50 + y, -45 + x, 47.5 + y);

	//1,3
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-45 + x, 50 + y, -42.5 + x, 47.5 + y);

	//2,4
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-42.5 + x, 47.5 + y, -40 + x, 45 + y);

	//3,5
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-40 + x, 45 + y, -37.5 + x, 42.5 + y);

	//4,5
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-40 + x, 42.5 + y, -37.5 + x, 40 + y);

	//5,5
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-40 + x, 40 + y, -37.5 + x, 37.5 + y);

	//6,4
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-42.5 + x, 37.5 + y, -40 + x, 35 + y);

	//6,3
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-45 + x, 37.5 + y, -42.5 + x, 35 + y);

	//6,2
	glColor3f(((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX), ((double)rand() / RAND_MAX));
	glRectf(-47.5 + x, 37.5 + y, -45 + x, 35 + y);
}