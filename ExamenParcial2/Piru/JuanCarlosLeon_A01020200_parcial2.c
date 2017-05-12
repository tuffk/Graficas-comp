#include <stdlib.h>
#include <GL/glut.h>
#include <stdio.h>

#define WIN_WIDTH 800
#define WIN_HEIGHT 800

typedef struct _area {
    int id;
    int x, y;
    float min, max;
    float value;
    float step;
} area;

GLfloat eye[3] = { 0.0, 0.0, 60.0 };
GLfloat at[3]  = { 0.0, 0.0, 0.0 };
GLfloat up[3]  = { 0.0, 1.0, 0.0 };

area translation[5] = {
    { 0, 120, 40, -30.0, 30.0, 0.0, 0.05,},
    { 1, 180, 40, -30.0, 30.0, 0.0, 0.05,},
    { 2, 180, 40, -200.0, 200.0, 0.0, 0.1,},
        { 3, 180, 120, -100, 100, 0.0, 0.5},
        { 4, 240, 120, -100, 100, 0.0, 0.5}
};

GLuint old_thetaW3=0;
GLuint old_thetaX4=0;
GLuint old_thetaE5=0;
GLuint old_thetaC6=0;
GLuint old_thetaS11=0;
GLuint old_thetaD12=0;
GLint selection = 0;
int old_y, old_x;
static GLint choise = 2;
static GLint m_choise = 0;

GLfloat panpoints[4][4][3] =
{
    {
        {-1.71, -1.71, 0.0},
        {-1.4, -2.9, 0.0},
        {1.4, -2.9, 0.0},
        {1.71, -1.71, 0.0}},
    {
        {-3, -1.5, 0.0},
        {-1.5, -1.5, 1.8},
        {1.5, -1.5, 1.8},
        {3, -1.5, 0.0}},
    {
        {-3, 1.5, 0.0},
        {-1.5, 1.5, 1.8},
        {1.5, 1.5, 1.8},
        {3, 1.5, 0.0}},
    {
        {-1.71, -1.71, 0.0},
        {-1.4, -2.9, 0.0},
        {1.4, -2.9, 0.0},
        {1.71, -1.71, 0.0}},
};

void teoria(){
	printf("1. header: tiene el formato, el tamaño y la compresion del objeto, \n");
	printf("2. 4:3, 16:9, 5:1 \n");
	printf("3. taslacion: {(1,0,0,0), (0,1,0,0), (0,0,1,0),(0,0,0,z)}, rotacion: {(),(),(),()}\n");
	printf("4. COP: center of proyection, es donde se ve\nDOP: direccion de la proyeccion, hacia donde se ve\npunto de fuga: en donde se mueve\n");
	printf("5. cinematica: da el movimiento a los objetos.\n cinematica directa: se aplica directamente al objeto \ncinematica inversa: se aplica al ambiente y hace parecer que el objeto tiene movimiento");
	printf("6. En el hombro hay 2 grados de libertad (el que gira el hombro hacia atras y el que levanta el hombro), en el brazo hay 3 grados de libertad el que gira el brazo, el que lo dobla y el que permite la elasticidad, en la muñeca hay 5 grados de libertad (movimiento arriba y abajo, giro y a cada uno de los lados.\n");
	printf("7a. \n");
	printf("7b. \n");
	printf("8. Las curvas de bezier se basan en el inicio y fin de la curva, siendo los demas puntos los que jalan, mientras que el los NURBS se jala dependiendo de una matriz que se define.\n");
	printf("9. \n");
	printf("10. AR: es el poder proyectar o incluir al jugador dentro de un mundo.\nVR: es la inmersion del jugador al mundo, sintiendose parte de el\nMR: \nAV: \n");
}

void initlights(void)
{
    GLfloat ambient[] =
    {0.2, 0.2, 0.2, 1.0};
    GLfloat position[] =
    {0.0, 0.0, 6.0, 1.0};
    GLfloat mat_diffuse[] =
    {0.6, 0.6, 0.6, 1.0};
    GLfloat mat_specular[] =
    {1.0, 1.0, 1.0, 1.0};
    GLfloat mat_shininess[] =
    {50.0};

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_POSITION, position);

    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

/*
Pan de arriba
	  glPushMatrix();
    glRotatef(-25.0, 1.0, 0.0, 0.0);
    glRotatef(25.0,-1.0, 0.0, 0.0);
    glRotatef(10.0, 0.0, 1.0, 0.0);
    glRotatef(-10.0, 0.0, 1.0, 0.0);
    glEvalMesh2(GL_FILL, 0, 25, 0, 25);
    glPopMatrix();
*/

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glPushMatrix();
      glRotatef(-25.0, 0.0, 1.0, 0.0);
      glRotatef(25.0,0.0, 1.0, 0.0);
      glRotatef(10.0, 1.0, 0.0, 0.0);
      glRotatef(-10.0, -1.0, 0.0, 0.0);
      glEvalMesh2(GL_FILL, 0, 25, 0, 25);
    glPopMatrix();
    glFlush();
}

void myinit(void)
{
		glClearColor(0.0, 0.0, 0.0, 1.0);
    glEnable(GL_DEPTH_TEST);
    glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4, 0, 1, 12, 4, &panpoints[0][0][0]);
    glEnable(GL_MAP2_VERTEX_3);
    glEnable(GL_AUTO_NORMAL);
    glEnable(GL_NORMALIZE);
    glMapGrid2f(25, 0.0, 1.0, 25, 0.0, 1.0);
    initlights();
}

void reshape(int w, int h){
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  if (w <= h)
    glOrtho(-30.0, 30.0, -30.0 * (GLfloat) h / (GLfloat) w, 30.0 * (GLfloat) h / (GLfloat) w, -200, 200);
  else
    glOrtho(-30.0 * (GLfloat) w / (GLfloat) h, 30.0 * (GLfloat) w / (GLfloat) h, -30.0, 30.0, -200, 200);

  gluPerspective(1.0, (float)w/h, 2.0, 1.0);
  gluLookAt(translation[3].value, translation[4].value, eye[2], at[0], at[1], at[2], up[0], up[1],up[2]);
  glTranslatef(translation[0].value, translation[1].value, translation[2].value);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void redisplay_all(void){
    reshape(WIN_WIDTH, WIN_HEIGHT);
    glutPostRedisplay();
}

void myReshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-4.0, 4.0, -4.0 * (GLfloat) h / (GLfloat) w,
            4.0 * (GLfloat) h / (GLfloat) w, -4.0, 4.0);
    else
        glOrtho(-4.0 * (GLfloat) w / (GLfloat) h,
            4.0 * (GLfloat) w / (GLfloat) h, -4.0, 4.0, -4.0, 4.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int area_hit(area* area, int x, int y){
  if ((x > 0 && x < WIN_WIDTH) && (y > 0 && y < WIN_HEIGHT))
    return area->id;
  return 0;
}

/* RATON!!! \o/ */
void mouse(int button, int state, int x, int y)
{
  selection = 0;
  if (button==GLUT_LEFT_BUTTON && state == GLUT_DOWN && (m_choise==0||m_choise==2)) {
    selection += area_hit(&translation[0], x, y);
    if (m_choise==0) selection += area_hit(&translation[0], x, y);
    if (m_choise==2) selection += area_hit(&translation[3], x, y);
    old_x = x;
    redisplay_all();
  }
  if (button==GLUT_RIGHT_BUTTON && state == GLUT_DOWN && ((m_choise==0||m_choise==1)||m_choise==2)) {
    if (m_choise==0) selection += area_hit(&translation[1], x, y);
    if (m_choise==1) selection += area_hit(&translation[2], x, y);
    if (m_choise==2) selection += area_hit(&translation[4], x, y);
    old_y = y;
    redisplay_all();
  }
}

void area_update(area* area, int update){
  if (selection != area->id)
    return;

  area->value += update * area->step;

  if (area->value < area->min)
    area->value = area->min;
  else if (area->value > area->max)
    area->value = area->max;
}

/* funcion onclick era muy mainstream */
void pressed_mouse(int x, int y)
{
  area_update(&translation[0], x-old_x);
  area_update(&translation[1], old_y-y);
  area_update(&translation[2], old_y-y);
  area_update(&translation[3], x-old_x);
  area_update(&translation[4], old_y-y);
  old_y = y;
  old_x = x;
  redisplay_all();
}

int main(int argc, char **argv)
{
		teoria();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow(argv[0]);
    myinit();
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
		glutMotionFunc(pressed_mouse);
  	glutMouseFunc(mouse);
	  redisplay_all();
    glutMainLoop();
    return 0;
}
