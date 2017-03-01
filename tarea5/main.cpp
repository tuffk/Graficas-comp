/*
	s/S mueve de manera en revolucion los brazos
	a/A mueve los brazos de manera rotacional
	e/E mueve el codo de manera rotacional
	t/T mueve el antebrazo en torsion
	d/D mueve de manera rotacional la mano en X
	f/F mueve de manera rotacional la mano en Y
	x/X gira la cabeza de manera rotacional en X
	c/C mueve la cabeza en rotacion
	p/P mueve la pierna en rotacion en X
	o/O mueve la pierna en rotacion en Z
	l/L mueve la rodilla en rotacion en X
	m/M mueve el tobillo en rotacion en x
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