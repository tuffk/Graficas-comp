#pragma once
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <GL/glut.h>

using namespace std;

class Material
{
public:
	Material(double, double, double, double);
	void createMaterial();
	~Material();

private:
	double r, g, b; // color del material, 1 hard code para alfa
	double shiness; // brilla
};
