#include "Robot.h"

//Constructor
Robot::Robot() {
	shoulderZ = 180;
	shoulderX = 90;
	elbow = 0;
	torsion = 0;
	anguloMano1 = 0;
	anguloMano2 = 0;
	rotacionCabeza = 0;
	giroCabeza = 0;
	anguloPierna1 = 0;
	anguloPierna2 = 0;
	rodilla = 0;
	tobillo = 0;
}

//GETS
int Robot::getShoulderZ() { return shoulderZ; };
int Robot::getShoulderX() { return shoulderX; };
int Robot::getElbow() { return elbow; };
int Robot::getTorsion() { return torsion; };
int Robot::getAnguloMano1() { return anguloMano1; };
int Robot::getAnguloMano2() { return anguloMano2; };
int Robot::getRotacionCabeza() { return rotacionCabeza; };
int Robot::getGiroCabeza() { return giroCabeza; };
int Robot::getAnguloPierna1() {	return anguloPierna1; };
int Robot::getAnguloPierna2() { return anguloPierna2; };
int Robot::getRodilla() { return rodilla; };
int Robot::getTobillo() { return tobillo; };

//SETS
void Robot::setShoulderZ(int s) { shoulderZ = s; };
void Robot::setShoulderX(int s) { shoulderX = s; };
void Robot::setElbow(int e) { elbow = e; };
void Robot::setTorsion(int t) { torsion = t; };
void Robot::setAnguloMano1(int a) { anguloMano1 = a; };
void Robot::setAnguloMano2(int a) { anguloMano2 = a; };
void Robot::setRotacionCabeza(int r) { rotacionCabeza = r; };
void Robot::setGiroCabeza(int g) { giroCabeza = g; };
void Robot::setAnguloPierna1(int a) { anguloPierna1 = a; };
void Robot::setAnguloPierna2(int a) { anguloPierna2 = a; };
void Robot::setRodilla(int r) { rodilla = r; };
void Robot::setTobillo(int t) { tobillo = t; };


// <head>
void Robot::cabeza(double x, double y, Material * c, Material * n, Material * o) {
	glPushMatrix();
		glTranslatef(x, y - 3, 0.0);
		glRotatef((GLfloat) giroCabeza, 1.0, 0.0, 0.0); //giro de torsion de la cabeza
		glTranslatef(0.0, 3, 0.0);
		glRotatef((GLfloat) rotacionCabeza, 0.0, 1.0, 0.0); //giro rotacional de la cabeza
		c->createMaterial();
		glutSolidSphere(3, 20, 20);
		glPushMatrix();
			glTranslatef(0.0, 0.0, 3.0);
			n->createMaterial();
			glutSolidCone(0.5, 4.0, 20, 20);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(1.0, 1.0, 2.5);
			o->createMaterial();
			glutSolidSphere(0.5, 20, 20);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-1.0, 1.0, 2.5);
			o->createMaterial();
			glutSolidSphere(0.5, 20, 20);
		glPopMatrix();

	glPopMatrix();
} //</head>

//<body>
void Robot::torso(double x, double y, Material *t) {
	glPushMatrix();
		glScalef(x, y, 1.0);
		t->createMaterial();
		glutSolidSphere(3, 20, 20);
	glPopMatrix();
}


void Robot::brazo(double x, double y, double z, Material *b) {

	glPushMatrix();
		glTranslatef(x, y, z);
		glRotatef(90, 0.0, 1.0, 0.0);
		glRotatef((GLfloat)shoulderZ, 0.0, 0.0, 1.0); //giro de revoluci�n del brazo
		glTranslatef(1.75, 0.0, 0.0);
		glPushMatrix();
			glRotatef((GLfloat)shoulderX, 1.0, 0.0, 0.0); //giro rotacional del brazo

			glPushMatrix();
				glScalef(3, .5, 1.0);
				b->createMaterial();
				glutSolidSphere(1, 20, 20);
			glPopMatrix();

			anteBrazo(b);

		glPopMatrix();


	glPopMatrix();
}


void Robot::anteBrazo(Material *b) {
	glPushMatrix();
		
			glTranslatef(3, 0.0, 0.0);
			glRotatef((GLfloat)elbow, 0.0, 1.0, 0.0); //giro rotacional del codo
			glRotatef((GLfloat) torsion, 0.0, 0.0, 1.0); //giro de torsion del antebrazo
			b->createMaterial();
			glutSolidCone(.5, 6, 20, 20);

			mano(b);

	glPopMatrix();
}


void Robot::mano(Material *b) {
	
	glPushMatrix();

		glTranslatef(0.0, 0.0, 5.5);
		glRotatef((GLfloat) anguloMano1, 0.0, 1.0, 0.0); //giro rotacional de la mano
		glRotatef((GLfloat)anguloMano2, 1.0, 0.0, 0.0); //giro rotacional de la mano
		glTranslatef(0.0, 0.0, 0.5);
		glScalef(0.4, 0.4, 0.4);
		b->createMaterial();
		glutSolidDodecahedron();

	glPopMatrix();

}


void Robot::pierna(double x, double y, double z, Material *p) {
	glPushMatrix();

		glTranslatef(x, y - 0.5, z);
		glRotatef((GLfloat)anguloPierna1, 1.0, 0.0, 0.0); //giro rotacional de la pierna
		glRotatef((GLfloat)anguloPierna2, 0.0, 0.0, 1.0); //giro rotacional de la pierna
		glPushMatrix();
			glScalef(1.1, 2.5, 1.0);
			glTranslatef(0.0, -1.0, 0.0);
			p->createMaterial();
			glutSolidSphere(1.0, 20, 20);
		glPopMatrix();
		espinilla(p);

	glPopMatrix();
}


void Robot::espinilla(Material *p) {

	glPushMatrix();

		glTranslatef(0.0, -5.0, 0.0);
		glRotatef( (GLfloat) rodilla, 1.0, 0.0, 0.0); //giro rotacional de la rodilla
		glPushMatrix();
			glScalef(0.8, 3.0, 1.0);
			glTranslatef(0.0, -0.5, 0.0);
			p->createMaterial();
			glutSolidSphere(1.0, 20, 20);
		glPopMatrix();

		pie(p);
	glPopMatrix();
}


void Robot::pie(Material *p) {

	glPushMatrix();

		glTranslatef(0.0, -4, 0.0);
		glRotatef((GLfloat) tobillo, 1.0, 0.0, 0.0); //giro rotacional del tobillo
		glScalef(0.5, 0.5, 1.5);
		glTranslatef(0.0, 0.0, 1.0);
		p->createMaterial();
		glutSolidSphere(1.0, 20, 20);

	glPopMatrix();

}//</body>

//Destructor
Robot::~Robot()
{
}