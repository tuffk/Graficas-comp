#include "teoria.h"
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void respuestas(){
	cout << "1.a) MIT 1950" << endl;
	cout << "1.b) Silicon Graphics a principios de los 80's" << endl;
	cout << "2) HMD -> Head Mounted Display" << endl;
	cout << "   LCD -> Liquid Cristal Display" << endl;
	cout << "   GPU -> Graphics Processor Unit" << endl;
	cout << "   OpenGL -> Open Graphics Library" << endl;
	cout << "   ARB -> Architecture Review Board" << endl;
	cout << "   GLUT -> OpenGL Utility Toolkit" << endl;
	cout << "3) El espacio HSI se compone por Hue, Saturation e Intensity, de los cuales podemos ver que los siguientes colores estan: " << endl;
	cout << "   Red: \n   Green: \n   Blue: \n   Black: \n   White: "
	cout << "4) Es un cuerpo solido que su deformación es casi 0 ó 0, las transformaciones son: * Traslación\n* Rotación\n* Reflección" << endl;
	cout << "5.a) 1- Número de núcleos\n 2- Hz a los que corre la tarjeta\n 3- Número de threads por núcleo de la tarjeta\n 4- Arquitectura de la tarjeta\n 5- Clock Rate de la tarjeta\n 6- " << endl;
	cout << "5.b) GlutIdleFunc() para ejecutar background process, el background process son procesos que se llevan a cabo sin tener que renderear y se pueden ejecutar al mismo tiempo que otras funciones" << endl;
	cout << "6) Coordenadas cartesianas (x, y, z), cilindricas (distancia radial, desplazamiento angular (x-y) y desplazamiento en z)(p, phi, z), esféricas(distancia radial, desplazamiento angular (x-y) y desplazamiento angular en z)(r, teta, phi) y coordenadas 3D\n" << endl;
	cout << "7.a) La línea asigna el vector 4 al buffer del shader para agregar el color, el shader es para color" << endl;
	cout << "7.b) linea 1: se define una variable global que va a cambiar denpende el vertice, se usa en los vertex_shaders" << endl;
	cout << "     linea 2: se define una variable que no va a cambiar en ningun momento que se llame a dibujar, tambien es usado para los vertex_shaders"
	cout << "     linea 3: Asigna los vertex_shaders a la posision actual del vertex"
	cout << "7.c) Hace el render de un arreglo que sea de triángulos, empezando en 0 y llegando hasta n" << endl;
	cout << "7.d) Especifica los valores de la matriz de variables tipo uniform, pasandole un objeto uniform a cambiar, el segundo parametro siempre es falso, es la transpuesta y el tercer parametro son los valores que va a tomar" << endl;
	cout << "7.e) Resetea el buffer a  los valores default, su parametro es el buffer que se quiere resetear" << endl;
	cout << "7.f) Inicializa y crea un buffer de objetos, recibiendo el tipo de objetos, el tamaño y que va a hacer con ellos (su uso)" << endl;
} 