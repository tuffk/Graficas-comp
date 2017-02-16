
#include "Interface.h"

Interface *inter; // proxy

// opengl main magic
void display(void);
void reshape(int w, int h);
void simulation();

int main(int argc, char **argv) {

	inter = new Interface;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1000, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Tarea 5");
	inter->init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(simulation);
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

void simulation() {
	inter->simulation();
}
