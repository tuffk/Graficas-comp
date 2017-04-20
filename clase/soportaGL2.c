#include <GL/glew.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char **argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
   glutCreateWindow(argv[0]);
   float ver = 3;

   glewInit();
   if (glewIsSupported("GL_VERSION_3_0"))
      printf("Ready for OpenGL %f\n",ver);
   else
   {
      printf("OpenGL %f not supported\n",ver);
      exit(1);
   }
   glutMainLoop();

   return 0;
}
