#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

GLUquadric* qobj;

void teoria(){
	printf("P1: Ivan Sunderland\n");
	printf("P2: Silicon Graphics\n");
	printf("P3: Fundadores => HP, Intel, Silicon Graphics,Microsoft \nCaracterísticas => Open source, bien documentada, facil de usar, \n");
	printf("P4: El rendering es la creación de los objetos y materiales que se usarán\ninit-> Se inicializan las luces \nreshape-> Crea y configura la cámara \ndisplay -> Pasa los objetos para dibujarlos\n");
	printf("P5.a: Es para ubicar el contenido en cierto punto de la camara\n");
	printf("P5.b: Ingresa las partes del objeto que se esta creando\n");
	printf("P5.c: Carga el display de la escena, sin este no se puede setear la camara\n");
	printf("P5.d: Quita cualquier color que ya haya sido configurado y sobreescribe con los nuevos parametros\n");
	printf("P5.e: Permite que la simulacion sea detenida, hace que los objetos queden pausados\n");
	printf("P5.f: Dibuja los objetos en 2D en la patalla definida\n");
	printf("P6: \n");
	printf("P7: (b) -> (V)\n    (e) -> (I)\n    (a) -> (II)\n    (d) -> (III)\n    (IV) -> (f)\n    (c) -> (VI)\n");
}

void drawL(){
	//_
	glPushMatrix();
		glTranslatef(-5.0, 1.3, 0.0);
		glRotatef(110.0, 110.0, 45.5, 45.5);
		// declaramos las luces del planeta
		GLfloat mat_ambient[] = {0.5, 0.1, 0.0,1.0};
		GLfloat mat_diffuse[] = {0.5, 0.1, 0.0,1.0};
		GLfloat mat_specular[] = {0.5, 0.1, 0.0,1.0};
		GLfloat mat_shiness[] = {122.0};
		// declaramos el material del planeta
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shiness);
		// Dibujamos el planeta
		//glutSolidSphere(radius, 20, 20);
		gluCylinder(qobj, 0.5, 0.5, 2.0, 15, 15);
	glPopMatrix();
	//|
	glPushMatrix();
		glTranslatef(-4.5, 1.0, 0.0);
		glRotatef(195.0, 195.0, 195.0, 195.0);
		// declaramos el material del planeta
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shiness);
		// Dibujamos el planeta
		//glutSolidSphere(radius, 20, 20);
		gluCylinder(qobj, 0.5, 0.5, 2.0, 15, 15);
	glPopMatrix();
}

void drawE(){
	// |
	glPushMatrix();
		glTranslatef(-2.2, 1.8, 0.0);
		glRotatef(110.0, 110.0, 45.5, -180.0);
		// declaramos las luces del planeta
		GLfloat mat_ambient[] = {0.66, 0.66, 0.66,1.0};
		GLfloat mat_diffuse[] = {0.66, 0.66, 0.66,1.0};
		GLfloat mat_specular[] = {0.66, 0.66, 0.66,1.0};
		GLfloat mat_shiness[] = {122.0};
		// declaramos el material del planeta
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shiness);
		// Dibujamos el planeta
		glutSolidCone (0.1, 1.9, 10, 10);
	glPopMatrix();
	// _
	glPushMatrix();
		glTranslatef(-3.2, 0, 0.0);
		glRotatef(110.0, 110.0, 45.5, 45.5);
		// declaramos el material del planeta
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shiness);
		// Dibujamos el planeta
		glutSolidCone (0.1, 1.8, 10, 10);
	glPopMatrix();
	// -
	glPushMatrix();
		glTranslatef(-2.8, 0.9, 0.0);
		glRotatef(110.0, 110.0, 45.5, 45.5);
		// declaramos el material del planeta
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shiness);
		// Dibujamos el planeta
		glutSolidCone (0.1, 1.5, 10, 10);
	glPopMatrix();
	//palo arriba
	glPushMatrix();
		glTranslatef(-2.2, 1.8, 0.0);
		glRotatef(110.0, 110.0, 45.5, 45.5);
		// declaramos el material del planeta
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shiness);
		// Dibujamos el planeta
		glutSolidCone (0.1, 1.5, 10, 10);
	glPopMatrix();
}

void drawO(){
	glPushMatrix();
		// Deshabilitar la luz ambiental
		glDisable(GL_LIGHT0);

		// Creamos las luces del sol.
		GLfloat l_ambient[] = { 1.0, 0.4, 0.1, 1.0 };
		GLfloat l_specular[] = { 0.0, 0.0, 0.0, 1.0 };
		GLfloat l_diffuse[] = {0.0, 0.0, 0.0, 1.0};
		GLfloat position[] = {0.0, 1.01, 0.0, 1.0};
		glLightfv(GL_LIGHT1, GL_SPECULAR, l_ambient);
		glLightfv(GL_LIGHT1, GL_DIFFUSE, l_ambient);
		glLightfv(GL_LIGHT1, GL_AMBIENT, l_ambient);
		glLightfv(GL_LIGHT1, GL_POSITION, position);
		glEnable(GL_LIGHT1);

		// Material del sol
		GLfloat color[] = {1.0, 1.0, 1.0, 1.0};
		GLfloat mat_shiness[] = {128.0};
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, color);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, color);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, color);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shiness);

		// Pintamos el sol
		glutSolidTorus(0.275, 0.85, 15, 15);

		// Deshabilitamos la luz del sol y regresamos la luz ambiental
		glDisable(GL_LIGHT1);
		glEnable(GL_LIGHT0);
	glPopMatrix();
}

void drawN(){
	//|
	glPushMatrix();
		glTranslatef(1.8, 0.0, 0.0);
		glRotatef(110.0, 110.0, 45.5, -180.0);
		// declaramos las luces del planeta
		GLfloat mat_ambient[] = {0.0, 0.3, 0.7,1.0};
		GLfloat mat_diffuse[] = {0.0, 0.3, 0.7,1.0};
		GLfloat mat_specular[] = {0.0, 0.3, 0.7,1.0};
		GLfloat mat_shiness[] = {122.0};
		// declaramos el material del planeta
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shiness);
		// Dibujamos el planeta
		glutSolidCone (0.1, 1.9, 10, 10);
	glPopMatrix();
	// 
	glPushMatrix();
		glTranslatef(1.8, 0.0, 0.0);
		glRotatef(80.0, 110.0, 80, 0.0);
		// declaramos el material del planeta
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shiness);
		// Dibujamos el planeta
		glutSolidCone (0.1, 1.9, 10, 10);
	glPopMatrix();
	// |
	glPushMatrix();
		glTranslatef(3.2, -0.8, 0.0);
		glRotatef(110.0, 110.0, 45.5, -180.0);
		// declaramos el material del planeta
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shiness);
		// Dibujamos el planeta
		glutSolidSphere(1, 2, 2);
	glPopMatrix();
}

void display(void)
{
		// Set position and Activate light
		GLfloat l_position[] = {0.0, 0.0, 1.1, 1.0};
		glLightfv(GL_LIGHT0, GL_POSITION, l_position);
		glEnable(GL_LIGHT0);
		glEnable(GL_LIGHTING);
		glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glColor3f (1.0, 1.0, 1.0); // Set color of all objects to white
		glPushMatrix();
			/*Dibujamos */
			drawL();
			drawE();
			drawO();
			drawN();
		glPopMatrix();
		glutSwapBuffers();
		glFlush();
}

void init(void) 
{
		teoria();
		// Configuraciones de la luz
		GLfloat mat_ambient[] = { 0.2, 0.2, 0.0, 1.0 }; // Luz ambiental
		GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 }; // Luz especular blanca
		GLfloat mat_diffuse[] = {1.0, 1.0, 1.0, 1.0}; // Luz difusa blanca
		GLfloat mat_light_ambient[] = {0.0, 0.0, 0.0, 1.0}; // Luz de ambiente negra
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);

		// Set LIGHT0 settings
		glLightfv(GL_LIGHT0, GL_SPECULAR, mat_specular);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffuse);
		glLightfv(GL_LIGHT0, GL_AMBIENT, mat_ambient);
		glLightModelfv(GL_LIGHT_MODEL_AMBIENT, mat_light_ambient);

		glClearColor(0.0, 0.0, 0.0, 0.0);
		glShadeModel (GL_SMOOTH);

		//cilindro
		qobj = gluNewQuadric();
    gluQuadricNormals(qobj, GLU_SMOOTH);
    gluQuadricDrawStyle(qobj, GLU_LINE);
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION); // Modo Proyección
   glLoadIdentity ();
   gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 1000.0); // Configuracion de la perspectiva
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   gluLookAt (0.0, 5, 9, 0.0, 0.0, 1.0, 3.0, 3.0, 0.0); // Configuracion de la camara
}

/* Keys actions */
void keyboard (unsigned char key, int x, int y)
{
   switch (key) {
       case 'z':
        //acercamiento++;
        glutPostRedisplay();
        break;
    case 'Z':
        //acercamiento--;
        glutPostRedisplay();
        break;
    case 'i':
        //movimiento = !movimiento;
        break;
    case 27:
        exit(0); // Escape to exit program
        break;
    default:
         break;
   }
}

int main(int argc, char** argv)
{
		glutInit(&argc, argv);
		glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
		glutInitWindowSize (1000, 800); 
		glutInitWindowPosition (100, 100);
		glutCreateWindow (argv[0]);
		init ();
		glutReshapeFunc(reshape);
		glutDisplayFunc(display); 
		glutKeyboardFunc(keyboard);
		glutMainLoop();
		return 0;
}