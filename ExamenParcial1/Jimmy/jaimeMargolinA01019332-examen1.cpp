#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

// opengl main magic
void display(void);
void reshape(int w, int h);
void simulation();
void createMaterial(float,float,float,float);
void init();
void drawM();
void drawA();
void drawR();
void drawG();
void drawO();
void drawL();
void drawI();
void drawN();
void resp();

int main(int argc, char **argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1000, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("examen 1 parcial");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(simulation);
	glutMainLoop();

	return 0;
}

void resp()
{
  cout << "1 - ivan sutheland: tableta con pluma, algoritmo traslacion, sillicon graphics"<< endl;
  cout << "2 - , sillicon graphics hizo open gl" << endl;
  cout << "3 - miembros: intel, HP, intel, IBM. chars: escalable, confiable, portable, facil de usar y multiplataforma" << endl;
  cout << "4 - proceso por el que se pasan los objetos hacia la imagen, vertices -> iluminacion -> rasterizacion" << endl;
  cout << "5 - a) \n b) agrega una matrix al stack sobre la cual se aplicaran los nuevos cambios \n c) carga matriz identidad \n d) para cargar el nuevo color para lso objetos a crear \n e) funcion 'default' que se ejecuta en background \n f) royeccion ortogonal de la camara en 2d (es como un rectangulo)" << endl;
  cout << "6 - una gira la camra con un angulo, una usa la proporcion de w/h , como se calcula que esta mas cerca y lejos de la camra" << endl;
  cout << "7 - a - ; b - 5; c - " << endl;
}
void createMaterial(float r=0, float g=0, float b=0, float s=0) {

	GLfloat colors[] = {r, g, b, 1.0}; // no queremos que sea transparente
	GLfloat shiness_r[] = { s };

	glMaterialfv(GL_FRONT, GL_AMBIENT, colors);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, colors);
	glMaterialfv(GL_FRONT, GL_SPECULAR, colors);
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness_r);
	glMaterialfv(GL_FRONT, GL_EMISSION, colors);
}

void init(){

  resp();

  GLfloat mat_specular[] = { 1.0, 0.0, 0.0, 1.0 };
	GLfloat mat_shininess[] = { 100.0 };
	GLfloat light_position[] = { -1.0, -1.0, 1.0, 0.0 };


	GLfloat ambiental_colors[] = {0.5, 0.5, 0.0}; // y D"os dijo que se haga la luz
	//GLfloat specular_colors[] = {1.0, 1.0, 1.0, 0.0}; // y mas luz (specular esta vez)

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
//	glLightfv(GL_LIGHT1, GL_SPECULAR, specular_colors);
}

void drawM(){
  glPushMatrix();

    createMaterial(0.0,1.0,0.0,0.0);
    glPushMatrix();
      glRotatef(-90,1,0,0);
      glTranslatef(-15,0,0);
      glutSolidCone(1,4,15,15);
    glPopMatrix();

    glPushMatrix();

      glTranslatef(-13,2,0);
        glPushMatrix();
          glRotatef(-90,0,1,0);
          glRotatef(-45,1,0,0);
          glutSolidCone(0.5,3,15,15);
        glPopMatrix();
      glPopMatrix();

      glPushMatrix();
        glTranslatef(-13,2,0);
        glPushMatrix();
          glRotatef(-90,0,1,0);
          glRotatef(230,1,0,0);
          glutSolidCone(0.5,3,15,15);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glRotatef(-90,1,0,0);
    glTranslatef(-11.1,-0.1,0);
    glutSolidCone(1,4,15,15);
    glPopMatrix();

  glPopMatrix();
}

void drawA(){
  glPushMatrix();
    createMaterial(0.0,0.0,1.0,0.0);

    glTranslatef(-7.8,3,-2);

    glPushMatrix();
      glutSolidTorus(0.5,1.4,15,15);
      glPushMatrix();
        glTranslatef(1.8,-3.3,0);
        glRotatef(-90,1,0,0);
        glutSolidCone(1,3,15,15);
      glPopMatrix();
      glPushMatrix();
      glTranslatef(-1.8,-3.3,0);
      glRotatef(-90,1,0,0);
      glutSolidCone(1,3,15,15);
      glPopMatrix();
    glPopMatrix();
  glPopMatrix();
}

void drawR(){
  glPushMatrix();
    createMaterial(1.0,0.0,0.0,0.0);
    glTranslatef(-1.7,3,-4);
    glPushMatrix();
      glutSolidTorus(0.5,1.4,15,15);
      glPushMatrix();
        glTranslatef(1.4,-3.9,0);
        glRotatef(-90,1,0,0);
        glRotatef(-45,0,1,0);
        glutSolidCone(1,4,15,15);
      glPopMatrix();
      glPushMatrix();
      glTranslatef(-1.8,-3.3,0);
      glRotatef(-90,1,0,0);
      glutSolidCone(1,3,15,15);
      glPopMatrix();
    glPopMatrix();

  glPopMatrix();
}

void drawG(){
  glPushMatrix();
    createMaterial(0.4,0.6,0.3,0.0);
    glTranslatef(2,-1,-4);
    glPushMatrix();
      glTranslatef(0,5,0);
      glutSolidCube(0.7);
      glTranslatef(0,-.7,0);
      glutSolidCube(0.7);
      glTranslatef(0,-.7,0);
      glutSolidCube(0.7);
      glTranslatef(0,-.7,0);
      glutSolidCube(0.7);
      glTranslatef(0,-.7,0);
      glutSolidCube(0.7);
      glTranslatef(0,-.7,0);
      glutSolidCube(0.7);
      glTranslatef(0,-.7,0);
      glutSolidCube(0.7);
      glTranslatef(0,-.7,0);
      glutSolidCube(0.7);
      glTranslatef(0.7,0,0);
      glutSolidCube(0.7);
      glTranslatef(0.7,0,0);
      glutSolidCube(0.7);
      glTranslatef(0.7,0,0);
      glutSolidCube(0.7);
      glTranslatef(0.7,0,0);
      glutSolidCube(0.7);
      glTranslatef(0.0,0.7,0);
      glutSolidCube(0.7);
      glTranslatef(0.0,0.7,0);
      glutSolidCube(0.7);
      glTranslatef(0.0,0.7,0);
      glutSolidCube(0.7);
      glTranslatef(-0.7,0,0);
      glutSolidCube(0.7);
    glPopMatrix();

  glPopMatrix();
}

void drawO(){
  glPushMatrix();
    createMaterial(0.7,0.0,0.3,0.0);
    glTranslatef(9,2,-4);
    glutSolidTorus(1,2,15,15);
  glPopMatrix();
}

void drawL()
{
  glPushMatrix();
    createMaterial(0.4,0.7,0.0,0.0);
    glTranslatef(13,-1,-4);
    glPushMatrix();
      glTranslatef(0,5,0);
      glutSolidCube(0.7);
      glTranslatef(0,-.7,0);
      glutSolidCube(0.7);
      glTranslatef(0,-.7,0);
      glutSolidCube(0.7);
      glTranslatef(0,-.7,0);
      glutSolidCube(0.7);
      glTranslatef(0,-.7,0);
      glutSolidCube(0.7);
      glTranslatef(0,-.7,0);
      glutSolidCube(0.7);
      glTranslatef(0,-.7,0);
      glutSolidCube(0.7);
      glTranslatef(0,-.7,0);
      glutSolidCube(0.7);
      glTranslatef(0.7,0,0);
      glutSolidCube(0.7);
      glTranslatef(0.7,0,0);
      glutSolidCube(0.7);
      glTranslatef(0.7,0,0);
      glutSolidCube(0.7);
      glTranslatef(0.7,0,0);
      glutSolidCube(0.7);
    glPopMatrix();

  glPopMatrix();
}

void drawI()
{
  glPushMatrix();
    createMaterial(0.3,1.0,0.2,0.0);
    glTranslatef(17,-1,-4);
    glPushMatrix();
      glTranslatef(0,5,0);
      glutSolidCube(0.7);
      glTranslatef(0,-.7,0);
      glutSolidCube(0.7);
      glTranslatef(0,-.7,0);
      glutSolidCube(0.7);
      glTranslatef(0,-.7,0);
      glutSolidCube(0.7);
      glTranslatef(0,-.7,0);
      glutSolidCube(0.7);
      glTranslatef(0,-.7,0);
      glutSolidCube(0.7);
      glTranslatef(0,-.7,0);
      glutSolidCube(0.7);
      glTranslatef(0,-.7,0);
      glutSolidCube(0.7);
    glPopMatrix();

  glPopMatrix();
}

void drawN()
{
  glPushMatrix();
    createMaterial(0.3,0.2,1.0,0.0);
    glTranslatef(19,-1,-4);
    glPushMatrix();
      glTranslatef(0,5,0);
      glutSolidCube(0.7);
      glTranslatef(0,-.7,0);
      glutSolidCube(0.7);
      glTranslatef(0,-.7,0);
      glutSolidCube(0.7);
      glTranslatef(0,-.7,0);
      glutSolidCube(0.7);
      glTranslatef(0,-.7,0);
      glutSolidCube(0.7);
      glTranslatef(0,-.7,0);
      glutSolidCube(0.7);
      glTranslatef(0,-.7,0);
      glutSolidCube(0.7);
      glTranslatef(0,-.7,0);
      glutSolidCube(0.7);
      glTranslatef(0.7,0.7,0);
      glutSolidCube(0.7);
      glTranslatef(0.7,0.7,0);
      glutSolidCube(0.7);
      glTranslatef(0.7,0.7,0);
      glutSolidCube(0.7);
      glTranslatef(0.7,0.7,0);
      glutSolidCube(0.7);
      glTranslatef(0.7,0.7,0);
      glutSolidCube(0.7);
      glutSolidCube(0.7);
      glTranslatef(0,-.7,0);
      glutSolidCube(0.7);
      glTranslatef(0,-.7,0);
      glutSolidCube(0.7);
      glTranslatef(0,-.7,0);
      glutSolidCube(0.7);
      glTranslatef(0,-.7,0);
      glutSolidCube(0.7);
      glTranslatef(0,-.7,0);
      glutSolidCube(0.7);

    glPopMatrix();

  glPopMatrix();
}

void display(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();//push apra cada planeta y sus lunas y/o anillos
  glTranslatef(-0.3,0,0);
  drawM();
  drawA();
  drawR();
  drawG();
  drawO();
  drawL();
  drawI();
  drawN();
	glPopMatrix();//pop correspondiente

	glutSwapBuffers();
}

void reshape(int w, int h) {

	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 40.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 5.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0);
	// camara pos
	glRotatef(-15, -1, 0, 0);
	glTranslatef(0.0, -5.0, -15.0);
}

void simulation() {

}
//glutPostRedisplay();
