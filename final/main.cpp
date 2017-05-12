/* Incluir las librerias */
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <memory.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "../glm/glm.h"
#include "respuestas.h"
#include "glMagic.h"
/* Ya se incluyeron las librerias */

/* Defines */
#define bool int
#define true 1
#define false 0
/* Se definieron */

/* Ortho (if used) */
double _left = 0.0;
double _right = 0.0;
double _bottom = 0.0;
double _top = 0.0;
double _zNear = 0.1;
double _zFar = 10.0;
double fovy = 45.0;
double prev_z = 0;
/* Ya no es ortho */

/* Movimiento del mouse */
int _mouseX = 0;
int _mouseY = 0;
bool _mouseLeft = false;
bool _mouseMiddle = false;
bool _mouseRight = false;
double _dragPosX = 0.0;
double _dragPosY = 0.0;
double _dragPosZ = 0.0;
/* El mouse ya no se mueve */

/* Modelview Matrix */
double _matrix[16];
double _matrixI[16];
double vlen(double x, double y, double z);
void pos(double *px, double *py, double *pz, const int x, const int y,
         const int *viewport);
void getMatrix();
void invertMatrix(const GLdouble *m, GLdouble *out);

GLUnurbsObj *theNurb;
GLfloat ctlpoints[4][4][3], points2[4][4][3];
int showPoints = 0;
void init_surface(void)
{
    int u, v;
    for (u = 0; u < 4; u++) {
        for (v = 0; v < 4; v++) {
            ctlpoints[u][v][0] = 2.0*((GLfloat)u - 1.5);
            ctlpoints[u][v][1] = 2.0*((GLfloat)v - 1.5);

            if ( (u == 1 || u == 2) && (v == 1 || v == 2))
                ctlpoints[u][v][2] = -3.0;
            // else if (u == 0 || v== 0)
            //     ctlpoints[u][v][2] = -0.0;
            else
             ctlpoints[u][v][2] = -0.0;
        }
    }				
}

/* because podemos */
int full_screen = 0;

/* Global Variables for this app */
GLMmodel *wall, *piso, *pmodel, *pmodel2, *pmodel3, *pmodel4, *pmodel5,
    *pmodel6, *pmodel7, *pmodel8, *pmodel9, *pmodel10, *pmodel11, *pmodel12,
    *pmodel13, *pmodel14, *pmodel15, *pmodel16, *pmodel17, *pmodel18, *pmodel19,
    *pmodel20, *pmodel21, *pmodel22; /* the loaded model */
GLuint modeWall, modePiso, mode, mode2, mode3, mode4, mode5, mode6, mode7,
    mode8, mode9, mode10, mode11, mode12, mode13, mode14, mode15, mode16,
    mode17, mode18, mode19, mode20, mode21, mode22; /* viewing mode */

int ww, wh;        /* window width and height */
int wireframe = 0; /* Draw modes */
int show_axis = 1;
int smooth = 1;
int material = 1;
int textured = 1;
int two_sided = 1;
int show_help = 1; /* help toggle */
int stereo = 0;    /* stereo init variable */
int benchmark = 0;
int centerZ = -3;
float auto_rotate = 0;
int xrotate = 0;
int yrotate = 1;
int zrotate = 0;

int lighting = 1;

#ifdef SMOOTH_HINT
int smooth_hint = 0;
#endif
void *Help_Font = GLUT_BITMAP_8_BY_13;
int linestart = 10; /* start point on y axis for text lines */
int linespace = 20; /* spac betwwen text lines */

/* Las de siempre */
void Reshape(int w, int h);
void GLMagic(void);
void Mouse(int button, int state, int x, int y);
void Motion(int x, int y);
void Keyboard(unsigned char key, int x, int y);
void Display(void);
void AutoSpin(void);

/* Model and help display functoins */
void DrawAxis(float scale);
void HelpDisplay(GLint ww, GLint wh);
void HelpRenderBitmapString(float x, float y, void *font, char *string);
void loadWallFloor(void);
void loadobj(void);
void drawcrazyLR(void);

static GLuint cubeList;

void Reshape(int w, int h) {
  glViewport(0, 0, w, h);

  ww = w;
  wh = h;
  _top = 1.0;
  _bottom = -1.0;
  _left = -(double)w / (double)h;
  _right = -_left;

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(fovy, (double)w / (double)h, _zNear, -20); /* PErspective for stereo */

  glMatrixMode(GL_MODELVIEW);
}

void Mouse(int button, int state, int x, int y) {
  int viewport[4];
  _mouseX = x;
  _mouseY = y;

  if (state == GLUT_UP)
    switch (button) {
    case GLUT_LEFT_BUTTON:
      _mouseLeft = false;
      break;
    case GLUT_MIDDLE_BUTTON:
      _mouseMiddle = false;
      break;
    case GLUT_RIGHT_BUTTON:
      _mouseRight = false;
      break;
    }
  else
    switch (button) {
    case GLUT_LEFT_BUTTON:
      _mouseLeft = true;
      break;
    case GLUT_MIDDLE_BUTTON:
      _mouseMiddle = true;
      break;
    case GLUT_RIGHT_BUTTON:
      _mouseRight = true;
      break;
    }

  glGetIntegerv(GL_VIEWPORT, viewport);
  pos(&_dragPosX, &_dragPosY, &_dragPosZ, x, y, viewport);
}

void Motion(int x, int y) {
  bool changed = false;
  const int dx = x - _mouseX;
  const int dy = y - _mouseY;
  int viewport[4];

  glGetIntegerv(GL_VIEWPORT, viewport);

  if (dx == 0 && dy == 0)
    return;

  if (_mouseMiddle || (_mouseLeft && _mouseRight)) {
    glLoadIdentity();
    glTranslatef(0, 0, dy * 0.01);
    glMultMatrixd(_matrix);
    changed = true;
  } else if (_mouseLeft) {
    double ax, ay, az;
    double bx, by, bz;
    double angle;

    ax = dy;
    ay = dx;
    az = 0.0;
    angle = vlen(ax, ay, az) / (double)(viewport[2] + 1) * 180.0;

    bx = _matrixI[0] * ax + _matrixI[4] * ay + _matrixI[8] * az;
    by = _matrixI[1] * ax + _matrixI[5] * ay + _matrixI[9] * az;
    bz = _matrixI[2] * ax + _matrixI[6] * ay + _matrixI[10] * az;

    glRotatef(angle, bx, by, bz);

    changed = true;
  } else if (_mouseRight) {
    double px, py, pz;
    pos(&px, &py, &pz, x, y, viewport);
    glLoadIdentity();
    glTranslatef(px - _dragPosX, py - _dragPosY, pz - _dragPosZ);
    glMultMatrixd(_matrix);

    _dragPosX = px;
    _dragPosY = py;
    _dragPosZ = pz;

    changed = true;
  }

  _mouseX = x;
  _mouseY = y;

  if (changed) {
    getMatrix();
    glutPostRedisplay();
  }
}

void AutoSpin(void) {
  if (xrotate || yrotate || zrotate) {
    glRotatef(1, xrotate, yrotate, zrotate);
    getMatrix();
    glutPostRedisplay();
  }
}

void Keyboard(unsigned char key, int x, int y) {
  switch (key) {
    case 'h':
    case 'H': {
      show_help = !show_help;
      break;
    }
    /*Se cambia la variable del movimiento de Fondo con el mouse Arriba y abajo*/
    case 'e':
      _mouseMiddle = !_mouseMiddle;
      break;

    case 'r':
    case 'R': {
      int i;
      /* Resetting Scene */
      for (i = 0; i < 16; i++) {
        if (i == 0 || i == 5 || i == 10 || i == 15) {
          _matrix[i] = 1;
        } else {
          _matrix[i] = 0;
        }
      }
      prev_z = 0;
      glLoadIdentity();
      glMultMatrixd(_matrix);
      getMatrix();
      break;
    }
    case 'a':
    case 'A': {
      show_axis = !show_axis;
      break;
    }
    case 'b':
    case 'B': {
      benchmark = !benchmark;
      if (benchmark)
        glutIdleFunc(AutoSpin);
      else
        glutIdleFunc(NULL);
      break;
    }
    case 'x':
    case 'X': {
      xrotate = !xrotate;
      break;
    }
    case 'y':
    case 'Y': {
      yrotate = !yrotate;
      break;
    }
    case 'z':
    case 'Z': {
      zrotate = !zrotate;
      break;
    }

    case 'l':
    case 'L':
      lighting = !lighting;
      break;
      #ifdef SMOOTH_HINT
        case 'l':
        case 'L': {
          smooth_hint = !smooth_hint;
          if (smooth_hint) {
            glEnable(GL_LINE_SMOOTH);
            /* glEnable (GL_POLYGON_SMOOTH); */
            glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
            /* glHint (GL_POLYGON_SMOOTH_HINT, GL_NICEST); */
          } else {
            glDisable(GL_LINE_SMOOTH);
            /* glDisable (GL_POLYGON_SMOOTH); */
          }
          break;
        }
      #endif /* 0 */
    case 'w':
    case 'W': {
      wireframe = !wireframe;
      break;
    }
    case 'd':
    case 'D': {
      two_sided = !two_sided;
      break;
    }
    case 's':
    case 'S': {
      smooth = !smooth;
      break;
    }
    case 'm':
    case 'M': {
      material = !material;
      if (!material && textured)
        textured = 0;
      break;
    }
    case 't':
    case 'T': {
      textured = !textured;
      if (!material && textured)
        material = 1;
      break;
    }
    #ifdef AVL
      case 'f':
      case 'F': {
        glmFlipModelTextures(pmodel);
        break;
      }
    #endif

    case 9: {
      if (!full_screen) {
        glutFullScreen();
        full_screen = 1;
      }

      break;
    }
    case 27:
      exit(0);
      break;
    default: {
      break;
    } /* flush all other input */
  }
  glutPostRedisplay(); /* redisplay afterword */
}

/*****************************************************************************/
/*Matrix and Vector Utility functions ****************************************/
/*****************************************************************************/

double vlen(double x, double y, double z) {
  return sqrt(x * x + y * y + z * z);
}

void pos(double *px, double *py, double *pz, const int x, const int y, const int *viewport) {
  /*
     Use the ortho projection and viewport information
     to map from mouse co-ordinates back into world
     co-ordinates
   */

  *px = (double)(x - viewport[0]) / (double)(viewport[2]);
  *py = (double)(y - viewport[1]) / (double)(viewport[3]);

  *px = _left + (*px) * (_right - _left);
  *py = _top + (*py) * (_bottom - _top);
  *pz = _zNear;
}

void getMatrix() {
  glGetDoublev(GL_MODELVIEW_MATRIX, _matrix);
  invertMatrix(_matrix, _matrixI);
}

/*  From Mesa-2.2\src\glu\project.c */

/*  Compute the inverse of a 4x4 matrix.  Contributed by scotter@lafn.org */

void invertMatrix(const GLdouble *m, GLdouble *out) {
  /* NB. OpenGL Matrices are COLUMN major. */
  #define MAT(m, r, c) (m)[(c)*4 + (r)]

  /* Here's some shorthand converting standard (row,column) to index. */
  #define m11 MAT(m, 0, 0)
  #define m12 MAT(m, 0, 1)
  #define m13 MAT(m, 0, 2)
  #define m14 MAT(m, 0, 3)
  #define m21 MAT(m, 1, 0)
  #define m22 MAT(m, 1, 1)
  #define m23 MAT(m, 1, 2)
  #define m24 MAT(m, 1, 3)
  #define m31 MAT(m, 2, 0)
  #define m32 MAT(m, 2, 1)
  #define m33 MAT(m, 2, 2)
  #define m34 MAT(m, 2, 3)
  #define m41 MAT(m, 3, 0)
  #define m42 MAT(m, 3, 1)
  #define m43 MAT(m, 3, 2)
  #define m44 MAT(m, 3, 3)

  GLdouble det;
  GLdouble d12, d13, d23, d24, d34, d41;
  GLdouble tmp[16]; /* Allow out == in. */

  /* Inverse = adjoint / det. (See linear algebra texts.) */

  /* pre-compute 2x2 dets for last two rows when computing */
  /* cofactors of first two rows. */
  d12 = (m31 * m42 - m41 * m32);
  d13 = (m31 * m43 - m41 * m33);
  d23 = (m32 * m43 - m42 * m33);
  d24 = (m32 * m44 - m42 * m34);
  d34 = (m33 * m44 - m43 * m34);
  d41 = (m34 * m41 - m44 * m31);

  tmp[0] = (m22 * d34 - m23 * d24 + m24 * d23);
  tmp[1] = -(m21 * d34 + m23 * d41 + m24 * d13);
  tmp[2] = (m21 * d24 + m22 * d41 + m24 * d12);
  tmp[3] = -(m21 * d23 - m22 * d13 + m23 * d12);

  /* Compute determinant as early as possible using these cofactors. */
  det = m11 * tmp[0] + m12 * tmp[1] + m13 * tmp[2] + m14 * tmp[3];

  /* Run singularity test. */
  if(det != 0.0) {
    GLdouble invDet = 1.0 / det;
    /* Compute rest of inverse. */
    tmp[0] *= invDet;
    tmp[1] *= invDet;
    tmp[2] *= invDet;
    tmp[3] *= invDet;
  
    tmp[4] = -(m12 * d34 - m13 * d24 + m14 * d23) * invDet;
    tmp[5] = (m11 * d34 + m13 * d41 + m14 * d13) * invDet;
    tmp[6] = -(m11 * d24 + m12 * d41 + m14 * d12) * invDet;
    tmp[7] = (m11 * d23 - m12 * d13 + m13 * d12) * invDet;
  
    /* Pre-compute 2x2 dets for first two rows when computing */
    /* cofactors of last two rows. */
    d12 = m11 * m22 - m21 * m12;
    d13 = m11 * m23 - m21 * m13;
    d23 = m12 * m23 - m22 * m13;
    d24 = m12 * m24 - m22 * m14;
    d34 = m13 * m24 - m23 * m14;
    d41 = m14 * m21 - m24 * m11;
  
    tmp[8] = (m42 * d34 - m43 * d24 + m44 * d23) * invDet;
    tmp[9] = -(m41 * d34 + m43 * d41 + m44 * d13) * invDet;
    tmp[10] = (m41 * d24 + m42 * d41 + m44 * d12) * invDet;
    tmp[11] = -(m41 * d23 - m42 * d13 + m43 * d12) * invDet;
    tmp[12] = -(m32 * d34 - m33 * d24 + m34 * d23) * invDet;
    tmp[13] = (m31 * d34 + m33 * d41 + m34 * d13) * invDet;
    tmp[14] = -(m31 * d24 + m32 * d41 + m34 * d12) * invDet;
    tmp[15] = (m31 * d23 - m32 * d13 + m33 * d12) * invDet;
  
    memcpy(out, tmp, 16 * sizeof(GLdouble));
  }

  #undef m11
  #undef m12
  #undef m13
  #undef m14
  #undef m21
  #undef m22
  #undef m23
  #undef m24
  #undef m31
  #undef m32
  #undef m33
  #undef m34
  #undef m41
  #undef m42
  #undef m43
  #undef m44
  #undef MAT
}

/*****************************************************************************/
/*OpenGL Display Functions****************************************************/
/*****************************************************************************/

void DrawAxis(float scale) {
  glPushMatrix();
    glDisable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);
    glScalef(scale, scale, scale);

    glBegin(GL_LINES);

    GLfloat ambient[] = { 1.0, 1.0, 0.0, 1.0 }; // luz amarilla
	GLfloat diffuse[] = { 0.5, 0.5, 0.5, 1.0 }; // difusa gris
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);

    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(.8f, 0.05f, 0.0);
    glVertex3f(1.0, 0.25f, 0.0); /*  Letter X */
    glVertex3f(0.8f, .25f, 0.0);
    glVertex3f(1.0, 0.05f, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(1.0, 0.0, 0.0); /*  X axis */

    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 1.0, 0.0); /*  Y axis */

    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 1.0); /*  Z axis */
    glEnd();
    if (lighting)
      glEnable(GL_LIGHTING);
    if (lighting)
      glEnable(GL_TEXTURE_2D);
    glColor3f(1.0, 1.0, 1.0);
  glPopMatrix();
}

void HelpDisplay(GLint ww, GLint wh) {
  glDisable(GL_LIGHTING);
  glDisable(GL_TEXTURE_2D);
  glColor3f(1.0f, 1.0f, 1.0f);

  /*  switch to projection mode */
  glMatrixMode(GL_PROJECTION);
  /*  save previous matrix which contains the  */
  /* settings for the perspective projection */
  glPushMatrix();
    /* reset matrix */
    glLoadIdentity();
    /* set a 2D orthographic projection */
    gluOrtho2D(0, ww, 0, wh);
    /* invert the y axis, down is positive */
    glScalef(1, -1, 1);
    /* mover the origin from the bottom left corner */
    /* to the upper left corner */
    glTranslatef(0, -wh, 0);
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
      glLoadIdentity();
      linestart = 10;

      HelpRenderBitmapString(30, linestart += linespace, Help_Font, "Help Menu");
      HelpRenderBitmapString(30, linestart += linespace, Help_Font, "---------");
      HelpRenderBitmapString(30, linestart += linespace, Help_Font,
                         "H/h = Toggle Help Menu");
      if (!full_screen)
        HelpRenderBitmapString(30, linestart += linespace, Help_Font,
                           "TAB = Activate Full Screen");
      HelpRenderBitmapString(30, linestart += linespace, Help_Font,
                         "Esc = Exits Program");
      HelpRenderBitmapString(30, linestart += linespace, Help_Font,
                         "R/r = Reset Position");
      HelpRenderBitmapString(30, linestart += linespace, Help_Font,
                         "C/c = Toggle Axis");
      HelpRenderBitmapString(30, linestart += linespace, Help_Font,
                         "W/w = Toggle Wireframe");
      HelpRenderBitmapString(30, linestart += linespace, Help_Font,
                         "D/d = Toggle Double Sided Polygons");
      HelpRenderBitmapString(30, linestart += linespace, Help_Font,
                         "S/s = Toggle Smooth Shading");
      HelpRenderBitmapString(30, linestart += linespace, Help_Font,
                         "M/m = Toggle Materials");
      HelpRenderBitmapString(30, linestart += linespace, Help_Font,
                         "T/t = Toggle Textures");
      HelpRenderBitmapString(30, linestart += linespace, Help_Font,
                         "B/b = Toggle Auto Rotate");
      HelpRenderBitmapString(30, linestart += linespace, Help_Font,
                         "e = Movimiento Z mouse");
      #ifdef AVL
        HelpRenderBitmapString(30, linestart += linespace, Help_Font,
                         "F/f = Flip Textures");
      #endif
    glPopMatrix();

    /*  set the current matrix to GL_PROJECTION */
    glMatrixMode(GL_PROJECTION);
    /*  restore previous settings */
  glPopMatrix();
  
  /*  get back to GL_MODELVIEW matrix */
  glMatrixMode(GL_MODELVIEW);

  if (lighting)
    glEnable(GL_LIGHTING);
  glEnable(GL_TEXTURE_2D);
}

void HelpRenderBitmapString(float x, float y, void *font, char *string) {
  char *c;
  /* set position to start drawing fonts */
  glRasterPos2f(x, y);
  /* loop all the characters in the string */
  for (c = string; *c != '\0'; c++)
    glutBitmapCharacter(font, *c);
}




void loadWallFloor() {
  wall = glmReadOBJ("../tarea6/files/wall.obj");
  glmUnitize(wall);
  glmVertexNormals(wall, 90.0, GL_TRUE);
  modeWall =
      glmList(wall, GLM_SMOOTH | GLM_2_SIDED | GLM_MATERIAL | GLM_TEXTURE);

  piso = glmReadOBJ("../tarea6/files/floor.obj");
  glmUnitize(piso);
  glmVertexNormals(piso, 90.0, GL_TRUE);
  modePiso = glmList(piso, GLM_SMOOTH | GLM_2_SIDED | GLM_MATERIAL | GLM_TEXTURE);
}

void loadAlice() {

  pmodel5 = glmReadOBJ("../tarea6/files/tableBasseVerre.obj");
  glmUnitize(pmodel5);
  glmVertexNormals(pmodel5, 90.0, GL_TRUE);
  mode5 = glmList(pmodel5, GLM_SMOOTH | GLM_2_SIDED | GLM_MATERIAL | GLM_TEXTURE);

  pmodel6 = glmReadOBJ("../tarea6/files/beerGlass.obj");
  glmUnitize(pmodel6);
  glmVertexNormals(pmodel6, 90.0, GL_TRUE);
  mode6 = glmList(pmodel6, GLM_SMOOTH | GLM_2_SIDED | GLM_MATERIAL | GLM_TEXTURE);
}


void room() {
  glPushMatrix();
    glTranslatef(0, .60, -1);
    glScalef(2.3, 1, .8);
    glCallList(modeWall);
  glPopMatrix();

  glPushMatrix();
    glTranslatef(-2.3, .60, 0.5);
    glRotatef(90, 0, 1, 0);
    glScalef(1.5, 1, .8);
    glCallList(modeWall);
  glPopMatrix();

  glPushMatrix();
    glTranslatef(2.3, .60, 0.5);
    glRotatef(90, 0, 1, 0);
    glScalef(1.5, 1, .8);
    glCallList(modeWall);
  glPopMatrix();

  glPushMatrix();
    glTranslatef(0, -0.4, 0.5);
    glRotatef(90, 0, 1, 0);
    glScalef(1.5, .5, 2.3);
    glCallList(modePiso);
  glPopMatrix();
}


void drawAlice() {
	/*mesa que mas aplauda*/
	glPushMatrix();
		glScalef(0.5,0.5,0.5);
		glTranslatef(0.6, -0.77,0);
		glCallList(mode5);
  glPopMatrix();
	/*alicia en el pais de la AA*/
	glPushMatrix();
		glTranslatef(0.3, 0.02, 0.4);
		glRotatef(180, 0, 1, 0);
		glScalef(.1, .1, .1);
		glCallList(mode6);
	glPopMatrix();
}
void Display(void) {
  if (lighting) {
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
  } else {
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
  }

    GLfloat mat_solid[] = { 0.75, 0.75, 0.0, 1.0 };
    GLfloat mat_zero[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_transparent[] = { 0.0, 0.8, 0.8, 0.6 };
    GLfloat mat_emission[] = { 0.0, 0.3, 0.3, 0.6 };

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glPushMatrix();
    glLoadIdentity();
    glTranslatef(0, 0, centerZ); /* to center object down Z */
    glMultMatrixd(_matrix);

    if (show_axis)
      DrawAxis(1.0f);
    if (wireframe)                               /* if Wireframe is checked */
      glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); /* draw wireframe */
    else                                         /* else */
      glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); /* draw filled polygons */

      glPushMatrix ();
        glTranslatef (0, 0, -1.0);
        glRotatef (15.0, 1.0, 1.0, 0.0);
        glRotatef (30.0, 0.0, 1.0, 0.0);
        glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_transparent);
        glEnable (GL_BLEND);
        glDepthMask (GL_FALSE);
        glBlendFunc (GL_SRC_ALPHA, GL_ONE);
        glCallList (cubeList);
        glDepthMask (GL_TRUE);
        glDisable (GL_BLEND);
    glPopMatrix ();

    glPushMatrix();
        room();
        drawAlice();
    glPopMatrix();
   
  glPopMatrix();

  if (show_help)
    HelpDisplay(ww, wh);

  glutSwapBuffers();
}
/*****************************************************************************/
/*Main Functions**************************************************************/
/*****************************************************************************/

int main(int argc, char **argv) {
  int i;
  Answerme aa;
  aa.print_answers();

  glutInit(&argc, argv);

  /* a falta de cilindro cubo*/
  cubeList = glGenLists(1);
  glNewList(cubeList, GL_COMPILE);
  glutSolidCube (0.6);
  //init_surface();
  glEndList();

  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(1024, 768); /*  Window Size If We Start In Windowed Mode */
  glutCreateWindow("Sharmutta & Tutzke");
  if (full_screen)
    glutFullScreen();

  glutDisplayFunc(Display);
  glutKeyboardFunc(Keyboard);
  getMatrix();
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glClearAccum(0.0, 0.0, 0.0, 0.0);
  glutReshapeFunc(Reshape);
  glutMouseFunc(Mouse);
  glutMotionFunc(Motion);
  glutIdleFunc(NULL);

  GLmagic moy;
  moy.alakazam();

  if (lighting)
    glEnable(GL_LIGHTING);
  if (lighting)
    glEnable(GL_LIGHT0);
  glDepthFunc(GL_LESS);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_NORMALIZE);
  glEnable(GL_TEXTURE_2D);

  #ifdef SMOOTH_HINT
    if (smooth_hint) {
      glEnable(GL_LINE_SMOOTH);
      /* glEnable (GL_POLYGON_SMOOTH); */
      glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
      /* glHint (GL_POLYGON_SMOOTH_HINT, GL_NICEST); */
    }
  #endif /*0 */

  
  loadWallFloor();
  loadAlice();
  

  glutMainLoop();

  return 0;
}
