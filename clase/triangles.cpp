#include <stdio.h>
#include <GL/glew.h>
#include <GL/freeglut.h>

#define BUFFER_OFFSET(a) ((void*)(a))

const GLuint NumVertices = 24;

GLuint VAOs;
GLuint  Buffers;

GLfloat vertices[NumVertices][2] = {
   { -0.9f, -0.9f },
   { -0.7f, -0.9f },
   { -0.7f,  0.9f },

   { -0.7f,  0.9f },
   { -0.9f,  0.9f },
   { -0.9f, -0.9f },

   { -0.5f, -0.9f },
   { -0.3f, -0.9f },
   { -0.3f,  0.9f },

   { -0.3f,  0.9f },
   { -0.5f,  0.9f },
   { -0.5f, -0.9f },

   { -0.7f, -0.1f },
   { -0.5f, -0.1f },
   { -0.5f, 0.15f },

   { -0.5f, 0.15f },
   { -0.7f, 0.15f },
   { -0.7f, -0.1f },

   { -0.7f, 0.7f },
   { -0.5f, 0.7f },
   { -0.5f, 0.9f },

   { -0.5f, 0.9f },
   { -0.7f, 0.9f },
   { -0.7f, 0.7f }
};

GLuint shaders()
{
printf("shaders\n");

   const char *vertex_shader = "#version 300\n"
                               "layout(location = 0) in vec4 vPosition;"
                               "void main() {"
                               "   gl_Position = vPosition;"
                               "}";
   GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
   glShaderSource(vertexShader, 1, &vertex_shader, NULL);
   glCompileShader(vertexShader);

   const char *fragment_shader = "#version 300\n"
                                 "out vec4 fColor;"
                                 "void main () {"
                                 "   fColor = vec4 (0.0, 0.0, 1.0, 1.0);"
                                 "}";
   GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
   glShaderSource(fragmentShader, 1, &fragment_shader, NULL);
   glCompileShader(fragmentShader);

   GLuint shader_program = glCreateProgram();
   glAttachShader(shader_program, fragmentShader);
   glAttachShader(shader_program, vertexShader);
   glLinkProgram(shader_program);
   glUseProgram(shader_program);
   return shader_program;
}

void init()
{
printf("VAOs\n");
   glGenVertexArrays( 1, &VAOs );
   glBindVertexArray( VAOs );

   glGenBuffers( 1, &Buffers);
   glBindBuffer(GL_ARRAY_BUFFER, Buffers);
   glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

printf("shaders\n");
   GLuint program = shaders();
   glUseProgram( program );

   glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
   glEnableVertexAttribArray( 0 );
}

void display()
{
   glClear(GL_COLOR_BUFFER_BIT);
   glBindVertexArray( VAOs );
   glDrawArrays( GL_TRIANGLES, 0, NumVertices );
   glFlush();
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_RGBA);
   glutInitWindowSize(512, 512);
   glutInitContextVersion(3, 0);
   glutInitContextProfile(GLUT_CORE_PROFILE);
   glutCreateWindow("Letras");

   glewExperimental = GL_TRUE;
   if (glewInit())
   {
      printf("Error al inicializar GLEW\n");
      exit(0);
   }
   const GLubyte *renderer;
   const GLubyte *version;
   renderer = glGetString(GL_RENDERER);
   version = glGetString(GL_VERSION);
   printf("Renderer: %s\n", renderer);
   printf("OpenGL version supported %s\n", version);

   init();
   glutDisplayFunc(display);
   glutMainLoop();
   return 0;
}
