#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdarg.h>

/* Porpiedades de tamaños del robot */
#define WIN_WIDTH 800
#define WIN_HEIGHT 800
#define TORSO_HEIGHT 5.0
#define TORSO_RADIUS 1.3
#define UPPER_ARM_HEIGHT 2.5
#define LOWER_ARM_HEIGHT 2.3
#define UPPER_ARM_RADIUS  0.5
#define LOWER_ARM_RADIUS  0.5
#define UPPER_LEG_RADIUS  0.5
#define LOWER_LEG_RADIUS  0.5
#define LOWER_LEG_HEIGHT 3.1
#define UPPER_LEG_HEIGHT 3.3
#define HEAD_HEIGHT 1.2
#define HEAD_RADIUS 1.4
#define HAND_RADIUS 0.6
#define HAND_HEIGHT 0.9
#define FOOT_RADIUS 0.7
#define FOOT_HEIGHT 1.1
#define NECK_RADIUS 0.5
#define NECK_HEIGHT 1.0
#define JOINT_POINT_RADIUS 0.5
#define JOINT_POINT_HEIGHT 0.5

bool flag1=true, flag2=false, flag3=true, flag4=false, flag5=true, flag6=false, hflag=true;

/* Inicilizacion de los angulos de cada parte del cuerpo */
static GLfloat theta[17] = {0.0,   0.0,   0.0, 90.0, -20.0, 90.0, -20.0, 180.0, 0.0, 180.0, 0.0, 0.0,0.0, 0.0,  0.0, 0.0, 0.0 };
static GLint choise = 2;
static GLint m_choise = 0;

/* Partes del puerco digo cuerpo */
GLUquadricObj *t,   *h,   *n,    *lh, *rh,   *lf,  *rf,   *jp, *lhnd, *lft, *lua,  *lla, *rua,  *rla, *lll,  *rll, *rul,  *lul, *rhnd, *rft;
/* Control del mouse */
typedef struct _area {
    int id;
    int x, y;
    float min, max;
    float value;
    float step;
} area;

area translation[5] = {
    { 0, 120, 40, -30.0, 30.0, 0.0, 0.05,},
    { 1, 180, 40, -30.0, 30.0, 0.0, 0.05,},
    { 2, 180, 40, -200.0, 200.0, 0.0, 0.1,},
        { 3, 180, 120, -100, 100, 0.0, 0.5},
        { 4, 240, 120, -100, 100, 0.0, 0.5}
};

/* gluLookAt valores iniciales */
GLfloat eye[3] = { 0.0, 0.0, 60.0 };
GLfloat at[3]  = { 0.0, 0.0, 0.0 };
GLfloat up[3]  = { 0.0, 1.0, 0.0 };

/* Variables y angulos para la animación */
GLuint texture1=0;
GLuint texture2=0;
GLuint texture3=0;
GLuint texture4=0;
GLuint old_thetaW3=0;
GLuint old_thetaX4=0;
GLuint old_thetaE5=0;
GLuint old_thetaC6=0;
GLuint old_thetaS11=0;
GLuint old_thetaD12=0;
GLint selection = 0;

void redisplay_all(void);
