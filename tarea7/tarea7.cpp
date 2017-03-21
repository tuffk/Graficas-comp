#include <stdlib.h>
#include <GL/glut.h>

GLfloat jpts[4][3] = {
	{2,4,0},{3,-10,0},{0,0,0},{3,3,0}
    };
GLfloat apts[7][3] = {
	{ 2.0, 1.0, 0.0}, { 2.0, 3.0, 0.0}, 
	{-4.8, 3.0, 0.0}, {-4.8, -4.0, 0.0},
        {2.0, -4.0, 0.0}, {2.0, 8.0, 0.0}, {3.0, -2.0, 0.0}};
GLfloat ipts[5][3] = {
	{0,0,0},{5,0,0},{2.5,9,0},{3.5,-4,0},{5,0,0}
    };
GLfloat arcopts[5][3] = {
	{0,0,0},{0,2,0},{2,4,0},{4,2,0},{4,0,0}
    };

void drawJAIME();
void drawJUAN();
void pintaJ();
void pintaA();
void pintaI();
void pintaM();
void pintaarco();


// GLmagick
void init(void)
{
   glClearColor(0.0, 0.0, 0.0, 0.0);
   glShadeModel(GL_FLAT);
   glEnable(GL_MAP1_VERTEX_3);
}

void drawJAIME()
{
    //pintaJ();
    //pintaA();
    //pintaI();
    pintaM();
}

// J
void pintaJ()
{
  int i;
  glPushMatrix();
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &jpts[0][0]);
    glColor3f(0.0, 1.0, 0.0);
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
         glVertex3fv(&jpts[i][0]);
     glEnd();
  glPopMatrix();
}

void pintaA()
{
  int i;
  glPushMatrix();
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 7, &apts[0][0]);
    glColor3f(1.0, 1.0, 0.0);
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
         glVertex3fv(&apts[i][0]);
     glEnd();
  glPopMatrix();
}

void pintaI()
{
  int i;
  glPushMatrix();
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 5, &ipts[0][0]);
    glColor3f(1.0, 0.0, 0.5);
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
         glVertex3fv(&apts[i][0]);
     glEnd();
  glPopMatrix();
}

void pintaarco()
{
  int i;
  glPushMatrix();
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 5, &arcopts[0][0]);
    glColor3f(0.3, 0.0, 0.7);
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
         glVertex3fv(&jpts[i][0]);
     glEnd();
  glPopMatrix();
}

void pintaM()
{
    glPushMatrix();
        glScalef(0.5,1,1);
        glPushMatrix();
            pintaarco();
            glTranslatef(2,0,0);
            pintaarco();
            glTranslatef(2,0,0);
            pintaarco();
        glPopMatrix();
    glPopMatrix();
    
}

void display(void)
{

   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(1.0, 1.0, 1.0);
   drawJAIME();
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
   glutInitWindowSize (1000, 500);
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc (keyboard);
   glutMainLoop();
   return 0;
}
