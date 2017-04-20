#include <GL/glew.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
   glutCreateWindow(argv[0]);

   glewInit();
   if (GLEW_ARB_vertex_shader && GLEW_ARB_fragment_shader)
      printf("Ready for GLSL\n");
   else
   {
      printf("Not totally ready :( \n");
      exit(1);
   }
   glutMainLoop();

   return 0;
}
