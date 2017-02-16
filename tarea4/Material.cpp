#include "Material.h"


Material::Material(double r, double g, double b, double s) {
	this->r = r;
	this->g = g;
	this->b = b;
	shiness = s;
} //set los valores del planeta

// creamos el material
void Material::createMaterial() {

	GLfloat colors[] = {r, g, b, 1.0}; // no queremos que sea transparente
	GLfloat shiness_r[] = { shiness };

	glMaterialfv(GL_FRONT, GL_AMBIENT, colors);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, colors);
	glMaterialfv(GL_FRONT, GL_SPECULAR, colors);
	glMaterialfv(GL_FRONT, GL_SHININESS, shiness_r);
	glMaterialfv(GL_FRONT, GL_EMISSION, colors);
}

Material::~Material(){}
