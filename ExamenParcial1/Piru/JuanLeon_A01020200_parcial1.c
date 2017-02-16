#include <GL/glut.h>
#include <stdlib.h>

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
			/*Dibujamos */
			
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
    c
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