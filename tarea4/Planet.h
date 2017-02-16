#pragma once
#include <vector>
#include "Material.h"

class Planet
{
public:
	Planet(double, double, double, double, Material *);
	~Planet();
	void pushMoon(Planet *);
	void simulation();
	void draw();
	void insertRings(bool);

private:
	double year;
	double day;
	double distance;
	double size;
	vector<Planet *> *moons;
	bool rings;
	bool eje;
	double translation;
	double rotation;
	Material *material;
};
