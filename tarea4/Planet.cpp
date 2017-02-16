#include "Planet.h"

Planet::Planet(double d, double s, double t, double r, Material * ma) {
	year = 0.0;
	day = 0.0;
	distance = d;
	size = s;
	moons = new vector<Planet *>;
	material = ma;
	rings = false;
	eje = false;
	translation = t;
	rotation = r;
}

// traslacion espacial como se vio en clase
void Planet::simulation() {
	day =  (day + rotation);
	year = (year + translation);
	glutPostRedisplay();

	// lo mismo aplicado a la lunas
	for (int i = 0; i < moons->size(); ++i) {
		moons->at(i)->simulation();
	}
}

// if you like it put a ring on it
void Planet::insertRings(bool x) {

	rings = true;

	glPushMatrix();
		if (x) {
			glRotatef(90, 1, 0, 0);
			eje = true;
		} // definir orientacion de anillos
		glScalef(1.0, 1.0, 0.1);
		glutSolidTorus(0.1, size + .2, 20, 20); //torus para el anillo
	glPopMatrix();

}

// pintar el planeta
void Planet::draw() {
	glPushMatrix();
		material->createMaterial();
		glRotatef((GLfloat)year, 0.0, 1.0, 0.0);
		glTranslatef(distance, 0.0, 0.0);
		glRotatef((GLfloat)day, 0.0, 1.0, 0.0);
		glutSolidSphere(size, 100, 20);

		if (rings){
			insertRings(eje);
		}

		for (int i = 0; i < moons->size(); ++i) {
			moons->at(i)->draw();
		} //lunas

	glPopMatrix();
}

// lunas
void Planet::pushMoon(Planet * m) {
	moons->push_back(m);
}

Planet::~Planet() {
	int n = moons->size();

	for (int i = n; i > 0; --i) {
		delete moons->at(i);
	}

	delete moons;
	delete material;
}
