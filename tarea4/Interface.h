#pragma once
#include "Planet.h"

// clase para hacer magia en opengl
// tambien crea los objetos del sistema
class Interface
{
public:
	Interface();
	~Interface();
	void init(void);
	void display(void);
	void reshape(int, int);
	void simulation();

private:
	vector<Planet *> *planets;
  //un vector con planetas, aqui se guardan... los planetas

	// armar el sistema soalr
	// cada func crea el planeta y sus aditamentos
	void createSun();
	void createMercury();
	void createVenus();
	void createEarth();
	void createMars();
	void createJupiter();
	void createSaturn();
	void createUranus();
	void createNeptune();
  void createPluto();
};
