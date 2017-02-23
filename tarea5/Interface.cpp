#include "Interface.h"

//Constructor de la clase
Interface::Interface() {

	robot = new Robot();
	init();
}

//magia  OpenGL
void Interface::init(void) {

	GLfloat ambient[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat position[] = { 0.0, 3.0, 2.0, 0.0 };
	GLfloat lmodel_ambient[] = { 0.4, 0.4, 0.4, 1.0 };
	GLfloat local_view[] = { 0.0 };

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
	glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glClearColor(0.0, 0.0, 0.0, 0.0);
}

//display
void Interface::display(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	Material *cabeza = new Material(1.0, .5, .5, 1.0);
	Material *ojos = new Material(1.0, 0.0, 0.0, 1.0);
	Material *nariz = new Material(0.7, 0.7, 0.0, 1.0);
	robot->cabeza(0.0, 6.5, cabeza, nariz, ojos);

	Material *torso = new Material(0.3, 0.2, 0.3, 1.0);
	robot->torso(1.0, 2.0, torso);

	Material *brazo = new Material(1.0, .5, .5, 1.0);
	robot->brazo(1.5, 2.0, 1.5, brazo);
	robot->brazo(-1.5, 2.0, 1.5, brazo);

	Material *pierna = new Material(1.0, .5, .5, 1.0);
	robot->pierna(1.3, -2.8, 1.3, pierna);
	robot->pierna(-1.3, -2.8, 1.3, pierna);

	glutSwapBuffers();
}

//magia de camara
void Interface::reshape(int w, int h) {

	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 200.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -25.0);
	glRotatef(35, 0.0, 1.0, 0.0);
}

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
void Interface::keyboard(unsigned char key, int x, int y) {

	switch (key) {
	case 's':
		robot->setShoulderZ( (robot->getShoulderZ() + 5) % 360 );
		glutPostRedisplay();
		break;
	case 'S':
		robot->setShoulderZ((robot->getShoulderZ() - 5) % 360);
		glutPostRedisplay();
		break;
	case 'a':
		robot->setShoulderX( (robot->getShoulderX() + 5) % 360 );
		glutPostRedisplay();
		break;
	case 'A':
		robot->setShoulderX((robot->getShoulderX() - 5) % 360);
		glutPostRedisplay();
		break;
	case 'e':
		robot->setElbow( (robot->getElbow() + 5) % 360);
		glutPostRedisplay();
		break;
	case 'E':
		robot->setElbow((robot->getElbow() - 5) % 360);
		glutPostRedisplay();
		break;
	case 't':
		robot->setTorsion( (robot->getTorsion() + 5) % 360 );
		glutPostRedisplay();
		break;
	case 'T':
		robot->setTorsion((robot->getTorsion() - 5) % 360);
		glutPostRedisplay();
		break;
	case 'd':
		robot->setAnguloMano1( (robot->getAnguloMano1() + 5) % 360);
		glutPostRedisplay();
		break;
	case 'D':
		robot->setAnguloMano1( (robot->getAnguloMano1() - 5) % 360);
		glutPostRedisplay();
		break;
	case 'f':
		robot->setAnguloMano2( (robot->getAnguloMano2() + 5) % 360);
		glutPostRedisplay();
		break;
	case 'F':
		robot->setAnguloMano2( (robot->getAnguloMano2() - 5) % 360);
		glutPostRedisplay();
		break;
	case 'x':
		robot->setGiroCabeza( (robot->getGiroCabeza() + 5) % 360);
		glutPostRedisplay();
		break;
	case 'X':
		robot->setGiroCabeza((robot->getGiroCabeza() - 5) % 360);
		glutPostRedisplay();
		break;
	case 'c':
		robot->setRotacionCabeza( (robot->getRotacionCabeza() + 5) % 360);
		glutPostRedisplay();
		break;
	case 'C':
		robot->setRotacionCabeza((robot->getRotacionCabeza() - 5) % 360);
		glutPostRedisplay();
		break;
	case 'p':
		robot->setAnguloPierna1( (robot->getAnguloPierna1() + 5) % 360);
		glutPostRedisplay();
		break;
	case 'P':
		robot->setAnguloPierna1((robot->getAnguloPierna1() - 5) % 360);
		glutPostRedisplay();
		break;
	case 'o':
		robot->setAnguloPierna2((robot->getAnguloPierna2() + 5) % 360);
		glutPostRedisplay();
		break;
	case 'O':
		robot->setAnguloPierna2((robot->getAnguloPierna2() - 5) % 360);
		glutPostRedisplay();
		break;
	case 'l':
		robot->setRodilla( (robot->getRodilla() + 5) % 360);
		glutPostRedisplay();
		break;
	case 'L':
		robot->setRodilla((robot->getRodilla() - 5) % 360);
		glutPostRedisplay();
		break;
	case 'm':
		robot->setTobillo( (robot->getTobillo() + 5) % 360);
		glutPostRedisplay();
		break;
	case 'M':
		robot->setTobillo((robot->getTobillo() - 5) % 360);
		glutPostRedisplay();
		break;
	case 27:
		exit(0);
		break;
	default:
		break;
	}
}

//Destructor de la clase
Interface::~Interface() {
	delete robot;
}