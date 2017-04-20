#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <GL/glew.h>
#include <GL/glut.h>
#include "Include/ShaderObject.h"
#include "Include/BmpImage.h"
#ifndef M_PI
	#define M_PI       3.14159265358979323846
#endif

float angle=0, roll=0;
int whatShader=0, inc=0;

enum {
	ENV_PHONG_SHADER,
	ENV_TOON_SHADER,
	ENV_BUMP_MAPPING_SHADER,
	ENV_WOBBLE_SHADER,
	ENV_GEO_SHADER
};

ShaderObject *toon, *phong, *bump, *wobble;
ShaderObject *geo;
unsigned int bumpMapTexId;

void display(void)
{

   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glLoadIdentity();
   
	switch(whatShader){
		case ENV_PHONG_SHADER:
			glRotatef(angle,1,1,0);
			phong->activate ();
				glutSolidTeapot(1);
			phong->deactivate();
			break;
		case ENV_TOON_SHADER:
			glRotatef(angle,1,-1,0);
			toon->activate ();
				glutSolidTeapot(1);
			toon->deactivate();
			break;
		case ENV_BUMP_MAPPING_SHADER:
			glRotatef(angle,-1,1,0);
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, bumpMapTexId);
			bump->activate ();
					glutSolidTeapot(1);
			bump->deactivate ();
			glDisable(GL_TEXTURE_2D);
			break;
		case ENV_WOBBLE_SHADER:
			glRotatef(angle,-1,-1,0);
			wobble->activate ();
				wobble->setUniformf("roll", roll);
				glutSolidTeapot(1);
			wobble->deactivate();
			break;
		case ENV_GEO_SHADER:
			glRotatef(angle,1,-1,-1);
			geo->activate ();
			//	glutWireDodecahedron();
			glutSolidTorus(0.5, 1.5, 20.0, 20.0 );
			geo->deactivate();
			break;
   }

   glutSwapBuffers ();
}

void idle (void)
{
	angle+=0.05; 
	roll+=0.02*rand()/(float)RAND_MAX;
	glutPostRedisplay ();
}

void init (void) 
{

    glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
  
    glEnable(GL_DITHER);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_FASTEST);
    glHint(GL_POLYGON_SMOOTH_HINT, GL_FASTEST);

	toon = new ShaderObject("Shaders/toon/toonVertex.glsl", "Shaders/toon/toonFragment.glsl");
	toon->activate ();
		toon->setUniformf("posX", 0.0);
		toon->setUniformf("posY", 5.0);
		toon->setUniformf("posZ", 5.0);
		toon->setUniformi("toon", 1);
	toon->deactivate ();

	phong = new ShaderObject("Shaders/phong/phongVertex.glsl", "Shaders/phong/phongFragment.glsl");
	phong->activate ();
		phong->setUniformf("posX", 0.0);
		phong->setUniformf("posY", 5.0);
		phong->setUniformf("posZ", 5.0);
		phong->setUniformi("phong", 1);
	phong->deactivate ();

	float lPos[] = {0,5.0,5.0};
	float sColor[] = {1.0,0.5,0.5};

	bump = new ShaderObject("Shaders/bump mapping/bumpMappingVertex.glsl", "Shaders/bump mapping/bumpMappingFragment.glsl");
	bump->activate ();
		bump->setUniformi("bumpNormal",0);
		bump->setUniformfv("LightPosition", lPos,3);
		bump->setUniformfv("SurfaceColor", sColor,3);
		//bump->setUniformf("BumpDensity",26.0);
		//bump->setUniformf("BumpSize", 0.15);
		bump->setUniformf("SpecularFactor", 0.2);
	bump->deactivate ();

	BmpImage *texture = new BmpImage ();
	texture->readBmpFile ("Shaders/bump mapping/bumpMap.bmp");
	glGenTextures  (1, &bumpMapTexId);
	glBindTexture  (GL_TEXTURE_2D, bumpMapTexId);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D   (GL_TEXTURE_2D, 0, GL_RGB, texture->width, texture->height, 0, GL_RGB, GL_UNSIGNED_BYTE, texture->data);
	delete texture;

	float freq[] ={M_PI, M_PI};
	float amp[]={0.2,0.2};
	
	wobble = new ShaderObject("Shaders/wobble/wobbleVertex.glsl","Shaders/wobble/wobbleFragment.glsl");
	wobble->activate ();
		wobble->setUniformfv("LightPosition", lPos,3);
		wobble->setUniformi("texRiver",1);
		wobble->setUniformfv("Freq",freq,2);
		wobble->setUniformfv("Amplitude",amp,2);
	wobble->deactivate ();
	
	glClearColor (.99, .99, .85, 0.0);

	srand( (unsigned)time( NULL ) ); 

	geo = new ShaderObject("Shaders/geo/geoVertex.glsl", "Shaders/geo/geoFragment.glsl", "Shaders/geo/geoGeometry.glsl", GL_TRIANGLES, GL_TRIANGLE_STRIP); 
}


void keys (unsigned char key, int x, int y)
{
	static int toonf = 0;
	switch (key) {
		case '+':
			inc++;
			break;
		case '-':
			inc--;
			break;
	}
	whatShader=abs(inc%(ENV_GEO_SHADER+1));
	printf("%d\n", whatShader);
}


void reshape (int w, int h)
{
	glViewport (0,0, w,h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	
	gluPerspective (45, w*1.0/h*1.0, 0.01, 10);
	glTranslatef (0,0,-5);
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity ();
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize (720, 480); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("hello");
   glutReshapeFunc (reshape);
   glutKeyboardFunc (keys);
   glewInit();
   if (glewIsSupported("GL_VERSION_3_3"))
      printf("Ready for OpenGL 3.3\n");
   else
   {
      printf("OpenGL 3.3 not supported\n");
      exit(1);
   }
   printf("Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
   init ();
   glutDisplayFunc(display); 
   glutIdleFunc (idle);
   glutMainLoop();
   return 0;   /* ANSI C requires main to return int. */
}
