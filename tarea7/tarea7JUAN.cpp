/* Este código es formato de c++11 asi que se debe de compilar con la bandera --std=c++11 */
/* Se quito el dibujado de los puntos porque se veian feos en la pantalla */
#include <stdlib.h>
#include <GL/glut.h>
#include <random>
#include <cstdlib>
#include <iostream>

//porque que flojera estar escribiendo std::
using namespace std;

// definicion de los puntos que se utilizarán en cada letra
// puntos para la j
GLfloat jpts[4][3] = {
	{2,4,0},{3,-10,0},{0,0,0},{3,3,0}
    };
//puntos para la a
GLfloat apts[7][3] = {
	{ 2.0, 1.0, 0.0}, { 2.0, 3.0, 0.0}, 
	{-4.8, 3.0, 0.0}, {-4.8, -4.0, 0.0},
    {2.0, -4.0, 0.0}, {2.0, 8.0, 0.0}, {3.0, -2.0, 0.0}};
// puntos para los arcos de u y n
GLfloat arcopts[5][3] = {
	{0,0,0},{0,2,0},{2,4,0},{4,2,0},{4,0,0}
    };
// puntos para el palito de la n
GLfloat arquinpts[5][3] = {
	{0.0,1.5,0},{0,2,0},{2,4,0},{4,2,0},{4,0,0}
    };
//puntos para la e
GLfloat epts[6][3] = {
	{0,0,0},{5,0,0},{3.5,9,0},{0.5,5,0},{0.5,-4,0},{5,0,0}
    };
// puntos para la o
GLfloat opts[7][3] = {
	{0,0,0},{-1.5,0.0,0.0},{-1.5,-3,0},{0,-5,0},{3,-3,0},{1.5,0.0,0.0},{0,0,0}
    };
// puntos para el palito de la o
GLfloat cejitapts[2][3] = {
	{0,0,0},{2,0,0}
    };
// puntos para la l
GLfloat lpts[6][3] = {
	{0,0,0},{5,0,0},{3.5,18,0},{0.5,5,0},{0.5,-4,0},{5,0,0}
    };

// funciones que dibujan los nombres
void dibujaJUAN();
void dibujaLEON();

// funciones que dibujan las letras
void dibujaJ();
void dibujaarco();
void dibujaarquin();
void dibujaA();
void dibujaN();
void dibujaL();
void dibujaE();
void dibujaO();

// funcion para generar los colores aleatorios en cada corrida,
// es estandar c++11, por lo tanto se debe correr con el flag:
// --std=c++11
void zain()
{
    std::random_device rd; std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1);
    glColor3f(dis(gen), dis(gen), dis(gen));
}

// inicializacion
void init(void)
{
   glClearColor(0.0, 0.0, 0.0, 0.0);
   glShadeModel(GL_FLAT);
   glEnable(GL_MAP1_VERTEX_3);
}

//funcion que dibuja juan
void dibujaJUAN()
{
    glPushMatrix();
        glTranslatef(-10.0, 2.5, 0.0);
        dibujaJ();
        glTranslatef(1.8, 0.0, 0.0);
        glPushMatrix();
            glScalef(1.0,-1.0,1.0);
            dibujaarco();
        glPopMatrix();
        glTranslatef(3.0, -0.5, 0.0);
        glPushMatrix();
            glScalef(0.7, 0.7, 0.7);
            dibujaA();
        glTranslatef(1.5, -0.5, 0.0);
        dibujaN();
    glPopMatrix();
}

//funcion que dibuja leon
void dibujaLEON(){
    glPushMatrix();
        dibujaL();
        glTranslatef(2.2,0.0,0);
        dibujaE();
        glTranslatef(3.2,1.0,0);
        dibujaO();
        glTranslatef(0.71,-1.2,0);
        dibujaN();
    glPopMatrix();
}

// dibuja la J
void dibujaJ()
{
  int i;
  glPushMatrix();
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &jpts[0][0]);
    zain();
    glScalef(0.5, 0.5, 0.5);
     glBegin(GL_LINE_STRIP);
      for (i = 0; i <= 28; i++) 
         glEvalCoord1f((GLfloat) i/28.0);
     glEnd();
  glPopMatrix();
}

// dibuja la a de moy
void dibujaA()
{
  int i;
  glPushMatrix();
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 7, &apts[0][0]);
    zain();
    glScalef(0.5, 0.5, 0.5);
     glBegin(GL_LINE_STRIP);
      for (i = 0; i <= 28; i++) 
         glEvalCoord1f((GLfloat) i/28.0);
     glEnd();
  glPopMatrix();
}

// dibuja un arco para la n y para la u
void dibujaarco()
{
  int i;
  glPushMatrix();
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 5, &arcopts[0][0]);
    zain();
    glScalef(0.5, 0.5, 0.5);
     glBegin(GL_LINE_STRIP);
      for (i = 0; i <= 28; i++) 
         glEvalCoord1f((GLfloat) i/28.0);
     glEnd();
  glPopMatrix();
}

// dibuja el palito de la n
void dibujaarquin()
{
  int i;
  glPushMatrix();
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 5, &arquinpts[0][0]);
    zain();
    glScalef(0.5, 0.5, 0.5);
     glBegin(GL_LINE_STRIP);
      for (i = 0; i <= 28; i++) 
         glEvalCoord1f((GLfloat) i/28.0);
     glEnd();
  glPopMatrix();
}

//funcion que dibuja la e
void dibujaE()
{
  int i;
  glPushMatrix();
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 6, &epts[0][0]);
    zain();
    glScalef(0.5, 0.5, 0.5);
     glBegin(GL_LINE_STRIP);
      for (i = 0; i <= 28; i++) 
         glEvalCoord1f((GLfloat) i/28.0);
     glEnd();
  glPopMatrix();
}

//funcion que dibuja la o
void dibujaO()
{
  int i;
  glPushMatrix();
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 7, &opts[0][0]);
    zain();
    glScalef(0.5, 0.5, 0.5);
     glBegin(GL_LINE_STRIP);
      for (i = 0; i <= 28; i++) 
         glEvalCoord1f((GLfloat) i/28.0);
     glEnd();
     glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 2, &cejitapts[0][0]);
    glScalef(0.5, 0.5, 0.5);
     glBegin(GL_LINE_STRIP);
      for (i = 0; i <= 28; i++) 
         glEvalCoord1f((GLfloat) i/28.0);
     glEnd();
  glPopMatrix();
}

//funcion que dibuja la l
void dibujaL()
{
  int i;
  glPushMatrix();
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 6, &lpts[0][0]);
    zain();
    glScalef(0.5, 0.5, 0.5);
     glBegin(GL_LINE_STRIP);
      for (i = 0; i <= 28; i++) 
         glEvalCoord1f((GLfloat) i/28.0);
     glEnd();
  glPopMatrix();
}

//dibuja la n
void dibujaN()
{
    glPushMatrix();
        glScalef(0.5,1,1);
        glPushMatrix();
            dibujaarquin();
            glTranslatef(2,0,0);
            dibujaarco();
        glPopMatrix();
    glPopMatrix();
}

//funcion que hace el render de la app
void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(1.0, 1.0, 1.0);
   dibujaJUAN();
   glTranslatef(-4.8,-5,0);
   dibujaLEON();
   glFlush();
}

// otra funcion más de las de siempre
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

// funcion que renderea la pantalla y todo eso
int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (1500, 700);
   glutInitWindowPosition (00, 00);
   glutCreateWindow (argv[0]);
   init();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc (keyboard);
   glutMainLoop();
   return 0;
}
