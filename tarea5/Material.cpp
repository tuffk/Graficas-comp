#include "Material.h"

//Constructor
Material::Material(double r, double g, double b, double s) {
	this->r = r;
	this->g = g;
	this->b = b;
	shiness = s;
}

//creamos ameteriales
void Material::createMaterial() {

	GLfloat colors[] = { r, g, b, 1.0 };
	GLfloat shiness_r[] = { shiness };

	glMaterialfv(GL_FRONT, GL_AMBIENT, colors);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, colors);
	glMaterialfv(GL_FRONT, GL_SPECULAR, colors);
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness_r);
	glMaterialfv(GL_FRONT, GL_EMISSION, colors);
}

//Destructor, no hace nada
Material::~Material() {}