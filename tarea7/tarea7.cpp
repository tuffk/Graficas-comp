#include <stdlib.h>
#include <GL/glut.h>
#include <random>
#include <cstdlib>
#include <iostream>
using namespace std;

// arreglos de puntos para las letras y helpers
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
GLfloat epts[6][3] = {
	{0,0,0},{5,0,0},{3.5,9,0},{0.5,5,0},{0.5,-4,0},{5,0,0}
    };

// funciones de las letras y helpers
void drawJAIME();
void drawMARGOLIN();
void pintaJ();
void pintaA();
void pintaI();
void pintaM();
void pintaarco();
void pintaE();


//random colors
void getColor()
{
    std::random_device rd; std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1);
    glColor3f(dis(gen), dis(gen), dis(gen));
}

// GLmagick
void init(void)
{
   glClearColor(0.0, 0.0, 0.0, 0.0);
   glShadeModel(GL_FLAT);
   glEnable(GL_MAP1_VERTEX_3);
}

void drawJAIME()
{
    glPushMatrix();
        glTranslatef(-10.0, 2.5, 0.0);
        pintaJ();
        glTranslatef(2.2, 0.0, 0.0);
        pintaA();
        glTranslatef(1.9, -0.5, 0.0);
        pintaI();
        glTranslatef(2.5, 0.0, 0.0);
        pintaM();
        glTranslatef(3.0, 0.0, 0.0);
        pintaE();
    glPopMatrix();
}

void drawMARGOLIN(){
    glPushMatrix();
        pintaM();
        glTranslatef(4,0.5,0);
        glPushMatrix();
            glScalef(0.7,0.7,0.7);
            pintaA();
        glPopMatrix();
    glPopMatrix();
}

// J
void pintaJ()
{
  int i;
  glPushMatrix();
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &jpts[0][0]);
    getColor();
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
    getColor();
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
    getColor();
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
    getColor();
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

void pintaE()
{
  int i;
  glPushMatrix();
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 6, &epts[0][0]);
    getColor();
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

void display(void)
{

   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(1.0, 1.0, 1.0);
   drawJAIME();
   glTranslatef(-9.5,-2,0);
   drawMARGOLIN();
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
   glutInitWindowSize (1500, 700);
   glutInitWindowPosition (00, 00);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc (keyboard);
   glutMainLoop();
   return 0;
}
