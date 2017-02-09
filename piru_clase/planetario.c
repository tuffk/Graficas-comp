#include <GL/glut.h>
#include <stdlib.h>

static int year = 0, day = 0, luna = 0, day2 = 0, cont = 0;

void init(void) 
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_FLAT);
}

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT);
   glColor3f (1.0, 1.0, 1.0);

   glPushMatrix();
    glutWireSphere(1.0, 20, 16);   /* draw sun */
    glRotatef ((GLfloat) year, 0.0, 1.0, 0.0);
    glPushMatrix();
        glTranslatef (2.0, 0.0, 0.0);
        glRotatef ((GLfloat) day, 0.0, 1.0, 0.0);
        glutWireSphere(0.2, 10, 8);    /* draw smaller planet */
        glTranslatef(0.4,0,0);
        glRotatef((GLfloat)luna, 0,1,0);
        glutWireSphere(0.05, 8,8);      /* draw moon */
    glPopMatrix();

    glPushMatrix();
        glTranslatef(5.5, 0.0, 0.0);
        glRotatef((GLfloat) day2, 0.0, 1.0, 0.0);
        glutWireSphere(0.4, 10, 8); /* Otro planeta */
        glPushMatrix();
            glScalef(1.0, 0.03, 1.0);
            glutWireTorus(0.43, 0.5, 15, 15);
        glPopMatrix();
    glPopMatrix();

   glPopMatrix();
   glutSwapBuffers();
}

void simulacion(){
    cont ++;
  if((cont% 200000) == 0)
  {
    year = (year + 5) % 360;
    day = (day + 2) % 360;
    day2 = (day2 + 3) % 360;
    luna = (luna + 1) % 360;
    glutPostRedisplay();
  }
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 300.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   gluLookAt (0.0, 3.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

/* ARGSUSED1 */
void keyboard (unsigned char key, int x, int y)
{
   switch (key) {
      case 'd':
         day = (day + 10) % 360;
         glutPostRedisplay();
         break;
      case 'D':
         day = (day - 10) % 360;
         glutPostRedisplay();
         break;
      case 'l':
         luna = (luna +5) %360;
         glutPostRedisplay();
         break;
      case 'L':
         luna = (luna -5) %360;
         glutPostRedisplay();
         break;
      case 'y':
         year = (year + 5) % 360;
         glutPostRedisplay();
         break;
      case 'Y':
         year = (year - 2) % 360;
         glutPostRedisplay();
         break;
			case 'i':
         glutIdleFunc(NULL);
				 break;
      case 'I':
         glutIdleFunc(simulacion);
				 break;
      case 27:
         exit(0);
         break;
      default:
         break;
   }
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (1000, 500); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutIdleFunc(simulacion);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}