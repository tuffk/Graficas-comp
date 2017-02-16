#include <GL/glut.h>
#include <stdlib.h>

static int anioMer, anioVen, anioTie, anioMar, anioJup, anioSat, anioUra, anioNep = 0;
static int diaMer, diaVen, diaTie, diaMar, diaJup, diaSat, diaUra, diaNep = 0;
static char movimiento = 0;
static int acercamiento = 0;
static int moon = 0;

void dibujaSol(){
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
		glutSolidSphere(1, 20, 50);

		// Deshabilitamos la luz del sol y regresamos la luz ambiental
		glDisable(GL_LIGHT1);
		glEnable(GL_LIGHT0);
	glPopMatrix();
}

void dibujaAnillo(float ang, float ri, float re, float alt, float r, float g, float b){
	glPushMatrix();
		glRotatef(ang, 1.0, 0.0, 0.0);
		GLfloat mat_ambient[] = {r, g, b, 1.0};
		GLfloat mat_diffuse[] = {r, g, b, 1.0};
		GLfloat mat_specular[] = {0.0, 0.0, 0.0, 1.0};
		GLfloat mat_shiness[] = {128.0};
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shiness);
		glScalef(1.0, 1.0, alt);
		glutSolidTorus(ri, re, 15, 15);
	glPopMatrix();
}

void dibujaPlaneta(float x, float y, float z, float radius, float r, float g, float b, float angulo, int anillo, int moons){
	glPushMatrix();
		glTranslatef(x, y, z);
		glRotatef(angulo, 0.0, 1.0, 0.0);
		// declaramos las luces del planeta
		GLfloat mat_ambient[] = {r,g,b,1.0};
		GLfloat mat_diffuse[] = {r,g,b,1.0};
		GLfloat mat_specular[] = {r,g,b,1.0};
		GLfloat mat_shiness[] = {122.0};
		// declaramos el material del planeta
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shiness);
		// Dibujamos el planeta
		glutSolidSphere(radius, 20, 20);
		if(anillo == 1)
			dibujaAnillo(90.0, 0.09, 0.48, 0.01, 0.6, 0.5, 0.5);
		else if(anillo == 2) //si son normales o si son verticales
			dibujaAnillo(10.0, 0.09, 0.37, 0.005, 0.01, 0.01, 0.02);
		
		if(moons == 1)
			dibujaPlaneta(0.1, 0.1, 0.0, 0.03, 0.3, 0.3, 0.3, 10, 0, 0);
		else if(moons == 2)
		{
			for(int i = 0; i < moons; i++)
			{
				glRotatef(moon, 0.0, 1.0, 0.0);
				dibujaPlaneta(0.1, 0.1, 0.0, 0.03, 0.3, 0.3, 0.3, 10, 0, 0);
			}
		}
	glPopMatrix();
}

void muestraPlaneta(float x, float y, float z, float radius, float r, float g, float b, float anio, float dia, int anillo, int moons){
	glPushMatrix();
		// Rotación alrededor del sol
		glRotatef(anio, 0.0, 1.0, 0.0);
		// Dibujamos el planeta
		dibujaPlaneta(x, y, z, radius, r, g, b, dia, anillo, moons);
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
			dibujaSol(); // Draw sun
			/*Dibujamos los planetas*/
			muestraPlaneta(1.15, 0.0, 0.0, 0.05, 0.66, 0.66, 0.66, anioMer, diaMer, 0, 0); // Mercurio
			muestraPlaneta(1.4, 0.0, 0.0, 0.1, 0.5, 0.1, 0.0, anioVen, diaVen, 0, 0); // Venus
			muestraPlaneta(1.62, 0.0, 0.0, 0.1, 0.0, 0.9, 0.1, anioTie, diaTie, 0, 1); // Tierra
			muestraPlaneta(1.8, 0.0, 0.0, 0.04, 0.8, 0.3, 0.3, anioMar, diaMar, 0, 1); // Marte
			muestraPlaneta(2.7, 0.0, 0.0, 0.4, 0.5, 0.2, 0.0, anioJup, diaJup, 0, 2); // Júpiter
			muestraPlaneta(4.0, 0.0, 0.0, 0.3, 0.5, 0.4, 0.4, anioSat, diaSat, 1, 1); // Saturno
			muestraPlaneta(6.0, 0.0, 0.0, 0.27, 0.0, 0.0, 0.6, anioUra, diaUra, 2, 1); // Urano, este es el del anillo raro
			muestraPlaneta(8.0, 0.0, 0.0, 0.27, 0.0, 0.3, 0.7, anioNep, diaNep, 1, 1); // Neptuno
		glPopMatrix();
		glutSwapBuffers();
		glFlush();
}

void init(void) 
{
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
}

static int count = 0;
// Hace la simulación del movimiento de los planetas
void simulacion(){
    int x = 15;
    if(!movimiento)
        return;
    if(count != 1050000){ // Asignamos una velocidad
        count = count+1;
        return;
    }
		/* Sacamos las rotaciones de los planetas con respecto a la tierra */
    count = 0;
		anioMer = (anioMer+(x*40))%360;
		anioVen = (anioVen+(x*20))%360;
		anioTie = (anioTie+(x*10))%360;
    anioMar = (anioMar+(10*x/2))%360;
    anioJup = (anioJup+ (x/1))%360;
    anioSat = (anioSat+ (x/3))%360;
    anioUra = (anioUra + (x/8))%360;
    anioNep = (anioNep + (x/15))%360;
		moon = (moon + (x*10))%360; // Se moverá a la velocidad de la tierra
    glutPostRedisplay();
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
        acercamiento++;
        glutPostRedisplay();
        break;
    case 'Z':
        acercamiento--;
        glutPostRedisplay();
        break;
    case 'i':
        movimiento = !movimiento;
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
		glutIdleFunc(simulacion);
		glutKeyboardFunc(keyboard);
		glutMainLoop();
		return 0;
}