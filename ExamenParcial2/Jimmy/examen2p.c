#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
float angX=0, angY=0, angZ;
GLfloat PAAAAN[4][4][3] =
{
    {
        {-1.73, -1.73, 0.0}, 
        {-1.5, -3.0, 1.0}, 
        {1.5, -3.0, 1.0}, 
        {1.73, -1.73, 0.0}},  
    {
        {-3, -1.5, 1.0}, 
        {-1.5, -1.5, 2.0},  
        {1.5, -1.5, 2.0}, 
        {3, -1.5, 1.0}}, 
    {
        {-3, 1.5, 1.0}, 
        {-1.5, 1.5, 2.0}, 
        {1.5, 1.5, 2.0}, 
        {3, 1.5, 1.0}}, 
    {
        {-1.73, 1.73, 0.0}, 
        {-1.5, 3.0, 1.0}, 
        {1.5, 3.0, 1.0}, 
        {1.73, 1.73, 0.0}} 
};

GLfloat MEAAAT[4][4][3] =
{
    {
        {-1.73, -1.73, 0.0}, 
        {-1.5, -3.0, 0}, 
        {1.5, -3.0, 0}, 
        {1.73, -1.73, 0.0}},  
    {
        {-3, -1.5, 1.0}, 
        {-1.5, -1.5, 0},  
        {1.5, -1.5, 0}, 
        {3, -1.5, 1.0}}, 
    {
        {-3, 1.5, 1.0}, 
        {-1.5, 1.5, 0}, 
        {1.5, 1.5, 0}, 
        {3, 1.5, 1.0}}, 
    {
        {-1.73, 1.73, 0.0}, 
        {-1.5, 3.0, 0}, 
        {1.5, 3.0, 0}, 
        {1.73, 1.73, 0.0}} 
};


void 
initlights(void)
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

void 
display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    //mouse stuff
        glRotatef(angX, 1, 0, 0);
        glRotatef(angY, 0, 1, 0);
        glRotatef(angZ, 0, 0, 1);
        //glScalef(angZ,angZ,angZ);
        //glRotatef(-50.0, 1.0, 0.0, 0.0);
        //glRotatef(10.0, 0.0, 1.0, 0.0);
        glScalef(0.25,0.25,0.25);
        //pan 1
        glPushMatrix();
            glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4,
                 0, 1, 12, 4, &PAAAAN[0][0][0]);

            glMapGrid2f(25, 0.0, 1.0, 25, 0.0, 1.0);
            GLfloat colors[] = { 0.7,0.8 , 0.1, 1.0 };
	        GLfloat shiness_r[] = { 1 };
            glMaterialfv(GL_FRONT, GL_AMBIENT, colors);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, colors);
            glMaterialfv(GL_FRONT, GL_SPECULAR, colors);
            glMaterialfv(GL_FRONT, GL_SHININESS, shiness_r);
            glMaterialfv(GL_FRONT, GL_EMISSION, colors);
            glEvalMesh2(GL_FILL, 0, 25, 0, 25);
        glPopMatrix();
        //pan 2
        glPushMatrix();
            glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4,
                 0, 1, 12, 4, &PAAAAN[0][0][0]);

            glMapGrid2f(25, 0.0, 1.0, 25, 0.0, 1.0);
            glScalef(-1,-1,-1);
            glTranslatef(0,0,1);
            glEvalMesh2(GL_FILL, 0, 25, 0, 25);
        glPopMatrix();

        //meat
        glPushMatrix();
            GLfloat colors2[] = { 0.8, 0.35, 0.1,1.0 };
	        GLfloat shiness_r2[] = { 1 };
            glMaterialfv(GL_FRONT, GL_AMBIENT, colors2);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, colors2);
            glMaterialfv(GL_FRONT, GL_SPECULAR, colors2);
            glMaterialfv(GL_FRONT, GL_SHININESS, shiness_r2);
            glMaterialfv(GL_FRONT, GL_EMISSION, colors2);
            glScalef(-1,-1,-1);
            glTranslatef(0,0,0.5);

            glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4,
                0, 1, 12, 4, &MEAAAT[0][0][0]);

            glMapGrid2f(25, 0.0, 1.0, 25, 0.0, 1.0);

            glEvalMesh2(GL_FILL, 0, 25, 0, 25);
            glScalef(-1,-1,-1);
            glEvalMesh2(GL_FILL, 0, 25, 0, 25);
        glPopMatrix();
    glPopMatrix();


    glFlush();
}

void teoria(void)
{
    printf("1) header: contiene formato, tamaño, compresion, etc \t 2) los colores \n" \
     "2) 4:3, 16:9 , 1.5:1 \n" \
     "3) traslacion {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,z,1} \t rotacion {{1,0,0,0},{0,1,ang,ang},{0,0,ang,ang},{0,0,0,1}} \n" \
     "4) COP: center of proyection, donde se ve. \t DOP: direciton of projection: ahcia donde apunta. \t punto de fuga: punto en el que se juntan lineas paralelas de objetos \n" \
     "5) cinematica: ciancia que estudia el movimiento, no las fuerzas que actuan ni las masas. \t cinematica directa: parte de lso grados de movimeinto para calcular el punto final. \t cinematica inversa: parte del resultado final para obtener lso grados de libertad \n" \
     "6) hombro: rotacion,revolucion. \t codo: rotacio, torcion, revolusion \t muñeca: rotacion, torsion" \
     "\n7) en el espacio :)\n" \
     "8) las ecuaciones con las que se dibujan. las nurbs ademas de tener los puntos de control tienen los puntos knots que es que tan 'pronunciadas' van a ir avanzando als curvas \n"
     "9) explicita: variable despejada EJ: y=sqrt(x^2 - r^2). \t implicita: la ecuaciones estan igualadas a 0 EJ: 0= x^2 + y ^2 - r^2. \t parametricas: las ecuaciones estan dadas con un parametro 'u'. esta es la mas flexible y compelja para las graficas computaiconales \n"\
     "10) AR: augmented reality - sobreponer objetos virutales en objetos reales que dan mas info \t VR: virutal reality - realidad 100/100 virtual, tiene un VE  \t MR: mixed reality: una mescla de AR+AV \t AV: augmented virtuality: un mundo virutal que recibe algunos feedback del mundo real, 50-99/100 realidad \n");
}

void 
myinit(void)
{
    teoria();
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glEnable(GL_DEPTH_TEST);
    
    glEnable(GL_MAP2_VERTEX_3);
    glEnable(GL_AUTO_NORMAL);
    glEnable(GL_NORMALIZE);

    

    initlights();       /* for lighted version only */
}

void 
myReshape(int w, int h)
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

int down = 0,down2=0, lastx, lasty, lastz=1;
void
motion(int x, int y)
{
    if (down) {
        angX = lasty - y;
        angY = (lastx - x);
        glutPostRedisplay();
    }else if(down2)
    {
        angZ = lastz - y;
        glutPostRedisplay();
    }
}

void
mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            lastx = x;
            down = 1;
        } else {
            down = 0;
        }
    } else if(button == GLUT_RIGHT_BUTTON)
    {
        if (state == GLUT_DOWN) {
            lastz = y;
            down2 = 1;
        } else {
            down2 = 0;
        }
    }
}

int 
main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (500, 500);
    glutCreateWindow(argv[0]);
    myinit();
    glutReshapeFunc(myReshape);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;             /* ANSI C requires main to return int. */
}
