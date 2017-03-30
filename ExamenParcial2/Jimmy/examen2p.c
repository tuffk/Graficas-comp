#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>

GLfloat ctrlpoints[4][4][3] =
{
    {
        {-1.5, -1.5, -1.0},
        {-0.5, -1.5, -1.0},
        {0.5, -1.5, 1.0},
        {1.5, -1.5, 1.0}},
    {
        {-1.5, -0.5, -1.0},
        {-0.5, -0.5, 3.0},
        {0.5, -0.5, 1.0},
        {1.5, -0.5, 2.0}},
    {
        {-1.5, 0.5, 2.0},
        {-0.5, 0.5, 2.0},
        {0.5, 0.5, -1.0},
        {1.5, 0.5, -2.0}},
    {
        {-1.5, 1.5, 1},
        {-0.5, 1.5, 2},
        {0.5, 1.5, -1.0},
        {1.5, 1.5, -3}}
};
/*
    GLfloat ctrlpoints[4][4][3] =
    {
        {
            {-1.5, -1.5, 4.0},
            {-0.5, -1.5, 2.0},
            {0.5, -1.5, -1.0},
            {1.5, -1.5, 2.0}},
        {
            {-1.5, -0.5, 1.0},
            {-0.5, -0.5, 3.0},
            {0.5, -0.5, 0.0},
            {1.5, -0.5, -1.0}},
        {
            {-1.5, 0.5, 4.0},
            {-0.5, 0.5, 0.0},
            {0.5, 0.5, 3.0},
            {1.5, 0.5, 4.0}},
        {
            {-1.5, 1.5, -2.0},
            {-0.5, 1.5, -2.0},
            {0.5, 1.5, 0.0},
            {1.5, 1.5, -1.0}}
    };
*/

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
        glRotatef(-50.0, 1.0, 0.0, 0.0);
        glRotatef(10.0, 0.0, 1.0, 0.0);
       glEvalMesh2(GL_FILL, 0, 25, 0, 25);
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
     "6) hombro: rotacion,revolucion. \t codo: rotacio, torcion, revolusion \t muñeca: rotacion" \
     "\n7) en el espacio :)\n");
}

void 
myinit(void)
{
    teoria();
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glEnable(GL_DEPTH_TEST);
    glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4,
        0, 1, 12, 4, &ctrlpoints[0][0][0]);
    glEnable(GL_MAP2_VERTEX_3);
    glEnable(GL_AUTO_NORMAL);
    glEnable(GL_NORMALIZE);
    glMapGrid2f(25, 0.0, 1.0, 25, 0.0, 1.0);
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

int 
main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow(argv[0]);
    myinit();
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;             /* ANSI C requires main to return int. */
}
