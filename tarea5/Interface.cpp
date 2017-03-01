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

void Interface::keyboard(unsigned char key, int x, int y) {

	switch (key) {
	case 's':
		if (robot->getShoulderZ() < 245){
			robot->setShoulderZ( (robot->getShoulderZ() + 5) % 360 );
			glutPostRedisplay();
		}// limite inferior movimiento hombros
		break;
	case 'S':
		if (robot->getShoulderZ() > 135){
			robot->setShoulderZ((robot->getShoulderZ() - 5) % 360);
			glutPostRedisplay();
		}// limite superior movimiento hombros
		break;
	case 'a':
		if (robot->getShoulderX() < 150){
			robot->setShoulderX( (robot->getShoulderX() + 5) % 360 );
			glutPostRedisplay();
		} // limite baila izq
		break;
	case 'A':
		if (robot->getShoulderX() > 45){
			robot->setShoulderX((robot->getShoulderX() - 5) % 360);
			glutPostRedisplay();
		} // limite baile der
		break;
	case 'e':
		if(robot->getElbow() < 95){
			robot->setElbow( (robot->getElbow() + 5) % 360);
			glutPostRedisplay();
		} // limite estirar brazo
		break;
	case 'E':
		if(robot->getElbow() > -45){
			robot->setElbow((robot->getElbow() - 5) % 360);
			glutPostRedisplay();
		} // limite contraer brazo
		break;
	case 't':
		if(robot->getTorsion() < 80) {
			robot->setTorsion( (robot->getTorsion() + 5) % 360 );
			glutPostRedisplay();
		} // limite torcion muñecas
		break;
	case 'T':
		if(robot->getTorsion() > -80) {
			robot->setTorsion((robot->getTorsion() - 5) % 360);
			glutPostRedisplay();
		} // limite torcion muñecas
		break;
	case 'd':
		if(robot->getAnguloMano1() < 25) {
			robot->setAnguloMano1( (robot->getAnguloMano1() + 5) % 360);
			glutPostRedisplay();
		} // limite muñecas
		break;
	case 'D':
		if(robot->getAnguloMano1() > -35) {
			robot->setAnguloMano1( (robot->getAnguloMano1() - 5) % 360);
			glutPostRedisplay();
		} // limite muñecas
		break;
	case 'f':
		if (robot->getAnguloMano2() < 40 ) {
			robot->setAnguloMano2( (robot->getAnguloMano2() + 5) % 360);
			glutPostRedisplay();
		} // caramel dance
		break;
	case 'F':
		if (robot->getAnguloMano2() > -35){
			robot->setAnguloMano2( (robot->getAnguloMano2() - 5) % 360);
			glutPostRedisplay();
		} // caramel dance
		break;
	case 'x':
		if (robot->getGiroCabeza() < 35){
			robot->setGiroCabeza( (robot->getGiroCabeza() + 5) % 360);
			glutPostRedisplay();
		} // limite si
		break;
	case 'X':
		if(robot->getGiroCabeza() > -15){
			robot->setGiroCabeza((robot->getGiroCabeza() - 5) % 360);
			glutPostRedisplay();
		} // limite no
		break;
	case 'c':
		if(robot->getRotacionCabeza() < 35) {
			robot->setRotacionCabeza( (robot->getRotacionCabeza() + 5) % 360);
			glutPostRedisplay();
		}// limite no
		break;
	case 'C':
		if(robot->getRotacionCabeza() > -35){
			robot->setRotacionCabeza((robot->getRotacionCabeza() - 5) % 360);
			glutPostRedisplay();
		} // limite no
		break;
	case 'p':
		if(robot->getAnguloPierna1() < 15){
			robot->setAnguloPierna1( (robot->getAnguloPierna1() + 5) % 360);
			glutPostRedisplay();
		} // posesion por satanas
		break;
	case 'P':
		if(robot->getAnguloPierna1() > -85) {
			robot->setAnguloPierna1((robot->getAnguloPierna1() - 5) % 360);
			glutPostRedisplay();
		}// sentarse
		break;
	case 'o':
		if(robot->getAnguloPierna2() < 20){
			robot->setAnguloPierna2((robot->getAnguloPierna2() + 5) % 360);
			glutPostRedisplay();
		}
		break;
	case 'O':
		if(robot->getAnguloPierna2() > -20){
			robot->setAnguloPierna2((robot->getAnguloPierna2() - 5) % 360);
			glutPostRedisplay();
		}
		break;
	case 'l':
		if(robot->getRodilla() < 80){
			robot->setRodilla( (robot->getRodilla() + 5) % 360);
			glutPostRedisplay();
		}
		break;
	case 'L':
		if(robot->getRodilla() > -10){
			robot->setRodilla((robot->getRodilla() - 5) % 360);
			glutPostRedisplay();
		}
		break;
	case 'm':
		if(robot->getTobillo() < 10){
			robot->setTobillo( (robot->getTobillo() + 5) % 360);
			glutPostRedisplay();
		}
		break;
	case 'M':
		if(robot->getTobillo() > -20) {
			robot->setTobillo((robot->getTobillo() - 5) % 360);
			glutPostRedisplay();
		}
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