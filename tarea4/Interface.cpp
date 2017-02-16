#include "Interface.h"


Interface::Interface() {
	planets = new vector<Planet *>;
}

// magia de OpenGL
void Interface::init(void) {

	GLfloat mat_specular[] = { 1.0, 0.0, 0.0, 1.0 };
	GLfloat mat_shininess[] = { 100.0 };
	GLfloat light_position[] = { -1.0, -1.0, 1.0, 0.0 };


	GLfloat ambiental_colors[] = {0.5, 0.5, 0.0}; // y D"os dijo que se haga la luz
	GLfloat specular_colors[] = {1.0, 1.0, 1.0, 0.0}; // y mas luz (specular esta vez)

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH); // texturas bonitas

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
  // materiales birllositos y bonitos

	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT1, GL_POSITION, light_position);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_DEPTH_TEST);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambiental_colors);
	glLightfv(GL_LIGHT1, GL_SPECULAR, specular_colors);
  // ahora si se hace la luz

	//ver .h para mas info
	createSun();
	createMercury();
	createVenus();
	createEarth();
	createMars();
	createJupiter();
	createSaturn();
	createUranus();
	createNeptune();
}

// crear lso planetas
// que estan en el vector
void Interface::display(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();//push apra cada planeta y sus lunas y/o anillos
		for (int i = 0; i < planets->size(); i++){
			planets->at(i)->draw();
		}
	glPopMatrix();//pop correspondiente

	glutSwapBuffers();
}

// reshape
void Interface::reshape(int w, int h) {

	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 40.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	// camara pos
	glRotatef(-15, -1, 0, 0);
	glTranslatef(0.0, -5.0, -18.0);
}

//simulation
void Interface::simulation() {
	for (int i = 0; i < planets->size(); i++) {
		planets->at(i)->simulation();
	}
}

// sun
void Interface::createSun() {
	Material *sunMaterial = new Material(1, .333, .0, 1.0);
	Planet *sun = new Planet(0.0, 2.0, 0.0, 7.0, sunMaterial);
	planets->push_back(sun);
}

//mercury
void Interface::createMercury() {
	Material *mercuryMaterial = new Material(.3, .3, .3, 0.0);
	Planet *mercury = new Planet(2.16666, (0.02440 * 2), 1.724, .1083, mercuryMaterial);
	planets->push_back(mercury);
}

// venus
void Interface::createVenus() {
	Material *venusMaterial = new Material(.25, 0.15, 0.0, 0.0);
	Planet *venus = new Planet(2.4333, (0.06052 * 2), 1.261, .652, venusMaterial);
	planets->push_back(venus);
}

// home
void Interface::createEarth() {
	Material *earthMaterial = new Material(0.2, 0.2, 0.9, 0.0);
	Planet *earth = new Planet(2.7, (0.06371 * 2), 1.072, 1.674, earthMaterial);
	Material *moonMaterial = new Material(.5, .5, .5, 0.0);
	Planet *moon = new Planet((0.06371 * 2) + 0.12, (0.01737 * 3), 0.2, 0.3, moonMaterial);
	earth->pushMoon(moon); // luna 1
	planets->push_back(earth);
}

// mars
void Interface::createMars() {
	Material *marsMaterial = new Material(0.9, 0.1, 0.1, 0.0);
	Planet *mars = new Planet(2.9566, (0.03390 * 2), 0.8686, .866, marsMaterial);
	planets->push_back(mars);
}

// jupiter
void Interface::createJupiter() {
	Material *jupiterMaterial = new Material(0.9, 0.3, 0.1, 0.0);
	Planet *jupiter = new Planet(4.595, 0.69911, 0.47016, 4.5583, jupiterMaterial);
	Material *ganymedeMaterial = new Material(.5, .5, .5, 0.0);
	Planet *ganymede = new Planet(0.7, (0.02440 * 4), 0.108, .2, ganymedeMaterial);
	Material *callistoMaterial = new Material(.5, .5, .5, 0.0);
	Planet *callisto = new Planet(1.2, (0.02440 * 2), 0.8, .2, callistoMaterial);
	jupiter->pushMoon(ganymede); // luna 2
	jupiter->pushMoon(callisto); // luna 3
	planets->push_back(jupiter);
}

// saturn
void Interface::createSaturn() {
	Material *saturnMaterial = new Material(0.7, 0.2, 0.05, 0.0);
	Planet *saturn = new Planet(7.01, 0.58232, 0.34705, 3.684, saturnMaterial);
	saturn->insertRings(true);
	Material *titanMaterial = new Material(.5, .5, .5, 0.0);
	Planet *titan = new Planet(0.8, (0.02440 * 2) * 1.5, .2, 0.05, titanMaterial);
	saturn->pushMoon(titan); // luna 4
	Material *reaMaterial = new Material(.5, .5, .5, 0.0);
	//Esta luna, puede que no se vea mucho por los anillos, est� en el radio interior del anillo
	Planet *rea = new Planet(0.58232 + .04, (0.01737 * 2), .30528, 0.2, reaMaterial);
	saturn->pushMoon(rea); // luna 5
	planets->push_back(saturn);
}

// UrAnus
void Interface::createUranus() {
	Material *uranusMaterial = new Material(0.0, 0.77, 0.83, 0.0);
	Planet *uranus = new Planet(11.59, .25362, .24516, 1.4794, uranusMaterial);
	uranus->insertRings(false);
	Material *titaniaMaterial = new Material(.5, .5, .5, 0.0);
	Planet *titania = new Planet(.25362 + .215840, (.015768 * 2), .13104, .2, titaniaMaterial);
	uranus->pushMoon(titania); // luna 6
	planets->push_back(uranus);

}

// neptune
void Interface::createNeptune() {
	Material *neptuneMaterial = new Material(0.15, 0.15, 0.45, 0.0);
	Planet *neptune = new Planet(16.9933, .2422, .1954, 0.9719, neptuneMaterial);
	neptune->insertRings(true);
	Material *tritonMaterial = new Material(.5, .5, .5, 0.0);
	//Esta luna, puede que no se vea mucho por los anillos, est� en el radio interior del anillo
	Planet *triton = new Planet(.2422 + 0.12, 0.02440, .15804, .2, tritonMaterial);
	neptune->pushMoon(triton); // luna 7
	planets->push_back(neptune);
}

//pluto
void Interface::createPluto()
{
  
}

Interface::~Interface(){
	int n = planets->size();

	for (int i = n; i > 0; --i) {
		delete planets->at(i);
	}

	delete planets;
}
