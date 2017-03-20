#include <stdlib.h>
#include <GL/glut.h>

GLfloat ctrlpoints[6][3] = {
	{ -3.0, -4.0, 0.0}, { 4.0, -3.0, 0.0}, 
	{4.0, 0.0, 0.0}, {-4.0, 0.0, 0.0},
        {-4.0, 3.0, 0.0}, {3.0, 4.0, 0.0}};
GLfloat ctrlpoints2[7][3] = {
	{ 2.0, 1.0, 0.0}, { 2.0, 3.0, 0.0}, 
	{-4.8, 3.0, 0.0}, {-4.8, -4.0, 0.0},
        {2.0, -4.0, 0.0}, {2.0, 8.0, 0.0}, {3.0, -2.0, 0.0}};

void init(void)
{
   glClearColor(0.0, 0.0, 0.0, 0.0);
   glShadeModel(GL_FLAT);
   glEnable(GL_MAP1_VERTEX_3);
}

void pintaS()
{
  int i;
  glPushMatrix();
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 6, &ctrlpoints[0][0]);
    glTranslatef(-3.0, 0.0, 0.0);
    glScalef(0.5, 0.5, 0.5);
     glBegin(GL_LINE_STRIP);
      for (i = 0; i <= 28; i++) 
         glEvalCoord1f((GLfloat) i/28.0);
     glEnd();
   /* The following code displays the control points as dots. */
     glPointSize(5.0);
     glColor3f(1.0, 1.0, 0.0);
     glBegin(GL_POINTS);
      for (i = 0; i < 6; i++) 
         glVertex3fv(&ctrlpoints[i][0]);
     glEnd();
  glPopMatrix();
}

void pintaA()
{
  int i;
  glPushMatrix();
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 7, &ctrlpoints2[0][0]);
    glTranslatef(2.0, 0.0, 0.0);
    glScalef(0.5, 0.5, 0.5);
     glBegin(GL_LINE_STRIP);
      for (i = 0; i <= 28; i++) 
         glEvalCoord1f((GLfloat) i/28.0);
     glEnd();
   /* The following code displays the control points as dots. */
     glPointSize(5.0);
     glColor3f(1.0, 1.0, 0.0);
     glBegin(GL_POINTS);
      for (i = 0; i < 7; i++) 
         glVertex3fv(&ctrlpoints2[i][0]);
     glEnd();
  glPopMatrix();
}

void display(void)
{

   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(1.0, 1.0, 1.0);
   pintaS();
   pintaA();
   glFlush();
}

void reshape(int w, int h)
{
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   if (w <= h)
      glOrtho(-5.0, 5.0, -5.0*(GLfloat)h/(GLfloat)w, 
               5.0*(GLfloat)h/(GLfloat)w, -5.0, 5.0);
   else
      glOrtho(-5.0*(GLfloat)w/(GLfloat)h, 
               5.0*(GLfloat)w/(GLfloat)h, -5.0, 5.0, -5.0, 5.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

/* ARGSUSED1 */
void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
      case 27:
         exit(0);
         break;
   }
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (500, 500);
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc (keyboard);
   glutMainLoop();
   return 0;
}
