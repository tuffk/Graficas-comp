#pragma once

#include <GL/gl.h>
#include <GL/glut.h>

class Luces{
	public:
		void LucesMagicas() {
  		/* Variables de luz */
  		GLfloat light_ambient[] = {0.0, 0.0, 0.0, 1.0};
  		GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0};
  		GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0};
  		GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0};

  		/* Variable de material */
  		GLfloat mat_ambient[] = {0.7, 0.7, 0.7, 1.0};
  		GLfloat mat_diffuse[] = {0.8, 0.8, 0.8, 1.0};
  		GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
  		GLfloat high_shininess[] = {100.0};

  		glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
  		glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
  		glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
  		glLightfv(GL_LIGHT0, GL_POSITION, light_position);

  		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
  		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
  		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
  		glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
		}
};