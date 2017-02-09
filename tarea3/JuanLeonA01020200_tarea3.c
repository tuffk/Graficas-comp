#include <GL/glut.h>
#include <stdlib.h>

static int spin = 0;

// Posicion inicial de las camaras
float camX=1.5, camY=-2.0, camZ=10.0;

// Este es para hacer un cilindro
GLUquadric* qobj;

// Inicializacion de las luces de ambiente
void init(void)
{
    //definimos la luz de ambiente
    GLfloat light_ambient[] = { 0.0, 0.0, 1.0, 1.0 };
    GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
    GLfloat ambient[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat position[] = { 0.0, 3.0, 2.0, 0.0 };
    GLfloat lmodel_ambient[] = { 0.4, 0.4, 0.4, 1.0 };
    GLfloat local_view[] = { 0.0 };

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
    glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);

    glClearColor(0.0, 0.1, 0.1, 0.0);

    // Para el cilindro
    qobj = gluNewQuadric();
    gluQuadricNormals(qobj, GLU_SMOOTH);
    gluQuadricDrawStyle(qobj, GLU_LINE);
}

// Funcion para el uso de los materiales
void miMaterial(float rd, float vd, float ad, float rs, float vs, float as, float br)
{
    GLfloat mat_diffuse[] = { rd, vd, ad, 1.0 };
    GLfloat mat_specular[] = { rs, vs, as, 1.0 };
    GLfloat low_shininess[] = { br };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
}

//dibujara las llantas de la derecha
void dibujaLlanta12(GLfloat *no_mat, GLfloat *mat_diffuse, GLfloat *mat_specular, GLfloat *no_shininess, GLfloat *low_shininess){
  // llanta derecha adelante
  glPushMatrix ();
     glTranslatef (-4.0, 0.0, 8.0);
     glRotatef (90.0, 0.0, 1.0, 0.0);
     glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
 glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
 glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
 glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
 glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
    glutSolidTorus (0.275, 0.85, 15, 15);
  glPopMatrix ();
  glPushMatrix ();
     glTranslatef (-3.0, 0.0, 8.0);
     glRotatef (-90.0, 0.0, 1.0, 0.0);
     miMaterial( 0.3, 0.7, 0.1, 0.6, 0.6, 0.2, 10.0);
     glutSolidCone (1.0, 2.0, 15, 15);
  glPopMatrix ();

  // llanta derecha atras
  glPushMatrix ();
     glTranslatef (4.0, 0.0, 8.0);
     glRotatef (90.0, 0.0, 1.0, 0.0);
     glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
 glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
 glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
 glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
 glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
     glutSolidTorus (0.275, 0.85, 15, 15);
  glPopMatrix ();
  glPushMatrix ();
     glTranslatef (3.0, 0.0, 8.0);
     glRotatef (90.0, 0.0, 1.0, 0.0);
     miMaterial( 0.3, 0.7, 0.1, 0.6, 0.6, 0.2, 10.0);
     glutSolidCone (1.0, 2.0, 15, 15);
  glPopMatrix ();
}

//dibuja las llantas de la izquierda
void dibujaLlanta34(GLfloat *no_mat, GLfloat *mat_diffuse, GLfloat *mat_specular, GLfloat *no_shininess, GLfloat *low_shininess){
  //llanta adelante izquierda
  glPushMatrix ();
     glTranslatef (-4.0, 0.0, -8.0);
     glRotatef (90.0, 0.0, 1.0, 0.0);
     glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
  glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
  glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
     glutSolidTorus (0.275, 0.85, 15, 15);
  glPopMatrix ();
  glPushMatrix ();
     glTranslatef (-3.0, 0.0, -8.0);
     glRotatef (-90.0, 0.0, 1.0, 0.0);
     miMaterial( 0.3, 0.7, 0.1, 0.6, 0.6, 0.2, 10.0);
     glutSolidCone (1.0, 2.0, 15, 15);
  glPopMatrix ();

  // llanta atras izquierda
  glPushMatrix ();
     glTranslatef (4.0, 0.0, -8.0);
     glRotatef (90.0, 0.0, 1.0, 0.0);
     glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
  glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
  glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
     glutSolidTorus (0.275, 0.85, 15, 15);
  glPopMatrix ();
  glPushMatrix ();
     glTranslatef (3.0, 0.0, -8.0);
     glRotatef (90.0, 0.0, 1.0, 0.0);
     miMaterial( 0.3, 0.7, 0.1, 0.6, 0.6, 0.2, 10.0);
     glutSolidCone (1.0, 2.0, 15, 15);
  glPopMatrix ();
}

// Dibuja el cuerpo y las luces del coche
void dibujaCuerpo(GLfloat *no_mat, GLfloat *mat_diffuse, GLfloat *no_shininess, GLfloat *mat_emission, GLfloat *mat_ambient)
{
  //cuerpo
  glPushMatrix ();
    glTranslatef (0.0, 1.0, 0.0);
    glRotatef (90.0, 0.0, 0.0, 1.0);
    glScalef (2.5, 7.5, 20);
    glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
  	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
  	glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
  	glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
  	glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
       glutSolidCube (1.0);
    glPopMatrix ();

    //Color de los faros y asi
    glPushMatrix();
       glTranslatef (-2.0, 0.5, -11.0);
       glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
  	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
  	glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
  	glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
  	glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
       gluCylinder(qobj, 0.5, 0.5, 2.0, 15, 15);
  	glPopMatrix();
}

//dibuja los faros
void dibujaLuces(){
  //faro izquierdo
  glPushMatrix ();
     glTranslatef (-2.5, 1.2, 10.0);
     miMaterial( 0.95, 0.4, 0.4, 1.0, 1.0, 1.0, 5.0);
     glutSolidSphere (0.4, 15, 15);
    glPopMatrix ();

  //faro derecho
  glPushMatrix ();
     glTranslatef (2.5, 1.2, 10.0);
     miMaterial( 0.95, 0.4, 0.4, 1.0, 1.0, 1.0, 5.0);
     glutSolidSphere (0.4, 15, 15);
  glPopMatrix ();
}

// Display
void display(void)
{
	GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
  GLfloat mat_ambient[] = { 0.7, 0.7, 0.7, 1.0 };
  GLfloat mat_ambient_color[] = { 0.8, 0.8, 0.2, 1.0 };
  GLfloat mat_diffuse[] = { 0.1, 0.5, 0.8, 1.0 };
  GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
  GLfloat no_shininess[] = { 0.0 };
  GLfloat low_shininess[] = { 5.0 };
  GLfloat high_shininess[] = { 100.0 };
  GLfloat mat_emission[] = {0.3, 0.2, 0.2, 0.0};
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  GLfloat position[] = { 0.0, 0.0, 1.5, 1.0 };

    glPushMatrix ();
      glRotatef (20.0, 1.0, 0.0, 0.0);
      gluLookAt (camX, camY, camZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
      glRotated ((GLdouble) spin, 1.0, 0.0, 0.0);
	  glLightfv (GL_LIGHT0, GL_POSITION, position);

	  dibujaLlanta12(no_mat, mat_diffuse, mat_specular, no_shininess, low_shininess);
    dibujaLlanta34(no_mat, mat_diffuse, mat_specular, no_shininess, low_shininess);
    dibujaCuerpo(no_mat, mat_diffuse, no_shininess, mat_emission, mat_ambient);
    dibujaLuces();
    glFlush();
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
	glOrtho (-6.0, 6.0, -6.0*(GLfloat)h/(GLfloat)w,
	    6.0*(GLfloat)h/(GLfloat)w, -24.0, 24.0);
    else
	glOrtho (-6.0*(GLfloat)w/(GLfloat)h,
	    6.0*(GLfloat)w/(GLfloat)h, -6.0, 6.0, -24.0, 24.0);
    glMatrixMode(GL_MODELVIEW);
}

// Function for mouse
void mouse(int button, int state, int x, int y)
{
   switch (button) {
      case GLUT_LEFT_BUTTON:
         if (state == GLUT_DOWN) {
            spin = (spin + 30) % 360;
            glutPostRedisplay();
         }
         break;
      default:
         break;
   }
}

// Function for keyboard
void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
      case 'q':
         exit(0);
         break;
      case 'x':
           camX++;
           glutPostRedisplay();
           break;
      case 'X':
           camX--;
           glutPostRedisplay();
           break;
      case 'y':
           camY++;
           glutPostRedisplay();
           break;
      case 'Y':
           camY--;
           glutPostRedisplay();
           break;
      case 'z':
           camZ++;
           glutPostRedisplay();
           break;
      case 'Z':
           camZ--;
           glutPostRedisplay();
           break;
   }
}

// Main
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (800, 800);
    glutInitWindowPosition (100, 100);
    glutCreateWindow (argv[0]);

    init();

    glutReshapeFunc (reshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
