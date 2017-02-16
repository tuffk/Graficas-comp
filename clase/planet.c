#include <GL/glut.h>
#include <stdlib.h>

static int year = 0, day = 0, luna =0;
int cont =0;
static int day2 =0;

void init(void)
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_FLAT);
}

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT);
   glColor3f (1.0, 1.0, 1.0);

   // planet 1
   glPushMatrix();
   glutWireSphere(1.0, 20, 16);   /* draw sun */
   glRotatef ((GLfloat) year, 0.0, 1.0, 0.0);
   glTranslatef (2.0, 0.0, 0.0);
   glRotatef ((GLfloat) day, 0.0, 1.0, 0.0);
   glutWireSphere(0.2, 10, 8);    /* draw smaller planet */
   glTranslatef(0.4,0,0);
   glRotatef((GLfloat)luna,0,1.0,0);
   glutWireSphere(0.05,8,8);
   glPopMatrix();
   glutSwapBuffers();
   glPopMatrix();
   //planet 2
   glPushMatrix();
   glRotatef ((GLfloat) year, 0.0, 1.0, 0.0);
    glTranslatef(3.5,0,0);
    glRotatef((GLfloat)day2,0,1,0);
    glutWireSphere(0.2,10,8);
    //anillos
      //glPushMatrix();
      glRotatef(90,1,0,0);
      //glScalef(1,0.3,1);
      glutWireTorus(0.05,0.5,5,10);
      //glPopMatrix();
   glPopMatrix();

   glutSwapBuffers();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 100.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void simulation()
{
  cont++;
  if(cont % 2 == 0){
  year = (year + 2) % 360;
  day = (day + 3) % 360;
  luna = (luna + 1) % 360;
  day2 = (day2 +5) % 360;
  glutPostRedisplay();
  cont = 0;
  }
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
            luna = (luna + 10) % 360;
            glutPostRedisplay();
            break;
         case 'L':
            luna = (luna - 10) % 360;
            glutPostRedisplay();
            break;
      case 'y':
         year = (year + 5) % 360;
         glutPostRedisplay();
         break;
      case 'Y':
         year = (year - 5) % 360;
         glutPostRedisplay();
         break;
      case 'I':
        glutIdleFunc(simulation);
        break;
      case 'i':
        glutIdleFunc(NULL);
        break;
      case 'q':
      case 'Q':
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
   glutInitWindowSize (1000, 1000);
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutIdleFunc(simulation);
   glutMainLoop();
   return 0;
}
