#pragma once
#include "Material.h"

//factory 
class Robot
{
public:
	Robot();
	~Robot();

	//Funciones que arman el cuerpo del robot
	void torso(double, double, Material *);
	void cabeza(double, double, Material *, Material *, Material *);
	void brazo(double, double, double, Material *, Material*);
	void anteBrazo(Material *,Material *);
	void mano(Material *);
	void pierna(double, double, double, Material *, Material *);
	void espinilla(Material *, Material *);
	void pie(Material *);

	//GETS
	int getShoulderZ();
	int getShoulderX();
	int getElbow();
	int getTorsion();
	int getAnguloMano1();
	int getAnguloMano2();
	int getRotacionCabeza();
	int getGiroCabeza();
	int getAnguloPierna1();
	int getAnguloPierna2();
	int getRodilla();
	int getTobillo();

	//SETS
	void setShoulderZ(int);
	void setShoulderX(int);
	void setElbow(int);
	void setTorsion(int);
	void setAnguloMano1(int);
	void setAnguloMano2(int);
	void setRotacionCabeza(int);
	void setGiroCabeza(int);
	void setAnguloPierna1(int);
	void setAnguloPierna2(int);
	void setRodilla(int);
	void setTobillo(int);

private:
	//Valores de los angulos de todos los grados de libertad del robot
	int shoulderZ; //movimiento de revoluci�n del hombro
	int shoulderX; //movimiento rotacional del hombro
	int elbow; //movimiento rotacional del codo
	int torsion; //movimiento de torsion del antebrazo
	int anguloMano1; //movimiento rotacional de la mano en X
	int anguloMano2; //movimiento rotacional de la mano en Z
	int rotacionCabeza; //movimiento en torsion de la cabeza
	int giroCabeza; //movimiento rotacional de la cabeza en X
	int anguloPierna1; //movimiento rotacional de la pierna en X
	int anguloPierna2; //movimiento rotacional de la pierna en Y
	int rodilla; //movimiento rotacional de la rodilla en X
	int tobillo; //movimiento rotacional del tobillo en X
};