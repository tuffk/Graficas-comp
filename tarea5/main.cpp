/*
	Teclados:
	S mueve de manera en revolucion los brazos
	A mueve los brazos de manera rotacional
	E mueve el codo de manera rotacional
	t mueve el antebrazo en torsion
	d mueve de manera rotacional la mano en X
	f mueve de manera rotacional la mano en Y
	x gira la cabeza de manera rotacional en X
	c mueve la cabeza en rotacion
	p mueve la pierna en rotacion en X
	o mueve la pierna en rotacion en Z
	l mueve la rodilla en rotacion en X
	m mueve el tobillo en rotacion en x
*/
#include "Interface.h"

Interface *inter; //Objeto proxy

// openGL stuff
void display(void);
void reshape(int, int);
void keyboard(unsigned char, int, int);

int main(int argc, char** argv) {

	//inicio de openGL
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);

	inter = new Interface();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	
	delete inter;
	return 0;
}

void display(void) {
	inter->display();
}

void reshape(int w, int h) {
	inter->reshape(w, h);
}

void keyboard(unsigned char key, int x, int y) {
	inter->keyboard(key, x, y);
}